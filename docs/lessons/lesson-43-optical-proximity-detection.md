# Lektion 43: Optische Näherungserkennung

> **Bausatz:** Keyestudio 48-in-1 Sensorkit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P-Board

![Projekt 43: Illustration zur optischen Näherungserkennung](../media/4085d5742012b8647b52c537b82974ff.jpeg)

## Einführung

**Kompatibilitäts-Hinweis.** Der ursprüngliche Text benennt dieses Modul als TMD27713, während der Sketch unten auf den APDS-9930 abzielt. Prüfen Sie die IC-Beschriftung und verwenden Sie vor dem Hochladen eine passende Bibliothek.

Es handelt sich um einen Dreifach-Sensor, der Umgebungslicht, Näherungssensor und eine Infrarot-LED integriert.

Zum einen dient er zur Erfassung der aktuellen Umgebungshelligkeit (ALS). Er kann in Abhängigkeit von der aktuellen Umgebungshelligkeit die Hintergrundbeleuchtungshelligkeit automatisch per Softwareanpassung regulieren. Auf diese Weise wird die Hintergrundbeleuchtung sanfter, was die Augen schont und Energie spart.

Zum anderen verfügt er über eine Näherungsfunktion (PROX). Der Sensor integriert Sender und Empfänger, wodurch das Design minimiert wurde; somit bestehen kaum Platzbeschränkungen bei Design und Montage, und die mechanische Struktur ist relativ einfach.

## Parameter

- Betriebsspannung：DC 3.3V

- Erfassungsdistanz：100mm

- Kommunikationsschnittstelle：I2C-Kommunikation

- Temperaturbereich：-30℃ bis 85℃

## Anschlussdiagramm

Zuerst benötigen Sie die folgenden Teile:

- V4.0-Platine\*1

- TMD27713-Sensor\*1

- USB-Kabel\*1

- Jumperkabel\*5

Verbinden Sie den INT-Pin des Sensors mit dem Digital 2 Anschluss des V4.0-Boards, den SCL-Pin mit dem Analog A5 Anschluss, den SDA-Pin mit dem Analog A4 Anschluss; Verbinden Sie den VCC-Pin mit dem 3V3-Anschluss, den GND-Pin mit dem GND-Anschluss.

![Anschlussdiagramm-Illustration](../media/c9319e0f5116f416380d6b3c9ddc608c.jpeg)

## Beispielcode

Testet die Näherungs-Interrupt-Fähigkeiten des APDS-9930.

Konfiguriert den APDS-9930 über I2C und wartet auf einen externen Interrupt, der auf hohen oder niedrigen Näherungsbedingungen basiert. Bewegen Sie Ihre Hand in die Nähe des Sensors und beobachten Sie die LED an Pin 13.

## Hardware-Verbindungen

**WICHTIG**: Der APDS-9930 akzeptiert nur 3,3 V!

| Arduino Pin | APDS-9930-Modul | Funktion  |
| :---------: | :-------------: | :-------: |
|    3.3V     |       VCC       | Stromversorgung |
|     GND     |       GND       |   Masse   |
|     A4      |       SDA       | I2C-Daten |
|     A5      |       SCL       | I2C-Takt  |
|      2      |       INT       | Interrupt |
|     13      |        -        |    LED    |

**Ressourcen**: Wire.h und APDS9930.h einbinden

**Entwicklungsumgebung**: Geschrieben für Arduino 1.0.5

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
#include <Wire.h>
#include <APDS9930.h>

// Pins
#define APDS9930_INT    2  // Needs to be an interrupt pin
#define LED_PIN         13 // LED for showing interrupt

// Constants
#define PROX_INT_HIGH   600 // Proximity level for interrupt
#define PROX_INT_LOW    0  // No far interrupt

// Global variables
APDS9930 apds = APDS9930();
float ambient_light = 0; // can also be an unsigned long
uint16_t ch0 = 0;
uint16_t ch1 = 1;
uint16_t proximity_data = 0;
volatile bool isr_flag = false;

void setup() {

  // Set LED as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(APDS9930_INT, INPUT);

  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("------------------------------"));
  Serial.println(F("APDS-9930 - ProximityInterrupt"));
  Serial.println(F("------------------------------"));

  // Initialize interrupt service routine
  attachInterrupt(digitalPinToInterrupt(APDS9930_INT), interruptRoutine, FALLING);

  // Initialize APDS-9930 (configure I2C and initial values)
  if (apds.init()) {
    Serial.println(F("APDS-9930 initialization complete"));
  }
  else {
    Serial.println(F("Something went wrong during APDS-9930 init!"));
  }

  // Adjust the Proximity sensor gain
  if (!apds.setProximityGain(PGAIN_2X)) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }

  // Set proximity interrupt thresholds
  if (!apds.setProximityIntLowThreshold(PROX_INT_LOW)) {
    Serial.println(F("Error writing low threshold"));
  }
  if (!apds.setProximityIntHighThreshold(PROX_INT_HIGH)) {
    Serial.println(F("Error writing high threshold"));
  }

  // Start running the APDS-9930 proximity sensor (interrupts)
  if (apds.enableProximitySensor(true)) {
    Serial.println(F("Proximity sensor is now running"));
  }
  else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

  // Start running the APDS-9930 light sensor (no interrupts)
  if (apds.enableLightSensor(false)) {
    Serial.println(F("Light sensor is now running"));
  }
  else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

#ifdef DUMP_REGS
  /* Register dump */
  uint8_t reg;
  uint8_t val;

  for (reg = 0x00; reg <= 0x19; reg++) {
    if ((reg != 0x10) && \
      (reg != 0x11))
    {
      apds.wireReadDataByte(reg, val);
      Serial.print(reg, HEX);
      Serial.print(": 0x");
      Serial.println(val, HEX);
    }
  }
  apds.wireReadDataByte(0x1E, val);
  Serial.print(0x1E, HEX);
  Serial.print(": 0x");
  Serial.println(val, HEX);
#endif

}

void loop() {

  // If interrupt occurs, print out the proximity level
  if (isr_flag) {

    // Read proximity level and print it out
    if (!apds.readProximity(proximity_data)) {
      Serial.println("Error reading proximity value");
    }
    else {
      Serial.print("Proximity detected! Level: ");
      Serial.print(proximity_data);
      Serial.print("   ");
    }
    apds.readAmbientLightLux(ambient_light);
    // Read the light levels (ambient, red, green, blue)
    if (!apds.readAmbientLightLux(ambient_light) ||
      !apds.readCh0Light(ch0) ||
      !apds.readCh1Light(ch1)) {
      Serial.println(F("Error reading light values"));
    }
    else {
      Serial.print(F("Ambient: "));
      Serial.print(ambient_light);
      Serial.print(F("  Ch0: "));
      Serial.print(ch0);
      Serial.print(F("  Ch1: "));
      Serial.println(ch1);
    }

    // Turn on LED for a half a second
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);

    // Reset flag and clear APDS-9930 interrupt (IMPORTANT!)
    isr_flag = false;
    if (!apds.clearProximityInt()) {
      Serial.println("Error clearing interrupt");
    }

  }
}

void interruptRoutine() {
  isr_flag = true;
}
```

Hinweis: Bevor Sie den Code kompilieren, denken Sie daran, die Bibliothek in das Verzeichnis libraries der Arduino-IDE zu legen. Andernfalls schlägt die Kompilierung fehl.

## Beispielergebnis

![Beispielergebnis-Illustration](../media/f2c369c253c3b5fd8cf2c9df39f1c01a.png)

Getestet mit der Arduino-Version 1.8.2; öffnen Sie anschließend den Seriellen Monitor, Sie können die Daten wie in der folgenden Abbildung sehen.

![Beispielergebnis-Illustration](../media/607fe1d8c324c14c06492d96d60eb0ca.png)

---

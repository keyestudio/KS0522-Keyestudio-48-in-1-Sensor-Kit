# Lektion 42: Lage-Sensor

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / mit dem Arduino Uno kompatible ATmega328P-Platine

![Projekt 42: Lage-Sensor Abbildung](../media/8eb8d16c5e76e50a6609678130a9ee29.jpeg)

## Einführung

**Kompatibilitäts-Hinweis.** Die Teileliste bezeichnet diese Platine als APDS-9930, aber das folgende ältere Beispiel richtet sich an einen APDS-9960 und verwendet `SparkFun_APDS9960`. Prüfen Sie die IC-Beschriftung des tatsächlichen Moduls, bevor Sie diesen Sketch hochladen; verwenden Sie dieses Beispiel nicht mit einem APDS-9930-Board. Der APDS-9930 im 8-poligen Gehäuse bietet einen Umgebungslichtsensor, der I2C-kompatibel ist, sowie einen Infrarot-LED-Näherungssensor.

Der Näherungssensor, der vollständig kalibriert ist, kann Objekte in 100 mm Entfernung erkennen und hebt damit die werkseitigen Kalibrieranforderungen von Endgeräten und Unterbaugruppen auf.

Vom hellen Sonnenlicht bis zum dunklen Raum funktioniert die Näherungsdetektion zuverlässig.

Dieses Modul fügt eine mikro-optische Linse hinzu, die eine energieeffiziente Übertragung und Empfang von Infrarotenergie ermöglicht und so den Gesamtenergieverbrauch reduziert.

Zusätzlich kann seine interne Zustandsmaschine das Gerät in einen Niedrigenergie-Modus versetzen, was zu einem sehr geringen durchschnittlichen Stromverbrauch führt.

## Parameter

- Betriebsspannung：DC 3.3-3.8V

- Ausgangsstrom：0-20mA

- Temperaturbereich：-40℃—85℃

## Merkmale

1. Optisches Modul integriert ALS, Infrarot-LED und Näherungsdetektor;

2. Bis zu 16-Bit Auflösung;

3. Hohe Empfindlichkeit auch bei dunklem Glas;

4. 0.01 lux niedrige Lichtleistung;

5. Näherungserkennung, werkseitig vollständig auf 100 mm Detektion kalibriert;

6. Integrierte Infrarot-LED und synchroner LED-Treiber;

7. Keine werkseitige Kalibrierung für Näherungssensoren erforderlich;

8. Programmierbarer Warte-Timer, Leistungsaufnahme im Wartezustand – 90μA (typischer Wert);

9. Programmierbarer Bereich von 2,7 Millisekunden bis 8 Sekunden;

10. Kompatibel mit I2C-Schnittstelle, bis zu 400 kHz (I2C-Fast-Mode);

11. Dedizierter Interrupt-Pin;

12. Sleep-Modus Stromverbrauch - 2.2μA (typischer Wert).

## Anschlussdiagramm

Zuerst müssen Sie die folgenden Teile vorbereiten:

- V4.0 Platine\*1

- Lage-Sensor\*1

- USB-Kabel\*1

- Jumperkabel\*5

Verbinden Sie den INT-Pin des Sensors mit dem digitalen Port D2 der V4.0-Platine, den SCL-Pin mit dem analogen Port A5, den SDA-Pin mit dem analogen Port A4; verbinden Sie den 3V3-Pin mit dem 3V3-Anschluss und den GND-Pin mit GND.

![Anschlussdiagramm Abbildung](../media/c906c4e8a06998118eac5e3b981386d6.jpeg)

## Beispielcode

**WICHTIG**: Der APDS-9960 akzeptiert nur 3.3V!

## Hardware-Verbindungen

| Arduino Pin | APDS-9960 Board | Funktion  |
| :---------: | :-------------: | :-------: |
|    3.3V     |       VCC       |   Stromversorgung   |
|     GND     |       GND       |  Masse   |
|     A4      |       SDA       | I2C-Daten  |
|     A5      |       SCL       | I2C-Takt |
|     D2      |       INT       | Interrupt |
|     D13     |        -        |    LED    |

**Ressourcen:** Einbinden von Wire.h und SparkFun_APDS-9960.h

**Entwicklungsumgebung:** Geschrieben für Arduino 1.0.5

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
#include <Wire.h>
#include <SparkFun_APDS9960.h>

// Pins
#define APDS9960_INT    2  // Needs to be an interrupt pin
#define LED_PIN         13 // LED for showing interrupt

// Constants
#define LIGHT_INT_HIGH  1000 // High light level for interrupt
#define LIGHT_INT_LOW   10   // Low light level for interrupt

// Global variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
int isr_flag = 0;
uint16_t threshold = 0;

void setup() {
  // Set LED as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(APDS9960_INT, INPUT);
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("-------------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - Light Interrupts"));
  Serial.println(F("-------------------------------------"));
  // Initialize interrupt service routine
  attachInterrupt(0, interruptRoutine, FALLING);
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  // Set high and low interrupt thresholds
  if ( !apds.setLightIntLowThreshold(LIGHT_INT_LOW) ) {
    Serial.println(F("Error writing low threshold"));
  }
  if ( !apds.setLightIntHighThreshold(LIGHT_INT_HIGH) ) {
    Serial.println(F("Error writing high threshold"));
  }
  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }
  // Read high and low interrupt thresholds
  if ( !apds.getLightIntLowThreshold(threshold) ) {
    Serial.println(F("Error reading low threshold"));
  } else {
    Serial.print(F("Low Threshold: "));
    Serial.println(threshold);
  }
  if ( !apds.getLightIntHighThreshold(threshold) ) {
    Serial.println(F("Error reading high threshold"));
  } else {
    Serial.print(F("High Threshold: "));
    Serial.println(threshold);
  }
  // Enable interrupts
  if ( !apds.setAmbientLightIntEnable(1) ) {
    Serial.println(F("Error enabling interrupts"));
  }
  // Wait for initialization and calibration to finish
  delay(500);
}
void loop() {
  // If interrupt occurs, print out the light levels
  if ( isr_flag == 1 ) {

    // Read the light levels (ambient, red, green, blue) and print
    if (  !apds.readAmbientLight(ambient_light) ||
          !apds.readRedLight(red_light) ||
          !apds.readGreenLight(green_light) ||
          !apds.readBlueLight(blue_light) ) {
      Serial.println("Error reading light values");
    } else {
      Serial.print("Interrupt! Ambient: ");
      Serial.print(ambient_light);
      Serial.print(" R: ");
      Serial.print(red_light);
      Serial.print(" G: ");
      Serial.print(green_light);
      Serial.print(" B: ");
      Serial.println(blue_light);
    }
    // Turn on LED for a half a second
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);

    // Reset flag and clear APDS-9960 interrupt (IMPORTANT!)
    isr_flag = 0;
    if ( !apds.clearAmbientLightInt() ) {
      Serial.println("Error clearing interrupt");
    }
  }
}
void interruptRoutine() {
  isr_flag = 1;
}
```

Hinweis: Bevor Sie den Code kompilieren, denken Sie daran, die Bibliothek in das Verzeichnis libraries der Arduino-IDE zu legen. Andernfalls schlägt die Kompilierung fehl.

## Beispielergebnis

![Beispielergebnis Abbildung](../media/2a30729fa77874e4e61f51d2bb8e62c1.png)

Nachdem Sie den Code hochgeladen haben, öffnen Sie den seriellen Monitor und stellen Sie die Baudrate auf 9600 ein.

![Beispielergebnis Abbildung](../media/935c7035ef43f54ca65eaa49bbaf5e98.jpeg)

---

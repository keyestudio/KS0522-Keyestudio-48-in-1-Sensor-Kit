# Les 43: Optische nabijheidsdetectie

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 43: Illustratie optische nabijheidsdetectie](../media/4085d5742012b8647b52c537b82974ff.jpeg)

## Inleiding

**Compatibiliteitsmelding.** De legacy-tekst identificeert deze module als TMD27713, terwijl de sketch hieronder gericht is op APDS-9930. Controleer de IC-markering en gebruik een bijpassende bibliotheek voordat je uploadt.

Het is een drievoudige sensor geïntegreerd met omgevingslichtsensor, nabijheidssensor en infrarood-LED.

Ten eerste wordt deze gebruikt om de huidige omgevingshelderheid (ALS) te detecteren. Op basis van de huidige omgevingshelderheid kan hij via software automatisch de helderheid van de achtergrondverlichting aanpassen aan het omgevingslicht. Op deze manier kan de achtergrondverlichting zacht worden gehouden om je zicht te beschermen en energie te besparen.

Een andere functie is de nabijheidssensorfunctie (PROX). De sensor heeft zender/ontvanger geïntegreerd en het ontwerp geminimaliseerd; hierdoor zijn er geen ruimtelijke beperkingen meer voor ontwerp en installatie en is een deel van de constructie relatief eenvoudig.

## Parameters

- Werkspanning：DC 3.3V

- Detectieafstand：100mm

- Communicatie：IIC-communicatie

- Temperatuurbereik：-30℃ tot 85℃

## Aansluitschema

Bereid eerst de volgende onderdelen voor:

- V4.0 Board\*1

- TMD27713 sensor\*1

- USB-kabel\*1

- Dupontdraden\*5

Verbind de INT-pin van de sensor met de Digital 2-poort van het V4.0-bord, de SCL-pin met de Analog A5-poort, de SDA-pin met de Analog A4-poort; verbind de VCC-pin met de 3V3-poort, GND-pin met de GND-poort.

![Aansluitschema illustratie](../media/c9319e0f5116f416380d6b3c9ddc608c.jpeg)

## Voorbeeldcode

Test de interrupt-mogelijkheden voor nabijheid van de APDS-9930.

Configureert de APDS-9930 via I2C en wacht op een externe interrupt op basis van hoge of lage nabijheidscondities. Beweeg je hand dicht bij de sensor en kijk naar de LED op pin 13.

## Hardwareverbindingen

**BELANGRIJK**: De APDS-9930 accepteert alleen 3.3V!

| Arduino Pin | APDS-9930 Board | Functie   |
| :---------: | :-------------: | :-------: |
|    3.3V     |       VCC       |  Voeding  |
|     GND     |       GND       |   Massa   |
|     A4      |       SDA       | I2C-data  |
|     A5      |       SCL       | I2C-klok  |
|      2      |       INT       | Onderbreking |
|     13      |        -        |    LED    |

**Bronnen**: Voeg Wire.h en APDS9930.h toe

**Ontwikkelomgeving**: Geschreven voor Arduino 1.0.5

Kopieer en plak de onderstaande code in de Arduino-software.

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

Opmerking: plaats vóór het compileren de bibliotheek in de libraries-map van de Arduino IDE. Anders faalt het compileren.

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/f2c369c253c3b5fd8cf2c9df39f1c01a.png)

Getest met Arduino-1.8.2 software; open de seriële monitor om de gegevens te zien zoals in de onderstaande afbeelding.

![Voorbeeldresultaat illustratie](../media/607fe1d8c324c14c06492d96d60eb0ca.png)

---

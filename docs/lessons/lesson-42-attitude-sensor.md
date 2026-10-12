# Les 42: Oriëntatiesensor

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 42: Oriëntatiesensor illustratie](../media/8eb8d16c5e76e50a6609678130a9ee29.jpeg)

## Introductie

**Compatibiliteitsmelding.** De onderdelenlijst labelt dit bord als APDS-9930, maar het volgende legacy-voorbeeld is gericht op een APDS-9960 en gebruikt `SparkFun_APDS9960`. Controleer de IC-markering op het daadwerkelijke module voordat je dit sketch uploadt; gebruik dit voorbeeld niet met een APDS-9930-bord. APDS-9930 in een enkele 8-pins behuizing kan de omgevingslichtsensor leveren die compatibel is met de I2C-interface en de infrarood-LED nabijheidssensor.

De nabijheidssensor, die volledig is afgesteld, kan een object op 100 mm detecteren en ontslaat de fabriekscalibratievereisten van eindapparatuur en subcomponenten.

Van fel zonlicht tot een donkere kamer kan de nabijheidsdetectiefunctie goed werken.

Deze module heeft een micro optische lens toegevoegd die efficiënte transmissie en ontvangst van infraroodenergie biedt, wat het totale stroomverbruik kan verminderen.

Daarnaast kan de interne toestandsmachine het apparaat in een laagvermogenmodus brengen, wat een zeer laag gemiddeld stroomverbruik oplevert.

## Parameters

- Werkspanning：DC 3.3-3.8V

- Uitgangsstroom：0-20mA

- Temperatuurbereik：-40℃—85℃

## Kenmerken

1. Optische module geïntegreerd met ALS, infrarood-LED en nabijheidsdetector;

2. Tot 16-bit resolutie;

3. Hoge gevoeligheid bij werking achter donker glas;

4. 0.01lux detectie bij weinig licht;

5. Nabijheidsdetectie, volledig gekalibreerd voor 100 mm detectie;

6. Integreert infrarood-LED en synchrone LED-driver;

7. Elimineert fabriekskalibratie voor nabijheidssensoren;

8. Programmeerbare wachttimer, stroomverbruik in wachtstand - 90μA (typische waarde);

9. Programmeerbaar bereik van 2.7 milliseconden tot 8 seconden;

10. Compatibel met I2C-interface, tot 400kHz (I2C snelle modus);

11. Toegewijde onderbrekingspin;

12. Slaapmodusstroom - 2.2μA (typische waarde).

## Aansluitschema

Zorg eerst dat je de volgende onderdelen klaar hebt:

- V4.0 Bord\*1

- Oriëntatiesensor\*1

- USB-kabel\*1

- Jumper Wire\*5

Verbind de INT-pin van de sensor met digitale poort 2 van het V4.0-bord, de SCL-pin met Analoge A5-poort, de SDA-pin met Analoge A4-poort; verbind de 3V3-pin met de 3V3-aansluiting, GND-pin met de GND-aansluiting.

![Aansluitschema illustratie](../media/c906c4e8a06998118eac5e3b981386d6.jpeg)

## Voorbeeldcode

**BELANGRIJK**: De APDS-9960 accepteert alleen 3.3V!

## Hardware-aansluitingen

| Arduino Pin | APDS-9960 Board | Functie  |
| :---------: | :-------------: | :-------: |
|    3.3V     |       VCC       |   Voeding   |
|     GND     |       GND       |   Aarde    |
|     A4      |       SDA       | I2C-gegevens  |
|     A5      |       SCL       | I2C-klok |
|     D2      |       INT       | Onderbreking |
|     D13     |        -        |    LED    |

**Bronnen:** Inclusief Wire.h en SparkFun_APDS-9960.h

**Ontwikkelomgevingsdetails:** Geschreven in Arduino 1.0.5

Kopieer en plak onderstaande code in de Arduino-software.

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

Opmerking: plaats vóór het compileren de bibliotheek in de libraries-map van de Arduino IDE. Anders faalt de compilatie.

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/2a30729fa77874e4e61f51d2bb8e62c1.png)

Na het uploaden van de code, open de seriële monitor en stel de baudrate in op 9600.

![Voorbeeldresultaat illustratie](../media/935c7035ef43f54ca65eaa49bbaf5e98.jpeg)

---

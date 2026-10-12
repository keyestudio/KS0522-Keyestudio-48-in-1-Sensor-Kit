# Les 35: Hartslagmonitor

> **Kit:** Keyestudio 48-in-1 Sensorkit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-board

![Project 35: Hartslagmonitor illustratie](../media/0ec440cd93e00e956357ece654ce2a9c.png)

## Beschrijving

Deze module maakt gebruik van een ultra-heldere infrarood-LED en een fototransistor om de polsslag in je vinger te detecteren. De rode LED knippert synchroon met je hartslag.

Werkingsprincipe

Schijn de heldere LED op één zijde van je vinger terwijl de fototransistor aan de andere zijde de hoeveelheid doorgestralen licht opvangt. De weerstand van de fototransistor varieert lichtjes zodra het bloed door je vinger pulseert.

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je een test uitvoert.

- V4.0 Board\*1

- Pulsmodule\*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de signaalpin van de module met Analog A0 van het V4.0-board, de positieve pin met de 5V-poort en de negatieve pin met de GND-poort.

![Aansluitschema illustratie](../media/fa86e3930b83753af7ad87d0418cd350.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
///////////////////////////////////////////////////////////////
int ledPin = 13;
int sensorPin = 0;
double alpha = 0.75;
int period = 20;
double change = 0.0;
void setup()
{
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
}
void loop()
{
static double oldValue = 0;
static double oldChange = 0;
int rawValue = analogRead(sensorPin);
double value = alpha * oldValue + (1 - alpha) * rawValue;
Serial.print(rawValue);
Serial.print(",");
Serial.println(value);
oldValue = value;
delay(period);
}
///////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Sluit alles goed aan zoals in bovenstaand schema, upload vervolgens de code naar het board en klik op het pictogram van de seriële monitor in de rechterbovenhoek van de Arduino-software. Stel de baudrate in op 115200; je ziet dan de gegevens in de monitor verschijnen.

Je kunt de gegevens kopiëren en plakken in Excel; uiteindelijk wordt de bijbehorende grafiek gegenereerd zoals hieronder weergegeven.

![Voorbeeldresultaat illustratie](../media/3c3a1a0d120f1c68c95095a0fd98fa47.png)

![Voorbeeldresultaat illustratie](../media/215ab9a6174f9798a291bacb907eaf89.jpeg)

---

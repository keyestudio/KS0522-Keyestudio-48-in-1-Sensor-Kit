# Les 32: Ultraviolet licht

> **Kit:** Keyestudio 48-in-1 sensorkit  
> **Ontwikkelbord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 32: Ultraviolet licht illustratie](../media/15613ff0e8f059a9034e923ab5c2be24.jpeg)

## Beschrijving

De Keyestudio GUVA-S12SD ultraviolet-sensor wordt gebruikt om ultraviolet licht te detecteren. De GUVA-S12SD wordt toegepast om de UV-index te meten in slimme draagbare apparaten, zoals horloges, smartphones en draagbare buitenapparaten met UV-indexdetectie.

Hij kan ook worden gebruikt om de intensiteit van ultraviolet licht te monitoren of als UV-vlamdetector bij het desinfecteren met ultraviolet licht.

## Parameters

- Grootte: 15mm×30mm×0.7mm

- Voedingsspanning: 2.5V～5V

- Uitgangssignaal: Analoog signaal

- Detectiebereik van spectrum: 240-370nm

- Actief gebied: 0.076mm2

- Responsiviteit: 0.14A/W

- Donkerstroom: 1nA

- Lichtstroom: 101\~125nA UVA-licht, 1mW/cm2

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat u aansluit.

- V4.0-board\*1

- GUVA-S12SD 3528 ultraviolette sensor \*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de S-pin van de module met Analog A0 van het V4.0-board, verbind de negatieve pin met de GND-poort en de positieve pin met de 3V3-poort.

![Aansluitschema illustratie](../media/092ebb11142cfe83507989a5b2de0526.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
///////////////////////////////////////////////////////////////
/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
///////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/e81338e1f55ff6b55fbfe369f92b54da.png)

Sluit alles correct aan en upload de programmatuur, open vervolgens de seriële monitor; deze toont de gegevens.

Wanneer u UV-licht op de sensor richt, veranderen de gegevens in de seriële monitor zoals in de volgende afbeelding wordt getoond.

![Voorbeeldresultaat illustratie](../media/3a7f2a608faa9c72aee76d2820f78845.png)

![Voorbeeldresultaat illustratie](../media/610d2325395cd3b44ce3c18e05595518.jpeg)

---

# Les 12: Hall-magnetische sensor

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P bord

![Project 12: Hall-magnetische sensor illustratie](../media/c3d4d513b72ac04fad7e4f3015bfb1ed.png)

## Beschrijving

Dit is een magnetische inductiesensor. Hij kan magnetische materialen detecteren binnen een detectiebereik tot 3cm. Het detectiebereik en de sterkte van het magnetisch veld zijn evenredig. De uitgang is digitaal aan/uit.

Deze sensor gebruikt de SFE Reed Switch - Magnetic Field Sensor.

## Specificaties

- Detecteert magnetische materialen

- Detectiebereik: tot 3cm

- Uitgang: digitaal aan/uit

- Afmeting: 30*20mm

- Gewicht: 3g

## Aansluitschema

Eerst moet je de volgende onderdelen voorbereiden voordat je aansluit:

- V4.0 Bord\*1

- Hall-sensor \*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de S-pin van de module met Digital 3 van het V4.0-bord, verbind de negatieve pin met de GND-poort en de positieve pin met de 5V-poort.

![Aansluitschema illustratie](../media/db4db0c53435ceb1d6caaaf40502247a.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare push button as input
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Sluit alles aan en upload de code naar het bord; je zult zien dat de D13-indicator op het V4.0-bord uit is, en de LED op de module ook uit is.

![Voorbeeldresultaat illustratie](../media/102f67e289b5834de7fa80b6e6d99c20.png)

Maar als je een magneet dicht bij de hall-module houdt, zie je dat de D13-indicator op het V4.0-bord aangaat, en de LED op de module ook aangaat.

![Voorbeeldresultaat illustratie](../media/c3c4044f2205dd1ff162ef7e211d2b2c.png)

---

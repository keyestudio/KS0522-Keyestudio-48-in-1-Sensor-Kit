# Les 04: Verkeerslicht

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibele ATmega328P-bord

![Project 4: Verkeerslicht illustratie](../media/a20653cffac8985dc4919614540ac367.jpeg)

## Beschrijving

Bij het leren van de microcontroller gebruik je meestal drie LED's, namelijk rode, groene en gele lampjes om het knipperen van een verkeerslicht via een externe aansluiting na te bootsen.

Deze keer hebben we speciaal deze module ontworpen die zeer handig is voor bedrading, en op de module zie je de rode, gele en groene LED's.

Deze module is volledig compatibel met Arduino-microcontrollers en het Raspberry Pi-systeem.

## Specificaties

- Werkspanning: 3.3-5v

- Type interface: digitaal

- PH2.54-connector

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten:

- V4.0 bord\*1

- Verkeerslichtmodule \*1

- USB-kabel\*1

- Dupont-kabel\*4

Verbind de R-pin van de module met Digital 5 van het V4.0 board, verbind de Y-pin met Digital 4, de G-pin met Digital 3, en de GND-pin met de GND-aansluiting.

![Aansluitschema illustratie](../media/b6884692ce41d05d4afb167af5b2239d.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
int redled =5; // initialize digital pin 5.
int yellowled =4; // initialize digital pin 4.
int greenled =3; // initialize digital pin 3.
void setup()
{
pinMode(redled, OUTPUT);// set the pin with red LED as “output”
pinMode(yellowled, OUTPUT); // set the pin with yellow LED as “output”
pinMode(greenled, OUTPUT); // set the pin with green LED as “output”
}
void loop()
{
digitalWrite(greenled, HIGH);//// turn on green LED
delay(5000);// wait 5 seconds
digitalWrite(greenled, LOW); // turn off green LED
for(int i=0;i<3;i++)// blinks for 3 times
{
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, HIGH);// turn on yellow LED
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, LOW);// turn off yellow LED
}
delay(500);// wait 0.5 seconds
digitalWrite(redled, HIGH);// turn on red LED
delay(5000);// wait 5 seconds
digitalWrite(redled, LOW);// turn off red LED
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Na het uploaden van de code en het inschakelen zullen de drie LED's op de module automatisch in een lus het verkeerslicht simuleren.

![Voorbeeldresultaat illustratie](../media/6dd1ff8660b0a62795bd53fc6b6ff591.png)

---

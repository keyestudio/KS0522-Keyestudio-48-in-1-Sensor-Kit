# Les 41: Magische Lichtbeker

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 41: illustratie Magische Lichtbeker](../media/dc3acff676b2611f440643f1657b42e7.png)

## Inleiding

De magische lichtbeker-module kan met Arduino communiceren. Het principe is gebaseerd op PWM-dimmen.

De kwikschakelaar op de module levert een digitaal signaal en activeert PWM-regeling. De helderheid van twee modules verandert gelijktijdig via het programma; uiteindelijk zie je het veranderende effect waarbij twee bekers licht "gieten".

## Specificatie

- Voedingsspanning: 3.3V tot 5V

- Interface: Digitaal

## Aansluitschema

![Aansluitschema illustratie](../media/9d8d534c60a81608741f85c08d4d0bbe.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
///////////////////////////////////////////////////////////////
int LedPinA = 5;
int LedPinB = 6;
int ButtonPinA = 7;
int ButtonPinB = 4;
int buttonStateA = 0;
int buttonStateB = 0;
int brightnessA = 0;
int brightnessB= 255;
void setup()
{
Serial.begin(9600);
pinMode(LedPinA, OUTPUT);
pinMode(LedPinB, OUTPUT);

pinMode(ButtonPinA, INPUT);
pinMode(ButtonPinB, INPUT);
}
void loop()
{
buttonStateA = digitalRead(ButtonPinA);
if (buttonStateA == HIGH && brightnessA != 255)
{
brightnessA ++;
}
if (buttonStateA == LOW && brightnessA != 0)
{
brightnessA --;
}
analogWrite(LedPinB, brightnessA);
Serial.print(brightnessA);

Serial.print("   ");
buttonStateB = digitalRead(ButtonPinB);
if (buttonStateB == HIGH && brightnessB != 0)
{
brightnessB --;
}
if (buttonStateB == LOW && brightnessB != 255)
{
brightnessB++;
}
analogWrite(LedPinA, brightnessB);
Serial.println(brightnessB);
delay(5);
}
///////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/f629888f2fedea9442ba74dc8761fcb3.png)

Sluit alles aan volgens het bovenstaande schema en laad de code op het bord, dan zie je dat de ene beker oplicht terwijl de andere uit is. Wanneer je de twee bekers naar dezelfde kant kantelt, wordt de ene beker geleidelijk helderder en de andere geleidelijk gedoofd.

![Voorbeeldresultaat illustratie](../media/cfc57515b967d19fcda65ea50bda76f1.png)

---

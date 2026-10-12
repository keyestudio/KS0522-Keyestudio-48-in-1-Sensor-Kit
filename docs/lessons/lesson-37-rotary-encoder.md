# Les 37: Rotary-encoder

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 37: Rotary-encoder illustratie](../media/df622003846058dd3cf442518f655af2.png)

## Introductie

De rotary-encoder kan het aantal uitgezonden pulsen tellen tijdens het draaien in zowel de positieve als de omgekeerde richting.

Deze roterende telling is onbeperkt, anders dan bij een potentiometer. Hij kan worden teruggezet naar de begintoestand om vanaf 0 te tellen.

## Specificaties

- Voedingsspanning: 5V

- Interface: Digitaal

- Afmetingen: 30\*20mm

- Gewicht: 7g

## Aansluitschema

![Aansluitschema illustratie](../media/1de37f27caa224141230be6bdc95d29b.jpeg)

Zoals te zien is in het schema verbinden we de rotary-encodermodule en twee LED-modules met het breadboard en het V4.0-bord.

Gebruik de rotary-encodermodule om twee LED-modules in- en uit te schakelen.

## Voorbeeldcode

```c
///////////////////////////////////////////////////////////////
const int interruptA = 0;
const int interruptB = 1;
int CLK = 2;     // PIN2
int DAT = 3;     // PIN3
int BUTTON = 4;  // PIN4
int LED1 = 5;    // PIN5
int LED2 = 6;    // PIN6
int COUNT = 0;

void setup()
 {
  attachInterrupt(interruptA, RoteStateChanged, FALLING);
 // attachInterrupt(interruptB, buttonState, FALLING);
  pinMode(CLK, INPUT);
  digitalWrite(2, HIGH);  // Pull High Resistance
  pinMode(DAT, INPUT);
  digitalWrite(3, HIGH);  // Pull High Resistance

pinMode(BUTTON, INPUT);
  digitalWrite(4, HIGH);  // Pull High Resistance
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
   Serial.begin(9600);
 }

void loop()
{
  if  (!(digitalRead(BUTTON)))
    {
     COUNT = 0;
     Serial.println("STOP COUNT = 0");
     digitalWrite(LED1, LOW);
     digitalWrite(LED2, LOW);
     delay (2000);
    }
     Serial.println(COUNT);
}

//-------------------------------------------
void RoteStateChanged() //When CLK  FALLING READ DAT
{
 if  (digitalRead(DAT)) // When DAT = HIGH IS FORWARD
   {
    COUNT++;
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(20);
   }
 else                   // When DAT = LOW IS BackRote
   {
    COUNT--;
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
    delay(20);
   }
}
///////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Als je de bedrading correct aansluit en bovenstaande code uploadt, kun je aan de encoder draaien om willekeurig de twee LED-modules in- en uit te schakelen. Wanneer je aan de encoder draait, gaat één LED-module eerst aan terwijl de andere uit is.

Als je blijft draaien aan de encoder, gaat de ene LED-module uit terwijl de andere aan gaat, en dit herhaalt zich voortdurend.

![Voorbeeldresultaat illustratie](../media/4c1455602dc8ab6d61f5ab2e2d5dd67c.png)

---

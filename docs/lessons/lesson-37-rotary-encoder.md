# Lektion 37: Drehgeber

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 37: Drehgeber Abbildung](../media/df622003846058dd3cf442518f655af2.png)

## Einführung

Der Drehgeber kann die während der Rotation in Vorwärts- und Rückwärtsrichtung ausgegebenen Pulssignale zählen.

Diese Zählung ist unbegrenzt, im Gegensatz zum Potentiometer. Sie kann auf den Anfangszustand zurückgesetzt werden, um wieder bei 0 zu zählen.

## Spezifikation

- Stromversorgung: 5V

- Schnittstelle: Digital

- Größe: 30\*20mm

- Gewicht: 7g

## Anschlussdiagramm

![Anschlussdiagramm Abbildung](../media/1de37f27caa224141230be6bdc95d29b.jpeg)

Wie im Diagramm zu sehen, verbinden wir das Drehgeber-Modul und zwei LED-Module mit dem Steckbrett und dem V4.0-Board.

Verwende das Drehgeber-Modul, um zwei LED-Module ein- und auszuschalten.

## Beispielcode

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

## Beispielergebnis

Wenn die Verkabelung korrekt ist und der obenstehende Code hochgeladen wurde, kannst du durch Drehen des Encoders die beiden LED-Module abwechselnd ein- und ausschalten. Beim Drehen wird zunächst ein LED-Modul eingeschaltet, während das andere aus ist.

Wenn du weiter drehst, wird das eine LED-Modul ausgeschaltet, während das andere eingeschaltet wird — und das wiederholt sich.

![Beispielergebnis Abbildung](../media/4c1455602dc8ab6d61f5ab2e2d5dd67c.png)

---

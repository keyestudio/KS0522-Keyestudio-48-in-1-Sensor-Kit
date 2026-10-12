# Leçon 37 : Encodeur rotatif

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Projet 37 : illustration de l'encodeur rotatif](../media/df622003846058dd3cf442518f655af2.png)

## Introduction

L'encodeur rotatif peut compter le nombre d'impulsions émises pendant la rotation dans le sens positif et inverse.

Ce comptage rotatif est illimité, contrairement au comptage potentiométrique. Il peut être remis à l'état initial pour compter à partir de 0.

## Spécifications

- Alimentation : 5V

- Interface : Numérique

- Taille : 30\*20mm

- Poids : 7g

## Schéma de connexion

![Illustration du schéma de connexion](../media/1de37f27caa224141230be6bdc95d29b.jpeg)

Comme on le voit sur le schéma, nous connectons le module d'encodeur rotatif et deux modules LED à la breadboard et à la carte V4.0.

Utilisez le module d'encodeur rotatif pour contrôler l'allumage et l'extinction de deux modules LED.

## Code d'exemple

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

## Exemple de résultat

Une fois le câblage effectué et le code ci‑dessus téléversé, vous pouvez faire tourner l'encodeur pour contrôler de manière alternée l'allumage et l'extinction des deux modules LED. Lorsque vous faites tourner l'encodeur, un module LED s'allume d'abord tandis que l'autre est éteint.

Si vous continuez à faire tourner l'encodeur, un module LED s'éteint pendant que l'autre s'allume, de façon répétée.

![Illustration du résultat](../media/4c1455602dc8ab6d61f5ab2e2d5dd67c.png)

---

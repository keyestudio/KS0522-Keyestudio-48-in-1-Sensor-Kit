# Leçon 14 : Interrupteur d'inclinaison numérique

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte ATmega328P compatible Arduino Uno

![Illustration du projet 14 : Interrupteur d'inclinaison numérique](../media/45a40bdcc098c1c4e0efb8246447173c.png)

## Description

Le capteur d'inclinaison est un interrupteur d'inclinaison numérique. Il peut être utilisé comme un simple interrupteur d'inclinaison.

Branchez-le simplement sur notre IO/Sensor shield, ce qui facilite le branchement des fils. Avec un shield capteur dédié et une carte Arduino, vous pouvez réaliser de nombreux projets intéressants et interactifs.

## Spécifications

- Tension d'alimentation : 3,3 V à 5 V

- Interface : Numérique

- Dimensions : 30*20 mm

- Poids : 3 g

## Schéma de connexion

Connectez la broche S du module au Digital 3 de la carte V4.0, connectez la broche négative au port GND, la broche positive au port 5V.

![Illustration du schéma de connexion](../media/b909cdd6f697779371498723dc1407ab.jpeg)

## Exemple de code

Copiez et collez le code ci‑dessous dans le logiciel Arduino.

```c
int Led=13;//define LED interface
int Shock=3;//define knock sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED to be output interface
pinMode(Shock,INPUT);//define knock sensor to be output interface
}
void loop()
{
val=digitalRead(Shock);//read the value of interface3 and evaluate it to val
if(val==HIGH)//when the knock sensor detect a signal, LED will be flashing
{
digitalWrite(Led,LOW);
}
else
{
digitalWrite(Led,HIGH);
}
}
```

## Exemple de résultat

Une fois le câblage effectué et l'alimentation branchée, téléversez correctement le code sur la carte V4.0.

![Illustration du résultat](../media/d6a0aa9af1e43265114eec8570ac0f3c.png)

Inclinez ensuite le capteur : vous verrez la LED du capteur s'allumer, comme montré ci‑dessous.

![Illustration du résultat](../media/6c4a144c26675a100bffa806c532736c.png)

---

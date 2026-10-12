# Leçon 17 : Interrupteur Reed

> **Kit :** Kit de capteurs Keyestudio 48-en-1  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Projet 17 : illustration de l'interrupteur Reed](../media/e580999515f6522eb603ea723bf62173.png)

## Description

L'interrupteur reed est un commutateur spécial et un composant principal des relais reed et des capteurs de proximité.

Un interrupteur reed est généralement constitué de deux matériaux magnétiques doux et de contacts métalliques (lames) qui se séparent lorsqu'il n'y a pas de champ magnétique.

De plus, certains interrupteurs reed sont équipés d'une autre lame jouant le rôle d'un troisième contact normalement fermé. Ces contacts sont encapsulés dans un tube en verre rempli de gaz inertes (comme l'azote ou l'hélium) ou dans un tube en verre sous vide.

Les lames encapsulées dans le tube en verre sont placées en parallèle avec les extrémités se chevauchant. Un certain espace ou contact mutuel est prévu afin de constituer les contacts normalement ouverts ou normalement fermés de l'interrupteur.

L'interrupteur reed peut être utilisé pour le comptage, la détection de fin de course ou d'autres usages.

Par exemple, un compteur de vélo peut être constitué en collant un aimant sur le pneu et en fixant l'interrupteur reed à côté.

Vous pouvez également monter l'interrupteur reed sur une porte à des fins d'alarme ou comme interrupteur.

L'interrupteur reed est largement utilisé dans les appareils ménagers, l'automobile, les communications, l'industrie, la santé et la sécurité.

De plus, il peut être appliqué à d'autres capteurs et dispositifs électriques tels que détecteur de liquide, aimant de porte, relais reed, capteur de niveau d'huile et capteur de proximité (capteur magnétique). Il peut être utilisé dans des environnements à haut risque.

## Spécification

1. Tension de fonctionnement : CC 3.3V-5V

2. Courant de fonctionnement : ≥20mA

3. Température de fonctionnement : －10℃ à ＋50℃

4. Distance de détection : ≤10mm

5. Interface E/S : 3 broches (-/+/S)

6. Taille : 30\*20mm

7. Poids : 3g

## Schéma de connexion

Connectez la broche S du module à Digital 3 de la carte V4.0, connectez la broche négative au port GND, la broche positive au port 5V.

![Schéma de connexion illustration](../media/ad39b511b42657baed492704a9c84b13.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int buttonpin=3; //define magnetic ring sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED as output interface
pinMode(buttonpin,INPUT);//define magnetic ring sensor as output interface
 }
void loop()
{

val=digitalRead(buttonpin);// read and assign the value of digital interface 3 to val

if(val==HIGH)//When a signal is detected by magnetic ring sensor, LED will flash
{
digitalWrite(Led,HIGH);
}
else
{
digitalWrite(Led,LOW);
}
}
////////////////////////////////////////////////////////////////////
```

## Résultat attendu

Une fois le câblage effectué et l'alimentation mise, téléversez correctement le code sur la carte. Vous verrez la LED D13 de la carte V4.0 allumée.

![Illustration du résultat](../media/a2f983d5a5b324f55e3c0994458d4cbc.png)

Ensuite, nous approchons quelques aimants en bille du capteur. Lorsque le capteur détecte le champ magnétique, la LED du capteur s'allume tandis que la LED D13 s'éteint.

![Illustration du résultat](../media/ecbec914abc799076513f5c61149b004.png)

---

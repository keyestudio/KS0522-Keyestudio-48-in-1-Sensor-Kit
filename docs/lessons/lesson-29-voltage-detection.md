# Leçon 29 : Détection de tension

> **Kit :** Kit de capteurs Keyestudio 48-en-1  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P board

![Projet 29 : Illustration de la détection de tension](../media/41967398a781944fd64ebd49a9c746fa.jpeg)

## Description

Les produits électroniques étant variés, la tension d'alimentation l'est aussi. Il est donc nécessaire de la détecter à l'aide d'un module ou d'un contrôleur de détection de tension adapté.

La tension d'entrée maximale de l'interface analogique du contrôleur est de 5 V, ce qui signifie que les tensions supérieures à 5 V ne pourront pas être détectées directement.

Cependant, ce module de détection de tension permet de mesurer des tensions supérieures à 5 V.

Il est basé sur un diviseur résistif 5:1. Avec une référence analogique de 5 V, la tension d'entrée ne doit pas dépasser 25 V. Avec une référence analogique de 3,3 V, la tension d'entrée ne doit pas dépasser 16,5 V.

Le convertisseur analogique-numérique AVR est en 10 bits, donc la résolution analogique est de 0,00489 V (5 V / 1023). Avec le diviseur 5:1, l'incrément minimal mesurable en entrée est d'approximativement 0,02445 V.

Lorsqu'on connecte ce capteur à la carte d'extension à l'aide d'un câble 3 broches, il permet non seulement de détecter facilement l'amplitude de la tension d'alimentation et de surveiller l'état de charge d'une batterie pour des œuvres médiatiques interactives ou des robots, mais il peut aussi être combiné avec un module LCD IIC LCD1602 pour afficher la tension ou réaliser un moniteur de tension.

## Spécifications

- Tension de fonctionnement : 0V-25V CC

- Type de signal : signal analogique

## Schéma de connexion

Tout d'abord, préparez les pièces suivantes avant la connexion :

- Carte V4.0\*1

- Capteur de tension\*1

- Câble USB\*1

- Fils de liaison\*3

Connectez la broche S du module à l'entrée analogique A0 de la carte V4.0, connectez la broche négative à la borne GND, et la broche NC à la borne 5V.

![Schéma de connexion - illustration](../media/b8754c45901ff42ba9caadce5db01a3a.jpeg)

## Code d'exemple

```c
////////////////////////////////////////////////////////////////////
int analogpin=0;     // Define analogpin as analog port 0
int val,val5;       //Define variables val,val5
int val2=0;      //Define variables val2
int val3=0;     //Define variables val3
int val4=0;    //Define variables val4

void setup()
{
    Serial.begin(9600);     //Set baud rate of 9600
}
void loop()
{
    int val,val5;
    float val1;
    val=analogRead(analogpin);     //Read the value of the analog port and assign it to the variable val
    val1=val/3.9;
    val5=(int)val1;
    val3=val5/100;
    val2=(val5%100)/10;
    val4=val5%10;
    Serial.print("$CLEAR\r\n");      //clear the screen
    Serial.print("$GO 1 1\r\n");
    Serial.print("$PRINT Voltage:\r\n");
    Serial.print("$GO 1 9\r\n");
    Serial.print("$PRINT ");
Serial.print(val3);        //The serial port prints the value of the variable val3
Serial.print(val2);      //The serial port prints the value of the variable val2
    Serial.print(".");               //The serial port prints out a point"."
    Serial.print(val4);         //The serial port prints the value of the variable val4
    Serial.println("V");          //The serial port prints out capital “ V”
    delay(100);      //delay 0.1 second
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

![Illustration du résultat exemple](../media/ac8825bb333757bad26785e58651beb7.png)

Une fois le câblage réalisé comme ci-dessus, compilez et téléversez le code, alimentez le circuit, puis ouvrez le moniteur série ; il affichera la valeur de tension détectée comme montré ci-dessous.

![Illustration du résultat exemple](../media/af699a83a891ea99d193d5b53bd27fa1.jpeg)

---

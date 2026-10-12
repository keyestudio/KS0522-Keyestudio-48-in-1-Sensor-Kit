# Leçon 23 : Niveau d'eau

> **Kit :** Kit de capteurs Keyestudio 48 en 1  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno (ATmega328P)

![Projet 23 : Illustration du niveau d'eau](../media/23f40997b8634be91aed7311eca2dfbb.jpeg)

## Description

Le capteur d'eau Keyestudio est facile à utiliser, portable et économique, conçu pour identifier et détecter le niveau d'eau et les gouttes d'eau.

Ce petit capteur peut mesurer le volume d'une goutte d'eau ou la quantité d'eau grâce à une série de pistes constituées de fils parallèles exposés.

## Caractéristiques

- conversion fluide entre quantité d'eau et valeur analogique ;

- grande flexibilité, sortie d'une valeur analogique basique ;

- faible consommation d'énergie et haute sensibilité ;

- connexion directe à un microprocesseur ou à d'autres circuits logiques, compatible avec une grande variété de cartes de développement et de contrôleurs tels que Arduino, microcontrôleur STC, microcontrôleur AVR, et plus.

## Spécifications

- Tension de fonctionnement : DC5V

- Courant de fonctionnement : ﹤20mA

- Type de capteur : Analogique

- Zone de détection : 40mm x16mm

- Processus de fabrication : FR4 double-face étamé

- Conception de la forme : Encoches semi-lunaires antidérapantes

- Température de fonctionnement : 10℃-30℃

- Humidité de fonctionnement : 10%-90% sans condensation

- Poids : 3g

- Dimensions : 65mm x 20mm x 8mm

## Schéma de connexion

Connectez la broche S du module à Analog A0 de la carte V4.0, connectez la broche négative à la borne GND, la broche positive à la borne 5V.

![Schéma de connexion illustration](../media/92810e41aea313a15735eecb3a168e2f.jpeg)

## Code d'exemple

Copiez et collez le code ci-dessous dans l'environnement Arduino.

```c
////////////////////////////////////////////////////////////////////
    int analogPin = 0; //connect water sensor to analog interface 0
int led = 13; //LED to digital interface 13
int val = 0; //define the initial value of variable ‘val’ as 0
int data = 0; //define the initial value of variable ‘data’ as 0
void setup()
{
pinMode(led, OUTPUT); //define led as output pin
Serial.begin(9600); //set baud rate at 9600
}
void loop()
{
val = analogRead(analogPin); //read and assign analog value to variable ’val’
if(val>700){ //decide whether variable ‘val’ is over 700
digitalWrite(led,HIGH); //turn on LED when variable ‘val’ is over 700
}
else{
digitalWrite(led,LOW); //turn off LED when variable ‘val’ is under 700
}
data = val; //variable ’val’ assigns value to variable ‘data’
Serial.println(data); //print variable ‘data’ by Serial.print
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

![Illustration du résultat exemple](../media/ca727c75f4d4e454c95258d77afdf10e.png)

Après avoir réalisé les étapes ci‑dessus, faisons un test avec un niveau d'eau faible et voyons ce qui se passe ?

Téléversez correctement le code sur la carte V4.0, puis ouvrez le moniteur série et réglez la vitesse à 9600 bauds.

Lorsque vous placez le capteur à différents niveaux dans l'eau, vous verrez la valeur changer en conséquence.

![Illustration du résultat exemple](../media/8070cf2260fef39e5ec5e18b7a1849cf.jpeg)

De plus, vous pouvez définir une valeur d'alarme et connecter un avertisseur sonore pour déclencher une alarme.

La DEL ne s'allumera pas tant que le niveau d'eau n'aura pas atteint la valeur d'alarme. Si le niveau d'eau atteint la valeur d'alarme, la DEL s'allumera et l'avertisseur sonore sonnera pour déclencher l'alarme.

---

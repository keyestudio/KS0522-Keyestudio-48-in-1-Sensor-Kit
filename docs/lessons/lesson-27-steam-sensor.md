# Leçon 27: Capteur d'humidité

> **Kit:** Kit de capteurs Keyestudio 48-en-1  
> **Carte:** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 27 : Capteur d'humidité](../media/d19ac9430f793cdbedde891ee92671e7.jpeg)

## Description

Le capteur d'humidité est un capteur analogique et peut servir de simple détecteur de pluie ou d'interrupteur de niveau de liquide. Lorsque l'humidité à la surface de ce capteur augmente, la tension de sortie augmentera.

Attention : les parties de connexion ne sont pas étanches, ne les plongez donc pas dans l'eau.

## Paramètres

- Tension de fonctionnement: 3.3V ou 5V

- Courant de fonctionnement: \<20mA

- Plage de température de fonctionnement: －10℃～＋70℃

- Type d'interface: Sortie de signal analogique

## Définition des broches

- Broche S : pour la sortie du signal

- Broche positive (+) : pour l'alimentation (VCC)

- Broche négative (-) : pour la masse (GND)

## Schéma de connexion

Préparez d'abord les éléments suivants avant le branchement :

- Carte V4.0*1

- Capteur d'humidité*1

- Câble USB*1

- Fils de connexion*3

Connectez la broche S du module à l'entrée analogique A0 de la carte V4.0, connectez la broche négative au port GND et la broche positive au port 5V.

![Illustration du schéma de connexion](../media/8fa51466dbc9650dcaa740bce4dd654e.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans l'environnement Arduino.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //open serial port, and set baud rate at 9600bps
}
void loop()
{
int val;
val=analogRead(0); //plug vapor sensor into analog port 0
Serial.print("Moisture is ");
Serial.println(val,DEC); //read analog value through serial port printed
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Résultat exemple

![Exemple de résultat](../media/c4633c5911c042224d187645db4d0588.png)

Lors de la détection de différents degrés d'humidité, le capteur renverra différentes valeurs de courant. Comme montré sur l'image suivante.

Dans la limite des conditions, vous pouvez déposer une goutte d'eau sur le capteur ; la valeur d'humidité changera dans le moniteur série du logiciel Arduino.

![Exemple de résultat](../media/80e9b3e19db4bec337f3254545a58e9e.jpeg)

---

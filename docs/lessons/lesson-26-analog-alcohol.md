# Leçon 26 : Alcool analogique

> **Kit :** Kit de capteurs Keyestudio 48-en-1  
> **Carte :** Keyestudio V4.0 / compatible Arduino Uno ATmega328P

![Illustration du projet 26 : Alcool analogique](../media/288162cf02f2968eda57b437292a42dd.png)

## Description

Ce capteur MQ-3 analogique est adapté à la détection d'alcool. Il peut être utilisé dans un projet d'éthylotest.

Il présente une bonne sélectivité car il est plus sensible à l'alcool et moins sensible au benzène.

La sensibilité peut être ajustée en tournant le potentiomètre sur le module.

## Spécification

- Alimentation : 5V

- Type d'interface : Analogique

- Circuit de pilotage simple

- Stable et longue durée de vie

- Réponse rapide et haute sensibilité

## Schéma de connexion

Connectez la broche A0 du module à l'entrée analogique A0 de la carte V4.0, reliez la broche GND au port GND, la broche VCC au port 5V.

![Schéma de connexion (illustration)](../media/61632f44731176aaf95d313f2843c9de.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read Gas value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

![Illustration du résultat](../media/a21d5b8c686e46a59128ab48b96d177c.png)

Après avoir effectué les branchements et alimenté le montage, téléversez correctement le code, puis ouvrez le moniteur série et réglez le débit en bauds sur 9600 ; vous verrez la valeur analogique. Lors de la détection de vapeurs d'alcool, la valeur changera.

![Illustration du résultat](../media/97565d8ba7691b30a7aa96efc6c7728b.jpeg)

---

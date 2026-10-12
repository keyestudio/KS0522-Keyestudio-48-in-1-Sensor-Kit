# Leçon 20 : Rotation analogique

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration Projet 20 : Rotation analogique](../media/7a7fffa705c4a50e87455e6d378eb837.png)

## Description

Ce capteur de rotation analogique est compatible Arduino. Il est basé sur un potentiomètre. Sa tension peut être subdivisée en 1024 niveaux, et il se connecte facilement à l'Arduino avec notre shield capteur.

Combiné avec d'autres capteurs, vous pouvez l'utiliser pour réaliser des projets intéressants en lisant la valeur analogique depuis le port IO.

## Spécification

- Tension d'alimentation: 3.3V à 5V

- Interface : Analogique

- Taille: 30*20mm

- Poids: 8g

## Schéma de connexion

Connectez la broche S du module à l'A0 analogique de la carte V4.0, connectez la broche négative au port GND, la broche positive au port 5V.

![Schéma de connexion illustration](../media/f8a0c2cca0f3d0935ce0c9a0c4dbe59e.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read rotation sensor value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

![Illustration Exemple de résultat](../media/bae047449c10c99449c35a14b22d759c.png)

Une fois le câblage effectué et l'alimentation activée, téléversez correctement le code, puis ouvrez le moniteur série et réglez le débit en bauds sur 9600 ; vous verrez alors la valeur analogique. En tournant le bouton du capteur de rotation, la valeur changera entre 0 et 1023. Illustré ci‑dessous.

![Illustration Exemple de résultat](../media/bc7b15c3245b7cfd91b0ef4b0aeb8e7e.jpeg)

---

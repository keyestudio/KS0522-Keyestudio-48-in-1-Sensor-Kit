# Leçon 21 : Photocellule

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 21 : photocellule](../media/8eed60793fd64a7c0b9a9b2a2fc1ef67.png)

## Description

La photocellule (cellule photoélectrique) est couramment rencontrée dans la vie quotidienne et est principalement utilisée dans les interrupteurs intelligents, ainsi que dans la conception électronique courante. Pour faciliter et améliorer son utilisation, nous fournissons les modules correspondants.

La photocellule est un semi‑conducteur. Elle présente une grande sensibilité, une réponse rapide, des caractéristiques spectrales et une cohérence de la valeur R, assurant une grande stabilité et fiabilité dans des environnements extrêmes tels que des températures élevées et une forte humidité.

Elle est largement utilisée dans les domaines de commutation de contrôle automatique comme les appareils photo, les lampes solaires de jardin, les lampes pour pelouse, les détecteurs de monnaie, les horloges à quartz, les mugs musicaux, les boîtes cadeaux, les mini veilleuses, les interrupteurs contrôlés par le son et la lumière, etc.

## Spécification

- Type d'interface : analogique

- Tension de fonctionnement : 5V

- Taille : 30*20mm

- Poids : 3g

## Schéma de connexion

Connectez la broche S du module à l'Analog A0 de la carte V4.0, connectez la broche négative au port GND, la broche positive au port 5V.

![Illustration du schéma de connexion](../media/28a1990cd088d6f0301f02d217cef301.jpeg)

## Exemple de code

Copiez et collez le code ci‑dessous dans le logiciel Arduino.

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

![Illustration du résultat exemple](../media/78268e9cb1dbc127e7ae3299d3a35a45.png)

Une fois le câblage effectué et l'alimentation branchée, téléversez correctement le code, puis ouvrez le moniteur série. Si vous couvrez la photocellule du capteur avec votre main, vous verrez la valeur analogique diminuer.

![Illustration du résultat exemple](../media/85621deb4c66d6e53697cd0ef90cb6e2.jpeg)

---

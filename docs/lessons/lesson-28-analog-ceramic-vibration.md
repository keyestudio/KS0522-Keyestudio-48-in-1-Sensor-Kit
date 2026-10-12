# Leçon 28 : Capteur de vibration céramique analogique

> **Kit :** Kit de capteurs Keyestudio 48-en-1  
> **Carte :** Keyestudio V4.0 / Carte compatible Arduino Uno ATmega328P

![Module capteur de vibration céramique analogique](../media/2cf5c2793157816a2346a730ad064955.jpeg)

## Description

Ce capteur de vibration est basé sur une puce céramique piézoélectrique analogique. Il exploite le processus de conversion inverse par lequel la vibration de la céramique piézoélectrique génère des signaux électriques. Lorsque la puce céramique piézoélectrique vibre, la broche de signal du capteur génère des signaux électriques.

Le capteur peut être utilisé avec un shield de capteurs Arduino dédié, et le port analogique d'Arduino peut détecter de faibles signaux de vibration, ce qui permet de réaliser des applications interactives liées aux vibrations, comme une batterie électronique.

Connectez le capteur de vibration au port analogique A0 de l'Arduino UNO. En faisant vibrer le capteur avec des intensités différentes, vous verrez différentes valeurs de sortie affichées dans le moniteur série de l'IDE Arduino.

## Spécifications

- Tension d'alimentation : 3,3V à 5V

- Courant de fonctionnement：\<1mA

- Plage de température de fonctionnement：－10℃～＋70℃

- Signal de sortie：signal analogique

## Schéma de connexion

Avant de connecter, préparez les éléments suivants :

- Carte V4.0\*1

- capteur de vibration\*1

- Câble USB\*1

- fils Dupont\*3

Connectez la broche S du module à l'analogique A0 de la carte V4.0, connectez la broche négative au port GND, et la broche NC au port 5V.

![Illustration du schéma de connexion](../media/92fce2d45b05876a7928070bd2b137da.jpeg)

## Exemple de code

Copiez et collez le code ci‑dessous dans l'IDE Arduino.

```c
///////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //Open the serial to set the baud rate as 9600bps
}
void loop()
{
int val;
val=analogRead(0); //Connect the sensor to analog interface A0
Serial.print("Vibration is ");
Serial.println(val,DEC);//Print the analog value read on serial port
delay(100);
}
///////////////////////////////////////////////////////////
```

## Résultat de l'exemple

![Illustration du résultat](../media/e21152ca9f30274fcc658091f76f7044.png)

Câblez comme sur le schéma ci‑dessus et téléversez correctement le code, puis ouvrez le moniteur série et réglez la vitesse de transmission (baud) sur 9600.

Lorsque vous faites vibrer la puce céramique, vous verrez les données changer comme montré sur la figure ci‑dessous.

![Illustration du résultat](../media/4be72e831696d59b36082aa45d77a04d.jpeg)

---

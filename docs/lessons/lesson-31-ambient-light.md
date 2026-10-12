# Leçon 31 : Lumière ambiante

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 31 : lumière ambiante](../media/3eda1bbb84995dc2195a0406f1b0c196.jpeg)

## Description

À un moment donné, vous voudrez mesurer la luminosité ambiante avec une meilleure précision que votre fidèle photorésistance sans ajouter de complexité à votre projet. Quand ce jour arrivera, procurez-vous un capteur de lumière ambiante TEMT6000.

Le TEMT6000 est censé être adapté à la sensibilité de l'œil humain, mais il s'est avéré moins performant en faible luminosité. Il réagit néanmoins très bien à de très petits changements sur une large plage d'intensités lumineuses. Étant donné qu'il est conçu pour imiter l'œil humain, il ne réagit pas bien aux lumières IR ou UV, donc prenez-en compte ce point lorsque vous l'utilisez dans votre projet.

## Spécifications

- Tension d'alimentation : +5VDC 50mA

- Taille: 36.5\*16mm

- Poids: 4g

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant le raccordement.

- Carte V4.0\*1

- Capteur de lumière ambiante TEMT6000\*1

- Câble USB\*1

- Fils de connexion\*3

C'est une pièce incroyablement simple : connectez simplement l'alimentation et la masse, et la broche de signal au port d'entrée analogique. Une fois connecté, le capteur fournira une tension analogique qui augmente quand il fait plus clair. Vous pouvez l'alimenter en 3.3V si vous le souhaitez, la valeur de sortie sera simplement beaucoup plus faible.

![Illustration du schéma de connexion](../media/dae046a9efbeea661b9b6a2ab632fcbc.jpeg)

## Exemple de code

On ne peut pas faire plus simple que ceci – cela envoie simplement la valeur relevée par le capteur vers le moniteur série : 0–1023, 1023 étant très lumineux et 0 très sombre.

```c
///////////////////////////////////////////////////////////////
int temt6000Pin = 0;
void setup() {
 Serial.begin(9600);
}
void loop() {
 int value = analogRead(temt6000Pin);
 Serial.println(value);
 delay(100); //only here to slow down the output so it is easier to read
}
///////////////////////////////////////////////////////////////
```

## Exemple de résultat

Après avoir bien câblé et téléversé le code ci‑dessus, ouvrez le moniteur série du logiciel Arduino.

![Illustration du résultat](../media/ea9ab82076983cc965fe016297b6ad76.png)

Couvrez ensuite le capteur avec votre main ou un papier ; la lumière devient plus faible et vous verrez finalement la valeur affichée sur le moniteur diminuer.

![Illustration du résultat](../media/846828c9af69a9823ca7218157cc181e.jpeg)

---

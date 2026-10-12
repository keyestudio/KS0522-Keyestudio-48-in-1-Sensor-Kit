# Leçon 36 : Joystick

> **Kit :** Kit de capteurs Keyestudio 48-en-1  
> **Carte :** Carte Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 36 : joystick](../media/310a620a28ae6ebeeee7294bdc7a2bb0.png)

## Description

Beaucoup de projets robotiques nécessitent un joystick. Ce module offre une solution abordable. En le connectant simplement à deux entrées analogiques, le robot répond à vos commandes en X et Y. Il possède également un interrupteur relié à une broche numérique.

## Spécification

- Tension d'alimentation : 3.3V à 5V

- Interface : Analogique x2, Numérique x1

- Taille : 40*28mm

- Poids : 12g

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant la connexion.

- Carte V4.0\*1

- Module joystick\*1

- Câble USB\*1

- Fils de connexion\*5

Connectez la broche Y du module à Analog A1 de la carte V4.0, connectez la broche X à Analog A0, la broche B à Digital 3 ; connectez la broche négative au port GND, la broche positive au port 5V.

![Illustration du schéma de connexion](../media/3c0d2f553f6e76565171dae78a440568.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
///////////////////////////////////////////////////////////////
int JoyStick_X = 0; //x
int JoyStick_Y = 1; //y
int JoyStick_Z = 3; //key
  void setup()
{
  pinMode(JoyStick_Z, INPUT);
  Serial.begin(9600); // 9600 bps
}
void loop()
{
  int x,y,z;
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=digitalRead(JoyStick_Z);
  Serial.print(x ,DEC);
  Serial.print(",");
  Serial.print(y ,DEC);
  Serial.print(",");
  Serial.println(z ,DEC);
  delay(100);
}
///////////////////////////////////////////////////////////////
```

## Exemple de résultat

![Illustration du résultat](../media/5e6809517dd961c3740b04c7774c3e75.png)

Après avoir correctement câblé et téléversé le code, ouvrez le Moniteur Série dans le logiciel Arduino et réglez le débit en bauds sur 9600 ; vous verrez les valeurs affichées ci-dessous. Si vous poussez le joystick vers le bas / le haut / la gauche / la droite, les données changeront.

![Illustration du résultat](../media/6b3a1bd089cafce0f1db02f405ab5035.jpeg)

---

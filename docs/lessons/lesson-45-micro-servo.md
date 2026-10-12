# Leçon 45 : Micro Servo

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 45 : Micro Servo](../media/12c59bd3ab0733beb6ff7802305d4384.jpeg)

## Introduction

Un servomoteur est un actionneur rotatif à contrôle de position. Il se compose principalement du boîtier, d'une carte électronique, d'un moteur coreless, d'engrenages et d'un capteur de position.

Avec votre servo, vous trouverez plusieurs supports blancs qui se fixent sur l'axe du servo. Vous pouvez fixer celui que vous souhaitez pour le montage. Il sert d'aide visuelle, facilitant l'observation de la rotation du servo.

Le servo possède trois fils, distingués par les couleurs marron, rouge et orange (selon la marque, les couleurs peuvent varier). Le fil marron est la masse (GND), le rouge est l'alimentation 5V, l'orange est la borne de signal (signal PWM).

![Illustration d'introduction](../media/e7eb9914318b92eff98a4a84a8d1a557.png)

L'angle de rotation du servo est contrôlé en modulant le cycle de service du signal PWM (modulation de largeur d'impulsion). La période standard du signal PWM est de 20 ms (50 Hz), et la largeur d'impulsion varie entre 1 ms et 2 ms. La largeur d'impulsion correspond à l'angle de rotation (0°～90°) du servo.

![Illustration d'introduction](../media/723671941df8a57cf9246c9916e7b279.png)

Passons maintenant à l'apprentissage du contrôle d'un servomoteur.

Pour cette expérience, vous n'avez besoin que d'un servomoteur et de quelques fils de connexion.

## Schéma de connexion

Connexion pour V4.0 :

![Illustration du schéma de connexion](../media/da1e3590f86a5a8ed27b333742ae49c9.jpeg)

Connexion pour 2560 R3:

![Illustration du schéma de connexion](../media/1c8bd09408be60254883b910ef4fc9bf.png)

Connectez le moteur à la broche numérique 9.

Compilez un programme pour contrôler la rotation du moteur jusqu'à l'angle demandé, et afficher l'angle à l'écran.

## Programme d'exemple

Il y a deux manières de contrôler un servomoteur avec Arduino.

La première consiste à utiliser un port numérique standard d'Arduino pour produire une onde carrée avec différents rapports cycliques pour simuler un signal PWM, et utiliser ce signal pour contrôler la position du moteur.

L'autre manière est d'utiliser directement la fonction Servo d'Arduino pour contrôler le moteur.

Avec cette seconde méthode, le programme sera plus simple mais elle ne peut contrôler que des moteurs à deux fils via la fonction servo ; seules les broches numériques 9 et 10 peuvent être utilisées. La capacité de pilotage d'Arduino est limitée. Donc si vous devez contrôler plus d'un moteur, vous aurez besoin d'une alimentation externe.

## Méthode 1

## Programme d'exemple A

```c
//////////////////////////////////////////////////////////
int servopin=9;// select digital pin 9 for servomotor signal line
int myangle;// initialize angle variable
int pulsewidth;// initialize width variable
int val;
void servopulse(int servopin,int myangle)// define a servo pulse function
{
pulsewidth=(myangle*11)+500;// convert angle to 500-2480 pulse width
digitalWrite(servopin,HIGH);// set the level of servo pin as “high”
delayMicroseconds(pulsewidth);// delay microsecond of pulse width
digitalWrite(servopin,LOW);// set the level of servo pin as “low”
delay(20-pulsewidth/1000);
}
void setup()
{
pinMode(servopin, OUTPUT);
Serial.begin(9600);
Serial.println("servo=o_seral_simple ready" ) ;
}
void loop()// convert number 0 to 9 to corresponding 0-180 degree angle, LED blinks corresponding number of time
{
val=Serial.read();// read serial port value
if(val>='0'&&val<='9')
{
val=val-'0';// convert characteristic quantity to numerical variable
val=val*(180/9);// convert number to angle
Serial.print("moving servo to ");
Serial.print(val,DEC);
Serial.println();
for(int i=0;i<=50;i++) // giving the servo time to rotate to commanded position
{
servopulse(servopin,val);// use the pulse function
}
}
}
//////////////////////////////////////////////////////////
```

## Méthode 2

Voyons d'abord la fonction servo intégrée à Arduino et quelques instructions courantes.

1. **attach (interface)** — sélectionne la broche pour le servo ; seules les broches 9 ou 10 peuvent être utilisées.

2. **write (angle)** — sert à contrôler l'angle de rotation du servo ; on peut définir un angle entre 0° et 180°.

3. **read()** — sert à lire l'angle du servo ; considérez-la comme la lecture de la valeur définie avec write().

4. **attached()** — détermine si le servo est attaché à la broche (si les paramètres sont envoyés à la broche du servo).

5. **detach()** — détache le servo de la broche, et la broche (numérique 9 ou 10) peut être utilisée pour d'autres usages PWM.

**Remarque :** la forme écrite des instructions ci‑dessus est "nom_variable_servo.instruction_spécifique()", p. ex. myservo.attach(9).

Connectez donc le servo à la broche 9.

## Programme d'exemple B

```c
#include <Servo.h>// define a header file. Special attention here, you can call the servo function directly from Arduino's software menu

Servo myservo;// define servo variable name
void setup()
{
myservo.attach(9);// select servo pin(9 or 10)
}
void loop()
{
myservo.write(90);// set rotating angle of the motor
}
```

## Résultat de l'exemple

![Illustration du résultat de l'exemple](../media/f02556e0631fb206c114ced29e643016.png)

Branchez correctement, téléversez le Programme A sur la carte, puis ouvrez le moniteur série du logiciel Arduino, réglez la vitesse à 9600 bauds, et dans la barre supérieure saisissez un nombre et cliquez sur «Envoyer». Vous verrez le servo se positionner à l'angle correspondant, et l'angle en mouvement sera affiché dans le moniteur, comme montré ci‑dessous.

Sous tension, après avoir téléversé correctement le Programme B sur la carte, le premier servo se positionnera à 90 degrés.

![Illustration du résultat de l'exemple](../media/de50d502cb8ed1feb5935d16584cfd63.png)

---

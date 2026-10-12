# Leçon 06 : Buzzer passif

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / compatible Arduino Uno (ATmega328P)

![Illustration du projet 6 : buzzer passif](../media/1bd2e3afebf5a0d3712fe42092b0a1b4.png)

## Description

Nous pouvons utiliser Arduino pour réaliser de nombreuses créations interactives, parmi lesquelles l'affichage audio-visuel est l'une des plus courantes. Le circuit de cette expérience peut produire du son.

Habituellement, l'expérience peut être réalisée avec un buzzer ou un haut-parleur, le buzzer étant plus simple et plus facile à utiliser.

Le buzzer présenté ici est un buzzer passif. Il ne peut pas être actionné par lui-même, mais par des fréquences d'impulsion externes. Différentes fréquences produisent différents sons. Vous pouvez utiliser Arduino pour coder la mélodie d'une chanson, c'est très amusant et simple.

## Spécification

- Tension de fonctionnement : 3.3-5v

- Type d'interface : numérique

- Taille : 30\*20mm

- Poids : 4g

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant la connexion :

- Carte V4.0*1

- Module de buzzer passif*1

- Câble USB*1

- Fils de connexion*3

Connectez la broche S du module au port Digital 3 de la carte V4.0, la broche négative au GND, la broche positive au 5V.

![Illustration du schéma de connexion](../media/e9e7ba383738c3b6be85a1f3c97e5385.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
int buzzer=3;//set digital IO pin of the buzzer
void setup()
{
pinMode(buzzer,OUTPUT);// set digital IO pin pattern, OUTPUT to be output
}
void loop()
{ unsigned char i,j;//define variable
while(1)
{ for(i=0;i<80;i++)// output a frequency sound
{ digitalWrite(buzzer,HIGH);// sound
delay(1);//delay1ms
digitalWrite(buzzer,LOW);//not sound
delay(1);//ms delay
}
for(i=0;i<100;i++)// output a frequency sound
{
digitalWrite(buzzer,HIGH);// sound
digitalWrite(buzzer,LOW);//not sound
delay(2);//2ms delay
}
}
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

Une fois le code téléversé sur la carte, le buzzer émettra un son.

![Illustration du résultat](../media/9b29eccd437694e479a836b7da66d500.png)

---

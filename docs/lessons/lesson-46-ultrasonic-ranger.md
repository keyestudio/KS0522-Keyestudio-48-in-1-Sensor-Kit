# Leçon 46 : Détecteur de distance ultrasonique

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 46 : Détecteur ultrasonique](../media/c170155a5fb03abdc10866e25e3670b2.jpeg)

## Description

Comme les ultrasons ont une forte directivité, une faible consommation d'énergie et une grande portée dans les milieux, ils sont couramment utilisés pour la mesure de distance, tels que les télémètres et les instruments de position.

Le module détecteur ultrasonique peut fournir une distance de détection sans contact de 2 cm à 450 cm, et sa précision de mesure atteint 3 mm, ce qui répond très bien aux exigences normales.

Le module comprend un émetteur et un récepteur ultrasonique ainsi que le circuit de commande correspondant.

## Schéma de fonctionnement

La séquence de mesure du HC-SR04 est montrée ci‑dessous :

![Schéma de fonctionnement](../media/a7b0fc57b2e387962071da618153ad68.jpeg)

1\. Tout d'abord, mettre TRIG à l'état bas, puis le déclencher avec un signal de niveau haut d'au moins 10us ;

2\. Après le déclenchement, le module transmettra automatiquement huit ondes carrées à 40KHZ, et détectera automatiquement s'il y a un signal de retour.

3\. S'il y a un signal de retour, il sortira un niveau haut via ECHO ; la durée du niveau haut correspond en fait au temps entre l'émission et la réception de l'ultrason.
$$
Distance\ mesurée = Durée\ du\ niveau\ haut * 340m/s * 0.5
$$

## Paramètres

- Tension de fonctionnement : 5 V DC

- Courant de fonctionnement : 15mA

- Plage de détection : 2-450cm

- Angle de détection : 15 degrés

- Impulsion de déclenchement d'entrée : 10us Niveau TTL

- Signal d'écho en sortie : signal de niveau TTL (HIGH), proportionnel à la distance.

## Schéma des broches

![Illustration du brochage](../media/c03e563bcd19796b483156724bae174a.png)

## Schéma de connexion

Tout d'abord, vous devez préparer les composants suivants :

- Carte V4.0\*1

- Capteur ultrasonique\*1

- Câble USB\*1

- Fils de raccordement\*4

Ensuite, veuillez vous référer au tableau de connexion suivant :

![Illustration du schéma de connexion](../media/e708c019b57984a07feb241672793982.jpeg)

Remarque : D4, D5 sont les broches numériques 4 et 5.

Vous pouvez vous référer au schéma de connexion ci‑dessous :

![Illustration du schéma de connexion](../media/b5b964743eac977e687c454b64e061fa.jpeg)

Une fois correctement connecté, vous pouvez l'utiliser pour mesurer la distance et afficher la valeur de distance sur le moniteur.

## Code de test

Copiez et collez le code de test ci‑dessous dans le logiciel Arduino

```c
///////////////////////////////////////////////////////////////////////////////
int inputPin=4; // define ultrasonic signal receiver pin ECHO to D4
int outputPin=5; // define ultrasonic signal transmitter pin TRIG to D5
 void setup()
{
Serial.begin(9600);
pinMode(inputPin, INPUT);
pinMode(outputPin, OUTPUT);

}
void loop()
{
digitalWrite(outputPin, LOW); delayMicroseconds(2);
digitalWrite(outputPin, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
delayMicroseconds(10);
digitalWrite(outputPin, LOW);
int distance = pulseIn(inputPin, HIGH); // Read receiver pulse time
distance= distance/58; // Transform pulse time to distance
Serial.println(distance); //Output distance
delay(50);
}
///////////////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

![Exemple de résultat](../media/0dcff2ae88366ce40190b77f25d271d7.png)

Après avoir correctement téléversé le code sur la carte V4.0, ouvrez le moniteur série. En plaçant un objet devant le capteur ultrasonique (proche ou éloigné), il détectera la distance de l'objet. La valeur sera affichée sur le moniteur comme montré ci‑dessous.

![Exemple de résultat](../media/1dbca5dc233994f6923601d942fadba6.png)

![Exemple de résultat](../media/dcd49cc72e7a9f993083af7625d240db.png)

---

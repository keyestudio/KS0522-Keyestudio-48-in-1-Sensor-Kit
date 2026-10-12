# Les 45: Microservo

> **Kit:** Keyestudio 48-in-1 Sensorset  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 45: Microservo illustratie](../media/12c59bd3ab0733beb6ff7802305d4384.jpeg)

## Introductie

Een servomotor is een rotatie-actuator voor positieregeling. Hij bestaat voornamelijk uit behuizing, printplaat, kernloze motor, tandwiel en positieresensor.

Bij uw servomotor worden verschillende witte motorhouders geleverd die op de as van uw servo kunnen worden bevestigd. U kunt elke gewenste houder gebruiken voor het circuit. Deze dienen als visuele hulp, zodat het makkelijker is om de rotatie van de servo te zien.

De servo heeft drie aansluitingen, te onderscheiden door bruine, rode en oranje draad (verschillende merken kunnen andere kleuren gebruiken). De bruine draad is voor GND, de rode voor 5V voeding, en de oranje voor de signaalaansluiting (PWM-signaal).

![Introductie illustratie](../media/e7eb9914318b92eff98a4a84a8d1a557.png)

De rotatiehoek van de servo wordt geregeld door de duty cycle van het PWM (Pulse-Width Modulation) signaal te variëren. De standaardperiode van het PWM-signaal is vast op 20 ms (50 Hz), en de pulsbreedte varieert tussen 1 ms en 2 ms. De pulsbreedte komt overeen met de rotatiehoek (0°～90°) van de servo.

![Introductie illustratie](../media/723671941df8a57cf9246c9916e7b279.png)

Laten we nu leren hoe een servomotor te besturen.

In dit experiment heeft u alleen een servomotor en enkele jumperdraden nodig.

## Aansluitschema

Aansluiting voor V4.0 :

![Aansluitschema illustratie](../media/da1e3590f86a5a8ed27b333742ae49c9.jpeg)

Aansluiting voor 2560 R3:

![Aansluitschema illustratie](../media/1c8bd09408be60254883b910ef4fc9bf.png)

Verbind de motor met digitale pin 9.

Compileer een programma om de motor naar de gevraagde hoek te laten draaien en de hoek op het scherm weer te geven.

## Voorbeeldprogramma

Er zijn twee manieren om een servomotor met Arduino te besturen.

De ene is om een gewone digitale sensorpoort van Arduino te gebruiken om een blokgolf met verschillende duty cycle te produceren om een PWM-signaal te simuleren en dat signaal te gebruiken om de positionering van de motor te regelen.

Een andere manier is om direct de Servo-functie van Arduino te gebruiken om de motor te besturen.

Op die manier wordt het programma eenvoudiger, maar het kan alleen twee-draads motoren voor de servo-functie aansturen; alleen digitale pin 9 en 10 kunnen worden gebruikt. De stuurcapaciteit van de Arduino is beperkt. Dus als u meer dan één motor wilt aansturen, heeft u externe voeding nodig.

## Methode 1

## Voorbeeldprogramma A

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

## Methode 2

Laten we eerst kijken naar de ingebouwde servo-functie van Arduino en enkele veelvoorkomende instructies.

1\. **attach（interface）** —— selecteer de pin voor de servo, er kunnen alleen pin 9 of 10 worden gebruikt.

2\. **write（angle）** —— gebruikt om de draaishoek van de servo te regelen, kan een hoek instellen tussen 0 graden en 180 graden.

3\. **read（）** —— gebruikt om de hoek van de servo te lezen; beschouw het als een functie om de waarde uit de write() functie te lezen.

4\. **attached（）** —— bepaalt of de parameters van de servo naar de servopin zijn gestuurd.

5\. **detach（）** —— koppelt de servo los van de pin, en de pin (digitale pin 9 of 10) kan worden gebruikt als PWM-poort.

**Opmerking:** de schrijfwijze van bovenstaande instructies is "servo variabelenaam.specifieke instructie()", bijv. myservo.attach(9).

Sluit de servo nog steeds aan op pin 9.

## Voorbeeldprogramma B

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

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/f02556e0631fb206c114ced29e643016.png)

Zorg dat de bedrading goed is, upload Voorbeeldprogramma A naar het bord, open vervolgens de seriële monitor van de Arduino-software, stel de baudrate in op 9600, en voer in de bovenste balk een getal in en klik op “Verzenden”; u zult zien dat de servo naar de overeenkomstige hoek draait en dat de bewegingshoek in de monitor wordt weergegeven. Zie hieronder.

Als het bord van stroom is voorzien en Voorbeeldprogramma B correct is geüpload, zal de servo eerst naar een hoek van 90 graden draaien.

![Voorbeeldresultaat illustratie](../media/de50d502cb8ed1feb5935d16584cfd63.png)

---

# Lektion 45: Mikro-Servo

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino-Uno-kompatible ATmega328P-Platine

![Projekt 45: Mikro-Servo Abbildung](../media/12c59bd3ab0733beb6ff7802305d4384.jpeg)

## Einführung

Ein Servomotor ist ein drehbarer Aktuator zur Positionsregelung. Er besteht hauptsächlich aus Gehäuse, Platine, kernlosem Motor, Getriebe und einem Positionssensor.

Zum Lieferumfang Ihres Servomotors gehören verschiedene weiße Motorhalterungen, die an die Welle Ihres Servos angeschlossen werden. Sie können jede gewünschte Halterung anbringen. Sie dient als visuelle Hilfe und macht es einfacher, die Drehung des Servos zu sehen.

Der Servo hat drei Leitungen, die sich durch braune, rote und orangefarbene Drähte unterscheiden (bei anderen Herstellern können die Farben abweichen). Die braune Leitung ist für GND, die rote für die Versorgung 5V und die orange für das Signalkabel (PWM-Signal).

![Einführung Abbildung](../media/e7eb9914318b92eff98a4a84a8d1a557.png)

Der Drehwinkel des Servos wird durch Regelung des Tastverhältnisses des PWM (Pulsweitenmodulation)-Signals gesteuert. Der Standardzyklus des PWM-Signals ist auf 20 ms (50 Hz) festgelegt, und die Pulsbreite liegt zwischen 1 ms und 2 ms. Die Pulsbreite entspricht dem Drehwinkel (0°–90°) des Servos.

![Einführung Abbildung](../media/723671941df8a57cf9246c9916e7b279.png)

Als Nächstes lernen wir, wie man einen Servomotor steuert.

Für dieses Experiment benötigen Sie nur einen Servomotor und einige Jumperkabel.

## Anschlussdiagramm

Anschluss für V4.0 :

![Anschlussdiagramm Abbildung](../media/da1e3590f86a5a8ed27b333742ae49c9.jpeg)

Anschluss für 2560 R3:

![Anschlussdiagramm Abbildung](../media/1c8bd09408be60254883b910ef4fc9bf.png)

Schließen Sie den Motor an digitalen Pin 9 an.

Kompilieren Sie ein Programm, um den Motor auf den angeforderten Winkel zu drehen und den Winkel auf dem Bildschirm anzuzeigen.

## Beispielprogramm

Es gibt zwei Möglichkeiten, einen Servomotor mit Arduino zu steuern.

Die eine besteht darin, einen normalen digitalen Sensoranschluss des Arduino zu verwenden, um ein Rechtecksignal mit unterschiedlichem Tastverhältnis zu erzeugen, das ein PWM-Signal simuliert, und dieses Signal zur Positionssteuerung des Motors zu nutzen.

Die andere Möglichkeit ist, direkt die Servo-Funktion des Arduino zu verwenden, um den Motor zu steuern.

Auf diese Weise wird das Programm einfacher, aber es kann nur Zweileiter-Servomotoren steuern; es können nur die digitalen Pins 9 und 10 verwendet werden. Die Antriebskapazität des Arduino ist begrenzt. Wenn Sie mehr als einen Motor steuern müssen, benötigen Sie daher eine externe Stromversorgung.

## Methode 1

## Beispielprogramm A

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

Sehen wir uns zunächst die eingebaute Servo-Funktion des Arduino und einige gängige Anweisungen an.

1\. **attach（Schnittstelle**）——Wählen Sie den Pin für den Servo; es können nur die Pins 9 oder 10 verwendet werden.

2\. **write（Winkel）**——wird verwendet, um den Drehwinkel des Servos zu steuern; der Winkel kann von 0° bis 180° eingestellt werden.

3\. **read（）**——liest den Winkel des Servos; betrachten Sie es als Funktion, um den in write() gesetzten Wert auszulesen.

4\. **attached（）**——prüft, ob die Parameter des Servos an den Servopin gesendet wurden.

5\. **detach（）**——trennt den Servo vom Pin, und der Pin (digitaler Pin 9 oder 10) kann als PWM-Ausgang verwendet werden.

**Hinweis:** Die Schreibweise der obigen Anweisungen ist "servo-Variablenname.spezifische Anweisung()", z. B. myservo. Attach (9).

Verbinden Sie weiterhin den Servo mit Pin 9.

## Beispielprogramm B

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

## Beispielergebnis

![Beispielergebnis Abbildung](../media/f02556e0631fb206c114ced29e643016.png)

Verdrahten Sie alles korrekt, laden Sie Programm A auf das Board, öffnen Sie dann den Seriellen Monitor der Arduino-Software, stellen Sie die Baudrate auf 9600, geben Sie in der oberen Leiste eine Zahl ein und klicken Sie auf „Senden“; Sie werden sehen, dass der Servo zum entsprechenden Winkel dreht, und der Drehwinkel im Monitor angezeigt wird. Siehe unten.

Bei eingeschalteter Stromversorgung und korrekt hochgeladenem Programm B fährt der Servo zunächst auf einen Winkel von 90°.

![Beispielergebnis Abbildung](../media/de50d502cb8ed1feb5935d16584cfd63.png)

---

# Lektion 17: Reed-Schalter

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 17: Reed-Schalter Illustration](../media/e580999515f6522eb603ea723bf62173.png)

## Beschreibung

Der Reed-Schalter ist ein spezieller Schalter und eine Hauptkomponente für Reed-Relais und Näherungsschalter.

Ein Reed-Schalter besteht üblicherweise aus zwei weichmagnetischen Materialien und metallischen Kontaktzungen, die sich trennen, wenn kein Magnetfeld vorhanden ist.

Außerdem sind einige Reed-Schalter mit einer zusätzlichen Kontaktzunge als dritten normalerweise geschlossenen Kontakt ausgestattet. Diese Kontaktschaltzungen sind in einem Glasrohr versiegelt, das mit Inertgasen (wie Stickstoff und Helium) gefüllt ist, oder in einem Vakuum-Glasrohr.

Die im Glasrohr eingeschlossenen Kontaktzungen liegen parallel mit überlappenden Enden. Zwischen ihnen wird ein bestimmter Abstand oder gegenseitiger Kontakt vorgesehen, um die normalerweise offenen oder normalerweise geschlossenen Kontakte des Schalters zu bilden.

Der Reed-Schalter kann z. B. zum Zählen, als Endschalter oder für andere Zwecke verwendet werden.

Beispielsweise wird bei einem Fahrradkilometerzähler ein Magnet am Reifen befestigt und der Reed-Schalter daneben montiert.

Man kann den Reed-Schalter auch an einer Tür zur Alarmierung oder als Schalter anbringen.

Reed-Schalter werden weit verbreitet in Haushaltsgeräten, Fahrzeugen, der Kommunikationstechnik, Industrie, im Gesundheitswesen und im Sicherheitsbereich eingesetzt.

Darüber hinaus kann er in Verbindung mit anderen Sensoren und elektrischen Geräten eingesetzt werden, z. B. Flüssigkeitsstandsanzeigern, Türmagneten, Reed-Relais, Ölstandssensoren und Näherungssensoren (Magnetsensoren). Er kann in risikoreichen Umgebungen eingesetzt werden.

## Technische Daten

1. Betriebsspannung: DC 3.3V-5V

2. Betriebsstrom: ≥20mA

3. Betriebstemperatur: －10℃ bis ＋50℃

4. Erfassungsabstand: ≤10mm

5. IO-Schnittstelle: 3-Draht-Schnittstellen (-/+/S)

6. Größe: 30\*20mm

7. Gewicht: 3g

## Anschlussdiagramm

Verbinde den S-Pin des Moduls mit Digital 3 des V4.0-Boards, den negativen Pin mit dem GND-Port und den positiven Pin mit dem 5V-Port.

![Anschlussdiagramm Illustration](../media/ad39b511b42657baed492704a9c84b13.jpeg)

## Beispielcode

Kopiere und füge den folgenden Code in die Arduino-Software ein.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int buttonpin=3; //define magnetic ring sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED as output interface
pinMode(buttonpin,INPUT);//define magnetic ring sensor as output interface
 }
void loop()
{

val=digitalRead(buttonpin);// read and assign the value of digital interface 3 to val

if(val==HIGH)//When a signal is detected by magnetic ring sensor, LED will flash
{
digitalWrite(Led,HIGH);
}
else
{
digitalWrite(Led,LOW);
}
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

Nachdem die Verdrahtung abgeschlossen und die Stromversorgung eingeschaltet ist sowie der Code erfolgreich auf das Board hochgeladen wurde, leuchtet die D13-LED auf dem V4.0-Board.

![Beispielergebnis Illustration](../media/a2f983d5a5b324f55e3c0994458d4cbc.png)

Anschließend halten wir einige Magnetkugeln in die Nähe des Sensors. Wenn der Sensor das Magnetfeld erkennt, leuchtet die LED am Sensor, während die D13-LED erlischt.

![Beispielergebnis Illustration](../media/ecbec914abc799076513f5c61149b004.png)

---

# Lektion 22: Analoger Schall

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P-Board

![Projekt 22: Analoger Schall Abbildung](../media/a494bbec73f7c8ff91b3133c9d2798a7.jpeg)

## Beschreibung

Der analoge Schall-Sensor wird typischerweise zur Erkennung der Lautstärke der Umgebungsgeräusche verwendet. Der Sensor verfügt über ein Potentiometer, mit dem du die Verstärkung des Signals einstellen kannst.

Du kannst ihn verwenden, um einige interessante und interaktive Projekte zu erstellen, wie z. B. einen sprachgesteuerten Schalter.

## Spezifikation

- Versorgungsspannung: 3.3V bis 5V

- Schnittstelle: Analog

- Größe: 30*20mm

- Gewicht: 4g

## Anschlussdiagramm

Verbinde den S-Pin des Moduls mit dem analogen A0 des V4.0-Boards, den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/22e1124550d57015a6d2d5782b8febda.jpeg)

## Beispielcode

Kopiere und füge den folgenden Code in die Arduino-Software ein.

```c
////////////////////////////////////////////////////////////////////
int sensorPin =A0 ;
int value = 0;
void setup()
{
 Serial.begin(9600); }
void loop()
{
 value = analogRead(sensorPin);

Serial.println(value, DEC);

delay(50);
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

Nachdem die Verkabelung abgeschlossen und die Stromversorgung eingeschaltet ist und der Code erfolgreich hochgeladen wurde, öffne den Seriellen Monitor und stelle die Baudrate auf 9600 ein. Du wirst dann den analogen Wert sehen. Wenn du in Richtung des Mikrofons sprichst, erhöht sich der Wert. Siehe unten.

![Beispielergebnis Abbildung](../media/4d753036151413a1bdda3c0b283b8551.png)

---

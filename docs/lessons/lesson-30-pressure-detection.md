# Lektion 30: Druckerkennung

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P Board

![Projekt 30: Druckerkennung Illustration](../media/313f11bf4a7f52ac903c78976fe1e633.jpeg)

## Beschreibung

Dieser Sensor verwendet neues flexibles nano-druckempfindliches Material mit ultra-dünner Folienauflage. Er ist wasserdicht und zur Druckerkennung geeignet.

Wenn der Sensor äußeren Druck erkennt, ändert sich sein Widerstand.

Durch die Schaltung kann das vom Sensor erfasste Drucksignal in ein entsprechendes elektrisches Ausgangssignal umgewandelt werden.

Auf diese Weise können wir durch Erfassen der Signaländerungen die Druckverhältnisse ermitteln.

## Parameter

- Betriebsspannung：DC 3.3V—5V

- Messbereich：0-10KG

- Dicke：＜0.25mm

- Ansprechpunkt：＜20g

- Wiederholbarkeit：＜±5.8%（50% Belastung）

- Genauigkeit：±2.5%（85% Bereichsintervall）

- Lebensdauer：＞100.000 Mal

- Anfangswiderstand：＞100MΩ（ohne Last）

- Ansprechzeit：＜1ms

- Erholzeit：＜15ms

- Betriebstemperatur：﹣20℃—60℃

## Anschlussdiagramm

Zuerst müssen Sie die folgenden Teile vor dem Anschließen bereitlegen.

- V4.0-Board\*1

- Drucksensor\*1

- USB-Kabel\*1

- Jumperkabel\*3

Verbinden Sie den S-Pin des Moduls mit dem analogen A0 des V4.0-Boards, den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.
![Anschlussdiagramm Illustration](../media/3325303180f71db75d9e13acc5036d8f.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
///////////////////////////////////////////////////////////////
int s_pin = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(s_pin,INPUT);

}

void loop()
{
  Serial.println(analogRead(s_pin));
  delay(500);
}
///////////////////////////////////////////////////////////////
```

## Beispielergebnis

Bei korrekter Verdrahtung und nach dem Hochladen des Codes öffnen Sie den seriellen Monitor in der Arduino-Software.

Drücken Sie dann den Sensor fest mit der Hand; der im Monitor angezeigte Wert steigt an.

![Beispielergebnis Illustration](../media/a6c4be8596a0048cb5f3b2f1612241bd.png)

![Beispielergebnis Illustration](../media/e055d2749b14c62b92c22496a3d1f96a.jpeg)

---

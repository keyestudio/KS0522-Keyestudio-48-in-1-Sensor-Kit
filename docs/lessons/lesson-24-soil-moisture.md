# Lektion 24: Bodenfeuchtigkeit

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 24: Bodenfeuchte Illustration](../media/d1041a8e2cbfca69c5d8bbd9ba7d4f92.jpeg)

## Beschreibung

Dies ist ein einfacher Bodenfeuchtesensor, der darauf ausgelegt ist, die Bodenfeuchte zu erkennen. Wenn dem Boden Wasser fehlt, nimmt der vom Sensor ausgegebene analoge Wert ab, andernfalls steigt er an.

Wenn Sie diesen Sensor verwenden, um eine automatische Bewässerungseinrichtung zu bauen, kann er erkennen, ob Ihre Pflanzen Durst haben, und verhindert so, dass sie verwelken, wenn Sie unterwegs sind.

Die Kombination dieses Sensors mit einem Arduino-Controller kann Ihre Pflanzen komfortabler versorgen und Ihren Garten intelligenter machen.

Das Bodenfeuchtesensormodul ist nicht so kompliziert, wie Sie vielleicht denken. Wenn Sie in Ihrem Projekt den Bodenfeuchtigkeitsgehalt messen müssen, ist es die beste Wahl.

Der Sensor ist mit zwei Sonden ausgestattet, die in den Boden gesteckt werden. Fließt Strom durch den Boden, ermittelt der Sensor den Widerstand, indem er die Stromänderungen zwischen den beiden Sonden misst, und wandelt dann den Widerstandswert in einen Feuchtigkeitswert um.

Je feuchter (geringerer Widerstand), desto höher die Leitfähigkeit des Bodens.

Die Oberfläche des Sensors wurde metallisiert, um seine Lebensdauer zu verlängern. Stecken Sie ihn in die Erde und lesen Sie ihn anschließend mit dem A/D-Wandler aus. Mit Hilfe dieses Sensors kann die Pflanze Sie daran erinnern: Ich brauche Wasser.

## Spezifikation

- Versorgungsspannung: 3.3V oder 5V

- Betriebsstrom: ≤ 20mA

- Ausgangsspannung: 0-2.3V (wenn der Sensor vollständig in Wasser eingetaucht ist, beträgt die Spannung 2.3V). Je höher die Feuchtigkeit, desto höher die Ausgangsspannung.

- Sensortyp: Analoger Ausgang

- Schnittstelle: Pin1 - Signal, Pin2 - GND, Pin3 - VCC

## Anschlussdiagramm

Verbinden Sie den S-Pin des Moduls mit dem Analog A0 des V4.0-Boards, verbinden Sie den negativen Pin mit GND und den positiven Pin mit 5V.

![Anschlussdiagramm Illustration](../media/b1685a438f171f4bbb3cd8d1b1782bb1.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
////////////////////////////////////////////////////////////////////
/*
  # Example code for the moisture sensor
  # Connect the sensor to the A0(Analog 0) pin on the Arduino board
  # the sensor value description
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
*/
void setup(){
  Serial.begin(57600);
}
void loop(){
  Serial.print("Moisture Sensor Value:");
  Serial.println(analogRead(0));
  delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Illustration](../media/1200f0f53ca0758afc505c475ce75e68.png)

Nachdem die Verkabelung abgeschlossen und die Stromversorgung eingeschaltet ist, laden Sie den Code hoch, öffnen Sie den seriellen Monitor und stellen Sie die Baudrate auf 57600 ein. Sie werden dann den Wert sehen. Wenn der Sensor Feuchtigkeit erkennt, ändert sich der Wert entsprechend. Siehe unten.

![Beispielergebnis Illustration](../media/cb240ae7199f877c17b9ac3a4d9d6ced.jpeg)

---

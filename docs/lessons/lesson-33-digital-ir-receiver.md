# Lektion 33: Digitaler IR-Empfänger

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 33: Digitaler IR-Empfänger - Abbildung](../media/f64f21b6ca681f928c3318bd2d33a017.png)

## Beschreibung

IR wird häufig in Fernsteuerungen eingesetzt. Mit diesem IR-Empfänger kann ein Arduino-Projekt Befehle von beliebigen IR-Fernbedienungen empfangen, vorausgesetzt, Sie haben den passenden Decoder. Es ist außerdem einfach, mit einem IR-Sender eine eigene IR-Fernbedienung zu bauen.

## Spezifikation

- Stromversorgung: 5V

- Schnittstelle: Digital

- Modulationsfrequenz: 38Khz

- Modul-Anschlussbuchse: JST PH2.0

- Größe: 30*20mm

- Gewicht: 4g

## Anschlussdiagramm

Bereiten Sie vor dem Anschluss zunächst die folgenden Teile vor.

- V4.0-Platine\*1

- IR-Empfängermodul\*1

- USB-Kabel\*1

- Jumper-Kabel\*3

Verbinden Sie den S-Pin des Moduls mit Digitalpin 11 der V4.0-Platine, den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.

![Anschlussdiagramm - Abbildung](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

Im untenstehenden Beispielcode wird Digitalpin 11 verwendet. Sie können entweder die Verkabelung ändern oder den Beispielcode anpassen, damit er übereinstimmt.

## Beispielcode

Kopieren Sie den untenstehenden Code in die Arduino-Software.

```c
///////////////////////////////////////////////////////////////
#include <IRremote.h>
 int RECV_PIN = 11;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
 void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}

///////////////////////////////////////////////////////////////
```

**Hinweis:** Bevor Sie den Code kompilieren, denken Sie daran, die Bibliothek in das Verzeichnis libraries der Arduino IDE zu legen. Andernfalls schlägt die Kompilierung fehl.

Die IR Remote Library enthält einige Beispielcodes zum Senden und Empfangen.

<https://github.com/shirriff/Arduino-IRremote>

## Beispielergebnis

![Beispielergebnis - Abbildung](../media/2692333113be48ffa11c27649d18dcb8.png)

Nach dem Verdrahten und Hochladen des Codes steuern Sie das IR-Empfängermodul mit einer Infrarot-Fernbedienung; die D1-LED wird blinken.

![Beispielergebnis - Abbildung](../media/4bb52e2957e3aaeace252021e7084c95.png)

---

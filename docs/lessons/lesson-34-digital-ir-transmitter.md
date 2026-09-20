# Lektion 34: Digitaler IR-Sender

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Projekt 34: Digitaler IR-Sender - Abbildung](../media/9fe876a8c857650226cbe2f8a9bead59.png)

## Beschreibung

Das IR-Sendermodul ist für IR-Kommunikation ausgelegt und wird häufig verwendet, um ein Fernsehgerät aus kurzer Sichtverbindung zu bedienen.

Da Infrarot (IR)-Fernbedienung Licht verwendet, benötigt sie Sichtverbindung, um das Zielgerät zu bedienen. Das Signal kann jedoch wie andere Lichtquellen von Spiegeln reflektiert werden.

Infrarotempfänger haben ebenfalls einen mehr oder weniger begrenzten Betriebswinkel, der hauptsächlich von den optischen Eigenschaften des Phototransistors abhängt.

Den Betriebswinkel kann man jedoch leicht erhöhen, indem man ein mattes, transparentes Objekt vor den Empfänger stellt.

## Spezifikation

- Stromversorgung: 3-5V

- Infrarot-Zentrumwellenlänge: 850nm-940nm

- Abstrahlwinkel des Infrarots: etwa 20 Grad

- Abstrahldistanz des Infrarots: etwa 1,3 m (5V 38Khz)

- Anschlussstecker: JST PH2.0

- Befestigungsloch: Innen-Ø 3,2mm, Abstand 15mm

## Anschlussdiagramm

Bereiten Sie zunächst die folgenden Teile vor, bevor Sie die Verbindung herstellen.

- V4.0-Platine\*1

- IR-Sendermodul\*1

- USB-Kabel\*1

- Jumperkabel\*3

Verbinden Sie den S-Pin des Moduls mit Digital 3 des V4.0-Boards, verbinden Sie den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.

![Anschlussdiagramm - Abbildung](../media/31c03e9ad144e1124260ff6e0538fe69.jpeg)

## Beispielcode 1

```c
int led = 3;
void setup() {
   pinMode(led, OUTPUT);
}
void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
```

In dunkler Umgebung sehen Sie beim Filmen mit der Handykamera ein blinkendes blaues Licht auf dem Bildschirm, wenn die Infrarot-LED leuchtet.

Laden Sie den obigen Code auf das Board; die LED am Sensor blinkt rot.

Im Folgenden gehen wir zu einem interaktiven Beispiel zwischen IR-Empfänger und IR-Sendermodul über.

## Infrarot-Fernbedienung/Kommunikation

## Benötigte Hardware

- Arduino R3 x2

- Digitaler IR-Empfänger x1

- IR-Sendermodul x1

Hinweis: Dieses Experiment benötigt zwei Mikrocontroller-Boards. Ein Steckbrett ersetzt nicht das zweite Board, da es den Empfänger-Sketch nicht ausführen kann.

## Zwei-Board-Kommunikation

## Für IR-Sender

Hinweis: Arduino-IR remote unterstützt nur D3 als Sender.

![Für IR-Sender - Abbildung](../media/08ebf9b37949caf1782e499f49934f1d.png)

## Für IR-Empfänger

Verbinden Sie den Signaleingang mit dem D11-Port.

![Für IR-Empfänger - Abbildung](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

## Laden Sie Code 2 auf das mit dem IR-Sender verbundene V4.0-Board hoch

```c
 #include <IRremote.h>
  IRsend irsend;
 void setup()
 {}
 void loop() {
  irsend.sendRC5(0x0, 8); //send 0x0 code (8 bits)
     delay(200);
  irsend.sendRC5(0x1, 8);
     delay(200); }
```

## Laden Sie Code 3 auf das mit dem IR-Empfänger verbundene V4.0-Board hoch

```c
#include <IRremote.h>
 const int RECV_PIN = 11;
 const int LED_PIN = 13;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
 {Serial.begin(9600);
   irrecv.enableIRIn(); // Start the receiver
 }
  void loop()
 {if (irrecv.decode(&results))
   { if ( results.bits > 0 )
     {

       int state;
       if ( 0x1 == results.value )
       {
         state = HIGH;
       }
       else
       {
         state = LOW;
       }
       digitalWrite(LED_PIN, state);
     }
  irrecv.resume();        // prepare to receive the next value
   }}
```

## Ergebnis

Wenn das IR-Empfängermodul das Infrarotsignal vom IR-Sender empfängt, blinkt die D1-LED am IR-Empfängermodul.

Wenn das IR-Empfängermodul das Infrarotsignal vom IR-Sender empfängt, blinkt die D1-LED am IR-Empfängermodul.

![Ergebnis - Abbildung](../media/4d73a7178e89de72df7e82a147778ae9.png)

---

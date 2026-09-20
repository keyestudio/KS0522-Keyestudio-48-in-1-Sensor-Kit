# Lektion 10: Infrarot-Hinderniserkennung

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P-Platine

![Projekt 10: Illustration zur Infrarot-Hinderniserkennung](../media/54ab9db703340471fd9c3151934b85e7.png)

## Beschreibung

Der Infrarot-Hindernisdetektorsensor verfügt über eine Distanz-Einstellfunktion und ist speziell für Radroboter konzipiert.

Dieser Sensor hat eine hohe Anpassungsfähigkeit an Umgebungslicht und eine hohe Genauigkeit.

Er besitzt ein Paar aus Infrarot-Sende- und Empfangsröhre. Wenn der vom Sender ausgesandte Infrarotstrahl auf ein Hindernis (seinen Reflektor) trifft, wird der Strahl an die Empfangsröhre reflektiert, wodurch die Anzeigeleuchte aufleuchtet und die Signalausgangsschnittstelle ein digitales Signal ausgibt.

Zusätzlich können Sie den Potentiometerknopf drehen, um die Erkennungsdistanz einzustellen (effektive Distanz: 2～40cm, Betriebsspannung: 3,3V–5V).

Dank des weiten Spannungsbereichs kann dieser Sensor auch bei schwankender Versorgungsspannung stabil arbeiten und ist geeignet für verschiedene Mikrocontroller, Arduino-Controller und BS2-Controller.

Ein Roboter, der mit diesem Sensor ausgestattet ist, kann Hindernisse in der Umgebung wahrnehmen.

## Technische Daten

- Betriebsspannung: Gleichspannung (DC) 3,3V–5V

- Betriebsstrom: ≥20 mA

- Betriebstemperatur: －10℃ bis＋50℃

- Erkennungsreichweite: 2-40 cm

- IO-Schnittstelle: 4-adrige Schnittstelle (-/+/S/EN)

- Ausgangssignal: TTL-Spannung

- Einstellmodus: Mehrgang-Potentiometer

- Erfassungswinkel: 35°

## Anschlussdiagramm

Bereite vor der Verbindung zunächst die folgenden Teile vor:

- V4.0-Platine\*1

- Hindernisdetektor-Modul\*1

- USB-Kabel\*1

- Jumperkabel\*3

Verbinde den Out-Pin des Moduls mit Digital 2 der V4.0-Platine, den V+-Pin mit dem 5V-Anschluss und den GND-Pin mit dem GND-Anschluss.

![Anschlussdiagramm-Illustration](../media/48f60a482d777df19bc43a3203479b0c.jpeg)

## Beispielcode

Kopiere den folgenden Code in die Arduino-Software.

```c
const uint8_t sensorPin = 2;
const uint8_t ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  const int sensorState = digitalRead(sensorPin);
  digitalWrite(ledPin, sensorState == HIGH ? HIGH : LOW);
}
```

## Beispielergebnis

Nachdem der Code auf das Board hochgeladen wurde, leuchtet die LED sowohl auf der V4.0-Platine als auch am Hindernisdetektor-Modul.

![Beispielergebnis-Illustration](../media/44d035dfe09b4c803becd84c95b05956.png)

Wenn wir einen Schaumstoffblock vor den Sensor stellen, wird diesmal, sobald der Sensor das Hindernis erkennt, die LED am Sensor eingeschaltet.

![Beispielergebnis-Illustration](../media/da4468fead816d42b2ac43b29716b91f.png)

---

# Lektion 16: Flammenalarm

> **Bausatz:** Keyestudio 48-in-1 Sensorset  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P Platine

![Projekt 16: Flammenalarm Illustration](../media/35c5a2593df5d4e76865158e790feada.png)

## Beschreibung

Dieser Flammensensor kann verwendet werden, um Feuer oder andere Lichtquellen mit einer Wellenlänge von 760nm \~ 1100nm zu erkennen.

Im Feuerwehrroboter-Spiel spielt die Flamme eine wichtige Rolle bei der Erkundung und kann als „Augen“ des Roboters dienen, um die Brandquelle zu finden.

## Spezifikation

1. Versorgungsspannung: 3.3V bis 5V

2. Erkennungsreichweite: 20cm (4.8V) \~ 100cm (1V)

3. Bereich der spektralen Bandbreite: 760nm bis 1100nm

4. Betriebstemperatur: -25℃ bis 85℃

5. Schnittstelle: digital

6. Größe: 44*16.7mm

7. Gewicht: 4g

## Anschlussdiagramm

Bereiten Sie vor dem Anschluss zunächst die folgenden Teile vor:

- V4.0-Platine*1

- Flammensensor*1

- USB-Kabel*1

- Jumperkabel*3

Verbinden Sie den D0-Pin des Moduls mit Digital 2 der V4.0-Platine, verbinden Sie den GND-Pin mit dem GND-Anschluss und den VCC-Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Illustration](../media/a1ee506fc9921c7616349500c258b733.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
////////////////////////////////////////////////////////////////////
const int flamePin = 2;     // the number of the flame pin
const int ledPin =  13;      // the number of the LED pin
// variables will change:
int State = 0;         // variable for reading status
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(flamePin, INPUT);
}
void loop(){
  // read the state of the value:
State = digitalRead(flamePin);
  if (State == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

Nachdem die Verkabelung abgeschlossen und die Stromversorgung eingeschaltet ist, laden Sie den Code erfolgreich auf die Platine hoch.

![Beispielergebnis Illustration](../media/c769453bbd0e1c5fcf6c80cf697030b3.png)

Wenn Sie anschließend ein Feuerzeug in die Nähe des Sensors halten, schaltet eine weitere LED auf dem Sensor ein, sobald die Flamme erkannt wird.

![Beispielergebnis Illustration](../media/2ee5a36673d2cbeb934ca2af29dab607.png)

---

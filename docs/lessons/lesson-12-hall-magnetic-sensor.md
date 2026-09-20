# Lektion 12: Hall-Magnetfeldsensor

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 12: Hall-Magnetfeldsensor Abbildung](../media/c3d4d513b72ac04fad7e4f3015bfb1ed.png)

## Beschreibung

Dies ist ein magnetischer Induktionssensor. Er kann magnetische Materialien innerhalb einer Erkennungsreichweite von bis zu 3cm erfassen. Die Erkennungsreichweite und die Stärke des Magnetfeldes sind proportional. Der Ausgang ist digital ein/aus.

Dieser Sensor verwendet den SFE Reed Switch - Magnetic Field Sensor.

## Spezifikation

- Erkennt magnetische Materialien

- Erfassungsbereich: bis zu 3cm

- Ausgang: digital ein/aus

- Größe: 30*20mm

- Gewicht: 3g

## Anschlussdiagramm

Bereiten Sie vor dem Anschluss die folgenden Teile vor:

- V4.0 Platine\*1

- Hallsensor \*1

- USB-Kabel\*1

- Jumper-Kabel\*3

Verbinden Sie den S-Pin des Moduls mit Digital 3 der V4.0-Platine, den Minuspol mit dem GND-Anschluss und den Pluspol mit dem 5V-Anschluss.

![Verbindungsdiagramm Abbildung](../media/db4db0c53435ceb1d6caaaf40502247a.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
////////////////////////////////////////////////////////////////////
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare push button as input
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

Verdrahten Sie alles und laden Sie den Code auf das Board hoch. Sie werden sehen, dass die D13-Anzeige auf der V4.0-Platine aus ist und die LED am Modul ebenfalls aus ist.

![Beispielergebnis Abbildung](../media/102f67e289b5834de7fa80b6e6d99c20.png)

Wenn Sie jedoch einen Magnetball in die Nähe des Hall-Moduls bringen, wird die D13-Anzeige auf der V4.0-Platine eingeschaltet und die LED am Modul leuchtet ebenfalls.

![Beispielergebnis Abbildung](../media/c3c4044f2205dd1ff162ef7e211d2b2c.png)

---

# Lektion 36: Joystick

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Projekt 36: Joystick Abbildung](../media/310a620a28ae6ebeeee7294bdc7a2bb0.png)

## Beschreibung

Viele Roboterprojekte benötigen einen Joystick. Dieses Modul bietet eine kostengünstige Lösung. Durch einfaches Anschließen an zwei analoge Eingänge steht der Roboter unter Ihrer Kontrolle mit X- und Y-Steuerung. Es verfügt außerdem über einen Schalter, der an einen digitalen Pin angeschlossen ist.

## Spezifikation

- Betriebsspannung: 3.3V bis 5V

- Schnittstelle: Analog x2, Digital x1

- Größe: 40*28mm

- Gewicht: 12g

## Anschlussdiagramm

Bereiten Sie vor dem Anschluss zunächst die folgenden Teile vor.

- V4.0 Board\*1

- Joystick-Modul\*1

- USB-Kabel\*1

- Jumper-Kabel\*5

Verbinden Sie den Y-Pin des Moduls mit Analog A1 des V4.0 Boards, verbinden Sie den X-Pin mit Analog A0, den B-Pin mit Digital 3; schließen Sie den negativen Pin an den GND-Anschluss und den positiven Pin an den 5V-Anschluss an.

![Anschlussdiagramm Abbildung](../media/3c0d2f553f6e76565171dae78a440568.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
///////////////////////////////////////////////////////////////
int JoyStick_X = 0; //x
int JoyStick_Y = 1; //y
int JoyStick_Z = 3; //key
  void setup()
{
  pinMode(JoyStick_Z, INPUT);
  Serial.begin(9600); // 9600 bps
}
void loop()
{
  int x,y,z;
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=digitalRead(JoyStick_Z);
  Serial.print(x ,DEC);
  Serial.print(",");
  Serial.print(y ,DEC);
  Serial.print(",");
  Serial.println(z ,DEC);
  delay(100);
}
///////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Abbildung](../media/5e6809517dd961c3740b04c7774c3e75.png)

Gut verdrahten und den Code hochladen, öffnen Sie den seriellen Monitor in der Arduino-Software und stellen Sie die Baudrate auf 9600 ein, Sie sehen die unten gezeigten Werte. Wenn Sie den Joystick nach unten / nach oben / nach links / nach rechts bewegen, ändern sich die Daten.

![Beispielergebnis Abbildung](../media/6b3a1bd089cafce0f1db02f405ab5035.jpeg)

---

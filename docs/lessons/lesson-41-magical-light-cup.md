# Lección 41: Taza Mágica de Luz

> **Kit:** Keyestudio 48 en 1 Kit de sensores  
> **Placa:** Keyestudio V4.0 / Placa compatible con Arduino Uno ATmega328P

![Proyecto 41: Taza Mágica de Luz ilustración](../media/dc3acff676b2611f440643f1657b42e7.png)

## Introducción

El módulo Taza Mágica de Luz puede interactuar con ARDUINO. El principio se basa en el atenuado por PWM.

El interruptor de mercurio del módulo puede proporcionar una señal digital y activar la regulación por PWM. El brillo de dos módulos cambiará conjuntamente mediante el diseño del programa; finalmente podrás ver el efecto de cambio en el que los dos juegos de tazas parecen verter luz.

## Especificaciones

- Voltaje de alimentación: 3.3V a 5V

- Interfaz: Digital

## Diagrama de conexión

![Ilustración del diagrama de conexión](../media/9d8d534c60a81608741f85c08d4d0bbe.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
///////////////////////////////////////////////////////////////
int LedPinA = 5;
int LedPinB = 6;
int ButtonPinA = 7;
int ButtonPinB = 4;
int buttonStateA = 0;
int buttonStateB = 0;
int brightnessA = 0;
int brightnessB= 255;
void setup()
{
Serial.begin(9600);
pinMode(LedPinA, OUTPUT);
pinMode(LedPinB, OUTPUT);

pinMode(ButtonPinA, INPUT);
pinMode(ButtonPinB, INPUT);
}
void loop()
{
buttonStateA = digitalRead(ButtonPinA);
if (buttonStateA == HIGH && brightnessA != 255)
{
brightnessA ++;
}
if (buttonStateA == LOW && brightnessA != 0)
{
brightnessA --;
}
analogWrite(LedPinB, brightnessA);
Serial.print(brightnessA);

Serial.print("   ");
buttonStateB = digitalRead(ButtonPinB);
if (buttonStateB == HIGH && brightnessB != 0)
{
brightnessB --;
}
if (buttonStateB == LOW && brightnessB != 255)
{
brightnessB++;
}
analogWrite(LedPinA, brightnessB);
Serial.println(brightnessB);
delay(5);
}
///////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/f629888f2fedea9442ba74dc8761fcb3.png)

Conéctalo según el diagrama anterior y sube correctamente el código a la placa; entonces verás que una taza se enciende mientras la otra está apagada. Al inclinar estas dos tazas hacia el mismo lado, una taza se va iluminando gradualmente y la otra taza brillante se va apagando gradualmente.

![Ilustración del resultado de ejemplo](../media/cfc57515b967d19fcda65ea50bda76f1.png)

---

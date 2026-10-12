# Lección 36: Joystick

> **Kit:** Kit de sensores Keyestudio 48-en-1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Ilustración del proyecto 36: Joystick](../media/310a620a28ae6ebeeee7294bdc7a2bb0.png)

## Descripción

Muchos proyectos de robótica necesitan un joystick. Este módulo ofrece una solución económica. Conectándolo simplemente a dos entradas analógicas, el robot queda bajo su control con ejes X e Y. También tiene un interruptor que se conecta a un pin digital.

## Especificaciones

- Tensión de alimentación: 3.3V a 5V

- Interfaz: Analógica x2, Digital x1

- Tamaño: 40*28mm

- Peso: 12g

## Diagrama de conexión

Primero debe preparar las siguientes piezas antes de la conexión.

- Placa V4.0\*1

- Módulo joystick\*1

- Cable USB\*1

- Cables de puente\*5

Conecte el pin Y del módulo a Analog A1 de la placa V4.0, conecte el pin X a Analog A0, el pin B a Digital 3; conecte el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/3c0d2f553f6e76565171dae78a440568.jpeg)

## Código de ejemplo

Copie y pegue el código siguiente en el software de Arduino.

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

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/5e6809517dd961c3740b04c7774c3e75.png)

Una vez bien cableado y subido el código, abra el monitor serie en el software de Arduino y ajuste la velocidad en baudios a 9600; verá los valores mostrados abajo. Si empuja el joystick hacia abajo/arriba/izquierda/derecha, los datos cambiarán.

![Ilustración del resultado de ejemplo](../media/6b3a1bd089cafce0f1db02f405ab5035.jpeg)

---

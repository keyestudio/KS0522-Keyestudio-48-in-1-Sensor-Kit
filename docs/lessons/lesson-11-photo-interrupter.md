# Lección 11: Sensor de interrupción óptica

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 11: ilustración del sensor de interrupción óptica](../media/8b0f7b3ba3e139eeaeba9bb7f86a946a.png)

## Descripción

La parte vertical de este sensor es un emisor infrarrojo y en el otro lado hay un detector infrarrojo protegido. Al emitir un haz de luz infrarroja de un extremo al otro, el sensor puede detectar un objeto cuando éste atraviesa el haz.

Se utiliza para muchas aplicaciones incluyendo interruptores de límite ópticos, dispensación de pellets, detección general de objetos, etc.

## Especificación

- Tensión de alimentación: 3.3V a 5V

- Interfaz: Digital

- Tamaño: 30*20mm

- Peso: 3g

## Diagrama de conexión

Primero, debe preparar las siguientes piezas antes de la conexión:

- Placa V4.0\*1

- Módulo del sensor de interrupción óptica \*1

- Cable USB\*1

- Cable de puente\*3

Conecte el pin S del módulo a Digital 3 de la placa V4.0, conecte el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/669fa42ef7fb576047d6849940a305ba.jpeg)

## Código de ejemplo

Copie y pegue el siguiente código en el IDE de Arduino.

```c
////////////////////////////////////////////////////////////////////
// photo interrupter module
int Led = 13 ;// define LED Interface
int buttonpin = 3; // define the photo interrupter sensor interface
int val ;// define numeric variables val
void setup ()
{
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// define the photo interrupter sensor output interface
}
void loop ()
{
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read val
  if (val == HIGH) // When the light sensor detects a signal is interrupted, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Tras subir el código a la placa, puede ver que tanto el led en la placa V4.0 como el del módulo están encendidos. Se muestra a continuación.

![Ilustración del resultado de ejemplo](../media/fa4d06ebf82ec572b7eccf6b706942cb.png)

Al colocar un papel en la ranura del módulo, la señal se interrumpe y led1 del módulo se apaga.

![Ilustración del resultado de ejemplo](../media/3ecb941fafc71843148e0e19b6ceda57.png)

---

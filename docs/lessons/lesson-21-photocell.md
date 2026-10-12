# Lección 21: Fotorresistor

> **Kit:** Kit de sensores Keyestudio 48-in-1  
> **Placa:** Placa Keyestudio V4.0 / compatible con Arduino Uno ATmega328P

![Proyecto 21: ilustración del fotorresistor](../media/8eed60793fd64a7c0b9a9b2a2fc1ef67.png)

## Descripción

El fotorresistor es común en nuestra vida diaria y se utiliza principalmente en interruptores
inteligentes, así como en diseños electrónicos habituales. Para hacerlo más fácil y efectivo,
suministramos los módulos correspondientes.

El fotorresistor es un semiconductor. Tiene características de alta sensibilidad, respuesta
rápida, característica espectral y consistencia del valor R, manteniendo alta
estabilidad y fiabilidad en entornos extremos como alta temperatura y
alta humedad.

Se utiliza ampliamente en campos de control automático como cámaras, luces solares de jardín,
lámparas de césped, detectores de billetes, relojes de cuarzo, tazas musicales, cajas de regalo, mini
luces nocturnas, interruptores de control de sonido y luz, etc.

## Especificación

- Tipo de interfaz: analógica

- Voltaje de trabajo: 5V

- Tamaño: 30*20mm

- Peso: 3g

## Diagrama de conexión

Conecte el pin S del módulo al Analógico A0 de la placa V4.0, conecte el pin negativo
al puerto GND, el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/28a1990cd088d6f0301f02d217cef301.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read rotation sensor value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/78268e9cb1dbc127e7ae3299d3a35a45.png)

Una vez realizadas las conexiones y con la alimentación encendida, sube correctamente el código, luego abre el monitor serial; si cubres el fotorresistor del sensor con tu mano, verás que el valor analógico disminuye.

![Ilustración del resultado de ejemplo](../media/85621deb4c66d6e53697cd0ef90cb6e2.jpeg)

---

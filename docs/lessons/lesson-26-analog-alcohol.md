# Lección 26: Alcohol analógico

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / Placa compatible con Arduino Uno ATmega328P

![Proyecto 26: Ilustración de alcohol analógico](../media/288162cf02f2968eda57b437292a42dd.png)

## Descripción

Este sensor analógico MQ-3 es adecuado para detectar alcohol. Puede usarse en un proyecto de alcoholímetro.

Tiene buena selectividad porque presenta mayor sensibilidad al alcohol y menor sensibilidad a la gasolina.

La sensibilidad puede ajustarse girando el potenciómetro del sensor.

## Especificaciones

- Alimentación: 5V

- Tipo de interfaz: Analógica

- Circuito de control sencillo

- Estable y de larga vida útil

- Respuesta rápida y alta sensibilidad

## Diagrama de conexión

Conecta el pin A0 del módulo al pin analógico A0 de la placa V4.0, conecta el pin GND al puerto GND y el pin VCC al puerto de 5V.

![Ilustración del diagrama de conexión](../media/61632f44731176aaf95d313f2843c9de.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read Gas value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/a21d5b8c686e46a59128ab48b96d177c.png)

Una vez realizadas las conexiones y alimentada la placa, sube correctamente el código; a continuación abre el Monitor Serie y ajusta la velocidad a 9600. Verás el valor analógico. Al detectar gas de alcohol, el valor cambiará.

![Ilustración del resultado de ejemplo](../media/97565d8ba7691b30a7aa96efc6c7728b.jpeg)

---

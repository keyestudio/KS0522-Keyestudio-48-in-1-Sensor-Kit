# Lección 20: Rotación Analógica

> **Kit:** Keyestudio 48-en-1 Kit de sensores  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno (ATmega328P)

![Ilustración del Proyecto 20: Rotación Analógica](../media/7a7fffa705c4a50e87455e6d378eb837.png)

## Descripción

Este sensor de rotación analógico es compatible con Arduino. Está basado en un potenciómetro. Su voltaje puede subdividirse en 1024 pasos, y es fácil de conectar al Arduino con nuestro shield de sensores.

Combinado con otros sensores, puedes usarlo para crear proyectos interesantes leyendo el valor analógico desde el puerto IO.

## Especificación

- Tensión de alimentación: 3.3V a 5V

- Interfaz: Analógica

- Tamaño: 30*20mm

- Peso: 8g

## Diagrama de conexión

Conecta el pin S del módulo al pin analógico A0 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/f8a0c2cca0f3d0935ce0c9a0c4dbe59e.jpeg)

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

![Ilustración del resultado de ejemplo](../media/bae047449c10c99449c35a14b22d759c.png)

Una vez hecha la conexión y alimentada la placa, sube correctamente el código, luego abre el Monitor Serie y ajusta la velocidad a 9600 baudios; finalmente verás el valor analógico. Si giras la perilla del sensor de rotación, el valor cambiará entre 0-1023. Se muestra abajo.

![Ilustración del resultado de ejemplo](../media/bc7b15c3245b7cfd91b0ef4b0aeb8e7e.jpeg)

---

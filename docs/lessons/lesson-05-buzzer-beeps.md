# Lección 05: Pitidos del zumbador

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 5: Pitidos del zumbador - ilustración](../media/88c349b0602dfa2e166faabc13cb2f20.png)

## Descripción

Aquí está el módulo más sencillo para generar sonido. Puedes usar niveles alto/bajo para accionarlo. Cambiando la frecuencia con la que vibra se pueden producir diferentes sonidos.

Este módulo se utiliza ampliamente en nuestros electrodomésticos diarios como PC, frigorífico, teléfonos, etc.

Además, puedes crear muchos proyectos interactivos interesantes con este módulo pequeño pero útil. ¡Pruébalo! Encontrarás el sonido electrónico que genera muy fascinante.

## Especificación

- Voltaje de trabajo: 3.3-5v

- Tipo de interfaz: digital

- Tamaño: 30*20mm

- Peso: 4g

## Diagrama de conexión

Conecta el pin S del módulo al Digital 3 de la placa V4.0, conecta el pin negativo al puerto GND, y el pin positivo al puerto 5V.

![Diagrama de conexión - ilustración](../media/173f2e9a828b0b20d76dc07de57892c1.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
int buzzPin =3;    //Connect Buzzer on Digital Pin3
 void setup()
 {
  pinMode(buzzPin, OUTPUT);
}
 void loop()
{
  digitalWrite(buzzPin, HIGH);
  delay(1);
  digitalWrite(buzzPin, LOW);
  delay(1);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Una vez subido el código a la placa, el zumbador emitirá un sonido.

![Resultado de ejemplo - ilustración](../media/109e3287bff29d1d1fb88369d6705ad3.png)

---

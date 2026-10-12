# Lección 23: Nivel de agua

> **Kit:** Keyestudio Kit de sensores 48 en 1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno (ATmega328P)

![Proyecto 23: ilustración del nivel de agua](../media/23f40997b8634be91aed7311eca2dfbb.jpeg)

## Descripción

El sensor de agua Keyestudio es fácil de usar, portátil y económico, diseñado para identificar y detectar el nivel de agua y gotas de agua.

Este pequeño sensor puede medir el volumen de gotas de agua o la cantidad de agua mediante una matriz de pistas de cables paralelos expuestos.

## Características

- conversión fluida entre la cantidad de agua y la señal analógica;

- gran flexibilidad, entregando un valor analógico básico;

- bajo consumo de energía y alta sensibilidad;

- se conecta directamente a microprocesadores u otros circuitos lógicos, siendo adecuado para una variedad de placas de desarrollo y controladores como el controlador Arduino, microcontrolador STC, microcontrolador AVR y más.

## Especificaciones

- Voltaje de funcionamiento: DC5V

- Corriente de funcionamiento: ﹤20mA

- Tipo de sensor: Analógico

- Área de detección: 40mm x16mm

- Proceso de fabricación: FR4 estañado por ambas caras

- Diseño: Receso semilunar antideslizante

- Temperatura de funcionamiento: 10℃-30℃

- Humedad de funcionamiento: 10%-90% sin condensación

- Peso: 3g

- Dimensiones: 65mm x 20mm x 8mm

## Diagrama de conexión

Conecte el pin S del módulo al pin analógico A0 de la placa V4.0, conecte el pin negativo a GND, el pin positivo a 5V.

![Ilustración del diagrama de conexión](../media/92810e41aea313a15735eecb3a168e2f.jpeg)

## Código de ejemplo

Copie y pegue el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
    int analogPin = 0; //connect water sensor to analog interface 0
int led = 13; //LED to digital interface 13
int val = 0; //define the initial value of variable ‘val’ as 0
int data = 0; //define the initial value of variable ‘data’ as 0
void setup()
{
pinMode(led, OUTPUT); //define led as output pin
Serial.begin(9600); //set baud rate at 9600
}
void loop()
{
val = analogRead(analogPin); //read and assign analog value to variable ’val’
if(val>700){ //decide whether variable ‘val’ is over 700
digitalWrite(led,HIGH); //turn on LED when variable ‘val’ is over 700
}
else{
digitalWrite(led,LOW); //turn off LED when variable ‘val’ is under 700
}
data = val; //variable ’val’ assigns value to variable ‘data’
Serial.println(data); //print variable ‘data’ by Serial.print
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/ca727c75f4d4e454c95258d77afdf10e.png)

Tras completar los pasos anteriores, hagamos una prueba con un nivel de agua bajo y veamos qué ocurre.

Suba correctamente el código a la placa V4.0, luego abra el monitor serie y ajuste la velocidad de baudios a 9600.

Al colocar el sensor en el agua a diferentes niveles, verá cómo el valor cambia en consecuencia.

![Ilustración del resultado de ejemplo](../media/8070cf2260fef39e5ec5e18b7a1849cf.jpeg)

Además, puede establecer un valor de alarma y conectar un zumbador para que suene.

El LED no se encenderá cuando el nivel de agua no haya alcanzado el valor de alarma. Si el nivel de agua alcanza el valor de alarma, el LED se encenderá y el zumbador sonará para alertar.

---

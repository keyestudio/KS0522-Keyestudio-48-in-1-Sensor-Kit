# Lección 06: Zumbador pasivo

> **Kit:** Keyestudio Kit de sensores 48 en 1  
> **Placa:** Keyestudio V4.0 / placa ATmega328P compatible con Arduino Uno

![Proyecto 6: Ilustración del zumbador pasivo](../media/1bd2e3afebf5a0d3712fe42092b0a1b4.png)

## Descripción

Podemos usar Arduino para crear muchas obras interactivas, siendo la más común la visualización acústico-óptica. El circuito en este experimento puede producir sonido.

Normalmente, el experimento puede realizarse con un zumbador o un altavoz, mientras que el zumbador es más sencillo y fácil de usar.

El zumbador que presentamos aquí es un zumbador pasivo. No puede accionarse por sí mismo, sino mediante frecuencias de pulsos externas. Diferentes frecuencias producen distintos sonidos. Puedes usar Arduino para programar la melodía de una canción; es bastante divertido y sencillo.

## Especificaciones

- Voltaje de trabajo: 3.3-5V

- Tipo de interfaz: digital

- Tamaño: 30\*20mm

- Peso: 4g

## Diagrama de conexión

Primero, debes preparar las siguientes piezas antes de realizar la conexión:

- Placa V4.0*1

- Módulo de zumbador pasivo*1

- Cable USB*1

- Cables de puente*3

Conecta el pin S del módulo al Digital 3 de la placa V4.0, conecta el pin negativo a GND, y el pin positivo a 5V.

![Ilustración del diagrama de conexión](../media/e9e7ba383738c3b6be85a1f3c97e5385.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
int buzzer=3;//set digital IO pin of the buzzer
void setup()
{
pinMode(buzzer,OUTPUT);// set digital IO pin pattern, OUTPUT to be output
}
void loop()
{ unsigned char i,j;//define variable
while(1)
{ for(i=0;i<80;i++)// output a frequency sound
{ digitalWrite(buzzer,HIGH);// sound
delay(1);//delay1ms
digitalWrite(buzzer,LOW);//not sound
delay(1);//ms delay
}
for(i=0;i<100;i++)// output a frequency sound
{
digitalWrite(buzzer,HIGH);// sound
digitalWrite(buzzer,LOW);//not sound
delay(2);//2ms delay
}
}
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Una vez cargado el código en la placa, el zumbador emitirá un sonido.

![Ilustración del resultado de ejemplo](../media/9b29eccd437694e479a836b7da66d500.png)

---

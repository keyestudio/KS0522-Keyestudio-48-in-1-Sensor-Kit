# Lección 34: Transmisor IR digital

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Proyecto 34: ilustración del transmisor IR digital](../media/9fe876a8c857650226cbe2f8a9bead59.png)

## Descripción

El módulo transmisor IR está diseñado para la comunicación por IR, ampliamente usado para operar dispositivos de televisión desde una corta distancia en línea de vista.

Dado que el control remoto por infrarrojos (IR) utiliza luz, requiere línea de vista para operar el dispositivo destino. Sin embargo, la señal puede reflejarse en espejos, al igual que otras fuentes de luz.

Los receptores infrarrojos también suelen tener un ángulo de funcionamiento más o menos limitado, que depende principalmente de las características ópticas del fototransistor.

No obstante, es fácil aumentar el ángulo de operación colocando un objeto transparente mate frente al receptor.

## Especificaciones

- Fuente de alimentación: 3-5V

- Frecuencia central infrarroja: 850nm-940nm

- Ángulo de emisión infrarroja: aproximadamente 20 grados

- Alcance de emisión infrarroja: aproximadamente 1.3m (5V 38Khz)

- Conector: JST PH2.0

- Orificio de montaje: diámetro interior 3.2mm, separación 15mm

## Diagrama de conexión

Primero debes preparar las siguientes piezas antes de la conexión.

- Placa V4.0\*1

- Módulo transmisor IR\*1

- Cable USB\*1

- Cables jumper\*3

Conecta el pin S del módulo al Digital 3 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Ilustración del diagrama de conexión](../media/31c03e9ad144e1124260ff6e0538fe69.jpeg)

## Código de ejemplo 1

```c
int led = 3;
void setup() {
   pinMode(led, OUTPUT);
}
void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
```

En la oscuridad, verás una luz azul intermitente en la pantalla del teléfono al usar la cámara para filmar el LED infrarrojo.

Sube correctamente el código anterior a la placa; el LED del sensor parpadeará en rojo.

A continuación, pasemos a un ejemplo interactivo entre el receptor IR y el módulo transmisor IR.

## Control remoto/Comunicación infrarroja

## Hardware necesario

- Arduino R3 x2

- Receptor IR digital x1

- Módulo transmisor IR x1

Nota: este experimento necesita dos placas microcontroladoras. Un protoboard no reemplaza la segunda placa porque no puede ejecutar el sketch del receptor.

## Configuración de comunicación con dos placas

## Para el transmisor IR

Aviso: Arduino-IR remote solo soporta D3 como transmisor.

![Ilustración para el transmisor IR](../media/08ebf9b37949caf1782e499f49934f1d.png)

## Para el receptor IR

Conecta el pin de señal al puerto D11.

![Ilustración para el receptor IR](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

## Sube el código 2 a la V4.0 conectada al transmisor IR

```c
 #include <IRremote.h>
  IRsend irsend;
 void setup()
 {}
 void loop() {
  irsend.sendRC5(0x0, 8); //send 0x0 code (8 bits)
     delay(200);
  irsend.sendRC5(0x1, 8);
     delay(200); }
```

## Sube el código 3 a la V4.0 conectada al receptor IR

```c
#include <IRremote.h>
 const int RECV_PIN = 11;
 const int LED_PIN = 13;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
 {Serial.begin(9600);
   irrecv.enableIRIn(); // Start the receiver
 }
  void loop()
 {if (irrecv.decode(&results))
   { if ( results.bits > 0 )
     {

       int state;
       if ( 0x1 == results.value )
       {
         state = HIGH;
       }
       else
       {
         state = LOW;
       }
       digitalWrite(LED_PIN, state);
     }
  irrecv.resume();        // prepare to receive the next value
   }}
```

## Resultado

Cuando el módulo receptor IR reciba la señal infrarroja del transmisor IR, el LED D1 del módulo receptor IR parpadeará.

Cuando el módulo receptor IR reciba la señal infrarroja del transmisor IR, el LED D1 del módulo receptor IR parpadeará.

![Ilustración del resultado](../media/4d73a7178e89de72df7e82a147778ae9.png)

---

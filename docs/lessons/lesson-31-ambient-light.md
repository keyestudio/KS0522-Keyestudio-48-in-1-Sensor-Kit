# Lección 31: Luz ambiental

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Ilustración del Proyecto 31: Luz ambiental](../media/3eda1bbb84995dc2195a0406f1b0c196.jpeg)

## Descripción

En algún momento querrás medir el brillo ambiente con mayor precisión que con tu fiable fotorresistor sin añadir complejidad a tu proyecto. Cuando llegue ese día, hazte con un sensor de luz ambiental TEMT6000.

El TEMT6000 está diseñado para adaptarse a la sensibilidad del ojo humano, aunque se ha observado que rinde por debajo de lo esperado en condiciones de poca luz. Sin embargo, funciona muy bien reaccionando a cambios muy pequeños en un amplio rango de luminosidad. Debido a que está pensado para imitar al ojo humano, no responde bien a la luz IR o UV, así que tenlo en cuenta al usarlo en tu proyecto.

## Especificaciones

- Voltaje de alimentación: +5VDC 50mA

- Tamaño: 36.5\*16mm

- Peso: 4g

## Diagrama de conexión

Antes de la conexión, prepara las siguientes piezas.

- Placa V4.0\*1

- Sensor de luz ambiental TEMT6000\*1

- Cable USB\*1

- Cables jumper\*3

Es una pieza increíblemente simple: basta con conectar alimentación y masa, y el pin de señal al puerto de entrada analógica. Una vez conectado, el sensor dará como salida un voltaje analógico que aumenta cuando hay más luz. Puedes alimentarlo con 3.3V si lo deseas; el valor de salida solo será mucho más bajo.

![Ilustración del diagrama de conexión](../media/dae046a9efbeea661b9b6a2ab632fcbc.jpeg)

## Código de ejemplo

No puede ser más sencillo que esto: simplemente informa el valor leído por el sensor al monitor serie: 0-1023, donde 1023 es muy brillante y 0 es muy oscuro.

```c
///////////////////////////////////////////////////////////////
int temt6000Pin = 0;
void setup() {
 Serial.begin(9600);
}
void loop() {
 int value = analogRead(temt6000Pin);
 Serial.println(value);
 delay(100); //only here to slow down the output so it is easier to read
}
///////////////////////////////////////////////////////////////
```

## Ejemplo de resultado

Con el cableado correcto y habiendo subido el código anterior, abre el monitor serie del software de Arduino.

![Ilustración del resultado de ejemplo](../media/ea9ab82076983cc965fe016297b6ad76.png)

Luego cubre el sensor con la mano o con un papel; la luz se debilita y finalmente verás que el valor mostrado en el monitor disminuye.

![Ilustración del resultado de ejemplo](../media/846828c9af69a9823ca7218157cc181e.jpeg)

---

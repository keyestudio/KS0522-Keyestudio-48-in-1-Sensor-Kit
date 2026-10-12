# Lección 24: Humedad del suelo

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / placa ATmega328P compatible con Arduino Uno

![Proyecto 24: Ilustración del sensor de humedad del suelo](../media/d1041a8e2cbfca69c5d8bbd9ba7d4f92.jpeg)

## Descripción

Este es un sencillo sensor de humedad del suelo diseñado para detectar la humedad del suelo. Si el suelo carece de agua, el valor analógico que devuelve el sensor disminuirá; de lo contrario, aumentará.

Si usas este sensor para crear un dispositivo de riego automático, podrá detectar si tu planta tiene sed y evitar que se marchite cuando salgas.

Combinar este sensor con un controlador Arduino puede hacer que tu planta esté más cómoda y que tu jardín sea más inteligente.

El módulo sensor de humedad del suelo no es tan complicado como podrías pensar, así que si necesitas detectar la humedad del suelo en tu proyecto, será una excelente opción.

El sensor está equipado con dos sondas que se insertan en la tierra. Si la corriente atraviesa el suelo, el sensor obtendrá un valor de resistencia leyendo los cambios de corriente entre las dos sondas y luego convertirá ese valor de resistencia en contenido de humedad.

A mayor humedad (menor resistencia), mayor conductividad tiene el suelo.

La superficie del sensor ha pasado por un proceso de metalización para prolongar su vida útil. Insértalo en el suelo y luego utiliza el convertidor AD para leerlo. Con la ayuda de este sensor, la planta puede recordarte: necesito agua.

## Especificación

- Tensión de alimentación: 3.3V o 5V

- Corriente de trabajo: ≤ 20mA

- Voltaje de salida: 0-2.3V (cuando el sensor está totalmente sumergido en agua, el voltaje será 2.3V)  
  A mayor humedad, mayor será el voltaje de salida.

- Tipo de sensor: salida analógica

- Interfaz: Pin1- señal, Pin2- GND, Pin3 - VCC

## Diagrama de conexión

Conecta el pin S del módulo al Analog A0 de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.

![Diagrama de conexión ilustración](../media/b1685a438f171f4bbb3cd8d1b1782bb1.jpeg)

## Código de ejemplo

Copia y pega el siguiente código en el software de Arduino.

```c
////////////////////////////////////////////////////////////////////
/*
  # Example code for the moisture sensor
  # Connect the sensor to the A0(Analog 0) pin on the Arduino board
  # the sensor value description
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
*/
void setup(){
  Serial.begin(57600);
}
void loop(){
  Serial.print("Moisture Sensor Value:");
  Serial.println(analogRead(0));
  delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Resultado de ejemplo ilustración](../media/1200f0f53ca0758afc505c475ce75e68.png)

Una vez hechas las conexiones y alimentado el circuito, sube correctamente el código, luego abre el monitor serie y ajusta la velocidad en baudios a 57600, verás el valor. Cuando el sensor detecta humedad, el valor cambiará de forma correspondiente. Mostrado a continuación.

![Resultado de ejemplo ilustración](../media/cb240ae7199f877c17b9ac3a4d9d6ced.jpeg)

---

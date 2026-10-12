# Lección 30: Detección de presión

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / Placa compatible con Arduino Uno ATmega328P

![Ilustración del proyecto 30: Detección de presión](../media/313f11bf4a7f52ac903c78976fe1e633.jpeg)

## Descripción

Este sensor utiliza un nuevo material nano sensible a la presión flexible con almohadilla de película ultrafina. Tiene funciones de impermeabilidad y detección de presión.

Cuando el sensor detecta la presión externa, la resistencia del sensor cambiará.

Por lo tanto, usando el circuito, puede convertir la señal de presión que percibe el cambio de presión en la señal eléctrica correspondiente de salida.

De esta manera, podemos obtener las condiciones de cambio de presión detectando los cambios en la señal.

## Parámetros

- Voltaje de trabajo：DC 3.3V—5V

- Rango：0-10KG

- Espesor：＜0.25mm

- Punto de respuesta：＜20g

- Repetibilidad：＜±5.8%（50% carga）

- Precisión：±2.5%（85% intervalo de rango）

- Durabilidad：＞100000 veces

- Resistencia inicial：＞100MΩ（sin carga）

- Tiempo de respuesta：＜1ms

- Tiempo de recuperación：＜15ms

- Temperatura de trabajo：﹣20℃—60℃

## Diagrama de conexión

Primero necesita preparar las siguientes piezas antes de la conexión.

- Placa V4.0\*1

- Sensor de presión\*1

- Cable USB\*1

- Cable jumper\*3

Conecta el pin S del módulo al A0 analógico de la placa V4.0, conecta el pin negativo al puerto GND y el pin positivo al puerto 5V.  
![Ilustración del diagrama de conexión](../media/3325303180f71db75d9e13acc5036d8f.jpeg)

## Código de ejemplo

Copia y pega el código siguiente en el software de Arduino.

```c
///////////////////////////////////////////////////////////////
int s_pin = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(s_pin,INPUT);

}

void loop()
{
  Serial.println(analogRead(s_pin));
  delay(500);
}
///////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

Con el cableado correcto y después de subir el código, abre el monitor serie en el software de Arduino.

Luego, presiona el sensor con la mano con firmeza; el valor mostrado en el monitor aumentará.

![Ilustración del resultado de ejemplo](../media/a6c4be8596a0048cb5f3b2f1612241bd.png)

![Ilustración del resultado de ejemplo](../media/e055d2749b14c62b92c22496a3d1f96a.jpeg)

---

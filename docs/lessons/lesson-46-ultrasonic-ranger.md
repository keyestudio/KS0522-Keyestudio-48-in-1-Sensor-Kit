# Lección 46: Medidor ultrasónico

> **Kit:** Keyestudio 48-en-1 Kit de Sensores  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 46: ilustración del medidor ultrasónico](../media/c170155a5fb03abdc10866e25e3670b2.jpeg)

## Descripción

Como el ultrasonido tiene fuerte directividad, bajo consumo de energía y gran alcance de propagación en el medio, se utiliza comúnmente en la medición de distancias, como telémetros e instrumentos de medición de posición.

El módulo detector ultrasónico puede proporcionar una distancia de detección sin contacto de 2cm-450cm, y su precisión de medición es de hasta 3mm, muy buena para satisfacer los requisitos normales.

El módulo incluye un transmisor y receptor ultrasónicos, así como el circuito de control correspondiente.

## Esquema de funcionamiento

La secuencia de medición del HC-SR04 se muestra a continuación:

![Esquema de funcionamiento ilustración](../media/a7b0fc57b2e387962071da618153ad68.jpeg)

1\. Primero poner TRIG en bajo, y luego activarlo con una señal de nivel alto de al menos 10us;

2\. Tras el disparo, el módulo transmitirá automáticamente ocho ondas cuadradas de 40KHZ, y detectará automáticamente si hay una señal de retorno.

3\. Si se recibe una señal de retorno, ECHO saldrá a nivel alto; la duración de este nivel alto es en realidad el tiempo desde la emisión hasta la recepción del ultrasonido.
$$
Distancia = Duración\ del\ nivel\ alto * 340m/s * 0.5
$$

## Parámetros

- Tensión de trabajo: 5 V DC

- Corriente de trabajo：15mA

- Rango de detección：2-450cm

- Ángulo de detección：15 grados

- Pulso de disparo de entrada：10us Nivel TTL

- Señal de eco de salida： salida señal de nivel TTL(HIGH)，proporcional a la distancia.

## Diagrama de pines

![Diagrama de pines ilustración](../media/c03e563bcd19796b483156724bae174a.png)

## Diagrama de conexión

Primero, necesita preparar los siguientes componentes:

- Placa V4.0\*1

- Sensor ultrasónico\*1

- Cable USB\*1

- Cable de conexión\*4

A continuación, consulte la siguiente tabla de conexión:

![Diagrama de conexión ilustración](../media/e708c019b57984a07feb241672793982.jpeg)

Nota: D4, D5 son los pines digitales 4 y 5.

Puede referirse al diagrama de conexión que se muestra a continuación:

![Diagrama de conexión ilustración](../media/b5b964743eac977e687c454b64e061fa.jpeg)

Después de conectar correctamente, puede utilizarlo para medir la distancia, mostrando el valor de distancia en el monitor serie.

## Código de prueba

Copie y pegue el siguiente código de prueba en el software Arduino

```c
///////////////////////////////////////////////////////////////////////////////
int inputPin=4; // define ultrasonic signal receiver pin ECHO to D4
int outputPin=5; // define ultrasonic signal transmitter pin TRIG to D5
 void setup()
{
Serial.begin(9600);
pinMode(inputPin, INPUT);
pinMode(outputPin, OUTPUT);

}
void loop()
{
digitalWrite(outputPin, LOW); delayMicroseconds(2);
digitalWrite(outputPin, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
delayMicroseconds(10);
digitalWrite(outputPin, LOW);
int distance = pulseIn(inputPin, HIGH); // Read receiver pulse time
distance= distance/58; // Transform pulse time to distance
Serial.println(distance); //Output distance
delay(50);
}
///////////////////////////////////////////////////////////////////////////////
```

## Resultado de ejemplo

![Resultado de ejemplo ilustración](../media/0dcff2ae88366ce40190b77f25d271d7.png)

Después de subir correctamente el código a la placa V4.0, abra el monitor serie. Al colocar un objeto frente al sensor ultrasónico (desde cerca y desde lejos), detectará la distancia del objeto. El valor se mostrará en el monitor como se muestra a continuación.

![Resultado de ejemplo ilustración](../media/1dbca5dc233994f6923601d942fadba6.png)

![Resultado de ejemplo ilustración](../media/dcd49cc72e7a9f993083af7625d240db.png)

---

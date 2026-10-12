# Lección 42: Sensor de actitud

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Keyestudio V4.0 / Placa compatible con Arduino Uno ATmega328P

![Proyecto 42: ilustración del sensor de actitud](../media/8eb8d16c5e76e50a6609678130a9ee29.jpeg)

## Introducción

**Aviso de compatibilidad.** La lista de componentes etiqueta esta placa como APDS-9930, pero el siguiente ejemplo legado está orientado a un APDS-9960 y utiliza `SparkFun_APDS9960`. Comprueba la marcación del CI en el módulo real antes de subir este boceto; no uses este ejemplo con una placa APDS-9930. El APDS-9930 en un paquete de 8 pines puede proporcionar el sensor de luz ambiental compatible con la interfaz I2C y el sensor de proximidad con LED infrarrojo.

El sensor de proximidad, completamente ajustado, puede detectar objetos a 100 mm y exime los requisitos de calibración de fábrica de equipos terminales y subcomponentes.

Desde la luz solar intensa hasta una habitación oscura, la función de detección de proximidad del sensor puede operar correctamente.

Este módulo añade una microlente óptica que puede proporcionar transmisión y recepción eficientes de energía infrarroja, lo que puede reducir el consumo de energía general.

Además, su máquina de estados interna puede poner el dispositivo en un modo de bajo consumo, logrando un consumo medio muy bajo.

## Parámetros

- Voltaje de funcionamiento：CC 3.3-3.8V

- Corriente de salida：0-20mA

- Rango de temperatura：-40℃—85℃

## Características

1. Módulo óptico integrado con ALS, LED infrarrojo y detector de proximidad;

2. Hasta 16 bits de resolución;

3. Alta sensibilidad en operación detrás de vidrio oscuro;

4. Rendimiento de baja lúmenes de 0.01 lux;

5. Detección de proximidad, completamente calibrada para detección a 100 mm;

6. Integra LED infrarrojo y controlador síncrono de LED;

7. Elimina la calibración de fábrica para sensores de proximidad;

8. Temporizador de espera programable, consumo en estado de espera - 90μA (valor típico);

9. Rango programable desde 2.7 milisegundos hasta 8 segundos;

10. Compatible con interfaz I2C, hasta 400kHz (modo rápido I2C);

11. Pin de interrupción dedicado;

12. Modo de suspensión consumo - 2.2μA (valor típico).

## Diagrama de conexión

Primero necesita preparar las siguientes piezas:

- Placa V4.0\*1

- Sensor de actitud\*1

- Cable USB\*1

- Cables jumper\*5

Conecta el pin INT del sensor al puerto Digital 2 de la placa V4.0, el pin SCL al puerto Analog A5, el pin SDA al puerto Analog A4; conecta el pin 3V3 al puerto 3V3, y el pin GND al puerto GND.

![Diagrama de conexión ilustración](../media/c906c4e8a06998118eac5e3b981386d6.jpeg)

## Ejemplo de código

**¡IMPORTANTE!**: ¡El APDS-9960 sólo puede aceptar 3.3V!

## Conexiones de hardware

| Pin Arduino | Placa APDS-9960 | Función  |
| :---------: | :-------------: | :-------: |
|    3.3V     |       VCC       | Alimentación |
|     GND     |       GND       |   Masa    |
|     A4      |       SDA       | Datos I2C |
|     A5      |       SCL       | Reloj I2C |
|     D2      |       INT       | Interrupción |
|     D13     |        -        |   LED     |

**Recursos:** Incluir Wire.h y SparkFun_APDS-9960.h

**Especificaciones del entorno de desarrollo:** Escrito en Arduino 1.0.5

Copia y pega el siguiente código en el software de Arduino.

```c
#include <Wire.h>
#include <SparkFun_APDS9960.h>

// Pins
#define APDS9960_INT    2  // Needs to be an interrupt pin
#define LED_PIN         13 // LED for showing interrupt

// Constants
#define LIGHT_INT_HIGH  1000 // High light level for interrupt
#define LIGHT_INT_LOW   10   // Low light level for interrupt

// Global variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
int isr_flag = 0;
uint16_t threshold = 0;

void setup() {
  // Set LED as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(APDS9960_INT, INPUT);
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("-------------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - Light Interrupts"));
  Serial.println(F("-------------------------------------"));
  // Initialize interrupt service routine
  attachInterrupt(0, interruptRoutine, FALLING);
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  // Set high and low interrupt thresholds
  if ( !apds.setLightIntLowThreshold(LIGHT_INT_LOW) ) {
    Serial.println(F("Error writing low threshold"));
  }
  if ( !apds.setLightIntHighThreshold(LIGHT_INT_HIGH) ) {
    Serial.println(F("Error writing high threshold"));
  }
  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }
  // Read high and low interrupt thresholds
  if ( !apds.getLightIntLowThreshold(threshold) ) {
    Serial.println(F("Error reading low threshold"));
  } else {
    Serial.print(F("Low Threshold: "));
    Serial.println(threshold);
  }
  if ( !apds.getLightIntHighThreshold(threshold) ) {
    Serial.println(F("Error reading high threshold"));
  } else {
    Serial.print(F("High Threshold: "));
    Serial.println(threshold);
  }
  // Enable interrupts
  if ( !apds.setAmbientLightIntEnable(1) ) {
    Serial.println(F("Error enabling interrupts"));
  }
  // Wait for initialization and calibration to finish
  delay(500);
}
void loop() {
  // If interrupt occurs, print out the light levels
  if ( isr_flag == 1 ) {

    // Read the light levels (ambient, red, green, blue) and print
    if (  !apds.readAmbientLight(ambient_light) ||
          !apds.readRedLight(red_light) ||
          !apds.readGreenLight(green_light) ||
          !apds.readBlueLight(blue_light) ) {
      Serial.println("Error reading light values");
    } else {
      Serial.print("Interrupt! Ambient: ");
      Serial.print(ambient_light);
      Serial.print(" R: ");
      Serial.print(red_light);
      Serial.print(" G: ");
      Serial.print(green_light);
      Serial.print(" B: ");
      Serial.println(blue_light);
    }
    // Turn on LED for a half a second
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);

    // Reset flag and clear APDS-9960 interrupt (IMPORTANT!)
    isr_flag = 0;
    if ( !apds.clearAmbientLightInt() ) {
      Serial.println("Error clearing interrupt");
    }
  }
}
void interruptRoutine() {
  isr_flag = 1;
}
```

Nota: antes de compilar el código, recuerda colocar la biblioteca en el directorio libraries del IDE de Arduino. De lo contrario, la compilación fallará.

## Resultado de ejemplo

![Resultado de ejemplo ilustración](../media/2a30729fa77874e4e61f51d2bb8e62c1.png)

Después de subir el código, abre el monitor serie y ajusta la velocidad a 9600 baudios.

![Resultado de ejemplo ilustración](../media/935c7035ef43f54ca65eaa49bbaf5e98.jpeg)

---

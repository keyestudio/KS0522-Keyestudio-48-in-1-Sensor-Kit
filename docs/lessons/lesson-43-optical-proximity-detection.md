# Lección 43: Detección óptica de proximidad

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 43: ilustración de detección óptica de proximidad](../media/4085d5742012b8647b52c537b82974ff.jpeg)

## Introducción

**Aviso de compatibilidad.** El texto antiguo identifica este módulo como TMD27713, mientras que el boceto siguiente está dirigido al APDS-9930. Confirme el marcado del CI y utilice una biblioteca correspondiente antes de cargar.

Es un sensor triple integrado con sensor de luz ambiental, sensor de proximidad y LED infrarrojo.

Por un lado, se utiliza para detectar la luminosidad ambiental actual (ALS). Puede, en función de la luminosidad ambiental actual, ajustar automáticamente el brillo del retroiluminado mediante ajuste por software. De este modo el brillo del retroiluminado puede suavizarse para proteger la vista y lograr un efecto de ahorro de energía.

Otra función es la de sensor de proximidad (PROX). El sensor integra transmisor/receptor y minimiza el diseño; además, el diseño e instalación no tienen más restricciones de espacio y, en parte, la estructura es relativamente simple.

## Parámetros

- Tensión de funcionamiento：CC 3.3V

- Distancia de detección：100mm

- Modo de comunicación：IIC

- Rango de temperatura：-30℃ a 85℃

## Diagrama de conexión

Primero necesita preparar las siguientes piezas:

- Placa V4.0\*1

- Sensor TMD27713\*1

- Cable USB\*1

- Cables jumper\*5

Conecte el pin INT del sensor al puerto Digital 2 de la placa V4.0, el pin SCL al puerto Analógico A5, el pin SDA al puerto Analógico A4; conecte el pin VCC al puerto 3V3, el pin GND al puerto GND.

![Ilustración del diagrama de conexión](../media/c9319e0f5116f416380d6b3c9ddc608c.jpeg)

## Código de ejemplo

Prueba las capacidades de interrupción por proximidad del APDS-9930.

Configura el APDS-9930 mediante I2C y espera una interrupción externa basada en condiciones de proximidad alta o baja. Mueva la mano cerca del sensor y observe el LED en el pin 13.

## Conexiones de hardware

**IMPORTANTE**: ¡El APDS-9930 solo acepta 3.3V!

| Pin Arduino | Placa APDS-9930 | Función  |
| :---------: | :-------------: | :-------: |
|    3.3V     |       VCC       | Alimentación   |
|     GND     |       GND       | Tierra   |
|     A4      |       SDA       | Datos I2C  |
|     A5      |       SCL       | Reloj I2C |
|      2      |       INT       | Interrupción |
|     13      |        -        |    LED    |

**Recursos**: Incluir Wire.h y APDS9930.h

**Especificaciones del entorno de desarrollo**: Escrito en Arduino 1.0.5

Copie y pegue el código a continuación en el software de Arduino.

```c
#include <Wire.h>
#include <APDS9930.h>

// Pins
#define APDS9930_INT    2  // Needs to be an interrupt pin
#define LED_PIN         13 // LED for showing interrupt

// Constants
#define PROX_INT_HIGH   600 // Proximity level for interrupt
#define PROX_INT_LOW    0  // No far interrupt

// Global variables
APDS9930 apds = APDS9930();
float ambient_light = 0; // can also be an unsigned long
uint16_t ch0 = 0;
uint16_t ch1 = 1;
uint16_t proximity_data = 0;
volatile bool isr_flag = false;

void setup() {

  // Set LED as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(APDS9930_INT, INPUT);

  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("------------------------------"));
  Serial.println(F("APDS-9930 - ProximityInterrupt"));
  Serial.println(F("------------------------------"));

  // Initialize interrupt service routine
  attachInterrupt(digitalPinToInterrupt(APDS9930_INT), interruptRoutine, FALLING);

  // Initialize APDS-9930 (configure I2C and initial values)
  if (apds.init()) {
    Serial.println(F("APDS-9930 initialization complete"));
  }
  else {
    Serial.println(F("Something went wrong during APDS-9930 init!"));
  }

  // Adjust the Proximity sensor gain
  if (!apds.setProximityGain(PGAIN_2X)) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }

  // Set proximity interrupt thresholds
  if (!apds.setProximityIntLowThreshold(PROX_INT_LOW)) {
    Serial.println(F("Error writing low threshold"));
  }
  if (!apds.setProximityIntHighThreshold(PROX_INT_HIGH)) {
    Serial.println(F("Error writing high threshold"));
  }

  // Start running the APDS-9930 proximity sensor (interrupts)
  if (apds.enableProximitySensor(true)) {
    Serial.println(F("Proximity sensor is now running"));
  }
  else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

  // Start running the APDS-9930 light sensor (no interrupts)
  if (apds.enableLightSensor(false)) {
    Serial.println(F("Light sensor is now running"));
  }
  else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

#ifdef DUMP_REGS
  /* Register dump */
  uint8_t reg;
  uint8_t val;

  for (reg = 0x00; reg <= 0x19; reg++) {
    if ((reg != 0x10) && \
      (reg != 0x11))
    {
      apds.wireReadDataByte(reg, val);
      Serial.print(reg, HEX);
      Serial.print(": 0x");
      Serial.println(val, HEX);
    }
  }
  apds.wireReadDataByte(0x1E, val);
  Serial.print(0x1E, HEX);
  Serial.print(": 0x");
  Serial.println(val, HEX);
#endif

}

void loop() {

  // If interrupt occurs, print out the proximity level
  if (isr_flag) {

    // Read proximity level and print it out
    if (!apds.readProximity(proximity_data)) {
      Serial.println("Error reading proximity value");
    }
    else {
      Serial.print("Proximity detected! Level: ");
      Serial.print(proximity_data);
      Serial.print("   ");
    }
    apds.readAmbientLightLux(ambient_light);
    // Read the light levels (ambient, red, green, blue)
    if (!apds.readAmbientLightLux(ambient_light) ||
      !apds.readCh0Light(ch0) ||
      !apds.readCh1Light(ch1)) {
      Serial.println(F("Error reading light values"));
    }
    else {
      Serial.print(F("Ambient: "));
      Serial.print(ambient_light);
      Serial.print(F("  Ch0: "));
      Serial.print(ch0);
      Serial.print(F("  Ch1: "));
      Serial.println(ch1);
    }

    // Turn on LED for a half a second
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);

    // Reset flag and clear APDS-9930 interrupt (IMPORTANT!)
    isr_flag = false;
    if (!apds.clearProximityInt()) {
      Serial.println("Error clearing interrupt");
    }

  }
}

void interruptRoutine() {
  isr_flag = true;
}
```

Nota: antes de compilar el código, recuerde colocar la biblioteca en el directorio libraries del IDE de Arduino. De lo contrario, la compilación fallará.

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/f2c369c253c3b5fd8cf2c9df39f1c01a.png)

Probado con Arduino-1.8.2; luego abra el Monitor serie, podrá ver los datos como se muestra en la figura a continuación.

![Ilustración del resultado de ejemplo](../media/607fe1d8c324c14c06492d96d60eb0ca.png)

---

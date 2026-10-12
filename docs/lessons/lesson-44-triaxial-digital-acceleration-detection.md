# Lección 44: Detección de Aceleración Digital Triaxial

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Placa Keyestudio V4.0 compatible con Arduino Uno (ATmega328P)

![Proyecto 44: Ilustración de detección de aceleración digital triaxial](../media/2a26949601eb888348b798711fe1151e.jpeg)

## Introducción

MMA8452Q es un sensor de aceleración de tres ejes, capacitivo, de micromáquina inteligente y de bajo consumo con resolución de 12 bits.

Este sensor de aceleración tiene un rendimiento integrado completo, con opciones de programación flexibles por el usuario y configuración de dos pines de interrupción.

La función de interrupción integrada puede ahorrar el consumo general de energía y eliminar la carga de sondear constantemente los datos en el procesador principal.

Además, MMA8452Q tiene un rango dinámico opcional de ±2g / ±4g / ±8g, que puede emitir datos con filtrado paso alto y datos sin filtrar en tiempo real.

Este dispositivo puede configurar una función integrada para generar una señal de interrupción por activación inercial, lo que permite que MMA8452Q mantenga un modo de bajo consumo en estado estático mientras monitoriza el evento.

## Parámetros de rendimiento

- Tensión de alimentación：1.95 V a 3.6 V

- Tensión de interfaz：1.6 V a 3.6 V

- Rango dinámico opcional ±2g/±4g/±8g

- Rango de tasa de salida de datos (ODR): 1.56Hz a 800Hz

- Ruido：99μg/√Hz

- Salidas digitales de 12 bits y 8 bits;

- Interfaz de salida digital I2C (hasta 2.25MHz cuando la resistencia pull-up es de 4.7kΩ);

- Dos pines de interrupción programables aplicados a seis fuentes de interrupción;

- Tres canales integrados de detección de movimiento: detección de caída libre, detección de pulso, detección de sacudida;

- Detección de dirección (transversal/longitudinal) con compensación de retardo configurada;

- Arranque automático y ODR en reposo automático que pueden alterarse automáticamente;

- Los datos de filtrado paso alto pueden exportarse en tiempo real;

- Consumo de energía: 6μA – 165μA

## Diagrama de conexión

Primero necesita preparar las siguientes piezas:

- Placa V4.0*1

- Sensor MMA8452Q*1

- Cable USB*1

- Cables jumper*4

Conecte el pin SCL al puerto Analógico A5, el pin SDA al puerto Analógico A4; conecte el pin positivo al puerto 3V3 y el pin negativo a GND.

![Diagrama de conexión ilustración](../media/fdd68f7da45d46e65f42918eac68a2f3.jpeg)

## Código de ejemplo

Copie y pegue el código siguiente en el software de Arduino.

```c
#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library
// Begin using the library by creating an instance of the MMA8452Q
//  class. We'll call it "accel". That's what we'll reference from
//  here on out.
MMA8452Q accel;
// The setup function simply starts serial and initializes the
//  accelerometer.
void setup()
{
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");

  // Choose your adventure! There are a few options when it comes
  // to initializing the MMA8452Q:
  //  1. Default init. This will set the accelerometer up
  //     with a full-scale range of +/-2g, and an output data rate
  //     of 800 Hz (fastest).
  accel.init();
  //  2. Initialize with FULL-SCALE setting. You can set the scale
  //     using either SCALE_2G, SCALE_4G, or SCALE_8G as the value.
  //     That'll set the scale to +/-2g, 4g, or 8g respectively.
  //accel.init(SCALE_4G); // Uncomment this out if you'd like
  //  3. Initialize with FULL-SCALE and DATA RATE setting. If you
  //     want control over how fast your accelerometer produces
  //     data use one of the following options in the second param:
  //     ODR_800, ODR_400, ODR_200, ODR_100, ODR_50, ODR_12,
  //     ODR_6, or ODR_1.
  //     Sets to 800, 400, 200, 100, 50, 12.5, 6.25, or 1.56 Hz.
  //accel.init(SCALE_8G, ODR_6);
}

// The loop function will simply check for new data from the
//  accelerometer and print it out if it's available.
void loop()
{
  // Use the accel.available() function to wait for new data
  //  from the accelerometer.
  if (accel.available())
  {
    // First, use accel.read() to read the new variables:
    accel.read();

    // accel.read() will update two sets of variables.
    // * int's x, y, and z will store the signed 12-bit values
    //   read out of the accelerometer.
    // * floats cx, cy, and cz will store the calculated
    //   acceleration from those 12-bit values. These variables
    //   are in units of g's.
    // Check the two function declarations below for an example
    // of how to use these variables.
    printCalculatedAccels();
    //printAccels(); // Uncomment to print digital readings

    // The library also supports the portrait/landscape detection
    //  of the MMA8452Q. Check out this function declaration for
    //  an example of how to use that.
    printOrientation();

    Serial.println(); // Print new line every time.
  }
}

// The function demonstrates how to use the accel.x, accel.y and
//  accel.z variables.
// Before using these variables you must call the accel.read()
//  function!
void printAccels()
{
  Serial.print(accel.x, 3);
  Serial.print("\t");
  Serial.print(accel.y, 3);
  Serial.print("\t");
  Serial.print(accel.z, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.cx, accel.cy,
//  and accel.cz variables.
// Before using these variables you must call the accel.read()
//  function!
void printCalculatedAccels()
{
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.readPL()
// function, which reads the portrait/landscape status of the
// sensor.
void printOrientation()
{
  // accel.readPL() will return a byte containing information
  // about the orientation of the sensor. It will be either
  // PORTRAIT_U, PORTRAIT_D, LANDSCAPE_R, LANDSCAPE_L, or
  // LOCKOUT.
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}
```

Nota: antes de compilar el código, recuerde colocar la biblioteca en el directorio libraries del IDE de Arduino. De lo contrario, la compilación fallará.

## Resultado de ejemplo

![Resultado de ejemplo ilustración](../media/9f81d233c0387bc32d25951abd3a407c.png)

Una vez subido el código y abierto el monitor serie, mostrará la aceleración triaxial del sensor y su estado como se muestra a continuación.

![Resultado de ejemplo ilustración](../media/03421d279e2e961d7b40f645b7576d73.jpeg)

---

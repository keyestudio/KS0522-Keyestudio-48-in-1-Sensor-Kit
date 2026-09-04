# Lesson 43: Optical Proximity Detection

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-42-attitude-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-44-triaxial-digital-acceleration-detection.md) |
| --- | --- | --- |

![Project 43: Optical Proximity Detection illustration](../media/4085d5742012b8647b52c537b82974ff.jpeg)

## Introduction

**Compatibility notice.** The legacy text identifies this module as TMD27713, while the sketch below targets APDS-9930. Confirm the IC marking and use a matching library before uploading.

It is a triple sensor integrated with ambient light, proximity sensor and infrared LED.

For one thing, it is used to detect the current ambient brightness (ALS). It can in accordance with the current ambient brightness automatically adjust the backlight brightness to conform to ambient light by the mean of software adjustment. This way can make backlight brightness soft to protect your vision and to achieve the effect of energy saving.

For another feature we are referred to as proximity sensor function (PROX). Sensor has been integrated transmitter/receiver and minimized the design, besides, design and installation have no more space restrictions, and for part of a structure is relatively simple.

## Parameters

- Working voltage：DC 3.3V

- Detection distance：100mm

- Communication way：IIC communication

- Temperature range：-30℃ to 85℃

## Connection Diagram

Firstly you need to prepare the following parts:

- V4.0 Board\*1

- TMD27713 sensor\*1

- USB Cable\*1

- Jumper Wire\*5

Connect the INT pin of sensor to Digital 2 port of V4.0 board, SCL pin to Analog A5 port, SDA pin to Analog A4 port; Connect VCC pin to 3V3 port, GND pin to GND port.

![Connection Diagram illustration](../media/c9319e0f5116f416380d6b3c9ddc608c.jpeg)

## Sample Code

Tests the proximity interrupt abilities of the APDS-9930.

Configures the APDS-9930 over I2C and waits for an external interrupt based on high or low proximity conditions. Move your hand near the sensor and watch the LED on pin 13.

## Hardware Connections

**IMPORTANT**: The APDS-9930 can only accept 3.3V!

| Arduino Pin | APDS-9930 Board | Function  |
| :---------: | :-------------: | :-------: |
|    3.3V     |       VCC       |   Power   |
|     GND     |       GND       |  Ground   |
|     A4      |       SDA       | I2C Data  |
|     A5      |       SCL       | I2C Clock |
|      2      |       INT       | Interrupt |
|     13      |        -        |    LED    |

**Resources**: Include Wire.h and APDS9930.h

**Development environment specifics**: Written in Arduino 1.0.5

Copy and paste the code below to Arduino software.

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

Note: before compiling the code, do remember to place the library into libraries directory of Arduino IDE. Otherwise, compiling will fail.

## Example Result

![Example Result illustration](../media/f2c369c253c3b5fd8cf2c9df39f1c01a.png)

Tested by Arduino-1.8.2 version software, then open serial monitor, you can see the data as the figure shown below.

![Example Result illustration](../media/607fe1d8c324c14c06492d96d60eb0ca.png)

---

| [← Previous lesson](lesson-42-attitude-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-44-triaxial-digital-acceleration-detection.md) |
| --- | --- | --- |

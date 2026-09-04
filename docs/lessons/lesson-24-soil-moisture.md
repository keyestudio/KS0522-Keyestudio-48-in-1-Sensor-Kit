# Lesson 24: Soil Moisture

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 24: Soil Moisture illustration](../media/d1041a8e2cbfca69c5d8bbd9ba7d4f92.jpeg)

## Description

This is a simple soil humidity sensor aimed to detect the soil humidity. If the soil is in lack of water, the analog value output by the sensor will decrease, otherwise, it will increase.

If you use this sensor to make an automatic watering device, it can detect whether your botany is thirsty to prevent it from withering when you go out.

Combine this sensor with Arduino controller can make your plant more comfortable and your garden more smarter.

The soil humidity sensor module is not as complicated as you might think, so if you need to detect the soil in your project, it will be your best choice.

The sensor is set with two probes which are inserted into the soil. If the current goes through the soil, the sensor will get resistance value by reading the current changes between the two probes, then convert the resistance value into moisture content.

The higher moisture (less resistance), the higher conductivity the soil has.

The surface of the sensor has undergone metallization process to prolong its service life. Insert it into the soil and then use the AD converter to read it. With the help of this sensor, the plant can remind of you: I need water.

## Specification

- Power Supply Voltage: 3.3V or 5V

- Working Current: ≤ 20mA

- Output Voltage: 0-2.3V (When the sensor is totally immersed in water, the voltage will be 2.3V)
  The higher humidity, the higher the output voltage.

- Sensor type: Analog output

- Interface: Pin1- signal, Pin2- GND, Pin3 - VCC

## Connection Diagram

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/b1685a438f171f4bbb3cd8d1b1782bb1.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

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

## Example Result

![Example Result illustration](../media/1200f0f53ca0758afc505c475ce75e68.png)

Done wiring and powered up, upload well the code, then open the serial monitor and set the baud rate as 57600, you will see the value. When the sensor detects the moisture, the value will make corresponding changes. Shown below.

![Example Result illustration](../media/cb240ae7199f877c17b9ac3a4d9d6ced.jpeg)

---

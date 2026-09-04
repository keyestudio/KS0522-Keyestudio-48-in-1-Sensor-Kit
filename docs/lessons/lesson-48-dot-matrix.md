# Lesson 48: Dot Matrix

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 48: Dot Matrix illustration](../media/10e87958bbef207075643ae4f5481457.jpeg)

## Introduction

What's better than a single LED? Lots of LEDs! A fun way to make a small display is to use an 8x8 matrix.  This module uses HT16K33 chip to drive an 8x8 dot matrix.

Just need to use the I2C communication port of microcontroller to control the dot matrix, which can save more port resources of microcontroller.  The matrix module comes with a 4Pin header of 2.54mm pin pitch.

You can connect the module to control board for communication using jumper wires.

Besides, it comes with three DIP switches. You can randomly toggle the switch to select the I2C communication address.

## The address settings are as shown below

|   0x70   |          |          |      |   0x71   |          |          |      |   0x72   |          |          |
| :------: | :------: | :------: | ---- | :------: | :------: | :------: | ---- | :------: | :------: | :------: |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 0（OFF） | 0（OFF） | 0（OFF） |      | 1（ON）  | 0（OFF） | 0（OFF） |      | 0（OFF） | 1（ON）  | 0（OFF） |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x73** |          |          |      | **0x74** |          |          |      | **0x75** |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 1（ON）  | 1（ON）  | 0（OFF） |      | 0（OFF） | 0（OFF） | 1（ON）  |      | 1（ON）  | 0（OFF） | 1（ON）  |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x76** |          |          |      | **0x77** |          |          |      |          |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      |          |          |          |
| 0（OFF） | 1（ON）  | 1（ON）  |      | 1（ON）  | 1（ON）  | 1（ON）  |      |          |          |          |

## Technical Details

- Interface: 4Pin header

- Operating voltage: DC 4.5V-5.5V

- Comes with three DIP switches for address selection

- Dimensions：52mm\*34mm\*11mm

- Weight：13.2g

## Hookup Guide

Connect the SCL pin to Analog A5 port, SDA pin to Analog A4 port; Connect VCC pin to 5V port, GND pin to GND port.

![Hookup Guide illustration](../media/e2c09c1a7851f64ad03a027c1aa25a14.jpeg)

## Test Code

Download the library:

```C
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#ifndef _BV
#define _BV(bit) (1<<(bit))
#endif
Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();
uint8_t counter = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("HT16K33 test");
  matrix.begin(0x70);  // pass in the address
}
void loop() {
  // paint one LED per row. The HT16K33 internal memory looks like
  // a 8x16 bit matrix (8 rows, 16 columns)
  for (uint8_t i=0; i<8; i++) {
// draw a diagonal row of pixels

    matrix.displaybuffer[i] = _BV((counter+i) % 16) | _BV((counter+i+8) % 16)  ;
  }
  // write the changes we just made to the display
  matrix.writeDisplay();
  delay(100);
 counter++;
  if (counter >= 16) counter = 0;
}
```

**Note:** before compiling the code, do remember to place the Matrix library folder into directory \\Arduino\\libraries. Otherwise, fail to compile the code.

For example: **C:\\Program Files\\Arduino\\libraries**

## Test Result

Done uploading the code to the board, power on, you should see the 8\*8 matrix displaying a heart image. Shown below.

![Test Result illustration](../media/4a53bb681a3299be450726255f4d56a2.jpeg)

## Settings Method

1. Set the communication address. Refer to the address chart.

The code is set as below.

![Settings Method illustration](../media/187557b09de67c1236bfd6536b0b95ee.png)

![Settings Method illustration](../media/910472d4662d0c1f463f9bedfe4cef74.png)

![Settings Method illustration](../media/165615f73e4c9a49c861f5e17eb333e3.png)

1. Set the display image

You can set the display image in the code shown below.

![Settings Method illustration](../media/4a709cb4583c82f469c179dd6b1cfa71.png)

Place the matrix module as follows:

![Settings Method illustration](../media/10e87958bbef207075643ae4f5481457.jpeg)

Then convert 0x00,0x18,0x24,0x42,0x81,0x99,0x66,0x00 into Binary number:

- `0x00` corresponds to `0 0 0 0 0 0 0 0`.

- `0x18` corresponds to `0 0 0 1 1 0 0 0`.

- `0x24` corresponds to `0 0 1 0 0 1 0 0`.

- `0x42` corresponds to `0 1 0 0 0 0 1 0`.

- `0x81` corresponds to `1 0 0 0 0 0 0 1`.

- `0x99` corresponds to `1 0 0 1 1 0 0 1`.

- `0x66` corresponds to `0 1 1 0 0 1 1 0`.

- `0x00` corresponds to `0 0 0 0 0 0 0 0`.

The first hexadecimal number controls the first column of LEDs.

The second value controls the second column, and so on.

These settings convert each 8-bit hexadecimal value into its binary representation.

The number 0 means LED off, and number 1 means LED on.

The first converted number is controlling the first row of LED on and off, and so on.

![Settings Method illustration](../media/3ba4bb34ddf3ef182c5aa5bc7a309605.png)

---

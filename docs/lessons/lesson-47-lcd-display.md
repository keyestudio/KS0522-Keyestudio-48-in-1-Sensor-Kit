# Lesson 47: LCD Display

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 47: LCD Display illustration](../media/1aa1fd551e180d013633c1fe857c24a6.jpeg)

## Description

This project we are going to drive this 0802 LCD display the text combined with V4.0 board.

The display capacity of LCD is 8x2 characters, and operating voltage of the chip is 4.5～5.5V.

There are two connection method for 0802 LCD displaying the text, respectively 4-bit and 8-bit connection.

You can refer to the related explanation below.

## Interfaces Explanation

| **Interface** | **Pin** | **Explanation**                                              |
| :-----------: | :-----: | ------------------------------------------------------------ |
|       1       |   VSS   | Logic Power Ground                                           |
|       2       |   VDD   | Logic Power                                                  |
|       3       |   V0    | LCD adjustable voltage, connect to the middle pin of 10K potentiometer |
|       4       |   RS    | Data\\ Command option                                        |
|       5       |   RW    | read\\write option                                           |
|       6       |    E    | Enable read\\write, active at HIGH, falling edge lock the data |
|       7       |   DB0   | Data input/output pin                                        |
|       8       |   DB1   | Data input/output pin                                        |
|       9       |   DB2   | Data input/output pin                                        |
|      10       |   DB3   | Data input/output pin                                        |
|      11       |   DB4   | Data input/output pin                                        |
|      12       |   DB5   | Data input/output pin                                        |
|      13       |   DB6   | Data input/output pin                                        |
|      14       |   DB7   | Data input/output pin                                        |
|      15       |  LED-A  | backlight power positive end                                 |
|      16       |  LED-K  | backlight power negative end                                 |

## Hardware Required

Firstly you need to prepare the following parts:

- V4.0 Board × 1
- 0802 LCD × 1
- Rotary potentiometer × 1
- Breadboard × 1
- USB cable × 1
- Jumper wires, as needed
- Dupont wires, as needed

## Connection Diagram

## 4-bit Connection

![4-bit Connection illustration](../media/6b3c862d4b36726275b67b747e6d5df3.jpeg)

## 8-bit Connection

![8-bit Connection illustration](../media/97a92aff5ba45d0f7daaca6307b9a5fd.png)

## Source Code

## For 4-bit Connection

```C
//////////////////////////////////////////////////////////
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11, 12, 6, 7, 4, 5);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(8, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print(" Hello");
  lcd.setCursor(0, 1);
  lcd.print(" world!");
}

void loop() {
}
//////////////////////////////////////////////////////////
```

## For 8-bit Connection

```C
#include <LiquidCrystal.h>

// RS, RW, Enable, D0, D1, D2, D3, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10);

void setup() {
  lcd.begin(8, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ABCDEFGH");
  lcd.setCursor(0, 1);
  lcd.print("12345678");
}

void loop() {
  // The 8-bit display remains static after setup.
}
```

## Example Result

Wire it up well, powered up, upload the above code to the board, adjust the backlight of LCD through rotating the potentiometer, finally you can see the character is displayed on the LCD screen.

If you use the 4-bit connection, you should see the LCD display the character "Hello" on the first line, and the second line display the character "world!" shown as below.

![Example Result illustration](../media/7d2763d65677d2925902ffcc65bf1b12.png)

If using the 8-bit connection, you will see other characters are displayed on the LCD. Shown below.

![Example Result illustration](../media/61002a13397f8041574b375b0032da26.png)

---

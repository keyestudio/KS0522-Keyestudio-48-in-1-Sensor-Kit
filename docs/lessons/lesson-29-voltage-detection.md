# Lektion 29: Spannungsdetektion

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 29: Spannungsdetektion Abbildung](../media/41967398a781944fd64ebd49a9c746fa.jpeg)

## Beschreibung

Da elektronische Produkte vielfältig sind, variiert auch die Versorgungsspannung. Es ist daher notwendig, diese mit einem geeigneten Spannungsdetektionsmodul oder -controller zu erfassen.

Die maximale Eingangsspannung der analogen Schnittstelle des Controllers beträgt 5V, das bedeutet, dass Spannungen größer als 5V nicht gemessen werden können.

Dieses Spannungsdetektionsmodul kann jedoch Spannungen größer als 5 V detektieren.

Es basiert auf einem 5:1 Widerstands-Spannungsteiler. Bei einer analogen Referenz von 5 V darf die Eingangsspannung 25 V nicht überschreiten. Bei einer analogen Referenz von 3,3 V darf die Eingangsspannung 16,5 V nicht überschreiten.

Der AVR-Analog-Digital-Wandler ist 10-Bit, daher beträgt die analoge Auflösung 0,00489 V (5 V / 1023). Mit dem 5:1-Teiler ist die minimale messbare Eingangserhöhung ungefähr 0,02445 V.

Wenn Sie diesen Sensor mit dem Erweiterungsboard über ein 3-poliges Kabel verbinden, kann er nicht nur einfach die Höhe der Versorgungsspannung erfassen und den Ladezustand der Batterie für interaktive Medienprojekte oder Roboter überwachen, sondern auch in Kombination mit einem IIC LCD1602 LCD-Modul die Spannung anzeigen bzw. als Spannungsanzeige fungieren.

## Spezifikation

- Betriebsspannung: 0V-25V DC

- Signaltyp: analoges Signal

## Anschlussdiagramm

Zuerst müssen Sie vor dem Anschluss folgende Teile vorbereiten:

- V4.0-Platine\*1

- Spannungssensor\*1

- USB-Kabel\*1

- Jumper-Kabel\*3

Verbinden Sie den S-Pin des Moduls mit dem analogen A0 des V4.0-Boards, verbinden Sie den negativen Pin mit dem GND-Anschluss, den NC-Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/b8754c45901ff42ba9caadce5db01a3a.jpeg)

## Beispielcode

```c
////////////////////////////////////////////////////////////////////
int analogpin=0;     // Define analogpin as analog port 0
int val,val5;       //Define variables val,val5
int val2=0;      //Define variables val2
int val3=0;     //Define variables val3
int val4=0;    //Define variables val4

void setup()
{
    Serial.begin(9600);     //Set baud rate of 9600
}
void loop()
{
    int val,val5;
    float val1;
    val=analogRead(analogpin);     //Read the value of the analog port and assign it to the variable val
    val1=val/3.9;
    val5=(int)val1;
    val3=val5/100;
    val2=(val5%100)/10;
    val4=val5%10;
    Serial.print("$CLEAR\r\n");      //clear the screen
    Serial.print("$GO 1 1\r\n");
    Serial.print("$PRINT Voltage:\r\n");
    Serial.print("$GO 1 9\r\n");
    Serial.print("$PRINT ");
Serial.print(val3);        //The serial port prints the value of the variable val3
Serial.print(val2);      //The serial port prints the value of the variable val2
    Serial.print(".");               //The serial port prints out a point"."
    Serial.print(val4);         //The serial port prints the value of the variable val4
    Serial.println("V");          //The serial port prints out capital “ V”
    delay(100);      //delay 0.1 second
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Abbildung](../media/ac8825bb333757bad26785e58651beb7.png)

Nachdem die obige Verkabelung hergestellt wurde, kompilieren und laden Sie den Code hoch, schalten Sie die Stromversorgung ein und öffnen Sie dann den seriellen Monitor; er gibt den detektierten Spannungswert wie unten gezeigt aus.

![Beispielergebnis Abbildung](../media/af699a83a891ea99d193d5b53bd27fa1.jpeg)

---

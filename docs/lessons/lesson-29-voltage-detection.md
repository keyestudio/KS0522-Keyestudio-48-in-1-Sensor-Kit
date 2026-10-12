# Les 29: Spanningsdetectie

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibele ATmega328P board

![Project 29: Spanningsdetectie illustratie](../media/41967398a781944fd64ebd49a9c746fa.jpeg)

## Beschrijving

Aangezien elektronische producten uiteenlopend zijn, verschilt ook de voedingsspanning. Het is daarom nodig om deze te detecteren met een geschikte spanningsdetectiemodule of controller.

De maximale ingangsspanning van de analoge interface van de controller is 5V, wat betekent dat spanningen hoger dan 5V niet gedetecteerd kunnen worden.

Met deze spanningsdetectormodule kan echter wel spanning boven 5 V worden gemeten.

Deze is gebaseerd op een 5:1 weerstandsspanningsdeler. Met een analoge referentie van 5 V mag de ingangsspanning niet hoger zijn dan 25 V. Met een analoge referentie van 3,3 V mag de ingangsspanning niet hoger zijn dan 16,5 V.

De AVR analoog-naar-digitaal-omzetter is 10-bits, dus de analoge resolutie is 0,00489 V (5 V / 1023). Met de 5:1 deler is de minimaal meetbare ingangsverandering ongeveer 0,02445 V.

Wanneer je deze sensor via een 3Pin-kabel op de uitbreidingskaart aansluit, kan deze niet alleen eenvoudig de grootte van de voedingsspanning detecteren en het batterijniveau van interactieve media of robots bewaken, maar ook gecombineerd worden met een IIC LCD1602 LCD-module om de spanning weer te geven of een spanningsmonitor te maken.

## Specificaties

- Werkspanning: 0V-25V DC

- Signaaltype: analoog signaal

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je aansluit:

- V4.0 board\*1

- Spanningssensor\*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de S-pin van de module met analoge A0 van de V4.0 board, verbind de negatieve pin met de GND-aansluiting, en de NC-pin met de 5V-aansluiting.

![Aansluitschema illustratie](../media/b8754c45901ff42ba9caadce5db01a3a.jpeg)

## Voorbeeldcode

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

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/ac8825bb333757bad26785e58651beb7.png)

Als de bedrading zoals hierboven is uitgevoerd, compileer en upload je de code en zet je het bord onder spanning. Open vervolgens de seriële monitor; deze geeft de gedetecteerde spanningswaarde zoals hieronder weer.

![Voorbeeldresultaat illustratie](../media/af699a83a891ea99d193d5b53bd27fa1.jpeg)

---

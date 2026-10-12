# Lesson 39: Linear Temperature

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 39: Lineaire temperatuur illustratie](../media/9a9b328cb85401dce3932f047f0979e0.png)

## Inleiding

De LM35 lineaire temperatuursensor is gebaseerd op de halfgeleider LM35 temperatuursensor. Hij kan gebruikt worden om de omgevingstemperatuur te detecteren.

Deze sensor heeft een werkbereik van 0 graden Celsius tot 100 graden Celsius. De gevoeligheid is 10mV per graad Celsius. De uitgangsspanning is evenredig met de temperatuur.

Deze sensor wordt vaak gebruikt als temperatuursensor. Tot de categorieën behoren thermokoppels, platina-weerstandssensoren, thermische weerstanden en halfgeleider-temperatuurchips.

De chip wordt vaak toegepast in thermokoppels voor het meten van hoge temperaturen.

Een platina-weerstandstemperatuursensor wordt gebruikt voor metingen tot 800 graden Celsius, terwijl thermische weerstand- en halfgeleider-temperatuursensoren geschikt zijn voor het meten van temperaturen rond 100–200 graden of lager. Voor eenvoudige toepassingen is een halfgeleider-temperatuursensor geschikt vanwege de goede lineariteit en hoge gevoeligheid.

De LM35 lineaire temperatuursensor kan eenvoudig op een Arduino-shield worden aangesloten.

## Specificaties

- Gevoeligheid: 10mV per graad Celsius

- Functioneel bereik: 0 graden Celsius tot 100 graden Celsius

- Grootte: 30*20mm

- Gewicht: 3g

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat u gaat testen.

- V4.0 Board\*1

- LM35 temperatuursensor\*1

- USB-kabel\*1

- Jumperdraad\*3

Volg vervolgens het aansluitschema en verbind de signaaldraad van de sensor met de A0-poort van het V4.0-board, de negatieve pin met GND en de positieve pin met 5V.

![Aansluitschema illustratie](../media/e2f1fc77bb6b54c35bc3d1a8834cbf6b.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
///////////////////////////////////////////////////////////////
void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
}
 void loop()
{  int val;
    int dat;
    val=analogRead(0);//Connect LM35 on Analog 0
    dat=(500 * val) /1024;;
    Serial.print("Temp:"); //Display the temperature on Serial monitor
    Serial.print(dat);
    Serial.println("C");
    delay(500);
}
///////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/95d0d43a93fd2bf1e9c7248e80edcedc.png)

Sluit alles aan volgens het bovenstaande schema en upload de code naar het bord. Open vervolgens de seriële monitor en stel de baudrate in op 9600.

U ziet de huidige temperatuurwaarde zoals hieronder weergegeven. De waarde kan licht afwijken afhankelijk van de locatie en het weer.

![Voorbeeldresultaat illustratie](../media/8331a0416c8006161b3227e170a3b033.jpeg)

---

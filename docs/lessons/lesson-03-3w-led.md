# Les 03: 3W LED

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / compatibel met Arduino Uno-bord (ATmega328P)

![Project 3: 3W LED illustratie](../media/0b1110577bfde7df3b6aec41d5b21b28.png)

## Beschrijving

Deze LED-module heeft een hoge helderheid omdat de LED-chip die hij draagt 3W is.
Je kunt deze module toepassen in Arduino-projecten, ideaal voor robot- of zoek-
en reddingsplatformtoepassingen.

Bijvoorbeeld kunnen intelligente robots deze module gebruiken voor verlichting.
Let op dat het LED-licht om veiligheidsredenen niet rechtstreeks op menselijke ogen mag worden gericht.

## Specificatie

- Kleurtemperatuur: 6000\~7000K

- Lichtstroom: 180\~210lm

- Stroom: 700\~750mA

- Vermogen: 3W

- Lichthoek: 140 graden

- Werkingstemperatuur: -50\~80℃

- Opslagtemperatuur: -50\~100℃

- Hoog vermogen LED-module, aangestuurd door microcontroller via IO-poort

- IO-type: Digitaal

- Voedingsspanning: 3.3V tot 5V

- Afmeting: 40x28mm

- Gewicht: 6g

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten:

- V4.0 Bord\*1

- 3W LED-module \*1

- USB-kabel\*1

- Jumperkabel\*3

Verbind de S-pin van de module met Digital 13 van het V4.0 bord, verbind de negatieve pin met de GND-poort, de positieve pin met de 5V-poort.

![Aansluitschema illustratie](../media/7ca6e53405c422f3ae9b04ac572b40ef.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
///////////////////////////////////////////////////////////
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
///////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Na het aansluiten en inschakelen, en nadat de code succesvol is geüpload, knipperen zowel de D13-led als de led op de module één seconde aan en één seconde uit, herhalend.

![Voorbeeldresultaat illustratie](../media/edeb5b089be0300c719652badfd269e7.png)

---

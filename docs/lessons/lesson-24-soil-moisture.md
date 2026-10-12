# Les 24: Bodemvochtigheid

> **Set:** Keyestudio 48-in-1 sensorkit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibele ATmega328P-board

![Project 24: Bodemvochtigheid illustratie](../media/d1041a8e2cbfca69c5d8bbd9ba7d4f92.jpeg)

## Beschrijving

Dit is een eenvoudige bodemvochtigheidssensor bedoeld om de vochtigheid van de grond te detecteren. Als de grond water gebrek heeft, zal de door de sensor uitgegeven analoge waarde dalen; anders zal deze stijgen.

Als je deze sensor gebruikt om een automatisch watergeefsysteem te maken, kan hij detecteren of je planten dorst hebben en voorkomen dat ze verwelken wanneer je weg bent.

Door deze sensor te combineren met een Arduino-controller kun je je plant comfortabeler maken en je tuin slimmer.

De bodemvochtigheidssensormodule is niet zo ingewikkeld als je misschien denkt, dus als je in je project de bodem moet controleren, is dit je beste keuze.

De sensor heeft twee probes die in de grond worden gestoken. Als er stroom door de grond loopt, bepaalt de sensor de weerstand door de stroomveranderingen tussen de twee probes te meten en zet die weerstand om in vochtigheidswaarde.

Hoe hoger de vochtigheid (minder weerstand), hoe hoger de geleidbaarheid van de grond.

Het oppervlak van de sensor heeft een metallisatieproces ondergaan om de levensduur te verlengen. Steek hem in de grond en gebruik vervolgens de AD-omzetter om te lezen. Met behulp van deze sensor kan de plant je eraan herinneren: ik heb water nodig.

## Specificaties

- Voedingsspanning: 3.3V of 5V

- Werkstroom: ≤ 20mA

- Uitgangsspanning: 0-2.3V (Wanneer de sensor volledig in water is ondergedompeld, zal de spanning 2.3V zijn)  
  Hoe hoger de vochtigheid, hoe hoger de uitgangsspanning.

- Sensortype: Analoge uitgang

- Aansluiting: Pin1 - signaal, Pin2 - GND, Pin3 - VCC

## Aansluitschema

Verbind de S-pin van de module met Analog A0 van het V4.0-board, verbind de negatieve pin met GND en de positieve pin met 5V.

![Aansluitschema illustratie](../media/b1685a438f171f4bbb3cd8d1b1782bb1.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

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

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/1200f0f53ca0758afc505c475ce75e68.png)

Na het aansluiten en inschakelen, upload de code, open de seriële monitor en stel de baudrate in op 57600, je zult de waarden zien. Wanneer de sensor vocht detecteert, verandert de waarde overeenkomstig. Zie hieronder.

![Voorbeeldresultaat illustratie](../media/cb240ae7199f877c17b9ac3a4d9d6ced.jpeg)

---

# Les 23: Waterniveau

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 23: Illustratie van waterniveau](../media/23f40997b8634be91aed7311eca2dfbb.jpeg)

## Beschrijving

De Keyestudio watersensor is gebruiksvriendelijk, draagbaar en kosteneffectief, en ontworpen om het waterniveau en waterdruppels te identificeren en te detecteren.

Deze kleine sensor kan het volume van waterdruppels of de hoeveelheid water meten via een reeks blootgestelde parallelle geleiders.

## Kenmerken

- soepele conversie tussen waterhoeveelheid en analoge waarde;

- grote flexibiliteit, geeft een basis analoge waarde;

- laag stroomverbruik en hoge gevoeligheid;

- kan rechtstreeks worden aangesloten op een microprocessor of andere logische schakelingen, geschikt voor verschillende ontwikkelborden en controllers zoals Arduino-controllers, STC single-chip microcontrollers, AVR single-chip microcontrollers en meer.

## Specificaties

- Bedrijfsspanning: DC5V

- Bedrijfstroom: ﹤20mA

- Sensortype: Analoog

- Detectiegebied: 40mm x16mm

- Productieproces: FR4 dubbelzijdig getind

- Vormgeving: anti-slip halfmaanvormige inkeping

- Werktemperatuur: 10℃-30℃

- Werkvochtigheid: 10%-90% zonder condensatie

- Gewicht: 3g

- Afmetingen: 65mm x 20mm x 8mm

## Aansluitschema

Verbind de S-pin van de module met analoog A0 van het V4.0-bord, verbind de negatieve pin met GND, en de positieve pin met 5V.

![Illustratie van het aansluitschema](../media/92810e41aea313a15735eecb3a168e2f.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
    int analogPin = 0; //connect water sensor to analog interface 0
int led = 13; //LED to digital interface 13
int val = 0; //define the initial value of variable ‘val’ as 0
int data = 0; //define the initial value of variable ‘data’ as 0
void setup()
{
pinMode(led, OUTPUT); //define led as output pin
Serial.begin(9600); //set baud rate at 9600
}
void loop()
{
val = analogRead(analogPin); //read and assign analog value to variable ’val’
if(val>700){ //decide whether variable ‘val’ is over 700
digitalWrite(led,HIGH); //turn on LED when variable ‘val’ is over 700
}
else{
digitalWrite(led,LOW); //turn off LED when variable ‘val’ is under 700
}
data = val; //variable ’val’ assigns value to variable ‘data’
Serial.println(data); //print variable ‘data’ by Serial.print
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Illustratie van het voorbeeldresultaat](../media/ca727c75f4d4e454c95258d77afdf10e.png)

Nadat bovenstaande stappen zijn uitgevoerd, doen we een test met een laag waterniveau om te zien wat er gebeurt?

Upload de code naar het V4.0-bord, open vervolgens de seriële monitor en stel de baudrate in op 9600.

Wanneer je de sensor op verschillende niveaus in het water plaatst, zie je dat de waarde overeenkomstig verandert.

![Illustratie van het voorbeeldresultaat](../media/8070cf2260fef39e5ec5e18b7a1849cf.jpeg)

Verder kun je een alarmwaarde instellen en een zoemer aansluiten om een alarm te maken.

De LED gaat niet branden zolang het waterniveau de alarmwaarde niet heeft bereikt. Als het waterniveau de alarmwaarde bereikt, zal de LED aangaan en zal de zoemer klinken om alarm te geven.

---

# Les 46: Ultrasone afstandssensor

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 46: Ultrasone afstandssensor illustratie](../media/c170155a5fb03abdc10866e25e3670b2.jpeg)

## Beschrijving

Omdat ultrasoon geluid een sterke richtinggevoeligheid heeft, weinig energie verbruikt en ver door het medium verspreidt, wordt het vaak gebruikt bij afstandsmetingen, zoals afstandsmeter en positie-meetinstrument.

De ultrasone detectormodule kan een contactloze detectieafstand van 2cm–450cm bieden, en de meetnauwkeurigheid is tot 3mm, wat uitstekend voldoet aan normale eisen.

De module bevat een ultrasone zender en ontvanger en de bijbehorende stuurcircuits.

## Werkingsschema

De HC-SR04 meetvolgorde wordt hieronder weergegeven:

![Werkingsschema illustratie](../media/a7b0fc57b2e387962071da618153ad68.jpeg)

1\. Eerst TRIG laag trekken, en vervolgens triggeren met een hoog signaal van minimaal 10us;

2\. Na het triggeren zendt de module automatisch acht 40KHZ rechthoekgolven uit en detecteert automatisch of er een terugkerend signaal is.

3\. Als er een signaal terugkomt, geeft ECHO een hoog niveau uit; de duur van het hoge niveau is in feite de tijd van uitzending tot ontvangst van het ultrasone signaal.
$$
Testafstand = Duur van het hoge niveau * 340m/s * 0.5
$$

## Parameters

- Werkspanning: 5 V DC

- Werkstroom：15mA

- Detectiebereik：2-450cm

- Detectiehoek：15 graden

- Ingang-triggerpuls：10us TTL-niveau

- Uitgang-echo signaal：uitgang TTL-niveausignaal(HIGH)，evenredig met afstand.

## Pinout Diagram

![Pinout-diagram illustratie](../media/c03e563bcd19796b483156724bae174a.png)

## Aansluitschema

Eerst moet je de volgende componenten voorbereiden:

- V4.0 bord\*1

- Ultrasone sensor\*1

- USB-kabel\*1

- Jumperdraad\*4

Raadpleeg vervolgens de volgende aansluittafel:

![Aansluitschema illustratie](../media/e708c019b57984a07feb241672793982.jpeg)

Opmerking: D4、D5 zijn respectievelijk digitale pin 4 en pin 5.

Je kunt verwijzen naar het onderstaande aansluitdiagram:

![Aansluitschema illustratie](../media/b5b964743eac977e687c454b64e061fa.jpeg)

Na correcte aansluiting kun je het gebruiken om de afstand te meten; de afstandswaarde wordt op de monitor weergegeven.

## Testcode

Kopieer en plak de testcode hieronder in de Arduino-software

```c
///////////////////////////////////////////////////////////////////////////////
int inputPin=4; // define ultrasonic signal receiver pin ECHO to D4
int outputPin=5; // define ultrasonic signal transmitter pin TRIG to D5
 void setup()
{
Serial.begin(9600);
pinMode(inputPin, INPUT);
pinMode(outputPin, OUTPUT);

}
void loop()
{
digitalWrite(outputPin, LOW); delayMicroseconds(2);
digitalWrite(outputPin, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
delayMicroseconds(10);
digitalWrite(outputPin, LOW);
int distance = pulseIn(inputPin, HIGH); // Read receiver pulse time
distance= distance/58; // Transform pulse time to distance
Serial.println(distance); //Output distance
delay(50);
}
///////////////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/0dcff2ae88366ce40190b77f25d271d7.png)

Nadat je de code succesvol naar het V4.0 board hebt geüpload, open je de seriële monitor. Wanneer je een object voor de ultrasone sensor plaatst (van dichtbij naar verder weg), detecteert de sensor de afstand tot het object. De waarde wordt in de onderstaande monitor weergegeven.

![Voorbeeldresultaat illustratie](../media/1dbca5dc233994f6923601d942fadba6.png)

![Voorbeeldresultaat illustratie](../media/dcd49cc72e7a9f993083af7625d240db.png)

---

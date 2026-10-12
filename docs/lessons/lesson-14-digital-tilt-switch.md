# Les 14: Digitale kantelschakelaar

> **Kit:** Keyestudio 48-in-1 sensorkit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 14: Digitale kantelschakelaar illustratie](../media/45a40bdcc098c1c4e0efb8246447173c.png)

## Beschrijving

De kantelsensor is een digitale kantelschakelaar. Hij kan worden gebruikt als een eenvoudige kantelschakelaar.

Sluit hem eenvoudig aan op onze IO/Sensor-shield, gemakkelijk voor bedrading. Met een speciale sensor-shield en een Arduino kun je veel interessante en interactieve projecten maken.

## Specificaties

- Voedingsspanning: 3.3V tot 5V

- Interface: Digitaal

- Afmetingen: 30*20mm

- Gewicht: 3g

## Aansluitingsdiagram

Verbind de S-pin van de module met Digital 3 van de V4.0-board, verbind de negatieve pin met de GND-poort en de positieve pin met de 5V-poort.

![Aansluitingsdiagram illustratie](../media/b909cdd6f697779371498723dc1407ab.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
int Led=13;//define LED interface
int Shock=3;//define knock sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED to be output interface
pinMode(Shock,INPUT);//define knock sensor to be output interface
}
void loop()
{
val=digitalRead(Shock);//read the value of interface3 and evaluate it to val
if(val==HIGH)//when the knock sensor detect a signal, LED will be flashing
{
digitalWrite(Led,LOW);
}
else
{
digitalWrite(Led,HIGH);
}
}
```

## Voorbeeldresultaat

Na het aansluiten van de bedrading en het inschakelen, upload je de code correct naar het V4.0-board.

![Voorbeeldresultaat illustratie](../media/d6a0aa9af1e43265114eec8570ac0f3c.png)

Kantel vervolgens de sensor; je zult zien dat de led op de sensor oplicht. Zie hieronder.

![Voorbeeldresultaat illustratie](../media/6c4a144c26675a100bffa806c532736c.png)

---

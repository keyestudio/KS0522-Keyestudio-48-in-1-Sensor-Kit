# Les 17: Reedschakelaar

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P bord

![Project 17: Reedschakelaar illustratie](../media/e580999515f6522eb603ea723bf62173.png)

## Beschrijving

Een reedschakelaar is een speciaal type schakelaar en een hoofdcomponent voor reed-relais en nabuurschakelaars.

Een reedschakelaar bestaat meestal uit twee zachtmagnetische materialen en metalen reed-contacten die van elkaar loskomen wanneer er geen magneet aanwezig is.

Daarnaast zijn sommige reedschakelaars ook voorzien van een extra reed die functioneert als het derde normaal-gesloten contact. Deze reed-contacten zijn ingekapseld in een glazen buis gevuld met inert gas (zoals stikstof en helium) of in een vacuüm glazen buis.

De reeds in de glazen buis zijn parallel geplaatst met overlappende uiteinden. Er wordt een bepaalde ruimte of onderling contact gereserveerd om de normaal-open of normaal-gesloten contacten van de schakelaar te vormen.

Een reedschakelaar kan worden gebruikt voor tellen, begrenzing of andere doeleinden.

Bijvoorbeeld: een kilometer- of snelheidsmeter voor fietsen wordt gerealiseerd door een magneet op het wiel te plakken en de reedschakelaar naast het wiel te monteren.

Je kunt de reedschakelaar ook op een deur monteren voor alarmdoeleinden of als schakelaar.

Reedschakelaars worden veel toegepast in huishoudelijke apparaten, auto’s, communicatie, industrie, gezondheidszorg en beveiliging.

Bovendien kan het ook worden toegepast in andere sensoren en elektrische apparaten zoals vloeistofmeters, deurmagneten, reed-relais, olieniveausensoren en nabuursensoren (magnetische sensoren). Het kan worden gebruikt in risicovolle omgevingen.

## Specificaties

1. Werkspanning: DC 3.3V-5V

2. Werkstroom: ≥20mA

3. Werktemperatuur: －10℃ tot ＋50℃

4. Detectieafstand: ≤10mm

5. IO-interface: 3-aderige interface (-/+/S)

6. Grootte: 30\*20mm

7. Gewicht: 3g

## Aansluitschema

Sluit de S-pin van de module aan op Digital 3 van het V4.0-bord, sluit de negatieve pin aan op GND en de positieve pin op 5V.

![Aansluitschema illustratie](../media/ad39b511b42657baed492704a9c84b13.jpeg)

## Voorbeeldcode

Kopieer en plak onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int buttonpin=3; //define magnetic ring sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED as output interface
pinMode(buttonpin,INPUT);//define magnetic ring sensor as output interface
 }
void loop()
{

val=digitalRead(buttonpin);// read and assign the value of digital interface 3 to val

if(val==HIGH)//When a signal is detected by magnetic ring sensor, LED will flash
{
digitalWrite(Led,HIGH);
}
else
{
digitalWrite(Led,LOW);
}
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Na aansluiting, inschakelen en het succesvol uploaden van de code naar het bord zie je dat de D13-LED op het V4.0-bord brandt.

![Voorbeeldresultaat illustratie](../media/a2f983d5a5b324f55e3c0994458d4cbc.png)

Vervolgens brengen we enkele magneetballetjes dicht bij de sensor. Wanneer de sensor het magnetische veld detecteert, gaat de LED op de sensor branden en gaat de D13-LED uit.

![Voorbeeldresultaat illustratie](../media/ecbec914abc799076513f5c61149b004.png)

---

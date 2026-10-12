# Les 16: Vlamalarm

> **Kit:** Keyestudio 48-in-1 sensorpakket  
> **Printplaat:** Keyestudio V4.0 / Arduino Uno-compatibele ATmega328P-printplaat

![Project 16: Vlamalarm illustratie](../media/35c5a2593df5d4e76865158e790feada.png)

## Beschrijving

Deze vlamsensor kan worden gebruikt om vuur of ander licht met golflengte in het bereik van 760nm \~ 1100nm te detecteren.

In het brandbestrijdingsrobotspel speelt de vlam een belangrijke rol bij het opsporen; het kan dienen als de ogen van de robot om de vuurbron te vinden.

## Specificaties

1. Voedingsspanning: 3.3V tot 5V

2. Detectiebereik: 20cm (4.8V) \~ 100cm (1V)

3. Bereik van de spectrale bandbreedte: 760nm tot 1100nm

4. Bedrijfstemperatuur: -25℃tot 85℃

5. Interface: digitaal

6. Afmetingen: 44*16.7mm

7. Gewicht: 4g

## Aansluitschema

Eerst moet je de volgende onderdelen voorbereiden voordat je gaat aansluiten:

- V4.0-printplaat*1

- Vlamsensor*1

- USB-kabel*1

- Jumperdraad*3

Verbind de D0 pin van de module met Digital 2 van het V4.0-printplaat, verbind de GND pin met de GND-aansluiting en de VCC pin met de 5V-aansluiting.

![Aansluitschema illustratie](../media/a1ee506fc9921c7616349500c258b733.jpeg)

## Voorbeeldcode

Kopieer en plak onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
const int flamePin = 2;     // the number of the flame pin
const int ledPin =  13;      // the number of the LED pin
// variables will change:
int State = 0;         // variable for reading status
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(flamePin, INPUT);
}
void loop(){
  // read the state of the value:
State = digitalRead(flamePin);
  if (State == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Nadat de bedrading is voltooid en de voeding is ingeschakeld, upload je de code correct naar de printplaat.

![Voorbeeldresultaat illustratie](../media/c769453bbd0e1c5fcf6c80cf697030b3.png)

Als je vervolgens een aansteker dicht bij de sensor houdt, zal wanneer de sensor de vlam detecteert, een andere led op de sensor aangaan.

![Voorbeeldresultaat illustratie](../media/2ee5a36673d2cbeb934ca2af29dab607.png)

---

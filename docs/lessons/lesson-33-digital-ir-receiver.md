# Les 33: Digitale IR-ontvanger

> **Set:** Keyestudio 48-in-1 Sensorkit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibele ATmega328P-bord

![Project 33: Digitale IR-ontvanger illustratie](../media/f64f21b6ca681f928c3318bd2d33a017.png)

## Beschrijving

IR wordt veel gebruikt in afstandsbedieningen. Met deze IR-ontvanger kan een Arduino-project commando's van elke IR-afstandsbediening ontvangen als je de juiste decoder hebt. Het is ook eenvoudig om je eigen IR-afstandsbediening te maken met een IR-zender.

## Specificaties

- Voedingsspanning: 5V

- Interface: Digitaal

- Modulatiefrequentie: 38Khz

- Module-aansluiting: JST PH2.0

- Afmetingen: 30*20mm

- Gewicht: 4g

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten.

- V4.0 Board\*1

- IR-ontvangermodule\*1

- USB-kabel\*1

- Dupont-draad\*3

Verbind de S-pin van de module met Digital 11 van het V4.0 board, verbind de negatieve pin met de GND-aansluiting en de positieve pin met de 5V-aansluiting.

![Aansluitschema illustratie](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

In de voorbeeldcode hieronder wordt Digital pin 11 gebruikt; je kunt ofwel je bedrading aanpassen of de voorbeeldcode wijzigen zodat deze overeenkomt.

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
///////////////////////////////////////////////////////////////
#include <IRremote.h>
 int RECV_PIN = 11;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
 void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}

///////////////////////////////////////////////////////////////
```

**Opmerking:** voordat je de code compileert, plaats de bibliotheek in de libraries-directory van de Arduino IDE. Anders zal het compileren mislukken.

IR Remote Library bevat enkele voorbeeldcodes voor zenden en ontvangen.

<https://github.com/shirriff/Arduino-IRremote>

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/2692333113be48ffa11c27649d18dcb8.png)

Na het aansluiten en uploaden van de code, bedien de IR-ontvanger met een infrarood afstandsbediening; de D1 led zal knipperen.

![Voorbeeldresultaat illustratie](../media/4bb52e2957e3aaeace252021e7084c95.png)

---

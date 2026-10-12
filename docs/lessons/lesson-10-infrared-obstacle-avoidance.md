# Les 10: Infrarood obstakelvermijding

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel bord met ATmega328P

![Project 10: Infrarood obstakelvermijding illustratie](../media/54ab9db703340471fd9c3151934b85e7.png)

## Beschrijving

De infrarood obstakeldetector-sensor is uitgerust met een afstandsinstelfunctie en is speciaal ontworpen voor rijdende robots.

Deze sensor heeft een sterke aanpassing aan omgevingslicht en een hoge precisie.

Hij heeft een paar infrarood zend- en ontvangbuisjes. Wanneer de infraroodstraal die door het zendbuisje wordt uitgezonden een obstakel (zijn reflector) raakt, wordt de infraroodstraal teruggekaatst naar het ontvangbuisje, waardoor de indicator oplicht en de signaaluitgangsinterface een digitaal signaal afgeeft.

Daarnaast kunt u de potentiometerknop draaien om de detecteerafstand aan te passen (effectieve afstand: 2～40cm, voedingsspanning: 3.3V-5V).

Dankzij het brede spanningsbereik kan deze sensor stabiel werken zelfs bij schommelende voedingsspanning en is hij geschikt voor verschillende microcontrollers, Arduino-controllers en BS2-controllers.

Een robot uitgerust met deze sensor kan obstakels in de omgeving waarnemen.

## Specificatie

- Werkspanning: DC 3.3V-5V

- Werkstroom: ≥20mA

- Werktemperatuur: －10℃ tot ＋50℃

- Detectieafstand: 2-40cm

- IO-interface: 4-draads aansluiting (-/+/S/EN)

- Uitgangssignaal: TTL-spanning

- Aanpassingsmodus: meer-toerenpotentiometer

- Effectieve hoek: 35°

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat u begint met aansluiten:

- V4.0-bord\*1

- Obstakeldetectormodule \*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de Out-pin van de module met Digital 2 van de V4.0 board, verbind de V+ pin met de 5V-poort, GND pin met de GND-poort.

![Aansluitschema illustratie](../media/48f60a482d777df19bc43a3203479b0c.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
const uint8_t sensorPin = 2;
const uint8_t ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  const int sensorState = digitalRead(sensorPin);
  digitalWrite(ledPin, sensorState == HIGH ? HIGH : LOW);
}
```

## Voorbeeldresultaat

Nadat u de code naar het board heeft geüpload, ziet u dat de LED op zowel het V4.0 board als de obstakeldetector-sensor brandt.

![Voorbeeldresultaat illustratie](../media/44d035dfe09b4c803becd84c95b05956.png)

Als we een schuimblok voor de sensor plaatsen, zal wanneer de sensor het obstakel detecteert de LED op de sensor aangaan.

![Voorbeeldresultaat illustratie](../media/da4468fead816d42b2ac43b29716b91f.png)

---

# Lezione 34: Trasmettitore IR Digitale

> **Kit:** Keyestudio 48-in-1 Kit di sensori  
> **Scheda:** Scheda Keyestudio V4.0 / compatibile Arduino Uno ATmega328P

![Progetto 34: Trasmettitore IR Digitale - illustrazione](../media/9fe876a8c857650226cbe2f8a9bead59.png)

## Descrizione

Il modulo trasmettitore IR è progettato per la comunicazione IR, ampiamente utilizzata per comandare apparecchi televisivi da breve distanza in linea di vista.

Poiché il telecomando a infrarossi (IR) usa la luce, richiede la linea di vista per far funzionare il dispositivo di destinazione. Il segnale può però essere riflesso da specchi, proprio come qualsiasi altra sorgente luminosa.

Anche i ricevitori a infrarossi tendono ad avere un angolo di funzionamento più o meno limitato, il quale dipende principalmente dalle caratteristiche ottiche del fototransistor.

Tuttavia, è facile aumentare l'angolo di funzionamento usando un oggetto trasparente satinato davanti al ricevitore.

## Specifiche

- Alimentazione: 3-5V

- Frequenza centrale infrarossa: 850nm-940nm

- Angolo di emissione infrarossa: circa 20 gradi

- Distanza di emissione infrarossa: circa 1.3m (5V 38Khz)

- Connettore: JST PH2.0

- Foro di montaggio: diametro interno 3.2mm, distanza 15mm

## Schema di collegamento

Per prima cosa è necessario preparare i seguenti componenti prima del collegamento.

- Scheda V4.0\*1

- Modulo trasmettitore IR\*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin S del modulo al pin D3 della scheda V4.0, collega il pin negativo a GND e il pin positivo a 5V.

![Schema di collegamento - illustrazione](../media/31c03e9ad144e1124260ff6e0538fe69.jpeg)

## Esempio di codice 1

```c
int led = 3;
void setup() {
   pinMode(led, OUTPUT);
}
void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
```

In condizioni di oscurità, vedrai una luce blu lampeggiante sullo schermo del telefono quando userai la fotocamera per riprendere il LED infrarosso.

Carica correttamente il codice sopra sulla scheda; il LED sul sensore lampeggerà di rosso.

Di seguito, passiamo a un esempio interattivo tra modulo ricevitore IR e modulo trasmettitore IR.

## Telecomando/Comunicazione a infrarossi

## Materiale necessario

- Arduino R3 x2

- Ricevitore IR digitale x1

- Modulo trasmettitore IR x1

Nota: questo esperimento richiede due schede microcontrollore. Una breadboard non può sostituire la seconda scheda perché non può eseguire lo sketch del ricevitore.

## Configurazione per comunicazione a due schede

## Per il trasmettitore IR

Attenzione: Arduino-IR remote supporta solo D3 come trasmettitore.

![Per il trasmettitore IR - illustrazione](../media/08ebf9b37949caf1782e499f49934f1d.png)

## Per il ricevitore IR

Collega il pin del segnale al connettore D11.

![Per il ricevitore IR - illustrazione](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

## Carica il codice 2 sulla V4.0 connessa al trasmettitore IR

```c
 #include <IRremote.h>
  IRsend irsend;
 void setup()
 {}
 void loop() {
  irsend.sendRC5(0x0, 8); //send 0x0 code (8 bits)
     delay(200);
  irsend.sendRC5(0x1, 8);
     delay(200); }
```

## Carica il codice 3 sulla V4.0 connessa al ricevitore IR

```c
#include <IRremote.h>
 const int RECV_PIN = 11;
 const int LED_PIN = 13;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
 {Serial.begin(9600);
   irrecv.enableIRIn(); // Start the receiver
 }
  void loop()
 {if (irrecv.decode(&results))
   { if ( results.bits > 0 )
     {

       int state;
       if ( 0x1 == results.value )
       {
         state = HIGH;
       }
       else
       {
         state = LOW;
       }
       digitalWrite(LED_PIN, state);
     }
  irrecv.resume();        // prepare to receive the next value
   }}
```

## Risultato

Quando il modulo ricevitore IR riceve il segnale infrarosso dal trasmettitore IR, il LED D1 sul modulo ricevitore IR lampeggerà.

Quando il modulo ricevitore IR riceve il segnale infrarosso dal trasmettitore IR, il LED D1 sul modulo ricevitore IR lampeggerà.

![Risultato - illustrazione](../media/4d73a7178e89de72df7e82a147778ae9.png)

---

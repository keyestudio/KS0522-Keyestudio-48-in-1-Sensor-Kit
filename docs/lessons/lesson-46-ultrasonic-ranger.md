# Lezione 46: Rilevatore ultrasonico

> **Kit:** Keyestudio Kit sensori 48-in-1  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile Arduino Uno con ATmega328P

![Illustrazione Progetto 46: rilevatore ultrasonico](../media/c170155a5fb03abdc10866e25e3670b2.jpeg)

## Descrizione

Poiché gli ultrasuoni hanno una forte direttività, bassa dissipazione di energia e grande capacità di propagazione nel mezzo, sono comunemente usati nella misurazione delle distanze, come nei telemetri e negli strumenti di rilevamento di posizione.

Il modulo rilevatore ultrasonico può fornire una distanza di rilevamento non a contatto da 2cm a 450cm, e la sua precisione di misura arriva fino a 3mm, ottimo per soddisfare le esigenze ordinarie.

Il modulo include un trasmettitore e un ricevitore ultrasonico oltre al circuito di controllo corrispondente.

## Schema di funzionamento

La sequenza di misura dell'HC-SR04 è mostrata di seguito:

![Illustrazione Schema di funzionamento](../media/a7b0fc57b2e387962071da618153ad68.jpeg)

1\. Per prima cosa tenere basso il TRIG, quindi attivarlo con un segnale livello alto di almeno 10us;

2\. Dopo l'attivazione, il modulo trasmetterà automaticamente otto onde quadre a 40KHz e rileverà automaticamente se vi è un segnale di ritorno.

3\. Se esiste un segnale di ritorno, tramite l'ECHO viene emesso un livello alto; la durata del livello alto corrisponde al tempo dall'emissione alla ricezione dell'ultrasuono.
$$
Distanza\ misurata = Durata\ del\ livello\ alto * 340m/s * 0.5
$$

## Parametri

- Tensione di lavoro: 5 V DC

- Corrente di lavoro：15mA

- Campo di rilevamento：2-450cm

- Angolo di rilevamento：15 gradi

- Impulso di trigger in ingresso：10us livello TTL

- Segnale di eco in uscita： segnale a livello TTL (HIGH), proporzionale alla distanza.

## Diagramma dei pin

![Illustrazione Diagramma dei pin](../media/c03e563bcd19796b483156724bae174a.png)

## Schema di collegamento

Per prima cosa, è necessario preparare i seguenti componenti:

- Scheda V4.0\*1

- Sensore ultrasonico\*1

- Cavo USB\*1

- Cavi jumper\*4

Successivamente, fare riferimento alla seguente tabella di collegamento:

![Illustrazione Schema di collegamento](../media/e708c019b57984a07feb241672793982.jpeg)

Nota: D4、D5 sono i pin digitali 4 e 5.

È possibile fare riferimento al diagramma di collegamento mostrato di seguito:

![Illustrazione Schema di collegamento](../media/b5b964743eac977e687c454b64e061fa.jpeg)

Dopo aver effettuato correttamente i collegamenti, è possibile misurare la distanza e visualizzare il valore della distanza sul monitor.

## Codice di test

Copia e incolla il codice di test qui sotto nel software Arduino

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

## Esempio di risultato

![Illustrazione Esempio di risultato](../media/0dcff2ae88366ce40190b77f25d271d7.png)

Dopo aver caricato correttamente il codice sulla scheda V4.0, aprire il monitor seriale. Posizionando un oggetto davanti al sensore ultrasonico (da vicino e da lontano), verrà rilevata la distanza dell'oggetto. Il valore verrà visualizzato sul monitor mostrato di seguito.

![Illustrazione Esempio di risultato](../media/1dbca5dc233994f6923601d942fadba6.png)

![Illustrazione Esempio di risultato](../media/dcd49cc72e7a9f993083af7625d240db.png)

---

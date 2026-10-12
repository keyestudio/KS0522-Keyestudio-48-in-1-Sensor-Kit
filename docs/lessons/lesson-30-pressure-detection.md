# Lezione 30: Rilevamento della pressione

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Illustrazione del progetto 30: Rilevamento della pressione](../media/313f11bf4a7f52ac903c78976fe1e633.jpeg)

## Descrizione

Questo sensore utilizza un nuovo materiale sensibile alla pressione nano-flessibile con pad a pellicola ultrasottile. Ha le funzioni di impermeabilità e rilevamento della pressione.

Quando il sensore rileva la pressione esterna, la resistenza del sensore varierà.

Pertanto, tramite il circuito, può convertire il segnale di pressione (che rileva la variazione di pressione) nel corrispondente segnale elettrico di uscita.

In questo modo possiamo ottenere le condizioni delle variazioni di pressione rilevando i cambiamenti del segnale.

## Parametri

- Tensione di lavoro: DC 3.3V—5V

- Intervallo: 0-10 kg

- Spessore: ＜0.25 mm

- Punto di risposta: ＜20 g

- Ripetibilità: ＜±5.8%（50% del carico）

- Precisione: ±2.5%（85% dell'intervallo）

- Durata: ＞100.000 volte

- Resistenza iniziale: ＞100 MΩ（nessun carico）

- Tempo di risposta: ＜1 ms

- Tempo di recupero: ＜15 ms

- Temperatura di lavoro: −20℃—60℃

## Diagramma di collegamento

Per prima cosa è necessario preparare le seguenti parti prima del collegamento.

- Scheda V4.0\*1

- Sensore di pressione\*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin S del modulo ad Analog A0 della scheda V4.0, collega il pin negativo al GND, il pin positivo al 5V.  
![Diagramma di collegamento illustrazione](../media/3325303180f71db75d9e13acc5036d8f.jpeg)

## Codice di esempio

Copia e incolla il codice qui sotto nell'IDE di Arduino.

```c
///////////////////////////////////////////////////////////////
int s_pin = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(s_pin,INPUT);

}

void loop()
{
  Serial.println(analogRead(s_pin));
  delay(500);
}
///////////////////////////////////////////////////////////////
```

## Risultato di esempio

Dopo aver cablato correttamente e caricato il codice, apri il monitor seriale nell'IDE di Arduino.

Poi, premi il sensore con forza con la mano: il valore mostrato nel monitor aumenterà.

![Risultato di esempio illustrazione](../media/a6c4be8596a0048cb5f3b2f1612241bd.png)

![Risultato di esempio illustrazione](../media/e055d2749b14c62b92c22496a3d1f96a.jpeg)

---

# Lezione 39: Temperatura lineare

> **Kit:** Keyestudio Kit sensori 48-in-1  
> **Scheda:** Keyestudio V4.0 / Scheda ATmega328P compatibile con Arduino Uno

![Progetto 39: Sensore di temperatura lineare illustrazione](../media/9a9b328cb85401dce3932f047f0979e0.png)

## Introduzione

Il sensore di temperatura lineare LM35 è basato sul sensore di temperatura a semiconduttore LM35. Può essere utilizzato per rilevare la temperatura dell'aria ambiente.

Questo sensore offre un intervallo di funzionamento da 0 gradi Celsius a 100 gradi Celsius. La sensibilità è di 10mV per grado Celsius. La tensione di uscita è proporzionale alla temperatura.

Questo sensore è comunemente usato come sensore di misura della temperatura. Include termocoppie, sensori a resistenza di platino (RTD), termistori e sensori di temperatura a semiconduttore.

Il sensore a resistenza di platino è usato per misurazioni fino a 800 gradi Celsius, mentre i termistori e i sensori di temperatura a semiconduttore sono adatti per misurare temperature intorno a 100–200 gradi Celsius o inferiori; in queste applicazioni l'impiego di un semplice sensore di temperatura a semiconduttore garantisce buona linearità e alta sensibilità.

Il sensore di temperatura lineare LM35 può essere facilmente collegato a uno shield per Arduino.

## Specifiche

- Sensibilità: 10mV per grado Celsius

- Intervallo di funzionamento: 0 gradi Celsius a 100 gradi Celsius

- Dimensioni: 30*20mm

- Peso: 3g

## Schema di collegamento

Per prima cosa è necessario preparare le parti seguenti prima del test.

- Scheda V4.0\*1

- Sensore di temperatura LM35\*1

- Cavo USB\*1

- Cavi jumper\*3

Quindi seguire lo schema di collegamento: collegare il pin di segnale del sensore alla porta A0 della scheda V4.0, il pin negativo a GND e il pin positivo a 5V.

![Schema di collegamento illustrazione](../media/e2f1fc77bb6b54c35bc3d1a8834cbf6b.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nell'ambiente Arduino.

```c
///////////////////////////////////////////////////////////////
void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
}
 void loop()
{  int val;
    int dat;
    val=analogRead(0);//Connect LM35 on Analog 0
    dat=(500 * val) /1024;;
    Serial.print("Temp:"); //Display the temperature on Serial monitor
    Serial.print(dat);
    Serial.println("C");
    delay(500);
}
///////////////////////////////////////////////////////////////
```

## Risultato d'esempio

![Risultato d'esempio illustrazione](../media/95d0d43a93fd2bf1e9c7248e80edcedc.png)

Collegalo come nello schema sopra e carica correttamente il codice sulla scheda, quindi apri il monitor seriale e impostane la velocità di trasmissione a 9600 baud.

Vedrai il valore della temperatura corrente mostrato di seguito. Il valore può differire leggermente a seconda del luogo e delle condizioni meteorologiche.

![Risultato d'esempio illustrazione](../media/8331a0416c8006161b3227e170a3b033.jpeg)

---

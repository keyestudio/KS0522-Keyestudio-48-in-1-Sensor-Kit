# Lezione 29: Rilevamento della tensione

> **Kit:** Keyestudio Kit sensori 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile con Arduino Uno ATmega328P

![Illustrazione Progetto 29: Rilevamento della tensione](../media/41967398a781944fd64ebd49a9c746fa.jpeg)

## Descrizione

Poiché i prodotti elettronici sono diversi, anche la tensione dell'alimentazione varia. È quindi necessario rilevarla con un modulo di rilevamento della tensione o un controller adeguato.

La tensione massima di ingresso dell'interfaccia analogica del controller è 5V, il che significa che tensioni maggiori di 5V non verranno rilevate.

Tuttavia, questo modulo di rilevamento della tensione consente di rilevare tensioni superiori a 5 V.

Si basa su un partitore resistivo 5:1. Con un riferimento analogico di 5 V, la tensione di ingresso non deve superare i 25 V. Con un riferimento analogico di 3.3 V, la tensione di ingresso non deve superare i 16.5 V.

Il convertitore analogico-digitale AVR è a 10 bit, quindi la risoluzione analogica è 0.00489 V (5 V / 1023). Con il partitore 5:1, l'incremento minimo misurabile in ingresso è approssimativamente 0.02445 V.

Quando si collega questo sensore alla scheda di espansione usando un cavo a 3 pin, non solo può rilevare facilmente l'entità della tensione di alimentazione e monitorare la carica della batteria per opere multimediali interattive o robot, ma può anche essere abbinato a un modulo LCD IIC LCD1602 per visualizzare la tensione o realizzare un monitor della tensione.

## Specifiche

- Tensione di funzionamento: 0V-25V DC

- Tipo di segnale: segnale analogico

## Schema di collegamento

Per prima cosa, è necessario preparare i seguenti componenti prima del collegamento:

- Scheda V4.0\*1

- Sensore di tensione\*1

- Cavo USB\*1

- Cavi jumper\*3

Collegare il pin S del modulo ad Analog A0 della scheda V4.0, collegare il pin negativo alla porta GND, il pin NC alla porta 5V.

![Illustrazione dello schema di collegamento](../media/b8754c45901ff42ba9caadce5db01a3a.jpeg)

## Codice di esempio

```c
////////////////////////////////////////////////////////////////////
int analogpin=0;     // Define analogpin as analog port 0
int val,val5;       //Define variables val,val5
int val2=0;      //Define variables val2
int val3=0;     //Define variables val3
int val4=0;    //Define variables val4

void setup()
{
    Serial.begin(9600);     //Set baud rate of 9600
}
void loop()
{
    int val,val5;
    float val1;
    val=analogRead(analogpin);     //Read the value of the analog port and assign it to the variable val
    val1=val/3.9;
    val5=(int)val1;
    val3=val5/100;
    val2=(val5%100)/10;
    val4=val5%10;
    Serial.print("$CLEAR\r\n");      //clear the screen
    Serial.print("$GO 1 1\r\n");
    Serial.print("$PRINT Voltage:\r\n");
    Serial.print("$GO 1 9\r\n");
    Serial.print("$PRINT ");
Serial.print(val3);        //The serial port prints the value of the variable val3
Serial.print(val2);      //The serial port prints the value of the variable val2
    Serial.print(".");               //The serial port prints out a point"."
    Serial.print(val4);         //The serial port prints the value of the variable val4
    Serial.println("V");          //The serial port prints out capital “ V”
    delay(100);      //delay 0.1 second
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

![Illustrazione del risultato di esempio](../media/ac8825bb333757bad26785e58651beb7.png)

Dopo aver effettuato il collegamento come sopra, compilare e caricare il codice, alimentare la scheda, quindi aprire il monitor seriale: verrà stampato il valore della tensione rilevata come mostrato di seguito.

![Illustrazione del risultato di esempio](../media/af699a83a891ea99d193d5b53bd27fa1.jpeg)

---

# Lezione 36: Joystick

> **Kit:** Keyestudio Kit sensori 48-in-1  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile con Arduino Uno (ATmega328P)

![Progetto 36: illustrazione del joystick](../media/310a620a28ae6ebeeee7294bdc7a2bb0.png)

## Descrizione

Molti progetti robotici richiedono uno joystick. Questo modulo offre una soluzione economica. Collegandolo semplicemente a due ingressi analogici, il robot è sotto il tuo controllo con asse X e Y. Ha anche un interruttore collegato a un pin digitale.

## Specifiche

- Tensione di alimentazione: 3.3V a 5V

- Interfaccia: Analogico x2, Digitale x1

- Dimensioni: 40*28mm

- Peso: 12g

## Diagramma di collegamento

Prima di tutto, prepara i seguenti componenti prima del collegamento.

- Scheda V4.0\*1

- Modulo joystick\*1

- Cavo USB\*1

- Cavi jumper\*5

Collega il pin Y del modulo ad Analog A1 della Scheda V4.0, collega il pin X ad Analog A0, il pin B a Digital 3; collega il pin negativo alla porta GND, il pin positivo alla porta 5V.

![Diagramma di collegamento (illustrazione)](../media/3c0d2f553f6e76565171dae78a440568.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nell'IDE di Arduino.

```c
///////////////////////////////////////////////////////////////
int JoyStick_X = 0; //x
int JoyStick_Y = 1; //y
int JoyStick_Z = 3; //key
  void setup()
{
  pinMode(JoyStick_Z, INPUT);
  Serial.begin(9600); // 9600 bps
}
void loop()
{
  int x,y,z;
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=digitalRead(JoyStick_Z);
  Serial.print(x ,DEC);
  Serial.print(",");
  Serial.print(y ,DEC);
  Serial.print(",");
  Serial.println(z ,DEC);
  delay(100);
}
///////////////////////////////////////////////////////////////
```

## Risultato di esempio

![Esempio di risultato (illustrazione)](../media/5e6809517dd961c3740b04c7774c3e75.png)

Dopo aver effettuato i collegamenti e caricato il codice, apri il monitor seriale nell'IDE di Arduino e imposta la velocità di trasmissione su 9600 baud: vedrai i valori mostrati qui sotto. Se spingi lo joystick verso il basso, in alto, a sinistra o a destra, i dati cambieranno.

![Esempio di risultato (illustrazione)](../media/6b3a1bd089cafce0f1db02f405ab5035.jpeg)

---

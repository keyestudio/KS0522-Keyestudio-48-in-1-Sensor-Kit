# Lezione 37: Encoder rotativo

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / scheda compatibile con Arduino Uno (ATmega328P)

![Progetto 37: illustrazione dell'encoder rotativo](../media/df622003846058dd3cf442518f655af2.png)

## Introduzione

L'encoder rotativo può contare il numero di impulsi emessi durante la rotazione in senso orario e antiorario.

Questa conta durante la rotazione è illimitata, a differenza del conteggio di un potenziometro. Può essere riportato allo stato iniziale per ricominciare a contare da 0.

## Specifiche

- Alimentazione: 5V

- Interfaccia: Digitale

- Dimensioni: 30\*20mm

- Peso: 7g

## Schema di collegamento

![Illustrazione dello schema di collegamento](../media/1de37f27caa224141230be6bdc95d29b.jpeg)

Come mostrato nello schema, colleghiamo il modulo encoder rotativo e due moduli LED sulla breadboard e alla scheda V4.0.

Utilizza il modulo encoder rotativo per controllare l'accensione e lo spegnimento dei due moduli LED.

## Codice di esempio

```c
///////////////////////////////////////////////////////////////
const int interruptA = 0;
const int interruptB = 1;
int CLK = 2;     // PIN2
int DAT = 3;     // PIN3
int BUTTON = 4;  // PIN4
int LED1 = 5;    // PIN5
int LED2 = 6;    // PIN6
int COUNT = 0;

void setup()
 {
  attachInterrupt(interruptA, RoteStateChanged, FALLING);
 // attachInterrupt(interruptB, buttonState, FALLING);
  pinMode(CLK, INPUT);
  digitalWrite(2, HIGH);  // Pull High Resistance
  pinMode(DAT, INPUT);
  digitalWrite(3, HIGH);  // Pull High Resistance

pinMode(BUTTON, INPUT);
  digitalWrite(4, HIGH);  // Pull High Resistance
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
   Serial.begin(9600);
 }

void loop()
{
  if  (!(digitalRead(BUTTON)))
    {
     COUNT = 0;
     Serial.println("STOP COUNT = 0");
     digitalWrite(LED1, LOW);
     digitalWrite(LED2, LOW);
     delay (2000);
    }
     Serial.println(COUNT);
}

//-------------------------------------------
void RoteStateChanged() //When CLK  FALLING READ DAT
{
 if  (digitalRead(DAT)) // When DAT = HIGH IS FORWARD
   {
    COUNT++;
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(20);
   }
 else                   // When DAT = LOW IS BackRote
   {
    COUNT--;
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
    delay(20);
   }
}
///////////////////////////////////////////////////////////////
```

## Risultato d'esempio

Dopo aver collegato correttamente e caricato il codice sopra, puoi ruotare il modulo encoder per controllare in modo alternato l'accensione e lo spegnimento dei due moduli LED. Quando ruoti l'encoder, un modulo LED si accende prima mentre l'altro è spento.

Se continui a ruotare l'encoder, un modulo LED si spegnerà mentre l'altro si accende, ripetutamente.

![Illustrazione del risultato d'esempio](../media/4c1455602dc8ab6d61f5ab2e2d5dd67c.png)

---

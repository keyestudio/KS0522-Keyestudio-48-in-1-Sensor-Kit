# Lezione 45: Micro Servo

> **Kit:** Keyestudio Kit sensori 48-in-1  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile Arduino Uno ATmega328P

![Illustrazione Progetto 45: Micro Servo](../media/12c59bd3ab0733beb6ff7802305d4384.jpeg)

## Introduzione

Il servomotore è un attuatore rotante per il controllo della posizione. È composto principalmente da involucro, circuito, motore coreless, ingranaggi e sensore di posizione.

In dotazione con il tuo servomotore troverai una varietà di supporti bianchi per motore che si collegano all'albero del servo. Puoi scegliere di fissare qualsiasi supporto desideri per il circuito. Servirà come ausilio visivo, rendendo più facile vedere il movimento del servo.

Il servo ha tre interfacce, distinte da linee marrone, rossa e arancione (alcuni marchi possono avere colori diversi). La linea marrone è per GND, quella rossa per l'alimentazione 5V, quella arancione per il terminale del segnale (segnale PWM).

![Illustrazione introduzione](../media/e7eb9914318b92eff98a4a84a8d1a557.png)

L'angolo di rotazione del servo è controllato regolando il duty cycle del segnale PWM (modulazione di larghezza di impulso). Il periodo standard del segnale PWM è fissato a 20ms (50 Hz), e la larghezza dell'impulso è compresa tra 1ms e 2ms. La larghezza dell'impulso corrisponde all'angolo di rotazione ( 0°～90°) del servo.

![Illustrazione introduzione](../media/723671941df8a57cf9246c9916e7b279.png)

Ora impariamo come controllare un servomotore.

In questo esperimento ti servono solo un servomotore e alcuni cavi jumper.

## Diagramma di collegamento

Collegamento per V4.0 :

![Illustrazione diagramma di connessione](../media/da1e3590f86a5a8ed27b333742ae49c9.jpeg)

Collegamento per 2560 R3:

![Illustrazione diagramma di connessione](../media/1c8bd09408be60254883b910ef4fc9bf.png)

Collega il motore al pin digitale 9.

Compila un programma per controllare la rotazione del motore all'angolo richiesto e visualizzare l'angolo sullo schermo.

## Programma di esempio

Ci sono due modi per controllare un servomotore con Arduino.

Uno è usare una comune porta digitale per sensori di Arduino per generare un'onda quadra con diverso duty cycle per simulare un segnale PWM e usare quel segnale per controllare il posizionamento del motore.

Un altro modo è usare direttamente la funzione Servo di Arduino per controllare il motore.

In questo modo il programma sarà più semplice ma può controllare solo motori a due contatti tramite la funzione servo; possono essere usati solo i pin digitali 9 e 10. La capacità di pilotaggio di Arduino è limitata. Quindi se hai bisogno di controllare più di un motore, avrai bisogno di alimentazione esterna.

## Metodo 1

## Programma di esempio A

```c
//////////////////////////////////////////////////////////
int servopin=9;// select digital pin 9 for servomotor signal line
int myangle;// initialize angle variable
int pulsewidth;// initialize width variable
int val;
void servopulse(int servopin,int myangle)// define a servo pulse function
{
pulsewidth=(myangle*11)+500;// convert angle to 500-2480 pulse width
digitalWrite(servopin,HIGH);// set the level of servo pin as “high”
delayMicroseconds(pulsewidth);// delay microsecond of pulse width
digitalWrite(servopin,LOW);// set the level of servo pin as “low”
delay(20-pulsewidth/1000);
}
void setup()
{
pinMode(servopin, OUTPUT);
Serial.begin(9600);
Serial.println("servo=o_seral_simple ready" ) ;
}
void loop()// convert number 0 to 9 to corresponding 0-180 degree angle, LED blinks corresponding number of time
{
val=Serial.read();// read serial port value
if(val>='0'&&val<='9')
{
val=val-'0';// convert characteristic quantity to numerical variable
val=val*(180/9);// convert number to angle
Serial.print("moving servo to ");
Serial.print(val,DEC);
Serial.println();
for(int i=0;i<=50;i++) // giving the servo time to rotate to commanded position
{
servopulse(servopin,val);// use the pulse function
}
}
}
//////////////////////////////////////////////////////////
```

## Metodo 2

Diamo prima un'occhiata alla funzione Servo incorporata di Arduino e ad alcune istruzioni comuni.

1\. **attach（interface）**——seleziona il pin per il servo, può usare solo il pin 9 o 10.

2\. **write（angle）**——usata per controllare l'angolo di rotazione del servo, può impostare l'angolo tra 0 e 180 gradi.

3\. **read（）**——usata per leggere l'angolo del servo; considerala una funzione per leggere il valore impostato con write().

4\. **attached（）**——determina se il parametro del servo è assegnato al pin del servo.

5\. **detach（）**——scollega il servo dal pin, e il pin (pin digitale 9 o 10) può essere usato come porta PWM.

**Nota:** la forma scritta delle istruzioni sopra è "nomeVariabileServo.nomeFunzione()", ad es. myservo.attach(9).

Collega comunque il servo al pin 9.

## Programma di esempio B

```c
#include <Servo.h>// define a header file. Special attention here, you can call the servo function directly from Arduino's software menu

Servo myservo;// define servo variable name
void setup()
{
myservo.attach(9);// select servo pin(9 or 10)
}
void loop()
{
myservo.write(90);// set rotating angle of the motor
}
```

## Risultato di esempio

![Illustrazione risultato di esempio](../media/f02556e0631fb206c114ced29e643016.png)

Collega tutto correttamente, carica il Programma A sulla scheda, poi apri il monitor seriale del software Arduino, imposta il baud rate a 9600, e nella barra superiore inserisci un numero e clicca “Invia”; vedrai il servo ruotare all'angolo corrispondente e l'angolo in movimento verrà visualizzato sul monitor, come mostrato sotto.

Una volta alimentata, e caricato correttamente il Programma B sulla scheda, il servo si posizionerà inizialmente a 90 gradi.

![Illustrazione risultato di esempio](../media/de50d502cb8ed1feb5935d16584cfd63.png)

---

# Lektion 06: Passiver Summer

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P-Board

![Projekt 6: Passiver Summer Abbildung](../media/1bd2e3afebf5a0d3712fe42092b0a1b4.png)

## Beschreibung

Mit Arduino können wir viele interaktive Projekte erstellen, wobei die am häufigsten verwendete Anzeige die akustisch-optische Anzeige ist. Der Schaltkreis in diesem Experiment kann Töne erzeugen.

Normalerweise kann das Experiment mit einem Summer oder einem Lautsprecher durchgeführt werden, wobei der Summer einfacher und leichter zu verwenden ist.

Der hier vorgestellte Summer ist ein passiver Summer. Er lässt sich nicht selbst ansteuern, sondern wird durch externe Impulsfrequenzen betrieben. Verschiedene Frequenzen erzeugen unterschiedliche Töne. Mit Arduino kannst du die Melodie eines Liedes programmieren — sehr spaßig und einfach.

## Spezifikation

- Betriebsspannung: 3.3-5v

- Schnittstellentyp: digital

- Größe: 30\*20mm

- Gewicht: 4g

## Anschlussdiagramm

Vor dem Anschluss bereiten Sie bitte die folgenden Teile vor:

- V4.0-Platine*1

- Passives Summer-Modul*1

- USB-Kabel*1

- Jumper-Kabel*3

Verbinde den S-Pin des Moduls mit Digital 3 der V4.0-Platine, den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/e9e7ba383738c3b6be85a1f3c97e5385.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
////////////////////////////////////////////////////////////////////
int buzzer=3;//set digital IO pin of the buzzer
void setup()
{
pinMode(buzzer,OUTPUT);// set digital IO pin pattern, OUTPUT to be output
}
void loop()
{ unsigned char i,j;//define variable
while(1)
{ for(i=0;i<80;i++)// output a frequency sound
{ digitalWrite(buzzer,HIGH);// sound
delay(1);//delay1ms
digitalWrite(buzzer,LOW);//not sound
delay(1);//ms delay
}
for(i=0;i<100;i++)// output a frequency sound
{
digitalWrite(buzzer,HIGH);// sound
digitalWrite(buzzer,LOW);//not sound
delay(2);//2ms delay
}
}
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

Nach dem Hochladen des Codes auf die Platine gibt der Summer einen Ton von sich.

![Beispielergebnis Abbildung](../media/9b29eccd437694e479a836b7da66d500.png)

---

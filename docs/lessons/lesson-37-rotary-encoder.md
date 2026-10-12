# Lección 37: Codificador rotatorio

> **Kit:** Kit de sensores Keyestudio 48-en-1  
> **Placa:** Keyestudio V4.0 / placa compatible con Arduino Uno ATmega328P

![Proyecto 37: Ilustración del codificador rotatorio](../media/df622003846058dd3cf442518f655af2.png)

## Introducción

El codificador rotatorio puede contar el número de pulsos emitidos durante la rotación en sentido horario y antihorario.

Este conteo por rotación es ilimitado, a diferencia de un potenciómetro. Puede restablecerse al estado inicial para contar desde 0.

## Especificaciones

- Alimentación: 5V

- Interfaz: Digital

- Tamaño: 30\*20mm

- Peso: 7g

## Diagrama de conexión

![Ilustración del diagrama de conexión](../media/1de37f27caa224141230be6bdc95d29b.jpeg)

Como se ve en el diagrama, conectamos el módulo codificador rotatorio y dos módulos LED al protoboard y a la placa V4.0.

Utiliza el módulo codificador rotatorio para controlar el encendido y apagado de los dos módulos LED.

## Código de ejemplo

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

## Resultado de ejemplo

Con el cableado correcto y cargando el código anterior, puedes girar el codificador para alternar el encendido y apagado de los dos módulos LED. Cuando giras el codificador, un módulo LED se enciende primero mientras el otro está apagado.

Si continúas girando el codificador, un módulo LED se apaga mientras el otro se enciende, repetidamente.

![Ilustración del resultado de ejemplo](../media/4c1455602dc8ab6d61f5ab2e2d5dd67c.png)

---

# Lección 29: Detección de voltaje

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Placa Keyestudio V4.0 / compatible con Arduino Uno ATmega328P

![Proyecto 29: Ilustración de detección de voltaje](../media/41967398a781944fd64ebd49a9c746fa.jpeg)

## Descripción

Dado que los productos electrónicos son variados, el voltaje de la alimentación también difiere. Es necesario detectarlo con un módulo o controlador de detección de voltaje adecuado.

La tensión máxima de entrada de la interfaz analógica del controlador es 5V, lo que significa que no podrá detectarse un voltaje superior a 5V.

Sin embargo, este módulo de detección de voltaje puede detectar valores superiores a 5 V.

Se basa en un divisor resistivo 5:1. Con una referencia analógica de 5 V, la tensión de entrada no debe exceder los 25 V. Con una referencia analógica de 3.3 V, la tensión de entrada no debe exceder los 16.5 V.

El convertidor analógico a digital AVR es de 10 bits, por lo que la resolución analógica es 0.00489 V (5 V / 1023). Con el divisor 5:1, el incremento mínimo de entrada medible es aproximadamente 0.02445 V.

Al conectar este sensor a la placa de expansión usando un cable de 3 pines, no solo puede detectar fácilmente la magnitud del voltaje y monitorizar la carga de una batería para trabajos de medios interactivos o robots, sino que también puede combinarse con el módulo LCD IIC LCD1602 para mostrar el voltaje o crear un monitor de voltaje.

## Especificaciones

- Tensión de trabajo: 0V-25V CC

- Tipo de señal: señal analógica

## Diagrama de conexión

Primero, necesitas preparar los siguientes componentes antes de la conexión:

- placa V4.0\*1

- Sensor de voltaje\*1

- Cable USB\*1

- Cable jumper\*3

Conecta el pin S del módulo al analógico A0 de la placa V4.0, conecta el pin negativo al puerto GND, el pin NC al puerto 5V.

![Ilustración del diagrama de conexión](../media/b8754c45901ff42ba9caadce5db01a3a.jpeg)

## Código de ejemplo

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

## Resultado de ejemplo

![Ilustración del resultado de ejemplo](../media/ac8825bb333757bad26785e58651beb7.png)

Realizado el cableado anterior, compila y sube el código, enciende la alimentación y abre el monitor serie; imprimirá el valor de voltaje detectado que se muestra a continuación.

![Ilustración del resultado de ejemplo](../media/af699a83a891ea99d193d5b53bd27fa1.jpeg)

---

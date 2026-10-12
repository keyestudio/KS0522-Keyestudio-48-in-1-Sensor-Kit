# Lección 47: Pantalla LCD

> **Kit:** Kit de sensores Keyestudio 48 en 1  
> **Placa:** Placa Keyestudio V4.0 / compatible con Arduino Uno ATmega328P

![Ilustración del proyecto 47: Pantalla LCD](../media/1aa1fd551e180d013633c1fe857c24a6.jpeg)

## Descripción

En este proyecto vamos a controlar esta pantalla LCD 0802 para mostrar texto usando la placa V4.0.

La capacidad de visualización del LCD es de 8x2 caracteres, y el voltaje de funcionamiento del chip es 4.5～5.5V.

Hay dos métodos de conexión para que el LCD 0802 muestre texto: conexión de 4 bits y conexión de 8 bits.

Puedes consultar la explicación relacionada a continuación.

## Explicación de las interfaces

| **Interfaz** | **Pin** | **Explicación**                                              |
| :-----------: | :-----: | ------------------------------------------------------------ |
|       1       |   VSS   | Tierra de alimentación lógica                                |
|       2       |   VDD   | Alimentación lógica                                          |
|       3       |   V0    | Voltaje ajustable del LCD, conectar al pin central del potenciómetro de 10K |
|       4       |   RS    | Opción Datos\\Comando                                        |
|       5       |   RW    | Opción lectura\\escritura                                    |
|       6       |    E    | Habilita lectura\\escritura, activo en HIGH, flanco de bajada fija los datos |
|       7       |   DB0   | Pin de entrada/salida de datos                               |
|       8       |   DB1   | Pin de entrada/salida de datos                               |
|       9       |   DB2   | Pin de entrada/salida de datos                               |
|      10       |   DB3   | Pin de entrada/salida de datos                               |
|      11       |   DB4   | Pin de entrada/salida de datos                               |
|      12       |   DB5   | Pin de entrada/salida de datos                               |
|      13       |   DB6   | Pin de entrada/salida de datos                               |
|      14       |   DB7   | Pin de entrada/salida de datos                               |
|      15       |  LED-A  | Extremo positivo de alimentación de la retroiluminación      |
|      16       |  LED-K  | Extremo negativo de alimentación de la retroiluminación      |

## Hardware Requerido

Primero debes preparar las siguientes piezas:

- Placa V4.0 × 1
- LCD 0802 × 1
- Potenciómetro rotatorio × 1
- Protoboard × 1
- Cable USB × 1
- Cables jumper, según necesidad
- Cables Dupont, según necesidad

## Diagrama de conexión

## Conexión de 4 bits

![Ilustración de conexión de 4 bits](../media/6b3c862d4b36726275b67b747e6d5df3.jpeg)

## Conexión de 8 bits

![Ilustración de conexión de 8 bits](../media/97a92aff5ba45d0f7daaca6307b9a5fd.png)

## Código fuente

## Para conexión de 4 bits

```C
//////////////////////////////////////////////////////////
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11, 12, 6, 7, 4, 5);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(8, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print(" Hello");
  lcd.setCursor(0, 1);
  lcd.print(" world!");
}

void loop() {
}
//////////////////////////////////////////////////////////
```

## Para conexión de 8 bits

```C
#include <LiquidCrystal.h>

// RS, RW, Enable, D0, D1, D2, D3, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10);

void setup() {
  lcd.begin(8, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ABCDEFGH");
  lcd.setCursor(0, 1);
  lcd.print("12345678");
}

void loop() {
  // The 8-bit display remains static after setup.
}
```

## Resultado de ejemplo

Conéctalo correctamente, enciende la placa y sube el código anterior a la misma; ajusta la retroiluminación del LCD girando el potenciómetro; finalmente verás los caracteres mostrados en la pantalla LCD.

Si usas la conexión de 4 bits, deberías ver que el LCD muestra el texto "Hola" en la primera línea y "mundo!" en la segunda, como se muestra a continuación.

![Ilustración del resultado de ejemplo](../media/7d2763d65677d2925902ffcc65bf1b12.png)

Si usas la conexión de 8 bits, verás que se muestran otros caracteres en el LCD. Se muestra a continuación.

![Ilustración del resultado de ejemplo](../media/61002a13397f8041574b375b0032da26.png)

---

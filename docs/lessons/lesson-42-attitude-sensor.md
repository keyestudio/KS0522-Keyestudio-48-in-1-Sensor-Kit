# Lezione 42: Sensore di assetto

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile Arduino Uno ATmega328P

![Illustrazione Progetto 42: Sensore di assetto](../media/8eb8d16c5e76e50a6609678130a9ee29.jpeg)

## Introduzione

**Avviso di compatibilità.** L'elenco dei componenti contrassegna questa scheda come APDS-9930, ma il seguente esempio legacy è destinato a un APDS-9960 e utilizza `SparkFun_APDS9960`. Controllare la marcatura del circuito integrato sul modulo reale prima di caricare questo sketch; non utilizzare questo esempio con una scheda APDS-9930. L'APDS-9930 in un singolo package a 8 pin può fornire il sensore di luce ambientale compatibile con interfaccia I2C e il sensore di prossimità a LED infrarossi.

Il sensore di prossimità, completamente tarato, può rilevare oggetti a 100 mm, esentando i requisiti di calibrazione in fabbrica per l'apparecchiatura terminale e i sottocomponenti.

Dalla luce solare intensa alla stanza buia, la funzione di rilevamento di prossimità opera correttamente.

Questo modulo, dotato di micro-lente ottica, offre trasmissione e ricezione a infrarossi efficienti dal punto di vista energetico, riducendo il consumo complessivo di potenza.

Inoltre, la sua macchina a stati interna può mettere il dispositivo in modalità a basso consumo, garantendo un consumo medio molto ridotto.

## Parametri

- Tensione di lavoro：DC 3.3-3.8V

- Corrente di uscita：0-20mA

- Intervallo di temperatura：-40℃—85℃

## Caratteristiche

1. Modulo ottico integrato con ALS, LED a infrarossi e rivelatore di prossimità;
2. Risoluzione fino a 16 bit;
3. Alta sensibilità di funzionamento anche dietro vetro scuro;
4. Prestazioni a basso flusso luminoso di 0.01 lux;
5. Rilevamento di prossimità, completamente calibrato per rilevamento a 100 mm;
6. Integra LED a infrarossi e driver LED sincrono;
7. Elimina la calibrazione di fabbrica per i sensori di prossimità;
8. Timer di attesa programmabile, consumo in stato di attesa - 90μA (valore tipico);
9. Intervallo programmabile da 2.7 millisecondi a 8 secondi;
10. Compatibile con interfaccia I2C, fino a 400 kHz (modalità I2C fast);
11. Pin di interruzione dedicato;
12. Modalità sleep, consumo - 2.2μA (valore tipico).

## Schema di collegamento

Per prima cosa è necessario preparare le seguenti parti:

- Scheda V4.0\*1

- Sensore di assetto\*1

- Cavo USB\*1

- Cavi jumper\*5

Collegare il pin INT del sensore alla porta digitale D2 della scheda V4.0, il pin SCL alla porta analogica A5, il pin SDA alla porta analogica A4; collegare il pin 3V3 al terminale 3V3 e il pin GND al terminale GND.

![Illustrazione schema di collegamento](../media/c906c4e8a06998118eac5e3b981386d6.jpeg)

## Codice di esempio

**IMPORTANTE**: L'APDS-9960 può accettare solo 3.3V!

## Collegamenti hardware

| Pin Arduino | Scheda APDS-9960 | Funzione  |
| :---------: | :--------------: | :-------: |
|    3.3V     |       VCC        |   Alimentazione   |
|     GND     |       GND        |     Massa        |
|     A4      |       SDA        |   Dati I2C       |
|     A5      |       SCL        |   Clock I2C      |
|     D2      |       INT        |   Interruzione   |
|     D13     |        -         |      LED         |

**Risorse:** Includere Wire.h e SparkFun_APDS-9960.h

**Specifiche dell'ambiente di sviluppo:** Scritto in Arduino 1.0.5

Copia e incolla il codice sottostante nel software Arduino.

```c
#include <Wire.h>
#include <SparkFun_APDS9960.h>

// Pins
#define APDS9960_INT    2  // Needs to be an interrupt pin
#define LED_PIN         13 // LED for showing interrupt

// Constants
#define LIGHT_INT_HIGH  1000 // High light level for interrupt
#define LIGHT_INT_LOW   10   // Low light level for interrupt

// Global variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
int isr_flag = 0;
uint16_t threshold = 0;

void setup() {
  // Set LED as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(APDS9960_INT, INPUT);
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("-------------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - Light Interrupts"));
  Serial.println(F("-------------------------------------"));
  // Initialize interrupt service routine
  attachInterrupt(0, interruptRoutine, FALLING);
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  // Set high and low interrupt thresholds
  if ( !apds.setLightIntLowThreshold(LIGHT_INT_LOW) ) {
    Serial.println(F("Error writing low threshold"));
  }
  if ( !apds.setLightIntHighThreshold(LIGHT_INT_HIGH) ) {
    Serial.println(F("Error writing high threshold"));
  }
  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }
  // Read high and low interrupt thresholds
  if ( !apds.getLightIntLowThreshold(threshold) ) {
    Serial.println(F("Error reading low threshold"));
  } else {
    Serial.print(F("Low Threshold: "));
    Serial.println(threshold);
  }
  if ( !apds.getLightIntHighThreshold(threshold) ) {
    Serial.println(F("Error reading high threshold"));
  } else {
    Serial.print(F("High Threshold: "));
    Serial.println(threshold);
  }
  // Enable interrupts
  if ( !apds.setAmbientLightIntEnable(1) ) {
    Serial.println(F("Error enabling interrupts"));
  }
  // Wait for initialization and calibration to finish
  delay(500);
}
void loop() {
  // If interrupt occurs, print out the light levels
  if ( isr_flag == 1 ) {

    // Read the light levels (ambient, red, green, blue) and print
    if (  !apds.readAmbientLight(ambient_light) ||
          !apds.readRedLight(red_light) ||
          !apds.readGreenLight(green_light) ||
          !apds.readBlueLight(blue_light) ) {
      Serial.println("Error reading light values");
    } else {
      Serial.print("Interrupt! Ambient: ");
      Serial.print(ambient_light);
      Serial.print(" R: ");
      Serial.print(red_light);
      Serial.print(" G: ");
      Serial.print(green_light);
      Serial.print(" B: ");
      Serial.println(blue_light);
    }
    // Turn on LED for a half a second
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);

    // Reset flag and clear APDS-9960 interrupt (IMPORTANT!)
    isr_flag = 0;
    if ( !apds.clearAmbientLightInt() ) {
      Serial.println("Error clearing interrupt");
    }
  }
}
void interruptRoutine() {
  isr_flag = 1;
}
```

Nota: prima di compilare il codice, ricordarsi di posizionare la libreria nella directory libraries dell'IDE di Arduino. Altrimenti la compilazione fallirà.

## Risultato di esempio

![Illustrazione risultato di esempio](../media/2a30729fa77874e4e61f51d2bb8e62c1.png)

Dopo aver caricato il codice, aprire il monitor seriale e impostare il baud rate su 9600.

![Illustrazione risultato di esempio](../media/935c7035ef43f54ca65eaa49bbaf5e98.jpeg)

---

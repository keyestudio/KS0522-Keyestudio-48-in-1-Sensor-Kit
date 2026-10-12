# Lezione 43: Rilevamento di prossimità ottico

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Illustrazione Progetto 43: Rilevamento di prossimità ottico](../media/4085d5742012b8647b52c537b82974ff.jpeg)

## Introduzione

**Avviso di compatibilità.** Il testo originale identifica questo modulo come TMD27713, mentre lo sketch qui sotto è destinato all'APDS-9930. Verifica la marcatura del circuito integrato e usa una libreria corrispondente prima di effettuare l'upload.

Si tratta di un sensore triplo che integra sensore di luce ambientale, sensore di prossimità e LED a infrarossi.

Da un lato viene usato per rilevare la luminosità ambientale corrente (ALS). Può, in base alla luminosità ambientale, regolare automaticamente la luminosità del retroilluminazione tramite intervento software. Questo permette di rendere la retroilluminazione più morbida per proteggere la vista e ottenere un effetto di risparmio energetico.

Tra le altre funzioni è presente la rilevazione di prossimità (PROX). Il sensore integra trasmettitore/ricevitore e minimizza il design; inoltre l'installazione non ha più restrizioni di spazio e la struttura risulta relativamente semplice.

## Parametri

- Tensione di funzionamento: DC 3.3V

- Distanza di rilevamento: 100mm

- Modalità di comunicazione: Comunicazione I2C

- Intervallo di temperatura: -30℃ a 85℃

## Schema di collegamento

Per prima cosa è necessario preparare i seguenti componenti:

- Scheda V4.0\*1

- Sensore TMD27713\*1

- Cavo USB\*1

- Cavi jumper\*5

Connetti il pin INT del sensore alla porta Digital 2 della scheda V4.0, il pin SCL alla porta Analog A5, il pin SDA alla porta Analog A4; connetti il pin VCC alla porta 3V3, il pin GND alla porta GND.

![Diagramma di collegamento](../media/c9319e0f5116f416380d6b3c9ddc608c.jpeg)

## Codice di esempio

Testa le capacità di interrupt di prossimità dell'APDS-9930.

Configura l'APDS-9930 via I2C e attende un interrupt esterno basato su condizioni di prossimità alte o basse. Muovi la mano vicino al sensore e osserva il LED sul pin 13.

## Collegamenti hardware

**IMPORTANTE**: l'APDS-9930 può accettare solo 3.3V!

| Arduino Pin | APDS-9930 Board | Funzione  |
| :---------: | :-------------: | :-------: |
|    3.3V     |       VCC       |   Alimentazione   |
|     GND     |       GND       |  Massa   |
|     A4      |       SDA       | Dati I2C  |
|     A5      |       SCL       | Clock I2C |
|      2      |       INT       | Interrupt |
|     13      |        -        |    LED    |

**Risorse**: Include Wire.h e APDS9930.h

**Specifiche dell'ambiente di sviluppo**: Scritto in Arduino 1.0.5

Copia e incolla il codice qui sotto nell'IDE Arduino.

```c
#include <Wire.h>
#include <APDS9930.h>

// Pins
#define APDS9930_INT    2  // Needs to be an interrupt pin
#define LED_PIN         13 // LED for showing interrupt

// Constants
#define PROX_INT_HIGH   600 // Proximity level for interrupt
#define PROX_INT_LOW    0  // No far interrupt

// Global variables
APDS9930 apds = APDS9930();
float ambient_light = 0; // can also be an unsigned long
uint16_t ch0 = 0;
uint16_t ch1 = 1;
uint16_t proximity_data = 0;
volatile bool isr_flag = false;

void setup() {

  // Set LED as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(APDS9930_INT, INPUT);

  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("------------------------------"));
  Serial.println(F("APDS-9930 - ProximityInterrupt"));
  Serial.println(F("------------------------------"));

  // Initialize interrupt service routine
  attachInterrupt(digitalPinToInterrupt(APDS9930_INT), interruptRoutine, FALLING);

  // Initialize APDS-9930 (configure I2C and initial values)
  if (apds.init()) {
    Serial.println(F("APDS-9930 initialization complete"));
  }
  else {
    Serial.println(F("Something went wrong during APDS-9930 init!"));
  }

  // Adjust the Proximity sensor gain
  if (!apds.setProximityGain(PGAIN_2X)) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }

  // Set proximity interrupt thresholds
  if (!apds.setProximityIntLowThreshold(PROX_INT_LOW)) {
    Serial.println(F("Error writing low threshold"));
  }
  if (!apds.setProximityIntHighThreshold(PROX_INT_HIGH)) {
    Serial.println(F("Error writing high threshold"));
  }

  // Start running the APDS-9930 proximity sensor (interrupts)
  if (apds.enableProximitySensor(true)) {
    Serial.println(F("Proximity sensor is now running"));
  }
  else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

  // Start running the APDS-9930 light sensor (no interrupts)
  if (apds.enableLightSensor(false)) {
    Serial.println(F("Light sensor is now running"));
  }
  else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

#ifdef DUMP_REGS
  /* Register dump */
  uint8_t reg;
  uint8_t val;

  for (reg = 0x00; reg <= 0x19; reg++) {
    if ((reg != 0x10) && \
      (reg != 0x11))
    {
      apds.wireReadDataByte(reg, val);
      Serial.print(reg, HEX);
      Serial.print(": 0x");
      Serial.println(val, HEX);
    }
  }
  apds.wireReadDataByte(0x1E, val);
  Serial.print(0x1E, HEX);
  Serial.print(": 0x");
  Serial.println(val, HEX);
#endif

}

void loop() {

  // If interrupt occurs, print out the proximity level
  if (isr_flag) {

    // Read proximity level and print it out
    if (!apds.readProximity(proximity_data)) {
      Serial.println("Error reading proximity value");
    }
    else {
      Serial.print("Proximity detected! Level: ");
      Serial.print(proximity_data);
      Serial.print("   ");
    }
    apds.readAmbientLightLux(ambient_light);
    // Read the light levels (ambient, red, green, blue)
    if (!apds.readAmbientLightLux(ambient_light) ||
      !apds.readCh0Light(ch0) ||
      !apds.readCh1Light(ch1)) {
      Serial.println(F("Error reading light values"));
    }
    else {
      Serial.print(F("Ambient: "));
      Serial.print(ambient_light);
      Serial.print(F("  Ch0: "));
      Serial.print(ch0);
      Serial.print(F("  Ch1: "));
      Serial.println(ch1);
    }

    // Turn on LED for a half a second
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);

    // Reset flag and clear APDS-9930 interrupt (IMPORTANT!)
    isr_flag = false;
    if (!apds.clearProximityInt()) {
      Serial.println("Error clearing interrupt");
    }

  }
}

void interruptRoutine() {
  isr_flag = true;
}
```

Nota: prima di compilare il codice ricordati di posizionare la libreria nella cartella libraries dell'IDE Arduino. Altrimenti la compilazione fallirà.

## Risultato d'esempio

![Risultato d'esempio (illustrazione)](../media/f2c369c253c3b5fd8cf2c9df39f1c01a.png)

Testato con il software Arduino-1.8.2; aprendo il monitor seriale puoi vedere i dati come mostrato nella figura qui sotto.

![Risultato d'esempio (illustrazione)](../media/607fe1d8c324c14c06492d96d60eb0ca.png)

---

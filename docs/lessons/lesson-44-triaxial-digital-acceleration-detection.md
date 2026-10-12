# Les 44: Drie-assige digitale versnellingsdetectie

> **Kit:** Keyestudio 48-in-1 Sensorkit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 44: Drie-assige digitale versnellingsdetectie illustratie](../media/2a26949601eb888348b798711fe1151e.jpeg)

## Introductie

MMA8452Q is een slimme laag-vermogen, drie-assige, capacitatieve micromachine-versnellingssensor met 12-bits resolutie.

Deze versnellingssensor heeft rijke ingebouwde functionaliteit, met flexibele door de gebruiker programmeerbare opties en twee interrupt-pinnen configuratie.

De ingebouwde interrupt-functie kan het totale stroomverbruik verlagen en de last van constant polleren van gegevens in de hoofdprocessor wegnemen.

Daarnaast heeft de MMA8452Q een door de gebruiker te kiezen bereik van ±2g / ±4g / ±8g, en kan real-time hoogdoorlaatgefilterde gegevens en niet-gefilterde gegevens afgeven.

Dit apparaat kan een ingebouwde functie configureren om een inertiële wake-up interrupt-signaal te genereren, waardoor de MMA8452Q in de statische toestand in een laag-vermogenmodus kan blijven terwijl het gebeurtenissen bewaakt.

## Prestatiespecificaties

- Voedingsspanningsbereik: 1.95 V tot 3.6 V

- Interface spanning: 1.6 V tot 3.6 V

- Optioneel dynamisch bereik: ±2g / ±4g / ±8g

- Output-datafrequentie (ODR) bereik: 1.56Hz tot 800Hz

- Ruis: 99μg/√Hz

- 12-bits en 8-bits digitale outputs;

- I2C digitale output-interface (tot 2.25MHz wanneer de pull-up weerstand 4.7kΩ is);

- Twee programmeerbare interrupt-pinnen toegepast op zes interrupt-bronnen;

- Drie ingebouwde bewegingsdetectiekanalen: vrije-val-detectie, puls-detectie, schud-detectie;

- Richtingsdetectie (transversaal/ longitudinaal) met instelbare vertragingcompensatie;

- Automatische wake-up en automatische slaap-ODR kunnen automatisch aangepast worden;

- Gegevens met hoogdoorlaatfilter kunnen in realtime geëxporteerd worden;

- Stroomverbruik: 6μA – 165μA

## Aansluitschema

Bereid eerst de volgende onderdelen voor:

- V4.0-bord*1

- MMA8452Q-sensor*1

- USB-kabel*1

- Jumperdraden*4

Verbind de SCL-pin met de Analog A5-poort, de SDA-pin met de Analog A4-poort; verbind de positieve pin met de 3V3-poort, de negatieve pin met de GND-poort.

![Aansluitschema illustratie](../media/fdd68f7da45d46e65f42918eac68a2f3.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library
// Begin using the library by creating an instance of the MMA8452Q
//  class. We'll call it "accel". That's what we'll reference from
//  here on out.
MMA8452Q accel;
// The setup function simply starts serial and initializes the
//  accelerometer.
void setup()
{
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");

  // Choose your adventure! There are a few options when it comes
  // to initializing the MMA8452Q:
  //  1. Default init. This will set the accelerometer up
  //     with a full-scale range of +/-2g, and an output data rate
  //     of 800 Hz (fastest).
  accel.init();
  //  2. Initialize with FULL-SCALE setting. You can set the scale
  //     using either SCALE_2G, SCALE_4G, or SCALE_8G as the value.
  //     That'll set the scale to +/-2g, 4g, or 8g respectively.
  //accel.init(SCALE_4G); // Uncomment this out if you'd like
  //  3. Initialize with FULL-SCALE and DATA RATE setting. If you
  //     want control over how fast your accelerometer produces
  //     data use one of the following options in the second param:
  //     ODR_800, ODR_400, ODR_200, ODR_100, ODR_50, ODR_12,
  //     ODR_6, or ODR_1.
  //     Sets to 800, 400, 200, 100, 50, 12.5, 6.25, or 1.56 Hz.
  //accel.init(SCALE_8G, ODR_6);
}

// The loop function will simply check for new data from the
//  accelerometer and print it out if it's available.
void loop()
{
  // Use the accel.available() function to wait for new data
  //  from the accelerometer.
  if (accel.available())
  {
    // First, use accel.read() to read the new variables:
    accel.read();

    // accel.read() will update two sets of variables.
    // * int's x, y, and z will store the signed 12-bit values
    //   read out of the accelerometer.
    // * floats cx, cy, and cz will store the calculated
    //   acceleration from those 12-bit values. These variables
    //   are in units of g's.
    // Check the two function declarations below for an example
    // of how to use these variables.
    printCalculatedAccels();
    //printAccels(); // Uncomment to print digital readings

    // The library also supports the portrait/landscape detection
    //  of the MMA8452Q. Check out this function declaration for
    //  an example of how to use that.
    printOrientation();

    Serial.println(); // Print new line every time.
  }
}

// The function demonstrates how to use the accel.x, accel.y and
//  accel.z variables.
// Before using these variables you must call the accel.read()
//  function!
void printAccels()
{
  Serial.print(accel.x, 3);
  Serial.print("\t");
  Serial.print(accel.y, 3);
  Serial.print("\t");
  Serial.print(accel.z, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.cx, accel.cy,
//  and accel.cz variables.
// Before using these variables you must call the accel.read()
//  function!
void printCalculatedAccels()
{
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.readPL()
// function, which reads the portrait/landscape status of the
// sensor.
void printOrientation()
{
  // accel.readPL() will return a byte containing information
  // about the orientation of the sensor. It will be either
  // PORTRAIT_U, PORTRAIT_D, LANDSCAPE_R, LANDSCAPE_L, or
  // LOCKOUT.
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}
```

Opmerking: voordat je de code compileert, vergeet niet de bibliotheek in de libraries-map van de Arduino IDE te plaatsen. Anders zal het compileren mislukken.

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/9f81d233c0387bc32d25951abd3a407c.png)

Na het uploaden van de code en het openen van de seriële monitor, worden de drie-assige versnellingen van de sensor en de status hieronder weergegeven.

![Voorbeeldresultaat illustratie](../media/03421d279e2e961d7b40f645b7576d73.jpeg)

---

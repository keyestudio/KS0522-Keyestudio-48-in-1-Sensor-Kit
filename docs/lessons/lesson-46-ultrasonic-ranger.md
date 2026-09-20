# Lektion 46: Ultraschall-Entfernungsmesser

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 46: Ultraschall-Entfernungsmesser Abbildung](../media/c170155a5fb03abdc10866e25e3670b2.jpeg)

## Beschreibung

Da Ultraschall im Medium eine starke Richtwirkung, geringen Energieverlust und große Reichweite hat, wird er häufig zur Abstandsmessung verwendet, z. B. in Entfernungsmessern und Positionsmessgeräten.

Das Ultraschall-Detektormodul kann einen berührungslosen Messbereich von 2cm–450cm bereitstellen, mit einer Messgenauigkeit von bis zu 3mm, was für normale Anforderungen sehr gut geeignet ist.

Das Modul enthält einen Ultraschallsender und -empfänger sowie die entsprechende Steuerschaltung.

## Funktionsschema

Die Messsequenz des HC-SR04 ist unten dargestellt:

![Funktionsschema Abbildung](../media/a7b0fc57b2e387962071da618153ad68.jpeg)

1\. Zuerst TRIG auf LOW ziehen, und dann mit einem mindestens 10us langen High-Pegel-Signal auslösen;

2\. Nach dem Auslösen sendet das Modul automatisch acht 40KHZ-Rechteckwellen und prüft automatisch, ob ein Signal zurückkommt.

3\. Wenn ein Signal zurückkehrt, gibt ECHO ein HIGH-Signal aus; die Dauer des High-Pegels ist die Zeit vom Senden bis zum Empfang des Ultraschalls.
$$
Messdistanz = Dauer\ des\ High\text{-}Pegels * 340\ m/s * 0{,}5
$$

## Parameter

- Betriebsspannung: 5 V DC

- Betriebsstrom: 15mA

- Messbereich: 2-450cm

- Erfassungswinkel: 15 Grad

- Eingangsauslösepuls: 10 µs TTL-Pegel

- Ausgangs-Echo-Signal: TTL-Pegelausgang (HIGH), proportional zur Entfernung.

## Pinbelegung

![Pinbelegung Abbildung](../media/c03e563bcd19796b483156724bae174a.png)

## Anschlussdiagramm

Zuerst müssen Sie die folgenden Komponenten vorbereiten:

- V4.0-Board\*1

- Ultraschallsensor\*1

- USB-Kabel\*1

- Jumperkabel\*4

Als Nächstes beachten Sie bitte die folgende Verbindungstabelle:

![Anschlussdiagramm Abbildung](../media/e708c019b57984a07feb241672793982.jpeg)

Hinweis: D4 und D5 sind die digitalen Pins 4 und 5.

Sie können sich am folgenden Anschlussdiagramm orientieren:

![Anschlussdiagramm Illustration](../media/b5b964743eac977e687c454b64e061fa.jpeg)

Nach dem korrekten Anschluss können Sie damit Entfernungen messen; der Entfernungswert wird im Monitor angezeigt.

## Testcode

Kopieren Sie den folgenden Testcode und fügen Sie ihn in die Arduino-Software ein.

```c
///////////////////////////////////////////////////////////////////////////////
int inputPin=4; // define ultrasonic signal receiver pin ECHO to D4
int outputPin=5; // define ultrasonic signal transmitter pin TRIG to D5
 void setup()
{
Serial.begin(9600);
pinMode(inputPin, INPUT);
pinMode(outputPin, OUTPUT);

}
void loop()
{
digitalWrite(outputPin, LOW); delayMicroseconds(2);
digitalWrite(outputPin, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
delayMicroseconds(10);
digitalWrite(outputPin, LOW);
int distance = pulseIn(inputPin, HIGH); // Read receiver pulse time
distance= distance/58; // Transform pulse time to distance
Serial.println(distance); //Output distance
delay(50);
}
///////////////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Abbildung](../media/0dcff2ae88366ce40190b77f25d271d7.png)

Nachdem Sie den Code erfolgreich auf das V4.0-Board hochgeladen haben, öffnen Sie den seriellen Monitor. Wenn Sie ein Objekt vor den Ultraschallsensor halten (näher und weiter entfernt), erkennt er die Entfernung des Objekts. Der Wert wird im Monitor wie unten angezeigt.

![Beispielergebnis Abbildung](../media/1dbca5dc233994f6923601d942fadba6.png)

![Beispielergebnis Abbildung](../media/dcd49cc72e7a9f993083af7625d240db.png)

---

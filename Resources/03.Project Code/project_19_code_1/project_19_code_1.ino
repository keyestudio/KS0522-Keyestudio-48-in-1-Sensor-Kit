void setup() 
{Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() 
{int sensorValue = analogRead(A0);
Serial.println(sensorValue);
  delay(1); }

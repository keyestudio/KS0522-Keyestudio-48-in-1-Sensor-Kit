const int sensorPin = 3;     // the number of the sensor pin
const int ledPin =  13;      // the number of the LED pin
int sensorState = 0;         // variable for reading the sensor status
void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(sensorPin, INPUT); }
void loop(){
  // read the state of the sensor value:
  sensorState = digitalRead(sensorPin);
  // if it is, the sensorState is HIGH:
  if (sensorState == HIGH) {     
     digitalWrite(ledPin, HIGH);  
  } 
  else {
       digitalWrite(ledPin, LOW); 
  }
}

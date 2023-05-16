void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate at 9600 bps
}
void loop()
{
      int val;
      val=analogRead(0);   //connect mic sensor to Analog 0
      Serial.println(val,DEC);// print the sound value on serial monitor       
      delay(100);
}

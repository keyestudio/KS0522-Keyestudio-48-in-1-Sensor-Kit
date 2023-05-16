int Led=13;// set pin for LED 
int Shock=3// set pin for collision sensor
;int val;// set digital variable val
void setup()
{ 
pinMode(Led,OUTPUT);// set pin LED as output
pinMode(Shock,INPUT);// set collision sensor as input
}
void loop()
{
val=digitalRead(Shock);// read value on pin 3 and assign it to val
if(val==HIGH)// when collision sensor detects a signal, LED turns on.
{
digitalWrite(Led,LOW);
} else
{
digitalWrite(Led,HIGH);
}
}

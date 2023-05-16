#include <Servo.h>// define a header file. Special attention here, you can call the servo function directly from Arduino's software menu   

Servo myservo;// define servo variable name
void setup()
{
myservo.attach(9);// select servo pin(9 or 10)
}
void loop()
{
myservo.write(90);// set rotating angle of the motor
}

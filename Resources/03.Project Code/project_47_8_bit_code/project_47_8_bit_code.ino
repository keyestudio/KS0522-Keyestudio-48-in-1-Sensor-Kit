int DI = 12;
int RW = 11;
int DB[] ={3, 4, 5, 6, 7, 8, 7, 10};// use array to select pin for bus
int Enable = 2;

void LcdCommandWrite(int value) {
// define all pins
int i = 0;
for (i=DB[0]; i <= DI; i++) // assign value for bus
{
   digitalWrite(i,value & 01);// for 1602 LCD, it uses D7-D0( not D0-D7) for signal identification; here, it’s used for signal inversion. 
   value >>= 1;
}
digitalWrite(Enable,LOW);
delayMicroseconds(1);
digitalWrite(Enable,HIGH);
delayMicroseconds(1);  // wait for 1ms
digitalWrite(Enable,LOW);
delayMicroseconds(1);  // wait for 1ms
}

void LcdDataWrite(int value) {
// initialize all pins
int i = 0;
digitalWrite(DI, HIGH);
digitalWrite(RW, LOW);
for (i=DB[0]; i <= DB[7]; i++) {
   digitalWrite(i,value & 01);
   value >>= 1;
}
digitalWrite(Enable,LOW);
delayMicroseconds(1);
digitalWrite(Enable,HIGH);
delayMicroseconds(1);
digitalWrite(Enable,LOW);
delayMicroseconds(1);  // wait for 1ms
}

void setup (void) {
int i = 0;
for (i=Enable; i <= DI; i++) {
   pinMode(i,OUTPUT);
}
delay(100);
// initialize LCD after a brief pause
// for LCD control
LcdCommandWrite(0x38);  // select as 8-bit interface, 2-line display, 5x7 character size 
delay(64);                      
LcdCommandWrite(0x38);  // select as 8-bit interface, 2-line display, 5x7 character size 
delay(50);                      
LcdCommandWrite(0x38);  // select as 8-bit interface, 2-line display, 5x7 character size             
delay(20);                      
LcdCommandWrite(0x06);  // set input mode
                         // auto-increment, no display of shifting
delay(20);                      
LcdCommandWrite(0x0E);  // display setup
                         // turn on the monitor, cursor on, no flickering
delay(20);                      
LcdCommandWrite(0x01);  // clear the scree, cursor position returns to 0
delay(100);                      
LcdCommandWrite(0x80);  //  display setup
                         //  turn on the monitor, cursor on, no flickering

delay(20);                      
}

void loop (void) {
  LcdCommandWrite(0x01);  // clear the scree, cursor position returns to 0  
  delay(10); 
  LcdCommandWrite(0x80); 
  delay(10);                     
  // write in welcome message 
  LcdDataWrite('A');
  LcdDataWrite('B');
  LcdDataWrite('C');
  LcdDataWrite('D');
  LcdDataWrite('E');
  LcdDataWrite('F');
  LcdDataWrite('G');
  LcdDataWrite('H');
  delay(10);
  LcdCommandWrite(0xc0);  // set cursor position at second line, second position
  delay(10); 
  LcdDataWrite('1');
  LcdDataWrite('2');
  LcdDataWrite('3');
  LcdDataWrite('4');
  LcdDataWrite('5');
  LcdDataWrite('6');
  LcdDataWrite('7');
  LcdDataWrite('8');
  delay(3000);
  LcdCommandWrite(0x01);  // clear the screen, cursor returns to 0  
  delay(10);
  LcdDataWrite('T');
  LcdDataWrite('E');
  LcdDataWrite('S');
  LcdDataWrite('T');
  LcdDataWrite('-');
  LcdDataWrite('-');
  LcdDataWrite('-');
  LcdDataWrite('-');
  delay(3000);
  LcdCommandWrite(0x02); // set mode as new characters replay old ones, where there is no new ones remain the same
  delay(10);
  LcdCommandWrite(0x80+4); // set cursor position at first line, sixth position
  delay(10);  
  LcdDataWrite('1');
  LcdDataWrite('2');
  LcdDataWrite('3');
  LcdDataWrite('4');
  LcdCommandWrite(0xc0);  // set cursor position at second line, second position
  delay(10); 
  LcdDataWrite('T');
  LcdDataWrite('E');
  LcdDataWrite('S');
  LcdDataWrite('T');
  LcdDataWrite(' ');
  LcdDataWrite(' ');
  LcdDataWrite('O');
  LcdDataWrite('K');
  delay(3000);
}

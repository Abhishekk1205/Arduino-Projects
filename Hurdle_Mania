#include <Servo.h>
#define ea 10
#define eb 11
int aa= 250;
int m1a = 8, m1b = 9, m2a = 12, m2b = 13;    //for motors
int a = 12;  //for light
int ch1,ch2,ch3,ch4,ch5,ch6;
 
void setup()
{
pinMode(3,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);
Serial.begin(9600);
}
 
void loop()
{  
ch1= pulseIn(3,HIGH);
ch2= pulseIn(5,HIGH);
ch3= pulseIn(6,HIGH);
Serial.print("ch1= ");
Serial.print(ch1);Serial.print("\t");Serial.print("ch2= ");
Serial.print(ch2);Serial.print("\t");Serial.print("ch3= ");
Serial.print(ch3);Serial.print("\t");

speed();

if(ch1>1480 && ch1<1510 && ch2>=1470 && ch2<1510)             //stop
 {stop(); }

else if(ch1>=1480 && ch1<=1510 && ch2>=1510 && ch2<2000)      //forward
 {forward(); }

else if(ch1>=1480 && ch1<=1510 && ch2>=900 && ch2<=1470)      //backward
 {back(); }
 
else if(ch1>=900 && ch1<=1480 && ch2>=1470 && ch2<=1510)      //left
 {left(); }
 
else if(ch1>=1510 && ch1<=2000 && ch2>=1470 && ch2<=1510)     //right
 {right(); }
}
 
 void speed()
{
if(ch3>=986 && ch3<1094)
{         aa=0;  Serial.println("Speed 1"); }
else if(ch3>=1094 && ch3<1193)
{         aa=25; Serial.println("Speed 2"); }
else if(ch3>=1193 && ch3<1293)
{         aa=45; Serial.println("Speed 3"); }
else if(ch3>=1293 && ch3<1392)
{         aa=65; Serial.println("Speed 4"); }
else if(ch3>=1392 && ch3<1491)
{         aa=85; Serial.println("Speed 5"); }
else if(ch3>=1491 && ch3<1590)
{         aa=105;Serial.println("Speed 6"); }
else if(ch3>=1590 && ch3<1689)
{         aa=135;Serial.println("Speed 7"); }
else if(ch3>=1689 && ch3<1788)
{         aa=150;Serial.println("Speed 8"); }
else if(ch3>=1788 && ch3<1887)
{         aa=175;Serial.println("Speed 9"); }
else if(ch3>=1887 && ch3<1980)
{         aa=200;Serial.println("Speed 10"); }
else if(ch3>=1980)
{         aa=225;Serial.println("Speed max"); }
}

void stop()
{Serial.println("Stop\t");
digitalWrite(m1a, LOW);
digitalWrite(m1b, LOW);
digitalWrite(m2a, LOW);
digitalWrite(m2b, LOW); 
}

void forward()
{Serial.println("Forward\t");
digitalWrite(m1a, HIGH);
digitalWrite(m1b, LOW);
digitalWrite(m2a, HIGH);
digitalWrite(m2b, LOW);
enspeed();
}

void back()
{Serial.println("Backward\t");
digitalWrite(m1a, LOW);
digitalWrite(m1b, HIGH);
digitalWrite(m2a, LOW);
digitalWrite(m2b, HIGH); 
enspeed();
}

void left()
{Serial.println("left\t");
digitalWrite(m1a, HIGH);
digitalWrite(m1b, LOW);
digitalWrite(m2b, HIGH);
digitalWrite(m2a, LOW); 
enspeed();
}

void right()
{Serial.println("right\t");
digitalWrite(m1a, LOW);
digitalWrite(m1b, HIGH);
digitalWrite(m2a, HIGH);
digitalWrite(m2b, LOW);
enspeed();
}

void enspeed()
{
  analogWrite(ea, aa);   analogWrite(eb, aa);
}

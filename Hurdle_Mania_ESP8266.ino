#define ea   14          // Enable/speed motors Right        GPIO14(D5)
#define eb   12          // Enable/speed motors Left         GPIO12(D6)
#define m1a  15          // L298N in1 motors Right           GPIO15(D8)
#define m1b  13          // L298N in2 motors Right           GPIO13(D7)
#define m2a  2           // L298N in3 motors Left            GPIO2(D4)
#define m2b  0           // L298N in4 motors Left            GPIO0(D3)
const int ch11 = D0; // Connect to the PWM signal of channel 1
const int ch22 = D1; // Connect to the PWM signal of channel 2
const int ch33 = D2; // Connect to the PWM signal of channel 3;
int ch1= 0;
int ch2= 0;
int ch3= 0;

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

String command;             //String to store app command state.
int aa = 800;         // 400 - 1023.
int speed_Coeff = 3;

const char* ssid = "NodeMCU Car";
ESP8266WebServer server(80);
 
void setup()
{
pinMode(ch11,INPUT);
pinMode(ch22,INPUT);
pinMode(ch33,INPUT);
pinMode(ea, OUTPUT);
pinMode(eb, OUTPUT);  
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);
Serial.begin(115200);
}
 
void loop()
{  
 ch1= pulseIn(ch11,HIGH);
 ch2= pulseIn(ch22,HIGH);
 ch3= pulseIn(ch33,HIGH);
Serial.print("ch1= ");
Serial.print(ch1);Serial.print("\t");Serial.print("ch2= ");
Serial.print(ch2);Serial.print("\t");Serial.print("ch3= ");
Serial.print(ch3);Serial.print("\t");

speed();

if(ch1>1420 && ch1<1510 && ch2>=1420 && ch2<1510)             //stop
 {stop(); }

else if(ch1>=1420 && ch1<=1510 && ch2>=1510 && ch2<2000)      //backward
 {back(); }

else if(ch1>=1420 && ch1<=1510 && ch2>=900 && ch2<=1420)      //forward
 {forward(); }
 
else if(ch1>=900 && ch1<=1420 && ch2>=1420 && ch2<=1510)      //right
 {right(); }
 
else if(ch1>=1510 && ch1<=2000 && ch2>=1420 && ch2<=1510)     //left
 {left(); }
}
 
 void speed()
{
if(ch3>=986 && ch3<1094)
{         aa=400;  Serial.println("Speed 1"); }
else if(ch3>=1094 && ch3<1193)
{         aa=470; Serial.println("Speed 2"); }
else if(ch3>=1193 && ch3<1293)
{         aa=540; Serial.println("Speed 3"); }
else if(ch3>=1293 && ch3<1392)
{         aa=610; Serial.println("Speed 4"); }
else if(ch3>=1392 && ch3<1491)
{         aa=680; Serial.println("Speed 5"); }
else if(ch3>=1491 && ch3<1590)
{         aa=750;Serial.println("Speed 6"); }
else if(ch3>=1590 && ch3<1689)
{         aa=820;Serial.println("Speed 7"); }
else if(ch3>=1689 && ch3<1788)
{         aa=890;Serial.println("Speed 8"); }
else if(ch3>=1788 && ch3<1887)
{         aa=960;Serial.println("Speed 9"); }
else if(ch3>=1887 && ch3<1980)
{         aa=1023;Serial.println("Speed 10"); }
else if(ch3>=1980)
{         aa=1023;Serial.println("Speed max"); }
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

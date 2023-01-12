int a=8, b=9, c=10, d=11; //Digital pin for motors
int s0=A0; //Analog pin for IR sensors
int p=0, q=0, r=0; //reading stored for sensors
void setup()
{
Serial.begin(9600);
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(s0,INPUT);
}
void loop()
{
p =analogRead(s0);
Serial.println(p);
if(p>600) 
{
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
}
else if(p<=600) 
{
digitalWrite(a,LOW); 
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
}
}

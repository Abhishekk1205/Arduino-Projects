int a=8; //Digital pin for led
int s0=A0; //Analog pin for IR sensors
int p=0; //reading stored for sensors
void setup()
{
Serial.begin(9600);
pinMode(a,OUTPUT);
pinMode(s0,INPUT);
}
void loop()
{
p =analogRead(s0);
Serial.println(p);
if(p>600) digitalWrite(a,HIGH);

else if(p<=600) digitalWrite(a,LOW); 

}

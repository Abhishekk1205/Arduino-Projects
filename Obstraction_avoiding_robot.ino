#define echo 5
#define trig 6
#define led 13
void setup()
{
pinMode(trig, OUTPUT);
pinMode(echo,INPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);
}
void loop()
{
long time,dist;
digitalWrite(trig,LOW);
delayMicroseconds(2);

digitalWrite(trig,HIGH);
delayMicroseconds(10);

digitalWrite(trig,LOW);
time = pulseIn(echo,HIGH);

dist = time/2/29.1;
Serial.println(dist);

delay(1000);
if (dist<100)
{
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
}
else
{
digitalWrite(1,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
}
}

int m1a = 9, m1b = 10, m2a = 11, m2b = 12;
char c;
void setup()
{
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);
Serial.begin(9600);
}
void loop()
{
while (Serial.available() > 0)
{ c = Serial.read();
Serial.println(c);
}
if( c == 'F') //forward
{
digitalWrite(m1a, HIGH);
digitalWrite(m1b, LOW);
digitalWrite(m2a, HIGH);
digitalWrite(m2b, LOW); }
else if(c == 'B') //backward
{ digitalWrite(m1a, LOW);
digitalWrite(m1b, HIGH);
digitalWrite(m2a, LOW);
digitalWrite(m2b, HIGH); }
else if(c == 'L') //left
{ digitalWrite(m1a, LOW);
digitalWrite(m1b, LOW);
digitalWrite(m2a, HIGH);
digitalWrite(m2b, LOW); }
else if(c == 'R') //right
{ digitalWrite(m1a, HIGH);
digitalWrite(m1b, LOW);
digitalWrite(m2a, LOW);
digitalWrite(m2b, LOW); }
else if(c == 'S') //stop
{ digitalWrite(m1a, LOW);
digitalWrite(m1b, LOW);
digitalWrite(m2a, LOW);
digitalWrite(m2b, LOW); }
else if(c == 'I') //forward right
{ digitalWrite(m1a, HIGH);
digitalWrite(m1b, LOW);
digitalWrite(m2a, LOW);
digitalWrite(m2b, LOW); }
else if(c == 'J') //forward left
{ digitalWrite(m1a, LOW);
digitalWrite(m1b, HIGH);
digitalWrite(m2a, LOW);
digitalWrite(m2b, LOW); }
else if(c == 'G') //backward right
{ digitalWrite(m1a, LOW);
digitalWrite(m1b, LOW);
digitalWrite(m2a, HIGH);
digitalWrite(m2b, LOW); }
else if(c == 'H') //backward left
{ digitalWrite(m1a, LOW);
digitalWrite(m1b, LOW);
digitalWrite(m2a, LOW);
digitalWrite(m2b, HIGH); }
}

int ch1,ch2,ch3,ch4,ch5,ch6;
void setup() 
{
pinMode(3,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);
pinMode(11,INPUT)
Serial.begin(9600);
}
void loop() 
{
ch1= pulseIn(3,HIGH);
ch2= pulseIn(5,HIGH);
ch3= pulseIn(6,HIGH);
ch4= pulseIn(9,HIGH);
ch5= pulseIn(10,HIGH);
ch6= pulseIn(11,HIGH);

Serial.print((ch1-986)/10);Serial.print("\t");
Serial.print((ch2-986)/10);Serial.print("\t");
Serial.print((ch3-986)/10);Serial.print("\t");
Serial.print((ch4-986)/10);Serial.print("\t");
Serial.print((ch5-986)/10);Serial.print("\t");
Serial.println((ch6-986)/10);
}

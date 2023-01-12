char t;
const int r1=2,r2=3,l1=4,l2=5;
 
void setup() {
Serial.begin(9600);
pinMode(r1,OUTPUT); 
pinMode(r2,OUTPUT);
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
}
 
if(t == 'F'){
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
}
 
else if(t == 'B'){
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
}
 
else if(t == 'L'){ 
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  delay(100);
  t = 'S';
}
 
else if(t == 'R'){
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  delay(100);
  t = 'S';
}
}

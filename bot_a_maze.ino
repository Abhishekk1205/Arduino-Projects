const int trigPin1 = 11; // middle sensor

const int echoPin1 = 10; // middle sensor

const int trigPin2 = A3; // right sensor

const int echoPin2 = A4; // right sensor

const int trigPin3 = A2; // left sensor

const int echoPin3 = A5; // left sensor

const int in1 = 9; // motor 1 forward

const int in2 = 8; // motor 1 reverse

const int in3 = 4; // engine 2 forward

const int in4 = 3; // engine 2 reverse

const int enA = 5; // motor 1 speed

const int enB = 6; // motor 2 speed

#define PWM 90// speeds of our motors

#define DIS 12 // sensor sight distance
void setup()

{

  pinMode(trigPin1, OUTPUT); // as output

  pinMode(echoPin1, INPUT); // as input

 

  pinMode(trigPin2, OUTPUT);

  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);

  pinMode(echoPin3, INPUT);

 

  pinMode(in1, OUTPUT);

  pinMode(in2, OUTPUT);

  pinMode(in3, OUTPUT);

  pinMode(in4, OUTPUT); // as output

  pinMode(enA, OUTPUT);

  pinMode(enB, OUTPUT);

}
void loop()

{

  if ( FrontSensor() < DIS && RightSensor() <DIS && LeftSensor()<DIS)
  {

         turn_right();

         delay(3000);

//then reverse

  }

  else if (FrontSensor() <DIS && RightSensor() <DIS && LeftSensor()>DIS)

  {

  turn_left();



  }

  else if (FrontSensor() <DIS && RightSensor() >DIS && LeftSensor()<DIS)
  {

  turn_right();


  }

  else if (FrontSensor() <DIS && RightSensor() >DIS && LeftSensor()>DIS)

  {

  turn_right();



  }

  else if (FrontSensor() >DIS && RightSensor() >DIS && LeftSensor()<DIS)

  {

  turn_right();



  delay(180);

  forward();

  }

  else if (FrontSensor() >DIS && RightSensor() <DIS && LeftSensor()>DIS)

  {

  turn_left();



  delay(180);

  forward();

  }

  else

  {

  forward();

  }

}

void forward()

{

  digitalWrite(in1, HIGH);

  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);

  digitalWrite(in4, LOW);

  analogWrite(enA, PWM);

  analogWrite(enB, PWM);

}

void turn_left()

{

  digitalWrite(in1, HIGH);

  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);

  digitalWrite(in4, HIGH);

  analogWrite(enA, PWM);

  analogWrite(enB, PWM);

}

void turn_right()

{

  digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);

  digitalWrite(in4, LOW);

  analogWrite(enA, PWM);

  analogWrite(enB, PWM);

}

void reverse()

{

  digitalWrite(in1, LOW);

  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);

  digitalWrite(in4, HIGH);

  analogWrite(enA, PWM);

  analogWrite(enB, PWM);

}

void stop()

{

  digitalWrite(in1, LOW);

  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);

  digitalWrite(in4, LOW);

  analogWrite(enA, LOW);

  analogWrite(enB, LOW);

}

long FrontSensor ()

{

long stop;

 digitalWrite(trigPin1, LOW); 

 delayMicroseconds(5); 

 digitalWrite(trigPin1, HIGH);

 delayMicroseconds(10); 

 digitalWrite(trigPin1, LOW);

 stop = pulseIn(echoPin1, HIGH);

 return (stop/30);

}

long RightSensor () 

{

long stop;

 digitalWrite(trigPin2, LOW);

 delayMicroseconds(5); 

 digitalWrite(trigPin2, HIGH);

 delayMicroseconds(10); 
 
 digitalWrite(trigPin2, LOW);

 stop = pulseIn(echoPin2, HIGH);

 return (stop/62);

}

long LeftSensor ()    
{

long stop;

 digitalWrite(trigPin3, LOW); 

 delayMicroseconds(5); 

 digitalWrite(trigPin3, HIGH);

 delayMicroseconds(10); 

 digitalWrite(trigPin3, LOW);

 stop = pulseIn(echoPin3, HIGH);
return(stop/50);
}

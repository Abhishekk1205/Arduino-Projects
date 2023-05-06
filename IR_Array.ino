const int sensor1 = A0; // IR sensor 1 connected to analog pin A0
const int sensor2 = A1; // IR sensor 2 connected to analog pin A1
const int sensor3 = A2; // IR sensor 3 connected to analog pin A2
const int sensor4 = A3; // IR sensor 4 connected to analog pin A3
const int sensor5 = A4; // IR sensor 5 connected to analog pin A4
const int sensor6 = A5; // IR sensor 6 connected to analog pin A5

const int motor1 = 3; // Motor 1 connected to pin 3
const int motor2 = 5; // Motor 2 connected to pin 5

int sensorValues[6]; // array to store sensor values

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  readSensors(); // Read sensor values and update sensorValues array
  
  // If the robot is on the line, go straight
  if (sensorValues[2] > 600) {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, HIGH);
    Serial.println("Going straight");
  }
  // If the robot is off the line to the right, turn right
  else if (sensorValues[2] < 600 && sensorValues[1] > 600 && sensorValues[0] < 600) {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    Serial.println("Turning right");
  }
  // If the robot is off the line to the left, turn left
  else if (sensorValues[2] < 600 && sensorValues[3] > 600 && sensorValues[4] < 600) {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    Serial.println("Turning left");
  }
  // If the robot is completely off the line, stop
  else {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    Serial.println("Stopping");
  }
}

// Function to read sensor values and update sensorValues array
void readSensors() {
  sensorValues[0] = analogRead(sensor1);
  sensorValues[1] = analogRead(sensor2);
  sensorValues[2] = analogRead(sensor3);
  sensorValues[3] = analogRead(sensor4);
  sensorValues[4] = analogRead(sensor5);
  sensorValues[5] = analogRead(sensor6);
}

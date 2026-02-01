int in1 = A5;
int in2 = A4;
int in3 = A3;
int in4 = A2;
int enA = 5;
int enB = 3;

#define S0 4
#define S1 9     // FIXED (was 1 — Serial conflict)
#define S2 6
#define S3 7
#define OUT 8
#define TRIG_PIN 10
#define ECHO_PIN 12
#define irSensorPin 2
#include <Servo.h>
Servo servo;  // create servo object to control a servo

enum LineColor {
  LINE_WHITE,
  LINE_BLUE,
  LINE_NONE
};

int obstruction_range = 5;
int numBlue = 0;

void setup() {

  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(13);  // attaches the servo on pin 9 to the servo objectư

  servo.write(104);

  pinMode(irSensorPin, INPUT);  // Set IR sensor pin as input

  // TCS3200 frequency scaling (20%)
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
  delay(500);
}

unsigned int readColor() {
  return pulseIn(OUT, LOW);
}

void loop() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int red = 255 - readColor();

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int green = 255 - readColor();

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int blue = 255 - readColor();

  

  LineColor line = senseLine(red, green, blue);

  // if (senseLine(red,green,blue) == LINE_BLUE)  {
  //   numBlue++;
  // }

  // if (numBlue == 1) {
  //   pickUp();
  // } else if (numBlue == 2) {
  //   drop67gooner();
  // }

  followLine(line);





  bool obstruction_detected = obstruction_IR();
  if (obstruction_detected) {
    reroute();
    if (line == LINE_NONE) {
      break;
    }
  }

  // for (int pos = 104; pos <= 134; pos += 1) {  // rotate slowly from 0 degrees to 180 degrees, one by one degree
  //   // in steps of 1 degree
  //   servo.write(pos);  // control servo to go to position in variable 'pos'
  //   delay(10);         // waits 10ms for the servo to reach the position
  // }
  // delay(1000);

  // for (int pos = 134; pos >= 107; pos -= 1) {  // rotate from 180 degrees to 0 degrees, one by one degree
  //   servo.write(pos);                        // control servo to go to position in variable 'pos'
  //   delay(10);                               // waits 10ms for the servo to reach the position
  // }
  
 

}

LineColor senseLine(int r, int g, int b) {
  if (r >= 200 && g >= 200 && b >= 205) {
    return LINE_WHITE;
  } 
  else if (b >= 200 && g <= 192 && r <= 175) {
    return LINE_BLUE;
  } 
  else {
    return LINE_NONE;
  }
}

void followLine(LineColor line) {
  switch (line) {
    case LINE_WHITE:
      moveLeft(40);
      break;

    case LINE_BLUE:
      stopMotors();
      rotateRight(150);
      break;

    case LINE_NONE:
      moveRight(40);
      break;
  }
}

void moveForward(int time) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 90);
  analogWrite(enB, 90);
  delay(time);
}

void moveRight(int time) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 100);
  analogWrite(enB, 0);
  delay(time);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void rotateRight(int time) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 120);
  analogWrite(enB, 120);
  delay(time);
}

void moveLeft(int time) {
  // motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  // motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
  delay(time);
}

void rotateLeft(int time) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 100);
  // motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
  delay(time);
} 

void pickUp() {
  //rotateLeft(1000);
  //moveBackwards(500);
  for (int pos = 104; pos <= 134; pos += 1) {  // rotate slowly from 0 degrees to 30 degrees, one by one degree
    // in steps of 1 degree
    servo.write(pos);  // control servo to go to position in variable 'pos'
    delay(15);         // waits 10ms for the servo to reach the position
  }

}

void drop67gooner() {
  //rotateRight(1000);
  for (int pos = 134; pos >= 104; pos -= 1) {  // rotate from 45 degrees to 0 degrees, one by one degree
    servo.write(pos);                        // control servo to go to position in variable 'pos'
    delay(15);                               // waits 10ms for the servo to reach the position
  }
//   moveForwards(500);
//   rotateLeft(1000);
}

void reroute() {
  // Move right to get off the path
  rotateLeft(1000); // assuming it's in degrees
  moveForward(2000); // adjust based on how long the obstruction is 
  rotateRight(750);
  moveForward(3000); // adjust again
  rotateRight(750); // adjust again
  moveForward(2000);
  rotateLeft(750);
  stopMotors();
}

bool obstruction_IR() {
  int sensorValue = digitalRead(irSensorPin); // Read the IR sensor output

  if (sensorValue == LOW) { // If Obstacle detected (This might be HIGH for your sensor, based on whether it is active-low or active-high. Adjust if required.)
    Serial.println("Obstacle detected!");
    return true;
  } else { // No obstacle
    Serial.println("No obstacle.");
    return false;
  }

  delay(100); // Small delay for stability
}

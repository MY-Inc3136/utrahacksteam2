int in1 = A5;
int in2 = A4;
int in3 = A3;
int in4 = A2;

int ea1 = 3;
int ea2 = 5;




void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(ea1, 100);
  analogWrite(ea2, 100);

}

void loop() {
  moveFoward(100);
  delay(100);
}

// adjust in case flipped 
void moveFoward(int time) { // in milliseconds
  digitalWrite(in1, HIGH);//this block of code moves the car forward
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);//set this high to turn car right
  digitalWrite(in4, LOW);
  delay(time);
}

void moveRight(int time) {
  // motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(time);

} 

void moveLeft(int time) {
  // motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(time);

} 

void moveBackwards(int time) {
  // motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(time);
}

void rotateRight(int time) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(time);

}

void rotateLeft(int time) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(time);
} 

// void pickUp() {
//   rotateLeft(1000);
//   moveBackwards(500);
//   for (int pos = 0; pos <= 30; pos += 1) {  // rotate slowly from 0 degrees to 30 degrees, one by one degree
//     // in steps of 1 degree
//     servo.write(pos);  // control servo to go to position in variable 'pos'
//     delay(15);         // waits 10ms for the servo to reach the position
//   }

// }

// void drop67gooner() {
//   rotateRight(1000);
//   for (int pos = 30; pos >= 0; pos -= 1) {  // rotate from 45 degrees to 0 degrees, one by one degree
//     servo.write(pos);                        // control servo to go to position in variable 'pos'
//     delay(15);                               // waits 10ms for the servo to reach the position
//   }
//   moveForwards(500);
//   rotateLeft(1000);
// }

// change this so nothing conflits 
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define OUT 8



int dCm = 30;

const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;


void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,  HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  

  const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
  int distance = duration/29/2;


  // maybe mount ultrasonic sensor on top to detect the boxes
  // 5 cm? 
  if (distance > 0 && distance < dCm) { // additional condition if If
    // do something(movement logic)
  } else {
    // color logic
  } 



}


void followLine(int r, int g, int b) {
  // detect color
  if () {

  }
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

voit rotateLeft(int time) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(time);
} 

// change this so nothing conflits 
int in1 = A5;
int in2 = A4;
int in3 = A3;
int in4 = A2;

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

  servo.attach(13);
  servo.write(0);


}

unsigned int readColor() {
  // pulseIn measures LOW time of output wave
  return pulseIn(OUT, LOW);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,  HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // RED
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  unsigned int red = 255 - readColor();

  // GREEN
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  unsigned int green = 255 - readColor();

  // BLUE
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  unsigned int blue = 255 - readColor();


  // varible declaration

  char currentColor;
  int numBlue = 0;

  // do I even need current color
  if (93 <= red && red <= 120 && 85 <= green && green <= 95 && 110 <= blue && blue <= 115) {
    currentColor = 'B';
    followLine('B');
    


  } else if (220 <= red && red <= 225 && 140 <= green && green <= 146 && 165 <= blue && blue <= 170) {
    currentColor = 'r';
    followLine('r');

  } else if (190 <= red && red <= 195 && 210 <= green && green <= 220 && 198 <= blue && blue <= 202) {
    currentColor = 'g'
    followLine('g');

  } else if (159 <= red && red <= 170 && 180 <= green && green <= 184 && 210 <= blue && blue <= 217) {
    numBlue++;
    


  } else {
    currentColor = 'p'
  }

  if (numBlue == 1) {
    pickup();
  } else if (numBlue == 2) {
    drop67gonner();
  }
  
  // if numBlue == 2, then drop

  

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


void followLine(char colorType) {
  // detect color
  if (colorType == 'r' || colorType == 'g' || colorType == 'B') {
    moveRight(500);
  } else {
    moveLeft(500);
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

void rotateLeft(int time) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(time);
} 

void pickUp() {
  rotateLeft(1000);
  moveBackwards(500);
  for (int pos = 0; pos <= 30; pos += 1) {  // rotate slowly from 0 degrees to 30 degrees, one by one degree
    // in steps of 1 degree
    servo.write(pos);  // control servo to go to position in variable 'pos'
    delay(15);         // waits 10ms for the servo to reach the position
  }

}

void drop67gooner() {
  rotateRight(1000);
  for (int pos = 30; pos >= 0; pos -= 1) {  // rotate from 45 degrees to 0 degrees, one by one degree
    servo.write(pos);                        // control servo to go to position in variable 'pos'
    delay(15);                               // waits 10ms for the servo to reach the position
  }
  moveForwards(500);
  rotateLeft(1000);
}

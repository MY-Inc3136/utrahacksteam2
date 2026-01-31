
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int dCm = 30;

const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;


void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
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
  if (distance > 0 && distance < dCm) {

  }



}

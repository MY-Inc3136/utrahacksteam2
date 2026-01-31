/* Detect obstructions
 * Navigate around obstruction using set routine and go back to path as usual
 */

const int ULTRASONIC_TRIG_PIN = 10;
const int ULTRASONIC_OUT_PIN = 11;
const int ULTRASONIC_ECHO_PIN = 12;

int obstruction_range = 5;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  // reroute if obstruction detected
  if (obstruction_detected()) 
    reroute();
  

}

void reroute() {
  // Move right to get off the path
  moveRight(50); // adjust timing based on how long it needs to move right for
  rotateLeft(90); // assuming it's in degrees
  moveForward(100); // adjust based on how long the obstruction is 
  rotateLeft(90);
  moveForward(100); // adjust again
  rotateRight(90); // adjust again
  
}

long get_distance() {

  long duration;
  
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);

  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH, 20000);

  return duration * 0.034 / 2;
  
}

bool obstruction_detected() {
  long distance = get_distance();

  // FOR DEBUGGING
  Serial.print("Obstruction detected at");
  Serial.print(distance);
  Serial.print(" cm, "); 
  
  // If the distance to the nearest object is within range
  if(distance <= obstruction_range) {
    Serial.println("within range => reroute");
    return true; // TRUE, there is an obstruction detected
    
  } else {
    Serial.println("not within range => stay on path");
    return false; // FALSE, there is no obstruction detected
  }
  
}

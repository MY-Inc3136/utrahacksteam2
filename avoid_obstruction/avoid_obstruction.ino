/* Detect obstructions
 * Navigate around obstruction using set routine and go back to path as usual
 */

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

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

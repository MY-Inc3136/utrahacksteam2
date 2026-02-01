// IR Sensor Test Code
// Wittle pookie edition 💕

int irPin = 9;      // IR sensor OUT pin
int irValue = 0;   // Variable to store sensor reading

void setup() {
  pinMode(irPin, INPUT);      // Set IR pin as input
  Serial.begin(9600);         // Start Serial Monitor
}

void loop() {
  irValue = digitalRead(irPin);  // Read the IR sensor

  if (irValue == HIGH) {
    Serial.println("Object detected 👀✨");
  } else {
    Serial.println("No object 😴");
  }

  delay(200);  // Small delay so it’s readable
}

// TCS3200 test code

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define OUT 8

void setup() {
  Serial.begin(9600);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.println("TCS3200 Color Sensor Test");
}

unsigned int readColor() {
  // pulseIn measures LOW time of output wave
  return pulseIn(OUT, LOW);
}

void loop() {
  // RED
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  unsigned int red = readColor();

  // GREEN
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  unsigned int green = readColor();

  // BLUE
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  unsigned int blue = readColor();

  Serial.print("R: ");
  Serial.print(255 - red);
  Serial.print("  G: ");
  Serial.print(255 - green);
  Serial.print("  B: ");
  Serial.println(255 - blue);

  delay(500);
}

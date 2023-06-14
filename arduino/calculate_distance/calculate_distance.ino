// defines pins numbers
const int trigPin1 = 7;
const int echoPin1 = 6;
const int trigPin2 = 3;
const int echoPin2 = 4;
// defines variables
long duration1;
int distance1;
long duration2;
int distance2;
void setup() {
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Measure distance for the first sensor
  distance1 = getDistance(trigPin1, echoPin1);
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  // Measure distance for the second sensor
  distance2 = getDistance(trigPin2, echoPin2);
  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Delay between measurements
  delay(1000);

}

int getDistance(int trigPin, int echoPin) {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculating the distance based on the speed of sound (approximated at 343 meters per second)
  int distance = duration * 0.0343 / 2;

  return distance;
}

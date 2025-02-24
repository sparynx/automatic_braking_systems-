// Arduino Code for Ultrasonic Braking System
const int trigPin = 9;  // Trigger pin of ultrasonic sensor
const int echoPin = 10; // Echo pin of ultrasonic sensor
const int motor1 = 5;   // Motor control pin 1
const int motor2 = 6;   // Motor control pin 2

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    long duration;
    int distance;

    // Send trigger signal
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo signal
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; // Convert to cm

    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 10) {
        // Stop motors if obstacle is too close
        digitalWrite(motor1, LOW);
        digitalWrite(motor2, LOW);
    } else {
        // Continue moving forward
        digitalWrite(motor1, HIGH);
        digitalWrite(motor2, HIGH);
    }
    delay(100);
}
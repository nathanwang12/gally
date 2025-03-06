// Define motor control pins (only Motor A is used)
#define MOT_A1_PIN 15  // Motor A Input 1
#define MOT_A2_PIN 33  // Motor A Input 2
#define MOT_B1_PIN 12
#define MOT_B2_PIN 27

void setup() {
    Serial.begin(115200);  // Start Serial Monitor
    pinMode(MOT_A1_PIN, OUTPUT);
    pinMode(MOT_A2_PIN, OUTPUT);
    pinMode(MOT_B1_PIN, OUTPUT);
    pinMode(MOT_B2_PIN, OUTPUT);

    Serial.println("Starting motor test...");

    // Move motor forward
    analogWrite(MOT_A1_PIN, 180);
    digitalWrite(MOT_A2_PIN, LOW);
    analogWrite(MOT_B1_PIN, 180);
    digitalWrite(MOT_B2_PIN, LOW);
    Serial.println("Motor should be moving FORWARD (A1 = HIGH, A2 = LOW)");
    Serial.println("Motor should be moving FORWARD (B1 = HIGH, B2 = LOW)");
}

void loop() {
    // Keep running and print status every second
    Serial.println("Motors running...");
    delay(1000);
}
const int ledPin = 5; // Pin 5 supports PWM

void setup() {
  Serial.begin(115200);
  delay(5000);
  Serial.println(__FILE__);
  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(10);
  }
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(10);
  }
}
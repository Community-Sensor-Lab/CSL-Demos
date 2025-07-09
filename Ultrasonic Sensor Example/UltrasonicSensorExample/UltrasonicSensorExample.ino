//Sourced From: https://gist.github.com/dhruvsaidava/661acb770fb10ab0f7400d12cb5c0525
// https://content.instructables.com/FRW/614F/H994I1VE/FRW614FH994I1VE.txt?_gl=1*k5ec1d*_ga*MTQwNjkxNTA0MC4xNzE5ODYyNDA1*_ga_NZSJ72N6RX*czE3NTA3NzkzOTYkbzQkZzEkdDE3NTA3NzkzOTYkajYwJGwwJGgw

// Pin assignments
const int trigPin = 5;    // Pin for sending trigger signal
const int echoPin = 6;    // Pin for receiving echo signal
const int redPin = 10;      // Pin for red LED
const int yellowPin = 11;  // Pin for yellow LED
const int greenPin = 12;   // Pin for green LED
const int bluePin = 13;    // Pin for blue LED

// Variables for storing distance and duration
long duration, distance;

void setup() {
  // Set pin modes
  delay(5000);
  Serial.print(__FILE__);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(yellowPin, LOW);
}

void loop() {
  // Send trigger signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure duration of echo signal
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = (duration / 2) / 29.1;

  // Set LED color based on distance
  if (distance < 10) {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);

    delay(500);
  } else if (distance < 20) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
    delay(500);
  } else if (distance < 30) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
    delay(500);
  } else if (distance < 45) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
    delay(500);
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    delay(500);
  }
}
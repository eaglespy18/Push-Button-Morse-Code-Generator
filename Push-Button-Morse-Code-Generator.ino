const int buttonPin = 2;
const int ledPin = 8;
const int buzzerPin = 9;

unsigned long pressStart;
unsigned long pressTime;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(buttonPin) == HIGH) {

    pressStart = millis();

    while (digitalRead(buttonPin) == HIGH);  // wait for release

    pressTime = millis() - pressStart;

    if (pressTime < 300) {
      dot();
      Serial.println(".");
    } 
    else {
      dash();
      Serial.println("-");
    }
  }
}

void dot() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(200);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(200);
}
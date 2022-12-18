const int LATCH_PIN = 8;
const int CLOCK_PIN = 12;
const int DATA_PIN = 11;

byte ledStatus;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ledStatus = 0;
  Serial.println(ledStatus);
  for (int i = 0; i < 8; ++i) {
    ledStatus = (ledStatus << 1) | 1;
    Serial.println(ledStatus);
    digitalWrite(LATCH_PIN, LOW);
    delay(500);
    shiftOut(DATA_PIN
    , CLOCK_PIN, MSBFIRST, ledStatus);
    digitalWrite(LATCH_PIN, HIGH);
    delay(500);
  }

  for (int i = 0; i < 8; ++i) {
    ledStatus = ledStatus << 1;
    Serial.println(ledStatus);
    digitalWrite(LATCH_PIN, LOW);
    delay(500);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ledStatus);
    digitalWrite(LATCH_PIN, HIGH);
    delay(500);
  }
  
}

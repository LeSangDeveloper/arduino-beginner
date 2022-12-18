const int RED_PIN = 10;
const int GREEN_PIN = 7;
const int BLUE_PIN = 8;

const int DELAY_TIME = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  displayAllBasicColors();
  showSpectrum();
}

void displayAllBasicColors() {
  uint8_t SIGNALS[] = {LOW, HIGH};
	// Tắt toàn bộ các led - cái này dễ mà ha
 
	for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        digitalWrite(RED_PIN, SIGNALS[i]);
	      digitalWrite(GREEN_PIN, SIGNALS[j]);
	      digitalWrite(BLUE_PIN, SIGNALS[k]);
	
	      delay(DELAY_TIME);
      }
    }
  }

}

void showSpectrum() {
  for (int i = 0; i < 768; i++) {
    showRGB(i);
    delay(10);              
  }
}

void showRGB(int color) {
  int redPWM;
  int greenPWM;
  int bluePWM;

  if (color <= 255) {
    redPWM = 255 - color;
    greenPWM = color;
    bluePWM = 0;        
  }

  else if (color <= 511) {
    redPWM = 0;
    greenPWM = 255 - (color - 256);
    bluePWM = (color - 256);
  }

  else  {
    redPWM = (color - 512);
    greenPWM = 0;
    bluePWM = 255 - (color - 512);
  }

  analogWrite(RED_PIN, redPWM);
  analogWrite(GREEN_PIN, greenPWM);
  analogWrite(BLUE_PIN, bluePWM);
}
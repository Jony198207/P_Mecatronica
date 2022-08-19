#define LED 13 
#define BTN 12

int button_state;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(BTN,INPUT);
}

void loop() {
  button_state = digitalRead(BTN);

  if(button_state == 1) {
    // Rutina de 4 Hz
    digitalWrite(LED,HIGH);
    delay(250);
    digitalWrite(LED,LOW);
    delay(250);
  }

  else {
    // Rutina de 1 Hz
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);
  }
}

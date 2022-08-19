#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10
#define LED5 9
#define LED6 8

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1,HIGH);
  digitalWrite(LED6,HIGH);
  delay(5000);
  
  digitalWrite(LED6,LOW);
  digitalWrite(LED5,HIGH);
  delay(1000);
  digitalWrite(LED1,LOW);
  digitalWrite(LED5,LOW);

  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  delay(5000);

  digitalWrite(LED3,LOW);
  digitalWrite(LED2,HIGH);
  delay(1000);
  digitalWrite(LED4,LOW);
  digitalWrite(LED2,LOW);

}

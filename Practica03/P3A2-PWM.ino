# define pot A0
# define led 13

float value = 0;
float brillo = 0;
int pwm = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  
  value = analogRead(pot);
  pwm = value/4;
  
  analogWrite(led,pwm);
  
  brillo = value/1023*100;
  Serial.print("Brillo: ");
  Serial.println(brillo);
  delay(100);

}

# define pot A0
# define led 13

float value = 0;
float voltaje = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  
  value = analogRead(pot);
  voltaje = value/1023*5;
  Serial.print("Voltaje: ");
  Serial.println(voltaje);
  delay(100);
  // despues de 613 bits (más de 3 volts) se prende el led

  if (voltaje > 3) {
    digitalWrite(led,HIGH);
  }
  else {
    digitalWrite(led,LOW);
  }
}

#define MotA 10
#define MotB 11
#define pot A0

float value = 0;
float voltaje = 0;

void setup() {
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pot);
  voltaje = map(value,0,1023,0,5);
  if (voltaje > 0 && voltaje < 2) {
    levogirico();
  } 
  else if (voltaje >= 2 && voltaje < 3) {
    detener();
  }
  if (voltaje >= 3 && voltaje < 5) {
    dextrogiro();
  } 
  delay(10);
}

void levogirico() {
  Serial.println("Levogiro");
  digitalWrite(MotA,HIGH);
  digitalWrite(MotB,LOW);
}

void dextrogiro() {
  Serial.println("Dextrogiro");
  digitalWrite(MotA,LOW);
  digitalWrite(MotB,HIGH);
}

void detener() {
  Serial.println("Detenido");
  digitalWrite(MotA,LOW);
  digitalWrite(MotB,LOW);
}

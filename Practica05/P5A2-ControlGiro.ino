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
  if (voltaje < 2) {
    levogirico();
  }
  if (voltaje > 2 and voltaje < 3) {
    dextrogiro();
  }
  if (voltaje > 3 and voltaje < 5) {
    detener();
  }
  delay(1000);
}

void levogirico() {
  Serial.print("Levogiro");
  digitalWrite(MotA,HIGH);
  digitalWrite(MotB,LOW);
}

void dextrogiro() {
  Serial.print("Dextrogiro");
  digitalWrite(MotA,LOW);
  digitalWrite(MotB,HIGH);
}

void detener() {
  Serial.print("Detenido");
  digitalWrite(MotA,LOW);
  digitalWrite(MotB,LOW);
}

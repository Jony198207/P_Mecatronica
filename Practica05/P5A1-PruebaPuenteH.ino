#define MotA 10
#define MotB 11

void setup() {
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(MotA,HIGH);
  digitalWrite(MotB,LOW);
  delay(1000);
  Serial.print("Levogiro");
  digitalWrite(MotA,LOW);
  digitalWrite(MotB,LOW);
  delay(1000);
  Serial.print("Freno pasivo");
  digitalWrite(MotA,LOW);
  digitalWrite(MotB,HIGH);
  delay(1000);
  Serial.print("Dextrogiro");
  digitalWrite(MotA,HIGH);
  digitalWrite(MotB,HIGH);
  delay(1000);
  Serial.print("Freno activo");
}

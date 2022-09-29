// Declaramos los pines 10 y 11

#define MotA 10
#define MotB 11

void setup() {
  //Iniciamos la comunicacion serial a 9600 baudios. 
  pinMode(MotA, OUTPUT); // Declaramos como salida el pin 10
  pinMode(MotB, OUTPUT); // Declaramos como salida el pin 11
  Serial.begin(9600);
}

void loop() {
  // led del pin 10 encendido
  digitalWrite(MotA,HIGH); // Damos estado alto al pin 10
  digitalWrite(MotB,LOW); // Estado bajo del pin 11
  delay(1000); // Retardo de 1 segundo mientras se realiza un levogiro
  Serial.print("Levogiro"); // Impresion textual
  
  // ambos leds apagados
  digitalWrite(MotA,LOW); // Estado bajo "0" del pin 10
  digitalWrite(MotB,LOW); // Estado bajo del pin 11
  delay(1000); // Retardo de 1 segundo
  Serial.print("Freno pasivo"); // Imprime Freno pasivo, pues no hay movimiento en este punto
  
  // Led del pin 11 prendido
  digitalWrite(MotA,LOW); // Estado bajo del pin 10
  digitalWrite(MotB,HIGH); // Estado alto del pin 11
  delay(1000); // Retardo de 1 segundo
  Serial.print("Dextrogiro"); // Se hace dextrogiro y lo imprime en la comunicación serial
  
  // ambos leds prendidos
  digitalWrite(MotA,HIGH); // Estado alto del pin 10
  digitalWrite(MotB,HIGH); // Estado bajo del pin 11 
  delay(1000); // Retardo de 1 segundo
  Serial.print("Freno activo"); // Frena la accion de manera def.
}

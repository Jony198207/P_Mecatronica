// Declaracion de variables.
  #define LED 13 

void setup() {
  // se ejecuta solo una vez. Con pines digitales I/O.
  pinMode (LED, OUTPUT); // Define que será un puerto de salida.
}

void loop() {
  // loop en el arduino mientras que este conectado.
  digitalWrite(LED, HIGH); // Si fuera bajo seria LOW= 0V, HIGH=5V.
  delay(200); //Da un retardo de .002
  digitalWrite(LED, LOW); //Apaga el LED
  delay(200); //Da un retardo de .002
  
}

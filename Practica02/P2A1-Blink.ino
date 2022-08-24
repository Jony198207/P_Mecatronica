// Declaracion de variables.
  #define LED 13 

void setup() {
  // se ejecuta solo una vez. Con pines digitales I/O.
  pinMode (LED, OUTPUT); // Define que LED, es decir el puerto 13, será un puerto de salida.
}

void loop() {
  // loop en el arduino mientras que este conectado.
  digitalWrite(LED, HIGH); // Si fuera bajo seria LOW= 0V, HIGH=5V. Por tanto, prende led
  delay(200); //Da un retardo de 1/5 de segundo
  digitalWrite(LED, LOW); //Apaga el LED
  delay(200); //Da un retardo de 1/5 de segundo
  
}

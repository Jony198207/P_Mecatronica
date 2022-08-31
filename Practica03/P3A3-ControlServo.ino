// Anadimos al programa la libreria de Servo.h para poder utilizar el elemento fisico

# include <Servo.h>

// Definimos angulo para controlar las posiciones del servo.
int angulo;
float value = 0;
// Definimos un obejeto tipo servomotor.
Servo servo1;
// Definimos la senal en el puerto A0 del potenciometro 
# define pot A0 

void setup() {
  servo1.attach(3); // definimos que el servo esta conectado al pin 3
  Serial.begin(9600); // Inicia la comunicacion con la computadora, inicia el monitor a una velocidad de 9600 baudios por segundo. 
}

void loop() {
  value = analogRead(pot); // lee el valor analogico con respecto a la posicion del potenciometro
  angulo = map(value,0,1023,0,180); // asigna a angulo el valor de entre 0 y 180 grados, guardando una relacion entre los 1023 bits y los 180 grados.
  servo1.write(angulo); // indico al servo que se mantenga a angulo grados
  delay(100); // Retardo de 0.1 segundos
  
}

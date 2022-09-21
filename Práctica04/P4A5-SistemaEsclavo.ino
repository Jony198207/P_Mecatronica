// Sistema esclavo 

# include <Wire.h> 
# include <Servo.h> // Incluimos las librerias necesarias para manipular el servo y para tener comunicacion entre sistemas esclavo y maestro. 
int angulo; // Variable entera para recibir el dato del sistema maestro

Servo serv1; // Variable tipo servomotor
void setup() {
// put your setup code here, to run once
Wire.begin(0xAF); // Inicia comunicacion y la clave para hacerlo es 0xAF
Wire.onReceive(lectura); // Hace la lectura del dato por medio del metodo lectura
serv1.attach(4); // Informa que el servo esta conectado al pin 4 (al que mandaremos las señales de rotacion)
Serial.begin(9600); // Inicia comunicacion a 9600 baudios 
}

void loop() {
// Proceso que se ejecuta
Serial.println(angulo); //Imprime en la consola de control el dato de angulo 
delay(10); //retardo de 0.01 segundo para hacer fluido el movimiento del servomotor 

}

void lectura(){
angulo = Wire.read(); // Lee el dato que simboliza al angulo de rotacion que se desea hacer proveniente del sistema maestro
serv1.write(angulo); // Escribe en las indicaciones al servomotor que debera moverse este angulo 
delay(10); //retardo de 0.01 segundo para hacer fluido el movimiento del servomotor 
}

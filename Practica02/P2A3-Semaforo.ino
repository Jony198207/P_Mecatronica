// Nota: se habla indistintamente entre foco y LED.

#define LED1 13 // Define el puerto 13 como la señal del LED 1 (Foco rojo del primer semaforo)
#define LED2 12 // Define el puerto 12 como la señal del LED 2 (Foco amarillo del primer semaforo)
#define LED3 11 // Define el puerto 11 como la señal del LED 3 (Foco verde del primer semaforo)
#define LED4 10 // Define el puerto 10 como la señal del LED 4 (Foco rojo del segundo semaforo)
#define LED5 9 // Define el puerto 9 como la señal del LED 5 (Foco amarillo del segundo semaforo)
#define LED6 8 // Define el puerto 8 como la señal del LED 6 (Foco verde del segundo semaforo)

void setup() {
  // put your setup code here, to run once:
  // Espacio en el que se definen entradas y salidas. 
  pinMode(LED1,OUTPUT); // Define LED1, es decir el puerto 13, como salida 
  pinMode(LED2,OUTPUT); // Define LED2, es decir el puerto 12, como salida 
  pinMode(LED3,OUTPUT); // Define LED3, es decir el puerto 11, como salida 
  pinMode(LED4,OUTPUT); // Define LED4, es decir el puerto 10, como salida 
  pinMode(LED5,OUTPUT); // Define LED5, es decir el puerto 9, como salida 
  pinMode(LED6,OUTPUT); // Define LED6, es decir el puerto 8, como salida 
}

void loop() {
  // put your main code here, to run repeatedly:
  // Loop para ejecutar el código mientras se este activo
  
  digitalWrite(LED1,HIGH); // Enciende el foco rojo del primer semaforo 
  digitalWrite(LED6,HIGH); // Enciende el foco verde del segundo semaforo
  delay(5000); // da delay de 5 seg. para que los focos anteriores duren encendidos este tiempo antes de la siguiente instruccion 
  
  digitalWrite(LED6,LOW); // Apaga el foco verde del segundo semaforo
  digitalWrite(LED5,HIGH); // Prende el foco amarillo del segundo semaforo
  delay(1000); // delay de 1 segundo para que el foco amarillo del segundo semaforo dure este tiempo prendido
  digitalWrite(LED1,LOW); // Apaga foco rojo del primer semaforo 
  digitalWrite(LED5,LOW); // Apaga el foco amarillo del segundo semaforo

  digitalWrite(LED3,HIGH); // Prende el foco verde del primer semaforo
  digitalWrite(LED4,HIGH); // Prende el foco rojo del segundo semaforo
  delay(5000); // Da tiempo de 5 segundos para que las dos instrucciones anteriores duren este tiempo antes de ejecutar la siguiente instruccion

  digitalWrite(LED3,LOW); // Apaga el foco verde del primer semaforo
  digitalWrite(LED2,HIGH); // Prende el foco amarillo del primer semaforo
  delay(1000); // Da un tiempo de un segundo para que dure encendido el foco amarillo anterior
  digitalWrite(LED4,LOW); // Apaga el foco rojo del segundo semaforo
  digitalWrite(LED2,LOW); // Apaga el foco amarillo del primer semaforo
  
  // Aqui ya se cumplio la secuencia simultanea de los dos semaforos que se pedia, si el programa sigue corriendo en el arduino, lo anterior se repite debido al Loop.

}

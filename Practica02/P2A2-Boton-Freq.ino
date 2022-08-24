#define LED 13 
#define BTN 12

// se declara una variable tipo entero para saber si el boton del circuito es presionado o no 
int button_state;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT); // Indica que LED, es decir el puerto 13 será una salida
  pinMode(BTN,INPUT); // Indica que BTN será una entrada de datos, es decir, el puerto 12 será una entrada. 
}

void loop() {
  // Se redefine el estado del boton según se haya presionado o no el botón 
  button_state = digitalRead(BTN);

  // Si el boton fue presionado se ejecuta con una rutina de 4 hz, es decir, parpadea cada 0.25 segundos
  if(button_state == 1) {
    // Rutina de 4 Hz
    digitalWrite(LED,HIGH); // Se enciende el foco en cuestion 
    delay(250); // delay de cuarto de segundo, pues el dato esta en milesimas de segundo
    digitalWrite(LED,LOW); // Se apaga el foco en cuestion 
    delay(250);
  }

  // En el caso de que no se presione el botón se ejecuta una rutina de 1 hz, es decir, parpadea cada segundo  
  else {
    // Rutina de 1 Hz
    digitalWrite(LED,HIGH); // Se enciende el foco en cuestion 
    delay(1000); // delay de 1 segundo, pues el dato esta en milesimas de segundo
    digitalWrite(LED,LOW); // Se apaga el foco en cuestion 
    delay(1000); // delay de 1 segundo, pues el dato esta en milesimas de segundo
  }
}

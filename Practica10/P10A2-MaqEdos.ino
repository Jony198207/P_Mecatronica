# define LED 13 // Led de la placa Arduino

int estado;
int light_dif = 25; // Valor dado para calar el funcionamiento de la maquina de estados

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); // Definimos el pin como salida
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Switch para contemplar casos
  switch(estado){
    // Caso 0, que nos manda directamente al estado 1 después de imprimir "Estado 0"
    case 0:
      Serial.println("Estado 0");
      estado = 1;
      break; // termina el caso 0
     
     // Caso 1, donde apagamos el led y si light_dif es menor a 30, manda a estado 2
     case 1:
      Serial.println("Estado 1");
      digitalWrite(LED, LOW);
      if (abs(light_dif) < 30){
        estado = 2;
      }
      else{ // Si no se cumple la condicion, regresamos al estado 0
        estado = 0;
      }
      break; // termina el caso 1
    
    // Caso 2, prendemos el led e imprimimos "Estado 2", finalmente regresamos al estado 0
    case 2:
      Serial.println("Estado 2");
      digitalWrite(LED, HIGH);
      delay(1000);
      estado = 0;
      break; // termina el caso 2
    
  
  }
}

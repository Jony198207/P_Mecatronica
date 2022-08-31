// Definimos pot como la senal proveniente del potenciometro y el led.
# define pot A0
# define led 13

// Definicion de variables que se utilzaran en seguida 
float value = 0;
float voltaje = 0;
void setup() {
  Serial.begin(9600);  // Inicia comunicacion con la computadora. Empieza el monitor serial,. el 9600 son la velocidad en baudios cpor segundo 
  pinMode(led,OUTPUT); // define led como salida 
}

void loop() {
  
  value = analogRead(pot); // lee la senal analogica del potenciometro 
  voltaje = value/1023*5; // conviene a un valor propiol voltaje que se identifica 
  Serial.print("Voltaje: "); // imprime en la pantalla la palabra voltaje 
  Serial.println(voltaje); // imprime el valor del voltaje actual
  delay(100); // tiempo de retardo de 0.1 segundos. 
  // despues de 613 bits (más de 3 volts) se prende el led

  if (voltaje > 3) { // condicional, si el voltaje que se desea manipular en el momento es mayor a 3, el led se enciende, caso contrario, permanece apagado
    digitalWrite(led,HIGH); // prende el led 
  }
  else {
    digitalWrite(led,LOW); // Apaga el led. 
  }
}

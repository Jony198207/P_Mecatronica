// Definimos pot como la entrada del potenciometro, y el led.
# define pot A0
# define led 13

// Definimos valores.
float value = 0;
float brillo = 0;
int pwm = 0;

void setup() {
  Serial.begin(9600); // Inicia la comunicacion con la computadora, a una velocidad de 9600 baudios por segundo.
  pinMode(led,OUTPUT); // Definimos led como senal de salida 
}

void loop() {
  
  value = analogRead(pot); // Lee la senal del potenciometro.
  pwm = value/4; // Dividimos el valor obtenido entre 4, para obtener, m[as o menos, valores entre 0 y 250
  
  analogWrite(led,pwm); // Generamos una senal de PWM para el led 
  
  brillo = value/1023*100; // Modulamos el valor del brillo entre 0 y 100
  Serial.print("Brillo: "); // Imprime brillo
  Serial.println(brillo); // Imprime los valores del brillo segun la regulacion del potenciometro
  delay(100); // Retardo de 0.1 segundo

}

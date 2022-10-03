// pines para salida
#define MotA 10
#define MotB 11

// Pin para leer la entrada analogica
#define pot A0

#define pwm 13 // pin para la señal pwm con la que regularemos la velocidad

// definicion de valores que utilizaremos mas adelante
float value = 0;
float voltaje = 0;
float vel = 0;

void setup() {
pinMode(MotA, OUTPUT); // definimos pin 10 como salida
pinMode(MotB, OUTPUT); // definimos pin 11 como salida
pinMode(pwm, OUTPUT); // definimos pin 11 como salida
Serial.begin(9600); // Comunicacion a 9600 baudios
}

void loop() {
value = analogRead(pot); // Leemos el valor analógico del potenciometro (estará entre 0 y 1023).
voltaje = map(value,0,1023,0,5); // mapeamos lo leido a una escala entre 0 y 5 v
analogWrite(pwm,200); // cuando es 0, tenemos nuestro wmax

if (voltaje > 0 && voltaje < 2) { // Si el voltaje leído está entre 0 y 2, llama a la función levogirico() y la ejecuta
vel = map(voltaje,0,5,100,200);
analogWrite(pwm,vel);
levogirico();
}
if (voltaje == 2) {
analogWrite(pwm,100);
detener();
}
else if (voltaje > 2 && voltaje < 3) { // Si el voltaje leído está entre 2 y 3, llama a la función detener() y la ejecuta
analogWrite(pwm,0);
detener();
}
if (voltaje == 3) { // Si el voltaje es 3 hacemos dextrogiro
analogWrite(pwm,100);
desxtrogiro();
}
if (voltaje > 3 && voltaje < 5) { // Si el voltaje leído está entre 3 y 5, llama a la función dextrogiro() y la ejecuta
vel = map(voltaje,0,5,200,100);
analogWrite(pwm,vel);
dextrogiro();
}
if (voltaje == 5) { // Si el voltaje es 5 hacemos dextrogiro a maxima potencia
analogWrite(pwm,200);
dextrogiro();
}
delay(10); // retardo de 0.01 segundos
}

// Funcion para giro levogirico
void levogirico() {
Serial.println("Levogiro");
// Con esta combinacion, HIGH AND LOW, hacemos el levogiro
digitalWrite(MotA,HIGH);
digitalWrite(MotB,LOW);
}

// Funcion para dextrogiro
void dextrogiro() {
Serial.println("Dextrogiro");
//Con LOW Y HIGH hacemos un dextrogiro
digitalWrite(MotA,LOW);
digitalWrite(MotB,HIGH);
}

// funcion para detener el giro del motor
void detener() {
Serial.println("Detenido");
// Con ambos pines en LOW hacemos que se detenga el motor
digitalWrite(MotA,LOW);
digitalWrite(MotB,LOW);
}

#include <LiquidCrystal_I2C.h> //Incluimos la libreria para comunicarnos por I2C con el LCD
LiquidCrystal_I2C lcd(0x27,16,2);

#define motA1 4 // Pin de control del motor A
#define motA2 3 // Pin de control del motor A
#define motB1 6 // Pin de control del motor b
#define motB2 5 // Pin de control del motor b
#define enable1 2 // Enable motor 1
#define enable2 7 // Enable motor 2
#define voltaje A0 // medidor de voltaje
#define fotoD A1 // primer fotoresistor
#define fotoI A2 // segundo fotoresistor
#define fotoA A3 // tercer fotoresistor
#define fotoRC A4 // cuarto fotoresistor
#define trig 53 // pin de trigger
#define echo 51 // pin de echo
#define sharpP A8 // primer sensor sharp
#define sharpS A9 // segundo sensor sharp

float L_LDR, R_LDR, B_LDR, vsharpP, vsharpS, voltajeSistema, diferencia_luz; //definimos las variables que guardaran lo obtenido por los pines
float US_Sensor;
int battery;
float B_UMBRAL = 160;
float UMBRAL_SUPERIOR = 500; 
float UMBRAL_INFERIOR= -500;
void setup() {
// put your setup code here, to run once:
// Definimos la comunicaciòn serial e inicializamos todos nuestros puertos como salidas y el de echo del ultrasonico como entrada
lcd.backlight(); // Prendemos el lcd
Serial.begin(9600); // COmunicación serial
// Definición de pines como entradas o salidas 
pinMode(motA1, OUTPUT);
pinMode(motA2, OUTPUT);
pinMode(motB1, OUTPUT);
pinMode(motB2, OUTPUT);
pinMode(enable1, OUTPUT);
pinMode(enable2, OUTPUT);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
lcd.init(); // Iniciamos el lcd
}

void loop() {
// Hacemos uso de las funciones definidas que sensan el medio y imprimen los datos
lightSensor();
followLight();
voltageSensor();
distanceSensor();
temperatureSensor();
lcd_print(); // Imprimimos los valores de los LDRs
}

void followLight() {
  
  // Mientras el valor de la fotorresistencia trasera sea mayor que su umbral definido, gira a 180 grados
  while(B_LDR >= B_UMBRAL) {
    driveRobot(1,-1);
    lightSensor();
  } 
  driveRobot(0,0); //frenamos el moviemiento del robot para poder dar lugar al siguiente moviemiento. 

  // Mientras el valor de las fotorresistencias delanteras esten en el umbral definido, anda hacia el frente 
  while(diferencia_luz > UMBRAL_INFERIOR && diferencia_luz < UMBRAL_SUPERIOR) {
    driveRobot(1,1); // Si la luz se encuentra al frente, entonces avanzamos hacia ella en dirección recta. 
    lightSensor(); // Volvemos a sensar 
  }
  driveRobot(0,0);
  // Mientras el valor de la diferencia sea mayor que su umbral definido superior, gira a la izquierda.
 while(diferencia_luz > UMBRAL_SUPERIOR) {
    driveRobot(-1,1); // Giramos el robot hacia la izquierda hasta que se posicione e dirección a la luz. 
    lightSensor();
  }
    driveRobot(0,0);

  // Mientras el valor de la diferencia sea menor que su umbral definido inferior, gira a la derecha 
  while(diferencia_luz < UMBRAL_INFERIOR) {
    driveRobot(1,-1); // giro a la derecha 
    lightSensor(); // volvemos a sensar
  }
  driveRobot(0,0); // paramos el robot

}

// Mètodo que genera los movimientos por rueda
void driveRobot(float LSignal,float RSignal) {

  // Va hacia atrás
  if(LSignal < 0 && RSignal < 0 ) { 
    digitalWrite(motB2,HIGH);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,HIGH);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 85);
  }
  
  // Gira hacia izquierda sobre la rueda derecha
  if(LSignal < 0 && RSignal == 0 ) { 
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 0);
    digitalWrite(motA2,HIGH);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 85);
  }
  
  // Gira sobre su eje
  if(LSignal < 0 && RSignal > 0 ) { 
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,HIGH);
    digitalWrite(enable2, 20);
    digitalWrite(motA2,HIGH);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 45);
  }
  
  // No hay movimiento
  if(LSignal == 0 && RSignal == 0 ) { 
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 0);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 0);
  }
  
  // Gira hacia la derecha y hacia atrás  sobre la vuelta izquierda
  if(LSignal == 0 && RSignal < 0) { 
    digitalWrite(motB2,HIGH);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 0);
  }
  
  // Giro hacia delante y a la derecha sobre la rueda izquierda
  if(LSignal == 0 && RSignal > 0) { 
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,HIGH);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 85);
  }
  
  // Va hacia delante 
  if(LSignal > 0 && RSignal > 0) { 
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,HIGH);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,HIGH);
    digitalWrite(enable1, 85);
  }
  
  // Gira hacia la izquierda y hacia delante sobre la rueda derecha 
  if(LSignal > 0 && RSignal == 0) { 
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,HIGH);
    digitalWrite(enable1, 85);
  }
  
  // Giro sobre el eje
  if(LSignal > 0 && RSignal < 0) { 
    digitalWrite(motB2,HIGH);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 20);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,HIGH);
    digitalWrite(enable1, 45);
  }

}
void voltageSensor() {
voltajeSistema = analogRead(voltaje); //leemos el voltaje de alimentación y si es menor a 650 bits ponemos battery = 0
if (voltajeSistema > 650) {
battery = 1;
} else {
battery = 0;
}
}
void lightSensor() {
  R_LDR = analogRead(fotoD); //Sensamos la luz del medio con cuatro fotoresistores y usamos las de los lados para calcular la diferencia
  L_LDR = analogRead(fotoI) ; // Restamos 200 para hacer tender la diferencia a 0 en estado inicial. 
  B_LDR = analogRead(fotoA);
  diferencia_luz = R_LDR - L_LDR;
  lcd.setCursor(0,0);   
  lcd.print("L: ");
  lcd.print(L_LDR);
  lcd.setCursor(8,0);
  lcd.print("R: ");
  lcd.print(R_LDR);   //Imprimimos los valores que resultan de los fotoresistores para tener una interfaz que podamos usar para evaluar resultados
  lcd.setCursor(0,1);
  lcd.print("D: ");
  lcd.print(diferencia_luz);
  lcd.setCursor(8,1);
  lcd.print("A: ");
  lcd.print(B_LDR);
}
void distanceSensor() {
  vsharpP = analogRead(sharpP);
  vsharpS = analogRead(sharpS); //Sensamos los objetos que estan proximos a la locomocion con tres sensores (Dos Sharp y uno US)
  
  vsharpP = 1990 * (pow(vsharpP, -0.921)); //Funcion de lectura del sharp
  vsharpS = 1990 * (pow(vsharpS, -0.921));
  // Distancia con ultrasònico
  digitalWrite(trig, LOW); //Hacemos el envío y recepción del pulso ultrasonico
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  US_Sensor = pulseIn(echo, HIGH); //Calculamos la distancia que registro a partir de las lecturas
  US_Sensor = US_Sensor * 0.0343 / 2;
}

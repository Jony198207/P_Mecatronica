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
#define sharpP A10 // primer sensor sharp
#define sharpS A9 // segundo sensor sharp

// Guardamos la variable estado para saber en que estado de nuestra programación se encuentra el robot 
int estado;
String estador; // Variable auxiliar de movimientos 
float L_LDR, R_LDR, B_LDR, vsharpP, vsharpS, voltajeSistema, diferencia_luz; //definimos las variables que guardaran lo obtenido por los pines
float US_Sensor, US_Sensor2; // Sensores tipo Sharp
int battery; // Varible para conocer el estado de la batería 
float B_UMBRAL = 500; // Umbral del sensor de luz trasero
float UMBRAL_SUPERIOR = 300; // Umbral delantero maximo 
float UMBRAL_INFERIOR= -350; // Umbral trasero mínimo 
void setup() {
// Definimos la comunicaciòn serial e inicializamos todos nuestros puertos como salidas y el de echo del ultrasonico como entrada
  Serial.begin(9600);
  // Pines de motor A y B 
  pinMode(motA1, OUTPUT);
  pinMode(motA2, OUTPUT);
  pinMode(motB1, OUTPUT);
  pinMode(motB2, OUTPUT);
  // Señales de enable de ambos motores
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  // trig y echo del ultrasónico 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.init();
}

void loop() {
// Sensamos y ejecutamos la funcion encargada del movimiento del robot.
  // Invocamos a nuestras funciones para sensar el medio y con base en ello, realizar diversos movimientos
  lightSensor();
  distanceSensor();
  followLight();
}

// Funcion para seguir la luz y evadir objetos 
void followLight() {

  // Switch para contemplar casos
  switch(estado) {
    // Checa si puede avanzar o debe hacer alguna modificacion en la ruta 
    case 0:
      estador = "avanza";
      // Si hay un objeto, nos envía al estado 3
      if (US_Sensor < 10 || vsharpP < 10 || vsharpS < 10) {
        estado = 3; // Significa que se topò con un obstaculo.
      }      
      
      lcd_print();
      // Mientras se mantenga orientado con la luz mayor al umbral de la luz trasera, abra que girar hacia el
      while(B_LDR >= B_UMBRAL && US_Sensor > 10 && vsharpP > 10 && vsharpS > 10) { // Asì nos aseguramos que siempre esta orientado al frente
        estador = "atras";
        lcd_print();
        driveRobot(1,-1);
        lightSensor();
        distanceSensor();
      }

      driveRobot(0,0);
      // Si la luz se encuentra orientada hacia el frente, mantenemos nuestra ruta ideal hacia delante. Siempre sensamos al finalizaar el while para redefinir variables
      while(diferencia_luz > UMBRAL_INFERIOR && diferencia_luz < UMBRAL_SUPERIOR && US_Sensor > 10 && vsharpP > 10 && vsharpS > 10) { // Con orientaciòpn al frente, sigue.
        driveRobot(1,1);
        lightSensor();
        distanceSensor();
      }
      
      // Si esta fuera de los umbrales, checamos si hay que girar hacia la izquierda o hacia la derecha 
      if(diferencia_luz < UMBRAL_INFERIOR || diferencia_luz > UMBRAL_SUPERIOR) {
        // Girar hacia la izquierda
        if(diferencia_luz < UMBRAL_INFERIOR) {
          estado = 1; // Significa que deberà girar a la izquierda.
        }
        else {
          estado = 2; // Significa que deberà girar a la derecha.
        }
      }
      // Sensamos nuevamente para asegurarnos de que no se encontró con un nuevo obstáculo
      if (US_Sensor < 10 || vsharpP < 10 || vsharpS < 10) {
        estado = 3; // Significa que se topò con un obstaculo. Es necesario volver a checar.
      }       
      driveRobot(0,0);
    break;

    case 1:
      estador= "izq";
      lcd_print();
      // Si se encuentra con un ostaculo, manda al estado 3 
      if (US_Sensor < 10 || vsharpP < 10 || vsharpS < 10) {
        estado = 3;
      }
      
      // Mientras no este orientado hacia el frente, gira a la izquierda 
      while(diferencia_luz < UMBRAL_INFERIOR && US_Sensor > 10 && vsharpP > 10 && vsharpS > 10 ) {
        driveRobot(1,-1);
        distanceSensor();
        lightSensor();
      }
      driveRobot(0,0);
      
      // Una vez que está orientado, nos manda de nuevo al estado 0.
      if (diferencia_luz >= UMBRAL_INFERIOR){
        estado = 0;
      } // Ya esta orientado para seguir con el recorrido

      // Si ahora si se encontró con un obstaculo, manda al estado 3
      if (US_Sensor < 10 || vsharpP < 10 || vsharpS < 10) {
        estado = 3;
      }    
    break;

    case 2:
      estador= "der";
      lcd_print();
      
      // Encuentra un obstaculo y reenvia al estado 3
      if (US_Sensor < 10 || vsharpP < 10 || vsharpS < 10) {
       estado = 3;
      }
      
      // Gira a la derecha mientras los umbrales del frente no esten colocados
      while(diferencia_luz > UMBRAL_SUPERIOR && US_Sensor > 10 && vsharpP > 10 && vsharpS > 10) {
        driveRobot(-1,1);
        distanceSensor();
        lightSensor();
      }
      driveRobot(0,0);

      // Una vez orientado mandamos al estado 0
      if (diferencia_luz <= UMBRAL_SUPERIOR){
        estado = 0;
      } // Ya esta orientado para seguir con el recorrido
      
      // Volvemos a sensar para ver si es necesario corregir la trayectoria
      if (US_Sensor < 10 || vsharpP < 10 || vsharpS < 10) {
       estado = 3;
      }      
      
    break;

    case 3: // Caso en que se encuentra con un obstaculo
      estador = "obs";
      lcd_print();
      driveRobot(0,0);
      delay(500);
      if(vsharpP < vsharpS) { //vsharpS IZQUIERDO del robot; vsharpP DERECHO del robot.
      // Corrije a la izquierda
        while(US_Sensor < 10 || vsharpP < 10) { //
          estador = "corrizq";
          lcd_print();
          driveRobot(1,-1);
          distanceSensor();
          lightSensor();
        }
        driveRobot(1,1);
        delay(250);
      }
      else {
        while(US_Sensor < 10 || vsharpS < 10) { // Corrije a la derecha 
          estador = "corrDer";
          lcd_print();
          driveRobot(-1,1);
          distanceSensor();
          lightSensor();
        }
        driveRobot(1,1);
        delay(250);
      }
      driveRobot(0,0);
      estado = 0;
    break;
    }

  }

// Mètodo que genera los movimientos por rueda
void driveRobot(float LSignal,float RSignal) {

  // Giro hacia atrás
  if(LSignal < 0 && RSignal < 0 ) {
    digitalWrite(motB2,HIGH);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,HIGH);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 75);
  }
  //Giro hacia atrás sobre la rueda derecha
  if(LSignal < 0 && RSignal == 0 ) {
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, LOW);
    digitalWrite(motA2,HIGH);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 75);
  }
  // Giro sobre su propio eje
  if(LSignal < 0 && RSignal > 0 ) {
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,HIGH);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,HIGH);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 75);
  }
  // No hay movimiento
  if(LSignal == 0 && RSignal == 0 ) {
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, LOW);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, LOW);
  }
  // Giro sobre la rueda izquierda hacia atrás
  if(LSignal == 0 && RSignal < 0) {
    digitalWrite(motB2,HIGH);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, LOW);
  }
  // Giro sobre la rueda izquierda hacia delante
  if(LSignal == 0 && RSignal > 0) {
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,HIGH);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,LOW);
    digitalWrite(enable1, 85);
  }
  
  // Rueda hacia delante 
  if(LSignal > 0 && RSignal > 0) {
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,HIGH);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,HIGH);
    digitalWrite(enable1, 75);
  }
  
  // Giro sobre la rueda derecha hacia delante 
  if(LSignal > 0 && RSignal == 0) {
    digitalWrite(motB2,LOW);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,HIGH);
    digitalWrite(enable1, 75);
  }
  
  //Giro sobre el eje
  if(LSignal > 0 && RSignal < 0) {
    digitalWrite(motB2,HIGH);
    digitalWrite(motB1,LOW);
    digitalWrite(enable2, 40);
    digitalWrite(motA2,LOW);
    digitalWrite(motA1,HIGH);
    digitalWrite(enable1, 75);
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
  L_LDR = analogRead(fotoI) + 100; // Sumamos 100 para hacer tender la diferencia a 0 en estado inicial.
  B_LDR = analogRead(fotoA);
  diferencia_luz = R_LDR - L_LDR;
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
void lcd_print(){
  lcd.setCursor(0,0); //Imprimimos la diferencia de luz entre el lado derecho y izquierdo y tambien imprimimos el valor de battery
  lcd.print("I:");
  lcd.print(L_LDR);
  lcd.setCursor(0,1); 
  lcd.print("R:");
  lcd.print(R_LDR);  
  lcd.setCursor(8,0); 
  lcd.print("D:");
  lcd.print(diferencia_luz); 
  lcd.setCursor(8,1); 
  lcd.print("A:");
  lcd.print(B_LDR); 
}

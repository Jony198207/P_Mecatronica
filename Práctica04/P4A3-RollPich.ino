// Definimos los 3 puertos analógicos digitales a los que conectaremos nuestros ejes X,Y,Z
#define pot A2
#define pot2 A1
#define pot3 A0

                // DEFINICION DE VARIABLES LOCALES
// Definimos los valores de tipo flotante, pues no son exactos si no decimales. 
float valueX; // Valor de angulo que toma X
float valueY; // Valor de angulo que toma Y
float valueZ; // Valor de angulo que toma Z

// XG,YG y ZG son los valores de cada ángulo ya mapeados y reales 

float xg,yg,zg;
float z_min = 260.0; // valor mínimo que tomó nuestro sistema en z
float z_max = 387.5; // valor máximo que tomó nuestro sistema en z
float y_min = 260.0; // valor mínimo que tomó nuestro sistema en y
float y_max = 383.0; // valor máximo que tomó nuestro sistema en y
float x_min = 256.0; // valor mínimo que tomó nuestro sistema en x
float x_max = 392.0; // valor máximo que tomó nuestro sistema en x
float roll, pitch; // rotaciones respecto a los ejes x y z. 


void setup() {
// put your setup code here, to run once:
Serial.begin(9600); // Iniciamos la comunicacion a una velocidad de 9600 baudios

}

void loop() {
// put your main code here, to run repeatedly:
valueX = analogRead(pot); // Recuperamos el valor inicial de x (en grados)

valueY = analogRead(pot2); // Recuperamos el valor inicial de y (en grados)

valueZ = analogRead(pot3); // Recuperamos el valor inicial de z (en grados)

  // mapeamos a valores mas lógicos la entrada inicial que obtuvimos en cada angulo
zg = map(valueZ, z_min, z_max, -100, 100);
zg = -zg/100;

yg = map(valueY, y_min, y_max, -100, 100);
yg = -yg/100;

xg = map(valueX, x_min, x_max, -100, 100);
xg = xg/100;

// calculamos el pitch and roll segun las rotaciones que se tuvieron y las dormulas dadas
pitch = xg/(sqrt(sq(yg) + sq(zg)));
roll = yg/(sqrt(sq(xg) + sq(xg)));

pitch = (pitch*180)/3.1415; // Obtenemos el valor final de pitch
roll = (roll*180)/3.1415; // Obtenemos el valor final de roll

// En las siguientes 6 líneas imprimimos los valores correpondientes en angulos a cada inclinacion de cada eje. 
Serial.print("Xg: ");
Serial.print(xg );
Serial.print(" Yg: ");
Serial.print(yg );
Serial.print(" Zg: ");
Serial.print(zg );
Serial.print(" Roll: "); // Imprime textualmente "Roll: "
Serial.print(roll); // Imprime el contenido de roll
Serial.print("Pitch: "); // Imprime textualmente "Pitch: "
Serial.println(pitch); // Imprime el contenido de pitch

delay(150); // Retraso de 0.150 segundos

}

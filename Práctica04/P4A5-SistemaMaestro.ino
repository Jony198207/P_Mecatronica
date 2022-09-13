//Código para el maestro

# include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // Definimos los pines que usará el lcd

#define pot A2
#define pot2 A1
#define pot3 A0

float valueX;
float valueY;
float valueZ;

float xg,yg,zg;
float z_min = 262.0;
float z_max = 400.5;
float y_min = 257.0;
float y_max = 400.0;
float x_min = 256.0;
float x_max = 400.0;
float roll;
int angulo;

void setup() {
Wire.begin();
Serial.begin(9600);
lcd.init();

}

void loop() {
valueX = analogRead(pot);

valueY = analogRead(pot2);

valueZ = analogRead(pot3);

zg = map(valueZ, z_min, z_max, -100, 100);
zg = -zg/100;
yg = map(valueY, y_min, y_max, -100, 100);
yg = -yg/100;
xg = map(valueX, x_min, x_max, -100, 100);
xg = xg/100;
roll = yg/(sqrt(sq(xg) + sq(zg)));

roll = (roll*180)/3.1415;

if(roll == -90){
angulo = 0;
}
else {
if(roll == 0) {
angulo = 45;
}
else {
if(roll == 90) {
angulo = 90;
}
}
}
if(roll >= -89 and roll <=-1) {
angulo = map(roll,-89,-1,1,44);
}
if(roll >= 1 and roll <= 89) {
angulo = map(roll,1,89,45,89);
}
// LCD
lcd.backlight();
lcd.setCursor(4,0);
lcd.print("Angulo: ");
lcd.print(roll);
lcd.setCursor(4,1);
lcd.print("DatoIC2: ");
lcd.print(angulo);
delay(1000);
Wire.beginTransmission(0xAF);
Wire.write(angulo);
Wire.endTransmission();
}

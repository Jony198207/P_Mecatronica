# include <Servo.h>

int angulo;
float value = 0;
Servo servo1;
# define pot A0

void setup() {
  servo1.attach(3); // definimos que el servo esta conectado al pin 3
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pot);
  angulo = map(value,0,1023,0,180);
  servo1.write(angulo); // indico al servo que se mantenga a angulo grados
  delay(100);
  
}

// Sistema esclavo 

# include <Wire.h>
# include <Servo.h>
int angulo;

Servo serv1;
void setup() {
// put your setup code here, to run once
Wire.begin(0xAF);
Wire.onReceive(lectura);
serv1.attach(4);
Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
Serial.println(angulo);
delay(10);

}

void lectura(){
angulo = Wire.read();
serv1.write(angulo);
delay(10);
}

# define X A0
# define Y A1
# define Z A2

float Xval, Yval, Zval;
float Xg, Yg, Zg;

float z_min = 272.0;
float z_max = 412.0;

float y_min = 263.0;
float y_max = 387.0;

float x_min = 275.0;
float x_max = 393.0;

float tanAlfa, alfaGrados;
float tanBeta, betaGrados; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  Xval = analogRead(X);
  Yval = analogRead(Y);
  Zval = analogRead(Z);

  Zg = map(Zval,z_min,z_max,-100,100);
  Zg = Zg/100;

  Xg = map(Xval,x_min,x_max,-100,100);
  Xg = Xg/100;

  Yg = map(Yval,y_min,y_max,-100,100);
  Yg = Yg/100;

  tanAlfa = Yg/(sqrt(pow(Xg,2) + pow(Zg,2)));
  tanBeta = Xg/(sqrt(pow(Yg,2) + pow(Zg,2)));
  alfaGrados = (tanAlfa*180)/PI;
  betaGrados = (tanBeta*180)/PI;
  
  Serial.print("tanAlfa: ");
  Serial.print(tanAlfa);
  Serial.print("alfaGrados: ");
  Serial.print(alfaGrados);
  Serial.print("\n");
  Serial.print("tanBeta: ");
  Serial.print(tanBeta);
  Serial.print("\n");
  Serial.print("betaGrados: ");
  Serial.print(betaGrados);
  Serial.print("\n");
  //Serial.print("\n");
  
 /*Serial.print("X:");
  Serial.print(Xval);
  Serial.print("Y:");
  Serial.print(Yval);
  Serial.print("Z:");
  Serial.print(Zval);
  Serial.print("\n");

  Serial.print("Zg:");
  Serial.print(Zg);
  Serial.print("Xg:");
  Serial.print(Xg);
  Serial.print("Yg:");
  Serial.print(Yg);
  Serial.print("\n"); */
  
  delay(100);
}

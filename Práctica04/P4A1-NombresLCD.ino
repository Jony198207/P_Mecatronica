# include <LiquidCrystal.h> // importamos o incluimos librerias.

LiquidCrystal lcd(12,11,5,4,3,2); // Definimos los pines que usará el lcd
int indice = 15; // establecemos la totalidad de columnas en un fila de lcd. 
void setup() {
  lcd.begin(16,2); // Definimos el lcd de una pantalla 16x2
}

void loop() {
  lcd.setCursor(indice,0); // Definimos que el cursor en la pantalla empezará en la fila y columna indice.
  lcd.print("Jonathan_G      "); // imprime en pantalla el nombre de un integrante del equipo. Se dejan 6 espacios en blanco para completar los 16.
  lcd.setCursor(indice,1); // Definimos que el cursor en la pantalla empezará en la fila 1 y columna indice.
  lcd.print("Dante_F         "); // imprime en pantalla el nombre de un integrante del equipo.Se dejan 6 espacios en blanco para completar los 19.

  // En este if se va reduciendo, para recorrer los nombres de derecha a izquierda
  if (indice > 0){
    indice = indice - 1;
  }
  delay(100); // Retardo de 0.1 seg.
}

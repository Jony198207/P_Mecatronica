#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int indice = 15;
void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
}


void loop()
{
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

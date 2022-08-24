void setup()
{
  // Se ejecuta solo una vez. Con pines digitales I/O.
  DDRB = DDRB | B10000000; // Data Direction Register B: Inputs 0-6, Output 7. Asigna el puerto B con sus respectivas entradas y salidas. El 0 indica salida y el 1 entrada.
}
void loop()
{
  // Loop, proceso mismo de lo que se hace 
    asm (
      // En todas las lineas se emplean al final \n\t, lo que significa salto de linea
            "inicio: \n\t" // Etiqueta que indica el inicio del programa 
            "sbi 0x05,0x07 \n\t" // 
            "call tiempo \n\t"
            "cbi 0x05,0x07 \n\t"
            "call tiempo \n\t"
            "jmp main \n\t"
            "tiempo: \n\t" // Etiqueta nombrada tiempo
            "LDI r22, 45 \n\t" // Carga instantanea del valor 45 en decimal al registro 22
            "LOOP_3: \n\t" // Etiqueta nombrada LOOP_3
            "LDI r21, 255 \n\t" // Carga instantanea del valor 255 en decimal al registro 21
            "LOOP_2: \n\t" // Etiqueta nombrada LOOP_2
            "LDI r20, 255 \n\t" // Carga instantanea del valor 255 en decimal al registro 20
            "LOOP_1: \n\t" // Etiqueta nombrada LOOP_1
            "DEC r20 \n\t"  // Decrementa en 1 unidad el contenido del registro r20
            "BRNE LOOP_1 \n\t" // Hace un test de la FLAG Z, si el contenido de r20 ya es 0, pasa a la instruccion de abajo, caso contrario vuelve a la etiqueta LOOP-1 de arriba. 
            "DEC r21 \n\t" // Decrementa en 1 unidad el contenido del registro r21
            "BRNE LOOP_2 \n\t" // Hace un test de la FLAG Z, si el contenido de r21 ya es 0, pasa a la instruccion de abajo, caso contrario vuelve a la etiqueta LOOP-2 de arriba.
            // Lo anterior involucra a su vez que se repita el cargo de valor al registro r20 y su respectivo bucle. 
            "DEC r22 \n\t" // Decrementa en 1 unidad el contenido del registro r22
            "BRNE LOOP_3 \n\t" // Hace un test de la FLAG Z, si el contenido de r22 ya es 0, pasa a la instruccion de abajo, caso contrario vuelve a la etiqueta LOOP-3 de arriba.
            // Lo anterior involucra a su vez que se repita el cargo de valor al registro r20 y r21, así com sus respectivos bucles. 
            "ret \n\t" // Realiza un retorno de la subrutina, es decir, indica que se vuelve a comenzar 
      );
} 

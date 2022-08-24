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
            "LDI r22, 45 \n\t" // Carga instantanea del valor 45 en decimal al registro 45
            "LOOP_3: \n\t" // Etiqueta nombrada LOOP_3
            "LDI r21, 255 \n\t"
            "LOOP_2: \n\t" // Etiqueta nombrada LOOP_2
            "LDI r20, 255 \n\t"
            "LOOP_1: \n\t" // Etiqueta nombrada LOOP_1
            "DEC r20 \n\t"
            "BRNE LOOP_1 \n\t"
            "DEC r21 \n\t" // Decrementa en 1 unidad el contenido del registro r21
            "BRNE LOOP_2 \n\t"
            "DEC r22 \n\t" // Decrementa en 1 unidad el contenido del registro r22
            "BRNE LOOP_3 \n\t"
            "ret \n\t" // Realiza un retorno de la subrutina, es decir, indica que se vuelve a comenzar 
      );
} 

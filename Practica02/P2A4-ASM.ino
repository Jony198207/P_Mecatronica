void setup()
{
  // Se ejecuta solo una vez. Con pines digitales I/O.
  DDRB = DDRB | B10000000; // Data Direction Register B: Inputs 0-6, Output 7. Asigna el puerto B con sus respectivas entradas y salidas. El 0 indica salida y el 1 entrada.
}
void loop()
{
  // Loop, proceso mismo de lo que se hace 
    asm ( // siglas de ENSAMBLADOR, lo que indica que el siguiente codigo esta escrito en este lenguaje y que por tanto arduino necesita interpretarlo
      
      // En todas las lineas se emplean al final \n\t, lo que significa salto de linea
            "inicio: \n\t" // Etiqueta que indica el inicio del programa 
            "sbi 0x05,0x07 \n\t" // Coloca en nivel alto a estos bits, es decir setea a una entrada o salida. 
            "call tiempo \n\t" // Llama directamente a una subrutina (por su etiqueta y la ejecuta), en este caso a la de "tiempo" 
            "cbi 0x05,0x07 \n\t" // Al terminar el anterior ciclo ocurrido por la llamada del Call y retomado a este punto por la instruccion ret de abajo, borra estos bits en el registro de entrada/salida. 
            "call tiempo \n\t" // Llama directamente a una subrutina (por su etiqueta y la ejecuta), en este caso a la de "tiempo" por SEGUNDA OCASION. 
            "jmp main \n\t" //  Desvia el flujo del programa sin tomar en cuenta las condiciones actuales de las banderas ni de los datos. Esto permite saltar al siguiente codigo.
      
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
            // Lo anterior involucra a su vez que se repita el cargo de valor al registro r20 y r21, as?? com sus respectivos bucles. 
            "ret \n\t" // Realiza un retorno de la subrutina, es decir, indica que se vuelve a comenzar hacia la siguiente llamada call de arriba. De manera que este bloque de codigo se ejecuta dos veces 
      );
  
  // A este tipo de programas se les conoce como DESTELLOS, por los viajes entre llamadas y subrutinas que se hacen. 
} 

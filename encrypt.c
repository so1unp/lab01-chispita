#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#define BYTES 7

int main(int argc, char *argv[])
{
    char entrada[100]; // buffer
    int cantCaracteres;
    char *mensaje; // texto a encriptar

    srand(time(NULL));

    /*---- si no hay argumento, el texto se escribirá por entrada estándar ----*/
    if (argc < 2) {
        while ((cantCaracteres = read(0, entrada, sizeof(entrada))) > 0) {
            for (int i=0; i<cantCaracteres; i++) {
                for (int j=0; j<BYTES; j++) {
                    char byte = (rand() % 256);
                    write(1, &byte, 1);
                }
                write(1, &entrada[i], 1);
            }
        }

    /*---- si el texto fue escrito desde la línea de comando ----*/
    } else {
        cantCaracteres = strlen(argv[1]);
        mensaje = argv[1];

        for(int i=0; i<cantCaracteres; i++){
            for(int j=0; j<BYTES; j++){ // acá se imprimen los 7 bytes falsos
                char byte = (rand() % 256);
                write(1, &byte, 1);
            }
        write(1, &mensaje[i], 1); // y acá se imprime el byte real, caracter por caracter
        }
    }
    write(1, "\n", 1);
    exit(EXIT_SUCCESS);
}

/*
Cambios que se hicieron:
*Se cambió el rango del carácter aleatorio (33 -> 256) para que imprima todos los caracteres posibles.
(el profesor recomienda que se imprima cualquier carácter, por más raro que se vea en la salida,
pues no afecta a los BYTES)    
*Se quitó una parte del código que borraba el enter como otro carácter más al momento de ingresar el texto
por entrada estándar.
(el profesor recomienda que SI se lea el enter como otro carácter más)
*Se agregó un while a la entrada estándar donde read() lee por bloques (en este caso 100) y rellena el
buffer por cada iteración.
(recomendado por el profe para que el encriptador lea textos muy largos)

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#define BYTES 7

int main(int argc, char *argv[])
{
    char entrada[100]; 
    int cantCaracteres;
    char *mensaje; // texto a encriptar

    srand(time(NULL));

    /*---- si no hay argumento, el texto se escribirá por entrada estándar ----*/
    if (argc < 2) {
        cantCaracteres = read(0, entrada, sizeof(entrada)); // cantidad de bytes (o caracteres) del texto
        
        if(entrada[cantCaracteres-1] == '\n'){
            cantCaracteres--; // al presionar enter read() también lee el salto de línea como un carácter más, con esto me aseguro de borrarlo
        }

        mensaje = entrada;

    /*---- si el texto fue escrito desde la línea de comando ----*/
    } else {
        cantCaracteres = strlen(argv[1]);
        mensaje = argv[1];
    }

    for(int i=0; i<cantCaracteres; i++){
        for(int j=0; j<BYTES; j++){ // acá se imprimen los 7 bytes falsos
            char byte = (rand() % 95) + 33;
            write(1, &byte, 1);
        }
        write(1, &mensaje[i], 1); // y acá se imprime el byte real, caracter por caracter
    }
    write(1, "\n", 1);
    exit(EXIT_SUCCESS);
}
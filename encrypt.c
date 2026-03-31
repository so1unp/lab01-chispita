#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#define BYTES 7

int main(int argc, char *argv[])
{

    if (argc < 2) {
        return EXIT_FAILURE; // el programa termina sin errores si no hay argumentos
    }

    srand(time(NULL));

    int caracteres = strlen(argv[1]); // cantidad de bytes/carácteres en el string del argumento (si el argumento es "hola" entonces caracteres=4)
    char *caracter = argv[1]; // apuntador de cada carácter del string del argumento

    for(int i=0; i<caracteres; i++){
        for(int j=0; j<BYTES; j++){
            char byte = rand() % 256; // carácter aleatorio
            write(1, &byte, 1); // se escribe carácter aleatorio (con write() me aseguro que trabajo con bytes puros)
        }
        write(1, &caracter[i], 1); // se escribe carácter por carácter hasta que no hayan más (h-o-l-a) luego de escribir los 7 bytes alteatorios
    }
    
    exit(EXIT_SUCCESS);
}
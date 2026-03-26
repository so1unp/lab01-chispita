#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h> 
#include <time.h>

/**
 * Lee el mensaje a encriptar como un argumento de la linea de comandos o desde la entrada estandar y generar
 * el contenido encriptado en la salida estandar.
 */

 /**
 *void encriptar(const char *mensaje) {
    char encriptado[100]; //cantidad de caracteres a encriptar
    srand(time(NULL));
    for (int i = 0; i <= 6; i++)
    {
        char clave = (rand() % 95) + 32; // Generar una clave aleatoria entre 32 y 126 (caracteres imprimibles)
        write(1, &clave, 1); // Escribir la clave al inicio del mensaje encriptado
    }
}
 int main(int argc, char *argv[])
{
    // Agregar código aquí.
    encriptar("Hola Mundo"); // Ejemplo de mensaje a encriptar

    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}
 */
int main(int argc, char *argv[])
{
    srand(time(NULL)); // semilla
    
    for(int i=0; i < 7; i++){ // for que itera 7 veces

        char byte = rand() % 256; // carácter aleatorio
        write(1, &byte, 1); // se escribe carácter aleatorio (con write() me aseguro que trabajo con bytes puros)

        char *caracter = argv[1]; // puntero a cada carácter del string del argumento (hola)

             if(caracter[i] != '\0'){
                 write(1, &caracter[i], 1); // se escribe el carácter hasta que no hayan más
             }
    }

    exit(EXIT_SUCCESS);
}
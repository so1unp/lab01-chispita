#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BYTES_RUIDO 7 
// El bloque total es ruido + el caracter real
#define TAMANO_BLOQUE (BYTES_RUIDO + 1) 

int main() {
    char buffer[TAMANO_BLOQUE];
    ssize_t total_leido;

    while (1) {
        total_leido = 0;

        // Bucle para asegurar que completamos el bloque de 8 bytes
        while (total_leido < TAMANO_BLOQUE) {
            ssize_t n = read(0, buffer + total_leido, TAMANO_BLOQUE - total_leido);

            if (n == 0) goto fin; // Fin del archivo
            if (n < 0) {
                perror("Error al leer");
                exit(EXIT_FAILURE);
            }
            total_leido += n;
        }
        
        // Escribimos el último byte del bloque (el real)
        // Usamos el índice BYTES_RUIDO porque es la posición 7 (la octava)
        write(1, &buffer[BYTES_RUIDO], 1);
    }

fin:
    return 0;
}

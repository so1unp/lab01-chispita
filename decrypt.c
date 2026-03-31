#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BYTES_RUIDO 7

int main() {
    char buffer[BYTES_RUIDO + 1];
    ssize_t bytes_leidos;

    while ((bytes_leidos = read(0, buffer, BYTES_RUIDO + 1)) > 0) {
        
        // solo entra si leyó el bloque completo de 8 bytes
        if (bytes_leidos == (BYTES_RUIDO + 1)) {
            // escribe el octavo byte en la salida estándar (1)
            if (write(1, &buffer[BYTES_RUIDO], 1) == -1) {
                perror("Error al escribir");
                exit(EXIT_FAILURE);
            }
        }
    }

    // perror dice si ocurrió algún error
    if (bytes_leidos == -1) {
        perror("Error al leer de la entrada estándar");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

/**
 * para compilar el programa, se puede usar el siguiente comando:
 * make (depende si lo tenemos instalado) pararse en directorio del proyecto y ejecutar el comando.
 * 
 */
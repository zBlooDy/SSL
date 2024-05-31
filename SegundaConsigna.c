
// Consigna 2
// Escriba un programa comando que utilizando strtok y un automata finito resuelva el siguiente problema “dado un archivo de texto con lineas de no mas de 100 caracteres formadas por palabras separadas por blanco y dado ademas un carácter se debe crear otro archivo de texto con aquellas palabras en las que el carácter dado aparezca exactamente dos veces en la palabra. El archivo resultante debe tener una sola palabra por linea

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *archivoEntrada, *archivoSalida;
    char caracter;
    char *palabra;
    char *token;
    int contador = 0;

    if (argc != 4) {
        printf("Error: cantidad de argumentos invalida\n");
        return 1;
    }

    archivoEntrada = fopen(argv[1], "r");
    archivoSalida = fopen(argv[2], "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        printf("Error: no se pudo abrir el archivo\n");
        return 1;
    }

    caracter = argv[3][0]; //[0] va a representar el caracter que le paso por parametro 

    palabra = malloc(100 * sizeof(char)); // Reservo un espacio de 100 caracteres, ya que por consigna cada linea tiene un maximo de 100 caracteres 

    while (fgets(palabra, 100, archivoEntrada) != NULL) { // fgets lee una linea del archivo y la guarda en palabra  y retorna NULL si llega al final del archivo 
        token = strtok(palabra, " ");

        while (token != NULL) {
            for (int i = 0; i < strlen(token); i++) {
                if (token[i] == caracter) {
                    contador++;
                }
            }

            if (contador == 2) {            //El caracter debe aparecer exactamente 2 veces, ni mas ni menos.
                fprintf(archivoSalida, "%s\n", token);
            }

            contador = 0;
            token = strtok(NULL, " ");
        }
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    return 0;
}
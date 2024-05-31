// Consigna 1
// Escriba un programa que determine e informe la cantidad de lines que tiene un archivo de texto, que se pasa como argumento desde la linea de comandos. 
//Debe resolverlo utilizando fgetc

#include <stdio.h>
//argc: cantidad de argumentos que se pasan por linea de comandos
//argv : argumentos que se pasan por linea de comandos

int main(int argc, char *argv[]) {
    FILE *archivo;  
    char caracter; 
    int lineas = 1; 

    if (argc != 2) { //Si la cantidad de argumentos es distinta de 2, se imprime un mensaje de error
        printf("Error: cantidad de argumentos invalida\n");
        return 1;
    }

    archivo = fopen(argv[1], "r");

    if (archivo == NULL) {
        printf("Error: no se pudo abrir el archivo\n");
        return 1;
    }

    if ((caracter = fgetc(archivo)) != EOF)
    {
        do
        {
            if (caracter == '\n') {
                lineas++;
            }
        } while ((caracter = fgetc(archivo)) != EOF);
    }
    else    //Significa que el archivo esta vacio
    {
        lineas = 0;
    }

    fclose(archivo);

    printf("El archivo tiene %d lineas\n", lineas);

    return 0;
}

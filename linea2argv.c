#include <stdlib.h>
#include <string.h>
#include "minish.h"
/*
entrada: una cadena de caracteres, tamaño del array argv y el array argv donde se almacenaran los punteros a palabras, 
salida: el array argv con los punteros a palabras y la cantidad de palabras como int
*/

int linea2argv(char *linea, int argc, char **argv) { 
    int i = 0;
    char* token = strtok(linea, " \t"); // se separan las palabras por espacios o tabulaciones (\t)
    while (token != NULL && i < argc - 1) { // mientras haya palabras y no se llego al final del array
        argv[i++] = strdup(token); // se copia la palabra en el array argv, se "mallocaran" os strings
        token = strtok(NULL, " \t"); // se sigue con la siguiente palabra, el parametro NULL es para que continue desde donde quedo
    }
    argv[i] = NULL; // se asegura que haya NULL al final del array


    return i;
}	


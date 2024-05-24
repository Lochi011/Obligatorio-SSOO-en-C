
#include <string.h>
#include <stdio.h>
#include "minish.h"

//funcion que busca un builtin en el array de builtins, recibe un string con el comando y devuelve un puntero al builtin

struct builtin_struct *builtin_lookup(char *cmd) {
    for (int i = 0; builtin_arr[i].cmd; i++) { //recorre el array de builtins mientras cmd no sea NULL
        if (strcmp(builtin_arr[i].cmd, cmd) == 0) { //strcmp compara dos cadenas, si son iguales devuelve 0
            return &builtin_arr[i]; //si cmd es igual al comando del builtin, devuelve un puntero hacia el builtin ("&" es para devolver la direccion de memoria del builtin)
        }
    }
    return NULL; //si no se encuentra el builtin, devuelve NULL
}
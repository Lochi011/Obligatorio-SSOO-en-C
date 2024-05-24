#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include "minish.h"


#define HELP_CD      "cd [..|dir] - cambia de directorio corriente"
#define HELP_DIR     "dir [str] - muestra archivos en directorio corriente, que tengan 'str'"
#define HELP_EXIT    "exit [status] - finaliza el minish con un status de retorno (por defecto 0)"
#define HELP_HELP    "help [cd|dir|exit|help|history|getenv|pid|setenv|status|uid]"
#define HELP_HISTORY "history [N] - muestra los últimos N (10) comandos escritos"
#define HELP_GETENV  "getenv var [var] - muestra valor de variable(s) de ambiente"
#define HELP_PID     "pid - muestra Process Id del minish"
#define HELP_SETENV  "setenv var valor - agrega o cambia valor de variable de ambiente"
#define HELP_STATUS  "status - muestra status de retorno de ultimo comando ejecutado"
#define HELP_UID     "uid - muestra nombre y número de usuario dueño del minish"


int globalstaret = 0; // variable global que guarda el retorno del ultimo comando, para saber si hubo error o no
char cwd[MAXCWD]; // almacena del directorio de trabajo actual, para mostrarlo en el prompt shell

int main(){
    char input[MAXLINE]; // almacena lo que esrcribe el usuario
    char *argv[MAXWORDS]; // array de punteros a char, cada puntero en el array apunta a una palabra 
    int argc; // cantidad de palabras en el input
    int status=0 ; // guarda el retorno de las funciones, se empieza en 0 

    while (1){
        fprintf(stderr, "(minish) > "); // imprime el prompt con standar error (stderr)
        if (fgets(input, MAXLINE, stdin) == NULL){
            break; // EOF, si fgets devuelve NULL, se alcanzo el final del archivo (EOF) o hubo un error, se sale del bucle con break
        }
        input[strcspn(input, "\n")] = 0; // Eliminar el caracter de nueva linea(/n), strcspn devuelve la longitud de la cadena, si encuentra el caracter de nueva linea(/n), lo reemplaza por 0
        if (input[0] == '\0'){
            continue; // si la linea no tiene nada, se continua
        }
        argc = linea2argv(input, MAXWORDS, argv); // se llama a la funcion linea2argv, que separa las palabras de la linea y las almacena en el array argv
        if (argc == 0){
            continue; // si no hay palabras, se continua
        }   
        status = ejecutar(argc, argv); // se llama a la funcion ejecutar, que ejecuta los comandos 
        globalstaret = status; // se actualiza el status global
        
        for (int i = 0; i < argc; i++){
            free(argv[i]); // se libera la memoria asignada por linea2argv
        }
    }
    return status; // se retorna el status
}




#include "minish.h"


#define HELP_ALIAS          ""
#define HELP_COPIAR         ""
#define HELP_BASEDIRNAME    ""
#define HELP_EXIT           "exit"
#define HELP_HELP           ""
#define HELP_HISTORY        ""
#define HELP_MES            ""
#define HELP_STATUS         ""
#define HELP_CD             ""
#define HELP_DIR            ""
#define HELP_GETENV         ""
#define HELP_GID            ""
#define HELP_SETENV         ""
#define HELP_PID            ""
#define HELP_UID            ""
#define HELP_UNSETENV       ""
//defincion de funciones builtin

int builtin_alias(int argc, char **argv) {
   
    return 0;
}

int builtin_copiar(int argc, char **argv) {
    
    return 0;
}

int builtin_basedirname(int argc, char **argv) {
    
    return 0;
}

int builtin_exit(int argc, char **argv) {
    int status = globalstatret; // se guarda el status global 
    if (argc == 2){ // si se pasa un status como argumento
        status = atoi(argv[1]); // se convierte el argumento status a entero
    }
    printf("Saliendo del programa con status: %d\n", status); // se imprime el status
    exit(status); // se sale del programa con el status
}

int builtin_help(int argc, char **argv) {
   if (argc == 1){ // solo se pasa el comando help sin argumentos
        for (int i = 0; builtin_arr[i].cmd ; i++) {
            printf("%s - %s\n", builtin_arr[i].cmd, builtin_arr[i].help_txt);
            
        }
    }else if (argc == 2){ // se pasa el comando help con un argumento
        struct builtin_struct *builtin = builtin_lookup(argv[1]); // se busca el comando en la lista de builtins
        if (builtin){
            printf("%s - %s\n", builtin->cmd, builtin->help_txt); // si se encuentra, se imprime el texto de ayuda ("->" es para acceder a un campo de una estructura a traves de un puntero)
            return 0;
        }else{
            printf("No se pudo encontrar el comando: %s\n", argv[1]); // si no se encuentra, se imprime un mensaje de error
            return 1;
        }
    }else{ 
        printf("Formato incorrecto, el comando se debe usar de la siguiente manera: help[comando]\n"); // si se pasan mas de dos argumentos, se imprime un mensaje de error, help solo admite un argumento
        return 1;
    } 
    return 0;
}

int builtin_history(int argc, char **argv) {
    
    return 0;
}

int builtin_mes(int argc, char **argv) {
   
    return 0;
}

int builtin_status(int argc, char **argv) {
    
    return 0;
}

int builtin_cd(int argc, char **argv) {
    
    return 0;
}

int builtin_dir(int argc, char **argv) {
    
    return 0;
}

int builtin_getenv(int argc, char **argv) {
    
    return 0;
}

int builtin_gid(int argc, char **argv) {
    
    return 0;
}

int builtin_setenv(int argc, char **argv) {
    
    return 0;
}

int builtin_pid(int argc, char **argv) {
    
    return 0;
}

int builtin_uid(int argc, char **argv) {
    
    return 0;
}

int builtin_unsetenv(int argc, char **argv) {
    
    return 0;
}

//se crea el builtin_arr
struct builtin_struct builtin_arr[] = {
    { "cd", builtin_cd, HELP_CD },
    { "dir", builtin_dir, HELP_DIR },
    { "exit", builtin_exit, HELP_EXIT },
    { "help", builtin_help, HELP_HELP },
    { "history", builtin_history, HELP_HISTORY },
    { "getenv", builtin_getenv, HELP_GETENV },
    { "pid", builtin_pid, HELP_PID },
    { "setenv", builtin_setenv, HELP_SETENV },
    { "status", builtin_status, HELP_STATUS },
    { "uid", builtin_uid, HELP_UID },
    { NULL, NULL, NULL }  // se marca el final del array
};


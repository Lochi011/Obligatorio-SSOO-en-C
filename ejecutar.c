
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minish.h"


int ejecutar(int argc, char **argv){
    struct builtin_struct *builtin = builtin_lookup(argv[0]); //se busca el comando en la lista de builtins usando la funcion builtin_lookup
    if (builtin){
        return builtin->func(argc, argv); //si builtin no es NULL, se llama a la funcion del builtin
    }else{
        fprintf(stderr, "Comando no encontrado: %s\n", argv[0]); //si builtin es NULL es porque no se encontro, se imprime un mensaje de error
        return 1;
    }

}























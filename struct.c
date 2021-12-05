#include <stdio.h>
#include <stdlib.h>


// forma de escribir una struct clasica
typedef struct structClasica{
    char pregunta[100];
    int respuesta;
}Preguntas;


// forma de escribir una struct utilizando typedef (RECOMENDADA)
typedef struct entradaArchivo{
    int valor;
    int cantidad;
}archivo;

// forma de escribir una funcion con retorno de tipo struct
archivo *lecturaDeDatos(int cantidad){
    archivo *retorno;
    retorno = (archivo*)malloc(sizeof(archivo)*cantidad);
    return retorno; 
    
}

int main(){
    struct structClasica entrada;
    Preguntas entradaM;
    printf("Ingrese una pregunta: \n");
    scanf("%s",entradaM.pregunta);

    printf("Ingrese una respuesta: \n");
    scanf("%d",&entradaM.respuesta );

    printf("PREGUNTA: %s      RESPUESTA: %d\n",entradaM.pregunta,entradaM.respuesta);
    
    // forma estatica
    Preguntas entradasS[5];

    // forma dinamica 
    Preguntas *entradas = (Preguntas*)malloc(sizeof(Preguntas)*5);

    // manipulacion de un arreglo de tipo struct 
    for (int i = 0; i < 5; i++){
        printf("Ingrese una pregunta: \n");
        scanf("%s",entradas[i].pregunta);

        printf("Ingrese una respuesta: \n");    
        scanf("%d",&entradas[i].respuesta);

         printf("PREGUNTA: %s      RESPUESTA: %d\n\n",entradas[i].pregunta,entradas[i].respuesta);
    }
    
    


    return 0; 
}
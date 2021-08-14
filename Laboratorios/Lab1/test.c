#include <stdio.h>
#include <stdlib.h>

struct Poblacion{
	char *celulas;
	int size;
}typedef Poblacion;

Poblacion generarStructs(int numero);
void display(Poblacion *poblacion, int numero);
int main(){
	int numero;
	printf("Ingrese un numero\n");
	scanf("%d",&numero);
	generarStructs(numero);
	display(&poblacion,numero);
	return 0;
}

Poblacion generarStructs(int numero){
	Poblacion *poblacion;
	poblacion = (struct Poblacion*)malloc(numero-1*sizeof(struct Poblacion));
	for (int i = 0; i < numero; ++i){
		(poblacion+i)->celulas = malloc(sizeof(char)*numero);
		printf("Ingrese una cadena para la fila %i\n",i );
		scanf("%s",(poblacion+i)->celulas);
		//printf("%s\n", (poblacion+i)->celulas);
	}
}
void display(Poblacion *poblacion, int numero){
	for (int i = 0; i < numero; ++i){
		printf("Fila %i: %s\n",i+1,(poblacion+i)->celulas);
	}

}
/*__X_____
_X___XXX
__X_____
_X______
__X_____
_X___XX_
__X__XX_
_X______
*/


/
int  crearMatriz(int tamanio){
    int  matriz = (int **)malloc(sizeof(int)*tamanio);
    int i = 0;
    for (i = 0; i < tamanio; ++i){
        matriz[i] = (int )malloc(sizeof(int)tamanio);
    }
    fo	r (int i = 0; i < tamanio; ++i){
        for (int j = 0; j < tamanio; ++j){
            matriz[i][j] = rand()%tamanio;
        }
    }
    return matriz;
}
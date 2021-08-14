#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	

	char stringEntrada[4];
	gets(stringEntrada);
	int contador = 0;

	for (int i = 0; i < 4; ++i){
		if (stringEntrada[i] != NULL){
			contador = contador + 1;
		}
	}
	if (contador != 4){ //
		printf("El numero ingresado no tiene 4 digitos\n");
		exit(1);
	}


}
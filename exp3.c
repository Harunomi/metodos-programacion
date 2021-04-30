#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Prototipado
//int * suma(int * primerNumero, int cantDigitos1, int * segundoNumero, int cantDigitos2, int * cantidadDigitosResultado);

/*
- Complete el código para que se sumen los números guardados en primerNumero y segundoNumero
- La cantidad de dígitos de los números se encuentra guardado en cantDigitos1 y cantDigitos2 respectivamente
- Modifique el parámetro cantidadDigitosResultado por referencia 
  para que guare la cantidad de dígitos del resultado de la suma
*/
int * suma(int * primerNumero, int cantDigitos1, int * segundoNumero, int cantDigitos2, int * cantidadDigitosResultado){
	int max;
	int low; 
	int aux;
	int max2;
	int low2; // Necesito variables en donde almacenar el numero que tenga más digitos y el menor
	if (cantDigitos1>=cantDigitos2){ // Compruebo cual de los numeros tiene mayor digito y lo guardo
		max = cantDigitos1 - 1;
		low = cantDigitos2 - 1;
	}else{
		max = cantDigitos2 - 1;
		low = cantDigitos1 - 1;
	}
	max2 = max; // Creo una copia
	low2 = low;
	aux = max ; // necesito guardar el numero maximo en otra variable 
	int *sum = (int*)malloc(sizeof(int)*max + 1 ); // Creo un array que tenga el mayor de digitos + 1
	for (int i = 0; i <= aux; ++i){
		sum[i] = 0;
	}
	/* Necesito 2 casos en los que el maximo de digitos sea del primerNumero y otro caso en que el maximo esté en el segundoNumero*/
	if (max == cantDigitos1 - 1){ 
		while (low >= 0) {
			if (sum[max] + primerNumero[max] + segundoNumero [low] >= 10){
				sum[max] = sum[max] + primerNumero[max] + segundoNumero[low] - 10;
				primerNumero[max-1] = primerNumero[max-1] + 1;
				max = max - 1;
				low = low - 1;
			}else{
				sum[max] = sum[max] + primerNumero[max] + segundoNumero[low];
				max = max - 1;
				low = low - 1;
			}
		}
	while (max2 - low2 >= 0){
			sum[max2 - low2-1 ] = sum[max2 - low2-1] + primerNumero[max2 - low2-1];
			max2 = max2 - 1;
			}
	}else{
		while (low >= 0) {
			if (sum[max] + primerNumero[low] + segundoNumero [max] >= 10){
				sum[max] = sum[max] + primerNumero[low] + segundoNumero[max] - 10;
				segundoNumero[max-1] = segundoNumero[max-1] + 1;
				max = max - 1;
				low = low - 1;
			}else{
				sum[max] = sum [max] + primerNumero[low] + segundoNumero[max];
				max = max - 1;
				low = low - 1;
			}
		}
		while (max2 - low2  >= 0){
			sum[max2 - low2-1] = sum[max2 - low2-1] + segundoNumero[max2 - low2- 1];
			max2 = max2 - 1;
		}
	}
	if (sum[0] == 0){
		*cantidadDigitosResultado = aux;
	}else{
		*cantidadDigitosResultado = aux + 1;
	}
	
	for (int i = 0; i < *cantidadDigitosResultado; ++i)
	{
		printf("%d",sum[i]);
	}
	free(sum);	
}/*Fin de su código aquí*/

int main(){
	
	srand(time(NULL));
	int cantDigitos1 = rand()%101 + 1;
	int cantDigitos2 = rand()%101 + 1;
	
	int *  primerNumero = (int *) malloc(sizeof(int)*cantDigitos1);
	int *  segundoNumero = (int *) malloc(sizeof(int)*cantDigitos2);
	
	printf("%d %d\n",cantDigitos1,cantDigitos2);
	
	
	int i;
	for (i=0;i<cantDigitos1;i++){
		primerNumero[i]= rand()%9 + 1;
		//segundoNumero[i]= rand()%9 + 1;  // Esta linea estaba mala, puesto que el segundoNumero se puede salir del rango
	}
	for (int i = 0; i < cantDigitos2; ++i)
	{
		segundoNumero[i]= rand()%9 + 1;	
	}
	printf("  ");
	
	for (i=0;i<cantDigitos1;i++)
		printf("%d",primerNumero[i]);
	printf("\n");
	printf("+ ");
	for (i=0;i<cantDigitos2;i++)
		printf("%d",segundoNumero[i]);
	printf("\n");
	printf("________________________________________________________________________\n");
	
	int cantidadDigitosResultado = 0;
	int * resultadoSuma = suma(primerNumero, cantDigitos1, segundoNumero, cantDigitos2, &cantidadDigitosResultado);
	/*for (i=0;i<cantidadDigitosResultado;i++)
		printf("%d",resultadoSuma[i]);   // Este printeo no funcionaba, asi que lo printeo directamente en la funcion
	printf("\n");*/

	free(primerNumero);
	free(segundoNumero);
	free(resultadoSuma);
	
	return 0;
}	
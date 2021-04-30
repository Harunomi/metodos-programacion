#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MAX = 200; // cambiar este número para variar el largo máximo del arreglo
void bubble_sort(int v[], int size);
void swap(int v[], int o, int d);
int * crearArray(int largo);
int busquedaBinaria(int *arreglo, int inicio, int fin, int elemento);

int main(){
	srand(time(NULL));
	int largo = rand()% MAX + 1;;
	int resultado = 1;
	int * arreglo =  crearArray(largo);
	printf("\n ARREGLO (largo: %d): \n", largo);
	int i;
	for (i = 0; i < largo; ++i)
		printf("%d  ", arreglo[i]);
	/*
	El arreglo se llama "arreglo" 
	y su largo está guardado en la variable "largo"
	*/
	
	while (busquedaBinaria(arreglo,0,largo,resultado) == 1 && resultado<largo){
		resultado++;
	}if (arreglo[largo] == resultado){ // en caso que esten todos los numeros del 1 hasta arreglo[largo]
		printf("El numero que no se encuentra en el arreglo es %i\n", resultado+1);
	}else{
		printf("\n\nEl numero que no se encuentra en el arreglo es %i\n",resultado);	
	}
	/**************************/
	free(arreglo); 
	return 0;
}
void swap(int v[], int o, int d)
{
 int temp;
 temp=v[d];
 v[d]=v[o];
 v[o]=temp;
}

void bubble_sort(int v[], int size)
{
 int i, j;
 for (j=0; j<size; j++)
  for (i=0; i<size-1; i++)
   if(v[i]>v[i+1])
    swap(v, i, i+1);
}
int * crearArray(int largo){
	int i;
	int * arreglo = (int*)malloc(sizeof(int)*largo);
	for (i = 0; i < largo; ++i)
		arreglo[i] = rand()% (MAX/2) + 1;
	bubble_sort(arreglo,largo);
	return arreglo;
}
int busquedaBinaria(int *arreglo, int inicio, int fin, int elemento){
	int medio = (fin-inicio)/2;
	if(inicio == fin){
		if (arreglo[0] == elemento)
			return 1;
		return 0;
	}else if (arreglo[inicio+medio] == elemento){
		return 1;
	}else{
		if(arreglo[inicio+medio]>elemento){

			return busquedaBinaria(arreglo,inicio,fin/2,elemento);
		}else{
			return busquedaBinaria(arreglo,fin/2+1,fin,elemento);
		}
	}
}

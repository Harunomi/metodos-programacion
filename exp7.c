#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* La idea de este codigo es transformar la matriz entregada a un arreglo de solamente una dimension,
esto es, para poder utilizar el algoritmo de busqueda binaria, para ello se implemento una funcion
que verifica si el numero de la matriz ya existe en el arreglo, para no tener numeros repetidos, luego
se ordena el arreglo con el algoritmo de bubble sort para finalmente utilizar la busqueda binaria.
Personalmente creo que es algo bastante complicado para el ejercicio, pero tuve que hacerlo de esta forma
para cumplir con lo requerido. Otra solucion que hubiese implementado a mi manera, despues de la linea 63 se
pudo perfectamente comparar el numero buscado con number_aux, es decir, buscar el numero mientras se lee la matriz.
De esa forma, no hubiese sido necesaria ninguna otra funcion mas que leer el archivo.*/

typedef struct Arreglo{
	int* array;
	int largo;
}Arreglo;
/*Entradas: solamente el nombre de archivo a leer
Salida: una estructura del tipo Arreglo 
Objetivo: Leer el archivo y retornar la matriz como un arreglo de 1 dimension sin numeros repetidos*/
Arreglo lecturaArchivo(char *nombreArchivo);

// Con esta funcion reviso si ya existe el numero dentro de mi arreglo creado, para no agregarlo de nuevo
int verRepetidos(int *array,int numero,int counter);

// Funcion que acompaña a bubblesort que compara si el de la posicion siguiente es menor y los da vuelta
void swap(int *xp, int *yp);

// Recorre el arreglo y compara si el numero siguiente es mayor o menor
void bubbleSort(int arr[], int n);

// busca el numero entregado dividiendo constantemente el arreglo por la mitad
int binarySearch(int* array, int size,int numero);

int main(){
	char nombreArchivo[20];
	int *array; int numero;
	Arreglo arreglo;
	printf("Ingrese el nombre de archivo a leer\n");
	scanf("%s",nombreArchivo);
	arreglo = lecturaArchivo(nombreArchivo);
	printf("Por favor, ingrese el numero a buscar dentro de la matriz entregada\n");
	scanf("%d",&numero);
	if (binarySearch(arreglo.array,arreglo.largo,numero) == 1){
		printf("El numero %i se encuentra en la matriz.\n",numero);
	}else{
		printf("El numero %i NO se encuentra en la matriz.\n",numero);
	}
	free(arreglo.array);
}

Arreglo lecturaArchivo(char *nombreArchivo){
	int filas; int columnas; Arreglo retorno; int* arrayNuevo;
	FILE *archivo = fopen(nombreArchivo,"r");
	if (archivo == NULL){ // caso de que el archivo no existe
		printf("Lo sentimos, pero el archivo no se encuentra en la carpeta o el nombre ingresado es incorrecto\n");
		exit(1);	
	}
	fscanf(archivo,"%d  %d",&filas,&columnas); 
	char filaChar[columnas*2]; // variable donde guardare toda la fila
	int *array = malloc(sizeof(int)*filas*columnas);
	int number_aux;
	int counter = 0; // este contador funcionara para indexar el array y ademas para el largo del arreglo sin los repetidos
	for (int i = 0; i < filas; ++i){
		fscanf(archivo," %[^\n]",filaChar); // leo TODA la fila
		char *token = strtok(filaChar," "); //strtok separa un string por lo que le pidamos, en este caso un espacio
		while(token != NULL){
			number_aux = atoi(token); // transformamos el numero en string a entero
			token = strtok(NULL," ");
			if (verRepetidos(array,number_aux,counter) == 1){ //Si no esta en el arreglo, lo agregamos
				array[counter] = number_aux;
				counter++;
			}
		}
	}
	fclose(archivo);
	bubbleSort(array,counter);
	arrayNuevo = malloc(sizeof(int)*counter); // como ya conocemos el tamaño del arreglo sin los repetidos, creamos una nueva variable
	for (int i = 0; i < counter; ++i){ // y agregamos cada elemento del arreglo antiguo al nuevo
		arrayNuevo[i] = array[i];
	}
	retorno.array = arrayNuevo;
	retorno.largo = counter;
	free(array); free(arrayNuevo);
	return retorno;
}

int verRepetidos(int *array,int numero,int counter){
	if (counter == 0) // necesito este if para el caso inicial en el cual counter es 0
		return 1; // y si counter es cero, claramente el arreglo esta vacio
	int i = 0;
	while (i < counter){
		if (array[i] == numero)
			return 0;
		i++;	
	}
	return 1;
}

void swap(int *xp, int *yp){ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(int arr[], int n){ 
   int i, j; 
   for (i = 0; i < n-1; i++)        
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
 }          

 int binarySearch(int* array, int size,int numero){
 	if (size == 0) // arreglo vacio
 		return 0;
 	else if (size == 1){
 		if (array[0] == numero)
 			return 1;
 		return 0;
 	}else if (array[size/2] == numero){
 		return 1;
 	}else if (array[size/2] > numero){
 		int i;
 		int * smallArr = (int*)malloc(sizeof(int)*(size/2));
 		for (int i = 0; i < size/2; i++){
 			smallArr[i] = array[i];
 		}
 		free(array);
 		binarySearch(smallArr,size/2,numero);
 	}else{
 		int i;
 		int * smallArr = (int*)malloc(sizeof(int)*(size - size/2));
 		for (int i = 0; i < size - size/2; i++){
 			smallArr[i] = array[size/2+i];
 		}
 		free(array);
 		binarySearch(smallArr,size-size/2,numero);
 	}
 }

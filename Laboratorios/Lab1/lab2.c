#include <stdio.h>
#include <stdlib.h>


struct Matriz{
	char** celula;
	int filas;
	int columnas;
}typedef Matriz;
void imprimirMatriz(Matriz matrizRel){
	for(int i = 0; i < matrizRel.filas; i++){
		for(int j = 0; j < matrizRel.columnas; j++){
			printf("%c",matrizRel.celula[i][j]);
		}
		printf("\n");
	}
	return;
}
int potenciaDeDos(int n);
Matriz leerArchivo(char nombreArchivo[]){
	FILE* archivo = fopen(nombreArchivo,"r");
	if(archivo == NULL){
		printf("No existe el archivo.\n");
		exit(1);
	}					
	int filas,columnas;
	char rel;
	fscanf(archivo,"%d",&filas);
	columnas = filas;
	if (potenciaDeDos(filas) == 0 || potenciaDeDos(columnas) == 0){ // se comprueba que el tamanio de la matriz sea un cuadrado de 2
		printf("Por favor asegurese que el tamano de la matriz sea un cuadrado de 2\n");
		exit(1);
	}
	char** celula = (char**)malloc(sizeof(int*)* filas);
	for(int i = 0; i < filas; i++){
		char* filaRel = (char*)malloc(sizeof(int)*columnas);
		for(int j = 0; j < columnas; j++){
			filaRel[j] = rel;
			}
		celula[i] = filaRel;
		printf("%c\n",celula[i]);
		}
	fclose(archivo);
	Matriz retorno;
	retorno.filas = filas;
	retorno.columnas = columnas;
	retorno.celula = celula;
	return retorno;
}
int main(){
	char nombreArchivo[60];
	Matriz matriz;
	//Aquí una forma de pedir un string al usuario con strings estáticos.
	printf("Ingrese el nombre del archivo: (con extensión .txt): ");
	scanf("%s",nombreArchivo);
	printf("\n");
	//Asignamos a la variable matriz el retorno de la función leerArchivo.
	matriz = leerArchivo(nombreArchivo);
	//Y finalmente la imprimimos.
	imprimirMatriz(matriz);
	//Liberamos memoria
	for(int i = 0; i < matriz.columnas;i++){
		free(matriz.celula[i]);
	}
	free(matriz.celula);
	return 0;
}
int potenciaDeDos(int n){
	if (n == 1) 
	  return 1; 
	else if (n % 2 != 0 || n ==0) 
	  return 0;	
	return potenciaDeDos(n / 2); 
	}	
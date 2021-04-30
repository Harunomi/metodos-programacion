#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_PERMUTACIONES 362880 // factorial de 9

/* Comentario: estuve la mayor parte del programa intentando entender el porqué de si borro la linea 25 el programa no hace nada
Si usted profe encuentra la solucion al porqué, por favor digamela por correo porque todavia no me creo que el meme de "esta linea mantiene todo mi programa"
me haya ocurrido*/


/*Objetivo: Revisar cada solucion, comprobando si el arreglo corresponde a un cuadrado magico
Entrada: un arreglo de chars de tamano 9
Salida: un 1 si el arreglo corresponde a un cuadrado magico, 0 de lo contrario*/
int verificarCuadradoMagico(char arreglo[9]);

/*Objetivo: crear las 9! soluciones en un archivo de texto para ser leido luego
Entrada: ninguna
Salida: ninguna*/
void crearCombinaciones();

/*Objetivo: mostrar por pantalla el arreglo de 1 dimension como si fuese una matrix
Entrada: un arreglo de char de tamano 9
Salida: ninguna*/
void displayMatrix(char fila[9]);

int main(){
			/*VARIABLES*/
	FILE *archivoEntrada = fopen("permutaciones.txt","r");
	FILE *archivoSalida = fopen("resultados.txt","w"); // no tengo la menor idea del porqué, pero si borro esta linea el programa no hace nada
	char fila[9]; // variable donde guardo cada solucion
	int cantSoluciones = 0; // contador de las soluciones
			/*PROCESAMIENTO*/
	crearCombinaciones();
	for (int i = 0; i <= TOTAL_PERMUTACIONES; ++i){
		fscanf(archivoEntrada," %[^\n]",fila); // leo TODA la fila
		if(verificarCuadradoMagico(fila) == 1){
			printf("   Solucion numero: %i\n",cantSoluciones+1);
			displayMatrix(fila); printf("\n");
			cantSoluciones++;
		}
	}
	if (cantSoluciones == 0)
		printf("No existe ninguna solucion para el problema\n");
	printf("El numero de soluciones encontradas es: %i\n", cantSoluciones);
	fclose(archivoEntrada);
	fclose(archivoSalida);
	return 0;
}


void displayMatrix(char fila[9]){
	printf("%c %c %c\n%c %c %c\n%c %c %c\n",fila[0],fila[1],fila[2],fila[3],fila[4],fila[5],fila[6],fila[7],fila[8]);
}

int verificarCuadradoMagico(char arreglo[9]){
	int fila1,fila2,fila3,columna1,columna2,columna3,diagonal1,diagonal2;
	/* SUMA PARA LAS 3 FILAS*/
	
	fila1 = (int)(arreglo[0]) + (int)(arreglo[1]) + (int)(arreglo[2]);
	fila2 = (int)(arreglo[3]) + (int)(arreglo[4]) + (int)(arreglo[5]);
	fila3 = (int)(arreglo[6]) + (int)(arreglo[7]) + (int)(arreglo[8]);
	/* SUMA PARA LAS 3 COLUMNAS*/
	
	columna1 = (int)(arreglo[0]) + (int)(arreglo[3]) + (int)(arreglo[6]);
	columna2 = (int)(arreglo[1]) + (int)(arreglo[4]) + (int)(arreglo[7]);
	columna3 = (int)(arreglo[2]) + (int)(arreglo[5]) + (int)(arreglo[8]);
	/* SUMA PARA LAS 2 DIAGONALES*/
	
	diagonal1 = (int)(arreglo[0]) + (int)(arreglo[4]) + (int)(arreglo[8]);
	diagonal2 = (int)(arreglo[2]) + (int)(arreglo[4]) + (int)(arreglo[6]);
	/* UNA VEZ TENEMOS TODAS LAS SUMAS, COMPROBAMOS SI SON TODAS LAS VARIABLES IGUALES ENTRE SI*/	
	
	if(fila1 == fila2 && fila1 == fila3 && fila2 == fila3){ // vericamos que todas las filas sean iguales
		if(columna1 == columna2 && columna1 == columna3 && columna2 == columna3){ // verificamos que todas las columnas sean iguales
			if(diagonal1 == diagonal2){ // verificamos uqe las diagonales sean iguales
				// dado este punto solo queda comparar cualquier fila, con cualquier columna y diagonal
				if(fila1 == columna1 && fila1 == diagonal1 && columna1 == diagonal1){ 
					return 1;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else{
		return 0;
	}
 }

 void crearCombinaciones(){
	int q,w,e,r,t,y,u,i,o; int counter = 0;
	FILE *archivo = fopen("permutaciones.txt","w");
	/* Cada for es para una posicion del arreglo */
	for (int q = 1; q<=9; ++q){
		for (int w = 1; w <=9; ++w){
			for (int e= 1; e <=9; ++e){
				for (int r = 1; r <=9; ++r){
					for (int t = 1; t <= 9; ++t){
						for (int y = 1; y <=9; ++y){
							for (int u = 1; u <=9; ++u){
								for (int i = 1; i <= 9; ++i){
									for (int o = 1; o <=9; ++o){
										/*Nos aseguramos que cada indice sea distinto de los demas indices*/
										if(q!=w&&q!=e&&q!=r&&q!=t&&q!=y&&q!=u&&q!=i&&q!=o)
											if(w!=e&&w!=r&&w!=t&&w!=y&&w!=u&&w!=i&&w!=o)
												if(e!=r&&e!=t&&e!=y&&e!=u&&e!=i&&e!=o)
													if(r!=t&&r!=y&&r!=u&&r!=i&&r!=i&&r!=o)
														if(t!=y&&t!=u&&t!=i&&t!=o)
															if(y!=u&&y!=i&&y!=o)
																if(u!=i&&u!=o)
																	if(i!=o){
																		fprintf(archivo,"%i%i%i%i%i%i%i%i%i\n",q,w,e,r,t,y,u,i,o );//se escribe la solucion en el archivo
																		counter++;
																		}
																	
									}
								}
							}
						}
					}
				}
			}
		}
	}
	fclose(archivo);
}
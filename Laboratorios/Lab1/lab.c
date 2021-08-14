#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
SECCIÓN DEL CURSO: 0-A-1
 PROFESOR DE TEORÍA: ALEJANDRO CISTERNA VILLALOBOS
 PROFESOR DE LABORATORIO: MARCELA RIVERA
 AUTOR
 NOMBRE: Cristhofer Parada Salazar
 RUT: 20.387.754-4
 CARRERA: Ingeniería Civil informatica
 Fecha: 16-12-2020
 Version: 1.0
 Objetivo: Construir un programa, que, dado la cantidad inicial de contagiantes y una cantidad total de computadoras del país, sea capaz de indicar en cuántas semanas el sistema 
 de seguridad del país se verá colapsado.
*/

// ENTRADA: un numero entero, en su defecto, el primer numero de la matriz
// SALIDA: un booleano
// OBJETIVO: Comprobar si el numero que esta en el archivo de entrada corresponde a una potencia de 2
//           de ser asi, retorna 1, si no lo es, retorna 0 y el programa termina
int potenciaDeDos(int n);

// ENTRADAS: el tamano de la matriz, la matriz, un auxiliar que servira para contar las generaciones desde 1
		//   el numero de generaciones que ingreso el usuario y si el usuario desea ver el progreso por pantalla
// SALIDA:  un booleano que dice cuando la funcion llega a la ultima generacion
// OBJETIVO: funcion recursiva que crea los archivos en donde se escribiran los cambios de generaciones 
//        	 ademas de leerlos para crear la nueva matriz		
int generaciones(int size,char matriz[size][size],int aux,int numeroGeneraciones,int seleccion);

/* ENTRADAS: el tamano de la matriz, la matriz, seleccion del usuario,una iteracion para las filas, una para las columnas, el archivo de salida y un contador
SALIDA: UN booleano
OBJETIVO: el objetivo de esta funcion es mediante recursividad mover las filas (i) cada vez que se haga el calculo de una fila
*/
int calculoGeneracion(int size,char matriz[size][size],int seleccion,int i,int j,int aux,FILE *archivoSalida,int contador);
/* ENTRADAS: tamano de la matriz,la matriz, la seleccion del usuario, fila actual, columna actual,un contador y el archivo de salida
   SALIDAS: un booleano
   OBJETIVO: hacer el calculo de las filas mediante recursidad, evalua solamente la fila actual (i) para cada celula
*/
int calculoFila(int size,char matriz[size][size],int seleccion,int i,int j,int contador,FILE *archivoSalida);

int main(){
	char nombreArchivo[20];
	int numeroGeneraciones;
	char numeroGeneracionesChar[5];
	int seleccion;
	int size;
	char fila[100];
	int i = 0;
	int aux = 1;
	printf("Ingrese el nombre del archivo de entrada:\n");
	scanf("%s",nombreArchivo);
	FILE *archivo = fopen(nombreArchivo,"r");
	if (archivo == NULL){
		printf("Lo sentimos, pero el archivo ingresado no existe en la carpeta raiz\n");
		exit(1);
	}
	fscanf(archivo,"%d",&size); // escaneamos el tamano de la matriz
	if (size == 1){
		printf("Por favor verifique que el tamano de la matriz sea un cuadrado de 2\n");
		exit(1);
	}else if (potenciaDeDos(size) == 0){ // verificamos que sea potencia de 2
		printf("Por favor verifique que el tamano de la matriz sea un cuadrado de 2\n");
		exit(1);
	}
	char matriz[size][size]; // creamos la variable matriz donde se almacenara el archivo
	for (int i = 0; i < size; ++i){
		fscanf(archivo," %[^\n]",fila); // leo TODA la fila
		if (strlen(fila) != size){ // compruebo que la fila sea de size chars
			printf("El tamano de la fila %i debiese ser %i\n",i,size );
			exit(1);
		}
		for (int j = 0; j < size; ++j){
			// comprobemos que cada elemento de la matriz este compuesto solamente por X y _
			if (fila[j] == 'X' || fila[j] == '_'){
				matriz[i][j] = fila[j]; // cada caracter de la fila lo transpasamos a la matriz
			}else{
				printf("Por favor verifique que la matriz solo contenga 'X' y '_'\n");
				printf("Error en la columna %i y fila %i del archivo\n", j,i);
				exit(1);
			}
		}
	}
	fclose(archivo);
	printf("*******El archivo fue leido exitosamente!*******\n");
	// Solicito el numero de generaciones
	// Si el usuario desea salir, ingresera el numero de generaciones como 0
	printf("Ingrese el numero de generaciones que le gustaria que se genere.\n");
	printf("    En caso de querer de salir del programa, ingrese 0\n");
	scanf("%s",numeroGeneracionesChar);
	while(numeroGeneracionesChar[i++] != '\0'){ // comprobamos si el numero de generaciones ingresado es un float
		if (numeroGeneracionesChar[i] == '.'){
			printf("Por favor ingrese un numero entero positivo\n");
			exit(1);
		}
	}if (atoi(numeroGeneracionesChar)< 0){ // comprobamos si el numero de generaciones es un numero negativo
		printf("Por favor ingrese un numero entero positivo\n");
		exit(1);
	}
	numeroGeneraciones = atoi(numeroGeneracionesChar);	// converitmos el arreglo de chars a int
	if (numeroGeneraciones == 0){ // si es cero, el programa termina
		exit(1);
	}
	printf("\n\n*******El numero de generaciones fue ingresado correctamente!*******\n");
	printf("Desea que el avance de las generaciones sea mostrado por pantalla?\n");
	printf("    Ingrese un 1 si desea que se muestra por pantalla, un 0 en caso opuesto\n");
	while(seleccion != 0 || seleccion != 1){
		scanf("%d",&seleccion);
		if(seleccion == 0 || seleccion == 1)
			break;
		printf("Por favor ingrese solo un 0 o un 1 para mostrar el resultado por pantalla\n");
	}
	printf("\n");
	generaciones(size,matriz,aux,numeroGeneraciones,seleccion);
	return 0;	
}
int potenciaDeDos(int n){
	if (n == 1) 
	  return 1; 
	else if (n % 2 != 0 || n ==0) 
	  return 0;	
	return potenciaDeDos(n / 2); 
}
int generaciones(int size,char matriz[size][size],int aux,int numeroGeneraciones,int seleccion){
	if (aux > numeroGeneraciones){
		return 1;
	}else if (aux == 1){
		char charSalida[15] = "Salida_gen";
		char charNumero[5];
		char output[5] = ".out";
		sprintf(charNumero,"%d",aux); // transformo el int a string
		strcat(charSalida,charNumero); strcat(charSalida,output);//agrego el numero como string al nombre y el .out al nombre de salida
		FILE *archivoSalida = fopen(charSalida,"w"); // creamos el archivo de salida con el nombre "Salida_gen" + numero de generacion + ".out"
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; ++j){
				fprintf(archivoSalida,"%c",matriz[i][j]);
				if(seleccion == 1)
					printf("%c",matriz[i][j]);
			}
			fprintf(archivoSalida,"\n");
			if (seleccion = 1)
				printf("\n");
		}
		fclose(archivoSalida);
		printf("\n\n*****Se ha finalizado la %i generacion con exito!***** \n\n",aux );
		aux++;
		return generaciones(size,matriz,aux,numeroGeneraciones,seleccion);
	}else if(aux == 2){
		int i = 0;
		int j = 0;
		int contador = 0;
		char charSalida[15] = "Salida_gen";
		char charNumero[5];
		char output[5] = ".out";
		sprintf(charNumero,"%d",aux); // transformo el int a string
		strcat(charSalida,charNumero); strcat(charSalida,output);//agrego el numero como string al nombre y el .out al nombre de salida
		FILE *archivoSalida = fopen(charSalida,"w"); // creamos el archivo de salida con el nombre "Salida_gen" + numero de generacion + ".out"
		calculoGeneracion(size,matriz,seleccion,i,j,aux,archivoSalida,contador);	
		fclose(archivoSalida);
		aux++;
		return generaciones(size,matriz,aux,numeroGeneraciones,seleccion);
	}else if(aux <= numeroGeneraciones){
		char filaEntrada[100];
		char matrizEntrada[size][size];
		char charEntrada[15] = "Salida_gen";
		char charNumeroEntrada[5];
		char outputEntrada[5] = ".out";
		sprintf(charNumeroEntrada,"%d",aux-1);
		strcat(charEntrada,charNumeroEntrada); strcat(charEntrada,outputEntrada);//agrego el numero como string al nombre y el .out al nombre de salida
		FILE *archivoEntrada = fopen(charEntrada,"r");
		for ( int i = 0; i < size; ++i){
			fscanf(archivoEntrada," %[^\n]",filaEntrada); // leo TODA la fila
			for (int j = 0; j < size; ++j){
				matrizEntrada[i][j] = filaEntrada[j];
			}
		}
		fclose(archivoEntrada);
		char charSalida[15] = "Salida_gen";
		char charNumeroSalida[5];
		sprintf(charNumeroSalida,"%d",aux);
		strcat(charSalida,charNumeroSalida); strcat(charSalida,outputEntrada);
		FILE *archivoSalidaNext = fopen(charSalida,"w");
		int i = 0;
		int j = 0;
		int contador = 0;
		calculoGeneracion(size,matrizEntrada,seleccion,i,j,aux,archivoSalidaNext,contador);
		fclose(archivoSalidaNext);
		aux++;
		return generaciones(size,matrizEntrada,aux,numeroGeneraciones,seleccion);
	}
}
int calculoGeneracion(int size,char matriz[size][size],int seleccion,int i,int j,int aux,FILE *archivoSalida,int contador){
	if (i <=size-1){ // itero las filas (i)
		calculoFila(size,matriz,seleccion,i,j,contador,archivoSalida);
		fprintf(archivoSalida,"\n");
		if (seleccion == 1) 
			printf("\n");
		i++;
		return calculoGeneracion(size,matriz,seleccion,i,j=0,aux,archivoSalida,contador);
	}else{
		printf("\n\n*****Se ha finalizado la %i generacion con exito!***** \n\n",aux );
		return 1;	
	}
}


int calculoFila(int size,char matriz[size][size],int seleccion,int i,int j,int contador,FILE *archivoSalida){
	if (i == 0 && j == 0){// CASO ESQUINA SUPERIOR IZQUIERDA
		switch (matriz[0][0]){ 
			case 'X': //                  PARA CELULA VIVA
			if (matriz[0][1] == 'X')
				contador++;
			if (matriz[1][0] == 'X')
				contador++;
			if (matriz[1][1] == 'X')
				contador++;
			if (contador == 2 || contador == 3){ // VIVE
				fprintf(archivoSalida,"X");
				if (seleccion == 1)
					printf("X");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}else{
				fprintf(archivoSalida, "_"); // MUERE
				if (seleccion == 1)
					printf("_");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}
			case '_': //                  PARA CELULA MUERTA
			if(matriz[0][1] == 'X' && matriz[1][0] == 'X' && matriz[1][1] == 'X'){ // REVIVE
				fprintf(archivoSalida,"X");
				if (seleccion == 1)
					printf("_");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}else{ // SIGUE MUERTA
				fprintf(archivoSalida,"_");
				if (seleccion == 1)
					printf("_");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}
		}	
	}else if (i == 0 && j == size-1){ // CASO ESQUINA SUPERIOR DERECHA
		switch (matriz[0][size-1]){
			case 'X': //                 PARA CELULA VIVA
			if (matriz[0][size-2] == 'X')
				contador++;
			if (matriz[1][size-2] == 'X')
				contador++;
			if (matriz[1][size-1] == 'X')
				contador++;
			if (contador == 2 || contador == 3){ // VIVE
				fprintf(archivoSalida,"X");
				if (seleccion == 1)
					printf("X");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}else{ // MUERE
				fprintf(archivoSalida, "_");
				if (seleccion == 1)
					printf("_");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}
			case '_': //                 PARA CELULA MUERTA
			if(matriz[0][size-2] == 'X' && matriz[1][size-2] == 'X' && matriz[1][size-1] == 'X'){ // REVIVE
				fprintf(archivoSalida,"X");
				if (seleccion == 1)
					printf("X");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}else{ // SIGUE MUERTA
				fprintf(archivoSalida,"_");
				if (seleccion == 1)
					printf("_");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}			
		}
	}else if (i == size-1 && j == 0){ // CASO ESQUINA INFERIOR IZQUIERDA
		switch (matriz[size-1][0]){
			case 'X': //                 PARA CELULA VIVA
			if (matriz[size-2][0] == 'X')
				contador++;
			if (matriz[size-1][1] == 'X')
				contador++;
			if (matriz[size-2][1] == 'X')
				contador++;
			if (contador == 2 || contador == 3){ // VIVE
				fprintf(archivoSalida,"X");
				if (seleccion == 1)
					printf("X");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}else{ // MUERE
				fprintf(archivoSalida, "_");
				if (seleccion == 1)
					printf("_");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}
			case '_': //                 PARA CELULA MUERTA
			if(matriz[size-2][0] == 'X' && matriz[size-1][1] == 'X' && matriz[size-2][1] == 'X'){ // REVIVE
				fprintf(archivoSalida,"X");
				if (seleccion == 1)
					printf("X");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}else{ // SIGUE MUERTA
				fprintf(archivoSalida,"_");
				if (seleccion == 1)
					printf("_");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}
		}
	}else if (i == size-1 && j == size-1){ // CASO ESQUINA INFERIOR derecha
		switch (matriz[size-1][size-1]){
			case 'X': //                 PARA CELULA VIVA
			if (matriz[size-1][size-2] == 'X')
				contador++;
			if (matriz[size-2][size-2] == 'X')
				contador++;
			if (matriz[size-2][size-1] == 'X')
				contador++;
			if (contador == 2 || contador == 3){ // VIVE
				fprintf(archivoSalida,"X");
				if (seleccion == 1)
					printf("X");
				j++;
				return 1;
				//calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}else{ // MUERE
				fprintf(archivoSalida, "_");
				if (seleccion == 1)
					printf("_");
				j++;
				//calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				return 1;
				break;
			}
			case '_': //                 PARA CELULA MUERTA
			if(matriz[size-2][size-2] == 'X' && matriz[size-1][size-2] == 'X' && matriz[size-2][size-1] == 'X'){ // REVIVE
				fprintf(archivoSalida,"X");
				if (seleccion == 1)
					printf("X");
				j++;
				//calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				return 1;
				break;
			}else{ // SIGUE MUERTA
				fprintf(archivoSalida,"_");
				if (seleccion == 1)
					printf("_");
				j++;
				//calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				return 1;
				break;
			}
		}
	}else{                                  // CASO FILAS Y COLUMNAS CENTRALES
		if (i == 0 && j < size - 1){ // primera fila
			switch (matriz[i][j]){
			case 'X':  // CELULA VIVA
			if (matriz[i][j-1] == 'X') // izquierda
				contador++;
			if (matriz[i+1][j-1] == 'X') //diagonal izquierda 
				contador++;
			if (matriz[i+1][j] == 'X') // arriba
				contador++;
			if (matriz[i+1][j+1] == 'X') // diagonal derecha
				contador++;
			if (matriz[i][j+1] == 'X') // derecha
				contador++;
			if (contador == 2 || contador == 3){
				fprintf(archivoSalida,"X");
				if (seleccion == 1){
					printf("X");
				}
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}else{
				fprintf(archivoSalida,"_");
				if (seleccion == 1){
					printf("_");
				}
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
			}
			case '_': // CELULA MUERTA
			if (matriz[i][j-1] == 'X') // izquierda
				contador++;
			if (matriz[i+1][j-1] == 'X') //diagonal izquierda 
				contador++;
			if (matriz[i+1][j] == 'X') // arriba
				contador++;
			if (matriz[i+1][j+1] == 'X') // diagonal derecha
				contador++;
			if (matriz[i][j+1] == 'X') // derecha
				contador++;
			if (contador == 3){
				fprintf(archivoSalida,"X");
				if (seleccion == 1)
					printf("X");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;	
			}else{
				fprintf(archivoSalida,"_");
				if(seleccion == 1)
					printf("_");
				j++;
				calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
				break;
				}
			}
		}else if (i < size-1 && j <= size-1 ){ // filas de al medio
			if(j == 0){ // primera columna
				switch (matriz[i][j]){
					case 'X': //            CELULA VIVA
					if (matriz[i-1][j] == 'X') // arriba
						contador++;
					if (matriz[i-1][j+1] == 'X') // diagonal arriba derecha
						contador++;
					if (matriz[i][j+1] == 'X') // derecha
						contador++;
					if (matriz[i+1][j+1] == 'X') // diagonal abajo derecha
						contador++;
					if (matriz[i+1][j] == 'X') // abajo
						contador++;
					if (contador == 2 || contador == 3){
						fprintf(archivoSalida,"X");
						if (seleccion == 1)
							printf("X");
						j++;
						calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;
					}else{
						fprintf(archivoSalida, "_");
						if (seleccion == 1)
							printf("_");
						j++;
						calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;
					}
					case '_': //           CELULA MUERTA
					if (matriz[i-1][j] == 'X') // arriba
						contador++;
					if (matriz[i-1][j+1] == 'X') // diagonal arriba derecha
						contador++;
					if (matriz[i][j+1] == 'X') // derecha
						contador++;
					if (matriz[i+1][j+1] == 'X') // diagonal abajo derecha
						contador++;
					if (matriz[i+1][j] == 'X') // abajo
						contador++;
					if (contador == 3){
						fprintf(archivoSalida,"X");
						if (seleccion == 1)
							printf("X");
						j++;
						calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;
					}else{
						fprintf(archivoSalida, "_");
						if (seleccion == 1)
							printf("_");
						j++;
						calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;	
					}
				}
			}else if(j == size-1){ // ultima columna
				switch (matriz[i][j]){
					case 'X': //        CELULA VIVA
					if (matriz[i-1][j] == 'X') // arriba
						contador++;
					if (matriz[i-1][j-1] == 'X') // diagonal izquierda arriba
						contador++;
					if (matriz[i][j-1] == 'X') // izquierda
						contador++;
					if (matriz[i+1][j-1] == 'X') // diagonal izquierda abajo
						contador++;
					if (matriz[i+1][j] == 'X') // abajo
						contador++;
					if (contador == 2 || contador == 3){
						fprintf(archivoSalida,"X");
						if (seleccion == 1)
							printf("X");
						j++;
						//calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;
					}else{
						fprintf(archivoSalida, "_");
						if (seleccion == 1)
							printf("_");
						j++;
						//calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;	
					}
					case '_':   //           CELULA MUERTA
					if (matriz[i-1][j] == 'X') // arriba
						contador++;
					if (matriz[i-1][j-1] == 'X') // diagonal izquierda arriba
						contador++;
					if (matriz[i][j-1] == 'X') // izquierda
						contador++;
					if (matriz[i+1][j-1] == 'X') // diagonal izquierda abajo
						contador++;
					if (matriz[i+1][j] == 'X') // abajo
						contador++;
					if (contador == 3){
						fprintf(archivoSalida,"X");
						if (seleccion == 1)
							printf("X");
						j++;
						//calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;
					}else{
						fprintf(archivoSalida, "_");
						if (seleccion == 1)
							printf("_");
						j++;
						//calculoFila(size,matriz,seleccion,i,j++,contador = 0,archivoSalida);
						break;	
					}
				}
			}else if(j < size-1){ // columnas de al medio
				switch(matriz[i][j]){
					case 'X':
					if (matriz[i-1][j-1] == 'X') // diagonal superior izquierda
						contador++;
					if (matriz[i-1][j] == 'X') // arriba
						contador++;
					if (matriz[i-1][j+1] == 'X') // diagonal superior derecha
						contador++;
					if (matriz[i][j-1] == 'X') // izquierda
						contador++;
					if (matriz[i][j+1] == 'X') // derecha
						contador++;
					if (matriz[i+1][j-1] == 'X') // diagonal inferior izquierda
						contador++;
					if (matriz[i+1][j] == 'X') // abajo
						contador++;
					if (matriz[i+1][j+1] == 'X') // diagonal inferior derecha
						contador++;
					if (contador == 2 || contador == 3){
						fprintf(archivoSalida,"X");
						if (seleccion == 1)
							printf("X");
						j++;
						calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;
					}else{
						fprintf(archivoSalida, "_");
						if (seleccion == 1)
							printf("_");
						j++;
						calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;
					}
					case '_':
					if (matriz[i-1][j-1] == 'X') // diagonal superior izquierda
						contador++;
					if (matriz[i-1][j] == 'X') // arriba
						contador++;
					if (matriz[i-1][j+1] == 'X') // diagonal superior derecha
						contador++;
					if (matriz[i][j-1] == 'X') // izquierda
						contador++;
					if (matriz[i][j+1] == 'X') // derecha
						contador++;
					if (matriz[i+1][j-1] == 'X') // diagonal inferior izquierda
						contador++;
					if (matriz[i+1][j] == 'X') // abajo
						contador++;
					if (matriz[i+1][j+1] == 'X') // diagonal inferior derecha
						contador++;
					if (contador == 3){
						fprintf(archivoSalida,"X");
						if (seleccion == 1)
							printf("X");
						j++;
						calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;
					}else{
						fprintf(archivoSalida, "_");
						if (seleccion == 1)
							printf("_");
						j++;
						calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
						break;
					}
				}
			}
		}else if (i == size-1 && j < size-1){ // ultima fila
			switch (matriz[i][j]){
				case 'X':
				if (matriz[i][j-1] == 'X') // izquierda
					contador++;
				if (matriz[i-1][j-1] == 'X') // diagonal izquierda
					contador++;
				if (matriz[i-1][j] == 'X') // arriba
					contador++;
				if (matriz[i-1][j+1] == 'X') // diagonal derecha
					contador++;
				if (matriz[i][j+1] == 'X') // derecha
					contador++;
				if (contador == 2 || contador == 3){
					fprintf(archivoSalida,"X");
					if (seleccion == 1){
						printf("X");
					}
					j++;
					calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
					break;
				}else{
					fprintf(archivoSalida,"_");
					if (seleccion == 1){
						printf("_");
					}
					j++;
					calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
					break;
				}	
				case '_':
				if (matriz[i][j-1] == 'X') // izquierda
					contador++;
				if (matriz[i-1][j-1] == 'X') // diagonal izquierda
					contador++;
				if (matriz[i-1][j] == 'X') // arriba
					contador++;
				if (matriz[i-1][j+1] == 'X') // diagonal derecha
					contador++;
				if (matriz[i][j+1] == 'X') // derecha
					contador++;
				if (contador == 3){
					fprintf(archivoSalida,"X");
					if (seleccion == 1){
						printf("X");
					}
					j++;
					calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
					break;
				}else{
					fprintf(archivoSalida,"_");
					if (seleccion == 1){
						printf("_");
					}
					j++;
					calculoFila(size,matriz,seleccion,i,j,contador = 0,archivoSalida);
					break;
				}	
			}
		} 
	}	
}
	


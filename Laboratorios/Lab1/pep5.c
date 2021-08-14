#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cordilleras{
	int *cerritos;
	int largo;
	char cerritosCompletos[100];
	int resultado;
}typedef Cordilleras;
/* Cabezera de funciones */
int recorrido(Cordilleras cordillera,int i,int resultadoDerecha,int resultadoIzquierda);

int mayorDerecha(Cordilleras cordillera,int i,int resultado);

int mayorIzquierda(Cordilleras cordillera,int i,int resultado);

int main(){
	char nombreArchivo[20];
	int cantidadCordilleras;
	int i = 0;
	int j = 0;
	int numero;
	char fila[100];
	char filaCopia[100];
	int resultadoDerecha = 0;
	int resultadoIzquierda = 0;
	printf("Por favor ingrese el nombre de archivo:\n");
	scanf("%s",nombreArchivo);
	FILE *archivo = fopen(nombreArchivo,"r"); // reviso si el archivo no existe
	if (archivo == NULL){
		printf("Lo sentimos, pero el archivo ingresado no existe en la raiz\n");
		exit(1);
	}
	fscanf(archivo,"%i",&cantidadCordilleras);
	Cordilleras cordillera[cantidadCordilleras]; // creo cantidadCordilleras del tipo Cordilleras 
	while (i < cantidadCordilleras){
		fscanf(archivo," %[^\n]",fila); // leo toda la primer fila
		strcpy(filaCopia,fila); // se copia
		char * token = strtok(fila," "); // separo la fila por los espacios
		while (token != NULL){ // conocer cuantos cerros tiene la cordilleras
			token = strtok(NULL," ");
			j++;
		}
		cordillera[i].cerritos = malloc(sizeof(int)*j); // con el dato de la cantidad de cerros, le asigno memoria a el arreglo cordillera.cerritos
		cordillera[i].largo = j; // guardo el largo de la cadena
		strcpy(cordillera[i].cerritosCompletos,filaCopia); // guardo la cadena
		token = strtok(filaCopia," "); // separo de nuevo la fila para guardar cada valor dentro del arreglo cordiller.cerritos
		j = 0;
		while (token != NULL){ // copio cada elemento en cada cerrito 
			numero = atoi(token);
			cordillera[i].cerritos[j] = numero;
			token = strtok(NULL," ");
			j++;
		}
		j = 0;
		i++;
	}	
	i = 0;
	j = 0;
	while (j<cantidadCordilleras){
		cordillera[j].resultado = recorrido(cordillera[j],i,resultadoDerecha,resultadoIzquierda) + 1;
		printf("La cadena es %s\n", cordillera[j].cerritosCompletos);
		printf("y la valor de la subsecuencia mayor es : %i\n",cordillera[j].resultado );
		i = 0;
		resultadoIzquierda = 0;
		resultadoDerecha = 0;
		j++;
	}

}

/* La idea general de mi funcion, es analizar que pasa a la izquierda y derecha de cada numero*/
int recorrido(Cordilleras cordillera,int i,int resultadoDerecha,int resultadoIzquierda){
	if (i == 0){ //en el primer numero, solamente se puede ver lo que pasa a la derecha
		resultadoDerecha = mayorDerecha(cordillera,i,resultadoDerecha);
		cordillera.resultado = resultadoDerecha;
		recorrido(cordillera,i+1,resultadoDerecha,resultadoIzquierda); // siempre guardo la cadena puesto que siempre sera mas grande que cero 
	}else if(i<cordillera.largo){
		resultadoDerecha = 0;
		resultadoIzquierda = 0;
		resultadoDerecha = mayorDerecha(cordillera,i,resultadoDerecha);
		resultadoIzquierda = mayorIzquierda(cordillera,i,resultadoIzquierda);
		if(cordillera.resultado < resultadoDerecha){ // si el nuevo valor del resultado a la derecha es mayor que el anterior, lo actualizo
			cordillera.resultado = resultadoDerecha;
		}else if (cordillera.resultado < resultadoIzquierda){// si el nuevo valor del resultado a la izquierda es mayor que el anterior, lo actualizo
			cordillera.resultado = resultadoDerecha;
		recorrido(cordillera,i+1,resultadoDerecha,resultadoIzquierda);	// repito el ciclo
		}
	}else if (i == cordillera.largo){ // caso especial para el ultimo valor del arreglo, puesto que no puede avanzar a la derecha
		resultadoIzquierda = 0;
		resultadoIzquierda = mayorIzquierda(cordillera,i,resultadoIzquierda);
		if (cordillera.resultado < resultadoIzquierda){
			cordillera.resultado = resultadoIzquierda;
		}
		recorrido(cordillera,i+1,resultadoDerecha,resultadoIzquierda);
	}else{
		return cordillera.largo;
	}

}

int mayorDerecha(Cordilleras cordillera,int i,int resultado){
	if (i == cordillera.largo){ // para que no se pase del limite del arreglo
		return resultado;
	}else if (cordillera.cerritos[i]<cordillera.cerritos[i+1]){ // compruebo si el cerro actual es menor que el cerro que sigue
		resultado++;
		return mayorDerecha(cordillera,i+1,resultado); // de ser asi, incremento el valor de resultado, que es en donde guardo el valor de la subsecuencia y me muevo a la derecha
	}else{
		return resultado;
	}

}
int mayorIzquierda(Cordilleras cordillera,int i,int resultado){
	if (i == 0){ // para que no se pase del limite del arreglo
		return resultado;
	}else if (cordillera.cerritos[i-1]>cordillera.cerritos[i]){ // compruebo si el cerro actual es menor que el cerro anterior
		resultado++;
		return mayorDerecha(cordillera,i-1,resultado); // de ser asi, incremento el valor de resultado, que es en donde guardo el valor de la subsecuencia y me muevo a la izquierda
	}else{
		return resultado;
	}
}

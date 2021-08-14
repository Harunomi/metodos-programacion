#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_COMBINACIONES 33554432
typedef struct Entrada{
	int fila[5][2];
	int columna[5][2];
}Entrada;

void crearSoluciones();
void menu();
void ejecucion();
void clearBuffer();
char **revisarSoluciones(Entrada reglas,int *cantSoluciones);
int verificarEntrada(char numero[2]);
int verificarFila(char solucion[25],int filActual,int rule1,int rule2);
char** agregarSolucion(char** soluciones, int* largo, char* nuevaSolucion);
Entrada lecturaArchivo(char nombreArchivoFilas[20],char nombreArchivoColumnas[20]);




int main(){
	menu();
	return 0;
}
void menu(){
	char seleccion;
	printf("\n\t\t*********************************************************\n");
	printf("\t\tBienvenid@ al programa de busqueda en Espacio de Soluciones\n");
	printf("\t\t*********************************************************\n");
	while(seleccion!='0'){
		printf("Ingrese una de las opciones:\n");
		printf("1: Si desea ingresar el nombre del par de archivos a leer.\n");
		printf("0: Si desea salir del programa.\n");
		scanf("%c",&seleccion);
		clearBuffer();
		switch (seleccion){
			case '1': // si el usuario ingresa 1 se ejectua el programa
				ejecucion();
				break;
			case '0': // si el usuario ingresa 0 se termina
				exit(1);
			default: // en caso que el usuario no ingrese una opcion valida, se printea este mensaje y se vuelve a repetir las opciones, hasta que se seleccione una opcion valida
				printf("\t\tPor favor, ingrese una de las opciones anteriormente mencionadas!!!\n\n");
		}
	}
	return;
}
void ejecucion(){
	int *cantSoluciones;
	char **soluciones;
	char nombreArchivoFilas[20];
	char nombreArchivoColumnas[20];
	Entrada reglas;
	printf("Ingrese el nombre del archivo correspondiente a las reglas de las filas: ");
	gets(nombreArchivoFilas); printf("\n");
	printf("Ingrese el nombre del archivo correspondiente a las reglas de las columnas: ");
	gets(nombreArchivoColumnas); printf("\n");
	reglas = lecturaArchivo(nombreArchivoFilas,nombreArchivoColumnas);
	crearSoluciones();
	//revisarSoluciones(reglas);

}
char **revisarSoluciones(Entrada reglas,int *cantSoluciones){
	FILE *archivo = fopen("soluciones.txt","r");
	char solAux[25];
	char **solucionesEncontradas = (char**)malloc(sizeof(char*)*0);
	int filActual;
	int colActual;
	if(archivo == NULL){
		printf("El archivo con las soluciones creadas no fue encontrado!\n");
		exit(1);
	}
	
	while (fgets(solAux,25,archivo)!=NULL){
		filActual = 0;
		colActual = 0;
		if (verificarFila(solAux,filActual,reglas.fila[0][0],reglas.fila[0][1]) == 1){
			filActual = filActual+1;
			if (verificarFila(solAux,filActual,reglas.fila[1][0],reglas.fila[0][1]) == 1){
				filActual = filActual+1;
				if (verificarFila(solAux,filActual,reglas.fila[2][0],reglas.fila[0][1]) == 1){
					filActual = filActual+1;
					if (verificarFila(solAux,filActual,reglas.fila[3][0],reglas.fila[0][1]) == 1){
						filActual = filActual+1;
						if (verificarFila(solAux,filActual,reglas.fila[4][0],reglas.fila[0][1]) == 1){
							filActual = filActual+1;
						}
					}
				}
			}
		}
	}

}
int verificarFila(char solucion[25],int filActual,int rule1,int rule2){
	if (filActual == 0){
		switch (rule1){
			case 0:
				printf("lol\n");
			case 1:
				printf("lol\n");
			case 2:
				printf("lol\n");
			case 3:	
				printf("lol\n");
		}
	}else if (filActual == 1){

	}else if (filActual == 2){

	}else if (filActual == 3){

	}else if (filActual == 4){

	}else if (filActual == 5){

	}
}

void crearSoluciones(){
	FILE *fp = fopen("soluciones.txt","w"); // creamos el archivo donde van las soluciones
	// en esta matriz guardamos las permutaciones, como por cada fila hay 5 espacios y cada espacio puede variar 2 veces
	// tenemos que seria 2*2*2*2*2, o 2**5 = 32
	int **matriz = (int**)malloc(sizeof(int*)*32); // le asignamos memoria a las permutaciones
	for (int i = 0; i < 32; ++i){ // le asignamos memoria a los espacios
		matriz[i] = (int*)malloc(sizeof(int)*5);
	}
	int m1[5],m2[5],m3[5],m4[5],m5[5]; // matrices de a 5, auxiliares que serviran para almacenar las combinaciones de la matriz anterior
	int index = 0; // indice para mover el espacio de la matriz 
	int a,b,c,d,e,q,w,r,t;
	for (int a = 0; a < 2; ++a){
		for (int b = 0; b < 2; ++b){
			for (int c = 0; c < 2; ++c){
				for (int d = 0;d < 2; ++d){
					for (int e = 0; e < 2; ++e){
						//hacemos estas 5 combinaciones, pero con ellas se pueden generar todas las demas
						matriz[index][0] = a;
						matriz[index][1] = b;
						matriz[index][2] = c;
						matriz[index][3] = d;
						matriz[index][4] = e;
					}
				}
			}
		}
	}
	//ahora juntamos las combinaciones anteriores en las matrices auxiliares
	for (int q = 0; q < 32; ++q){
		for (int w = 0; w < 32; ++w){
			for (int e = 0; e < 32; ++e){
				for (int r = 0;r < 32; ++r){
					for (int t = 0; t < 32; ++t){
						m1[0] = matriz[q][0];
						m1[1] = matriz[q][1];
						m1[2] = matriz[q][2];
						m1[3] = matriz[q][3]; 
						m1[4] = matriz[q][4];
						
						m2[0] = matriz[w][0];
						m2[1] = matriz[w][1];
						m2[2] = matriz[w][2];
						m2[3] = matriz[w][3]; 
						m2[4] = matriz[w][4];

						m3[0] = matriz[e][0];
						m3[1] = matriz[e][1];
						m3[2] = matriz[e][2];
						m3[3] = matriz[e][3]; 
						m3[4] = matriz[e][4];

						m4[0] = matriz[r][0];
						m4[1] = matriz[r][1];
						m4[2] = matriz[r][2];
						m4[3] = matriz[r][3]; 
						m4[4] = matriz[r][4];

						m5[0] = matriz[t][0];
						m5[1] = matriz[t][1];
						m5[2] = matriz[t][2];
						m5[3] = matriz[t][3]; 
						m5[4] = matriz[t][4];
						// escribimos todo en el archivo de salida			
						fprintf(fp,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",m1[0],m1[1],m1[2],m1[3],m1[4],m2[0],m2[1],m2[2],m2[3],m2[4],m3[0],
							m3[1],m3[2],m3[3],m3[4],m4[0],m4[1],m4[2],m4[3],m4[4],m5[0],m5[1],m5[2],m5[3],m5[4]);
					}
				}
			}
		}
	}
	// se libera memoria y cierra el archivo
	for (int i = 0; i < 32; ++i)
	{
		free(matriz[i]);
	}
	free(matriz);
	fclose(fp);
}
void clearBuffer(){
	while (getchar()!= '\n');
}
Entrada lecturaArchivo(char nombreArchivoFilas[20],char nombreArchivoColumnas[20]){
	char nombreFila[50] = "Pistas/"; char nombreColumna[50] = "Pistas/";
	char filaAux[2]; 
	Entrada retorno;
	strcat(nombreFila,nombreArchivoFilas);
	strcat(nombreColumna,nombreArchivoColumnas);
	FILE *archivoFila = fopen(nombreFila,"r");
	FILE *archivoColumna = fopen(nombreColumna,"r");
	if (archivoFila == NULL || archivoColumna == NULL){
		printf("Verifique que ambos archivos esten correctamente colocados en la carpeta Pistas\n");
		printf("La carpeta Pistas se debe encontrar en la misma raiz donde se encuentra el programa\n");
		exit(1);
	}
	// como bien dice el documento, los archivos siempre seran 5 numeros de 2 digitos, entonces
	for (int i = 0; i < 5; ++i){
		fscanf(archivoFila," %[^\n]",filaAux);
		if (verificarEntrada(filaAux) == 0){
			printf("ERROR EN EL ARCHIVO: %s, FILA: %i\n",nombreArchivoFilas,i+1 );
			exit(1);
		}
		retorno.fila[i][0] = (filaAux[0]) - '0';
		retorno.fila[i][1] = (filaAux[1]) - '0';
	}
	for (int i = 0; i < 5; ++i){
		fscanf(archivoColumna," %[^\n]",filaAux);
		if (verificarEntrada(filaAux) == 0){
			printf("ERROR EN EL ARCHIVO: %s, FILA: %i\n",nombreArchivoColumnas,i+1 );
			exit(1);
		}
		retorno.columna[i][0] = (filaAux[0]) - '0';
		retorno.columna[i][1] = (filaAux[1]) - '0';
	}
	fclose(archivoFila);
	fclose(archivoColumna);
	return retorno;
}	
int verificarEntrada(char numero[2]){
	switch (numero[0]){
		case '0': // si el primer digito es 0
			if(numero[1] == '0' || numero[1] == '1'|| numero[1] == '2'|| numero[1] == '3'|| numero[1] == '4'|| numero[1] == '5'){
				break;
			}else{
				printf("Lo sentimos, pero verifique que los numeros ingresados en los archivos sean solamente:\n");
				printf("00, 01, 02, 03, 04, 05, 11, 12, 13, 21,22 y 31\n");
				return 0;
				break;
			}
		case '1': // si el primer digito es 1
			if(numero[1] == '1'|| numero[1] == '2'|| numero[1] == '3'){
				break;
			}else{
				printf("Lo sentimos, pero verifique que los numeros ingresados en los archivos sean solamente:\n");
				printf("00, 01, 02, 03, 04, 05, 11, 12, 13, 21,22 y 31\n");
				return 0;
				break;
			}
		case '2': // si el primer digito es 2
			if(numero[1] == '1'|| numero[1] == '2'){
				break;
			}else{
				printf("Lo sentimos, pero verifique que los numeros ingresados en los archivos sean solamente:\n");
				printf("00, 01, 02, 03, 04, 05, 11, 12, 13, 21,22 y 31\n");
				return 0;
				break;
			}	
		case '3': // si el primer digito es 3 
			if(numero[1] == '1'){
				break;
			}else{
				printf("Lo sentimos, pero verifique que los numeros ingresados en los archivos sean solamente:\n");
				printf("00, 01, 02, 03, 04, 05, 11, 12, 13, 21,22 y 31\n");
				return 0;
				break;
			}
			break;	
		default: // que el primer digito no corresponda a los valores	
			printf("Lo sentimos, pero verifique que los numeros ingresados en los archivos sean solamente:\n");
			printf("00, 01, 02, 03, 04, 05, 11, 12, 13, 21,22 y 31\n");
			return 0;
			break;
	}
	return 1;
}
char** agregarSolucion(char** soluciones, int* largo, char* nuevaSolucion){
	//Se crea el nuevo conjunto de soluciones con malloc

	//primero las filas
	char** solucionesAux = (char**)malloc(sizeof(char*)*(*largo+1));

	//segundo las columnas
	for (int i = 0; i < *largo + 1; ++i)
	{
		solucionesAux[i] = (char*)malloc(sizeof(char)*25);
	}


	//Se copian los soluciones
	for (int i = 0; i < *largo; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			solucionesAux[i][j] = soluciones[i][j];
		}
	}


	//Se agrega la nueva solucion
	for (int i = 0; i < 25; ++i)
	{
		solucionesAux[*largo][i] = nuevaSolucion[i];
	}

	//se libera memoria columnas
	for (int i = 0; i < *largo; ++i)
	{
		free(soluciones[i]);
	}
	
	free(soluciones);
	*largo = *largo+1;//Se actualiza la cantidad de elementos
	
	return solucionesAux;
}

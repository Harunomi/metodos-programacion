#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
SECCIÓN DEL CURSO: L-10
 PROFESOR DE TEORÍA: ALEJANDRO CISTERNA VILLALOBOS
 PROFESOR DE LABORATORIO: MARCELA RIVERA
 AUTOR
 NOMBRE: Cristhofer Parada Salazar
 RUT: 20.387.754-4
 CARRERA: Ingeniería Civil informatica
 Fecha: 27-02-2021
 Version: 1.0
 Objetivo: Este programa tiene como objetivo resolver un problema respecto a tarjetas perforadas, para ello se crean reglas siguiendo como si fuese un "Nonograma",
 las tarjetas perforadas son representadas con 0 para no perforada y con 1 para perforada, las reglas de como resolver el puzzle son dadas por 2 archivos de texto
 y el tamano de las tarjetas es de 5x5, el conjunto  total de soluciones para estas tarjetas es de 2^25.
*/
/* Struct utilizada para luego de la lectura de los archivos, y luego de verificar que los archivos corresponden en su totalidad a la resolucion, se almacenan esos datos
en una de estas estructuras, un arreglo de enteros 2D para las filas y otro para las columnas.
*/
typedef struct Entrada{
	int fila[5][2];
	int columna[5][2];
}Entrada;
/**********************************************************************************************************************/
/*Entradas: Ninguna.
  Salidas: Ninguna.
  Objetivo: crear el conjunto solucion de todas las posibles combinaciones para una matriz de 5x5 con 2 estados posibles, 0 y 1, estas combinaciones son 
  escritas en un archivo de texto plano llamado "soluciones.txt"
  */
void crearSoluciones();

/*Entradas: Ninguna.
  Salidas: Ninguna.
  Objetivo: menu iterativo, al ingresar 1 el programa se ejecuta y al ingresar 0 se sale del programa, una vez terminado la ejecucion se volvera al menu siempre
  */
void menu();

/*Entradas: Ninguna.
  Salidas: Ninguna.
  Objetivo: opcion del menu en donde se le pregunta al usuario por los nombres de los archivos a leer, se comprueba que los archivos existan y esten bien escritos,
  cumple con la funcion de crear  el archivo con las soluciones (si es que no existe previamente) y mostrar las soluciones encontradas o informar de la no existencia de soluciones
  */
void ejecucion();

/*Entradas: Ninguna.
  Salidas: Ninguna.
  Objetivo: limpiar el buffer de entrada al momento de usar la funcion scanf
  */
void clearBuffer();

/*Entradas: Un arreglo de 2 dimensiones y un entero a modo de puntero
  Salidas: Por pantalla se muestra las soluciones encontradas
  Objetivo: A partir del arreglo 2D imprime las soluciones como si fuesen una matriz, por pantalla
  */
void mostrarSoluciones(char **soluciones,int *cantSoluciones);

/*Entradas: un struct con las reglas dadas por los archivos y un entero en modo de puntero
  Salidas: un arreglo de chars 2D
  Objetivo: lee el archivo con las soluciones y se encarga de revisar cuales cumplen con las reglas dadas
  */
char **revisarSoluciones(Entrada reglas,int *cantSoluciones);

/*Entradas: un arreglo estatico de chars de tamano 2
  Salidas: un 1 si la se verifico correctamente, un 0 si fue mal verificada
  Objetivo: verifica que cada linea de los archivos corresponda especificamente a 00, 01, 02, 03, 04, 05, 11, 12, 13, 21,22 y 31
  */
int verificarEntrada(char numero[2]);

/*Entradas: Un arreglo de chars estatico de 25, y 3 enteros correspondiente a la fila actual en la que nos encontremos y la reglas que le queramos aplicar (segun el archivo)
  Salidas: un 1 si el arreglo cumple con las reglas entregadas o un 0 si no lo cumple
  Objetivo: verificada que la fila dada por la  variable filActual cumpla con las reglas correspondiente al archivo
  */
int verificarFila(char sol[25],int filActual,int rule1,int rule2);

/*Entradas: Un arreglo de chars estatico de 25, y 3 enteros correspondiente a la columna actual en la que nos encontremos y la reglas que le queramos aplicar (segun el archivo)
  Salidas: un 1 si el arreglo cumple con las reglas entregadas o un 0 si no lo cumple
  Objetivo: verificada que la columna del arreglo dada por la  variable filActual cumpla con las reglas correspondiente al archivo
  */
int verificarColumna(char sol[25],int colActual,int rule1,int rule2);

/*Entradas: Un arreglo de chars de 2D, un entero a modo de puntero y un arreglo de chars
  Salidas: un arreglo de chars 2D
  Objetivo: Añade al arreglo 2D que se le entrega la ultima solucion encontrada
  */
char** agregarSolucion(char** soluciones, int* largo, char* nuevaSolucion);

/*Entradas: 2 chars estaticos de tamano 20
  Salidas: Una struct de tipo Entrada
  Objetivo: toma los nombres de los archivos dados por el usuario, comprueba su existencia y ademas comprueba si los datos en ellos son correctos, para 
  su posterior almacenaje en la variable de retorno
  */
Entrada lecturaArchivo(char nombreArchivoFilas[20],char nombreArchivoColumnas[20]);

int main(){
	menu(); // llamado al menu
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
				printf("FELICIDADES, HAZ HACKEADO LA NASA CON EXITO\n");
				printf("TE ESPERO EN OTRA AVENTURA\n");
				exit(1);
			default: // en caso que el usuario no ingrese una opcion valida, se printea este mensaje y se vuelve a repetir las opciones, hasta que se seleccione una opcion valida
				printf("\t\tPor favor, ingrese una de las opciones anteriormente mencionadas!!!\n\n");
		}
	}
	return;
}
void ejecucion(){
	FILE *fp = fopen("soluciones.txt","r"); // variable para comprobar si el archivo soluciones.txt fue creado con anterioridad o no
	int cantSoluciones = 0; // variable donde se almacena la cantidad de soluciones encontradas
	char **soluciones; // arreglo donde se guardan las soluciones encontradas
	char nombreArchivoFilas[20];
	char nombreArchivoColumnas[20];
	Entrada reglas;
	printf("Ingrese el nombre del archivo correspondiente a las reglas de las filas: ");
	gets(nombreArchivoFilas); printf("\n");
	printf("Ingrese el nombre del archivo correspondiente a las reglas de las columnas: ");
	gets(nombreArchivoColumnas); printf("\n");
	reglas = lecturaArchivo(nombreArchivoFilas,nombreArchivoColumnas); // se lee el archivo
	if (fp == NULL){ // en caso que sea la primera vez que se ejecuta el programa y no exista el archivo de soluciones
		crearSoluciones();
		fclose(fp);
	}
	fclose(fp);
	soluciones = revisarSoluciones(reglas,&cantSoluciones); // se revisan todas las soluciones y se guardan en la variable soluciones
	if (cantSoluciones == 0){
		printf("No se ha encontrado ninguna solucion para la combinacion de archivo entregada\n");
	}else{
		mostrarSoluciones(soluciones,&cantSoluciones); // en caso de haber soluciones, se muestran por pantalla
		printf("\nTOTAL DE SOLUCIONES ENCONTRADAS: %i\n", cantSoluciones);
	}
	printf("\n\t\t*********************************************************\n");
	printf("\t\tEL PROGRAMA HA FINALIZADO SU EJECUCION\n");
	printf("\t\t*********************************************************\n\n");
	for (int i = 0; i < cantSoluciones; ++i){
		free(soluciones[i]);
	}
	free(soluciones);
}
char **revisarSoluciones(Entrada reglas,int *cantSoluciones){
	FILE *archivo = fopen("soluciones.txt","r");
	char solAux[30];
	char **solucionesEncontradas = (char**)malloc(sizeof(char*)*0);
	int filActual;
	int colActual;
	if(archivo == NULL){ // caso en que el archivo no se encuentre o haya un error
		printf("El archivo con las soluciones creadas no fue encontrado!\n");
		exit(1);
	}
	// la idea es ir moviendo las variables filActual y colActual
	while (fgets(solAux,30,archivo)!=NULL){
		filActual = 0;
		colActual = 0;
		if (verificarFila(solAux,filActual,reglas.fila[0][0],reglas.fila[0][1]) == 1){ // se verifica la primera fila
			filActual = filActual+1;
			if (verificarFila(solAux,filActual,reglas.fila[1][0],reglas.fila[1][1]) == 1){ // se verifica la segunda fila
				filActual = filActual+1;
				if (verificarFila(solAux,filActual,reglas.fila[2][0],reglas.fila[2][1]) == 1){ // se verifica la tercera fila
					filActual = filActual+1;
					if (verificarFila(solAux,filActual,reglas.fila[3][0],reglas.fila[3][1]) == 1){ // se verifica la cuarta fila
						filActual = filActual+1;
						if (verificarFila(solAux,filActual,reglas.fila[4][0],reglas.fila[4][1]) == 1){ // se verifica la quinta fila
							if(verificarColumna(solAux,colActual,reglas.columna[0][0],reglas.columna[0][1]) == 1){ // se verifica la primera columna
								colActual = colActual + 1;
								if(verificarColumna(solAux,colActual,reglas.columna[1][0],reglas.columna[1][1]) == 1){ // se verifica la segunda columna
									colActual = colActual + 1;
									if(verificarColumna(solAux,colActual,reglas.columna[2][0],reglas.columna[2][1]) == 1){ // se verifica la tercera columna
										colActual = colActual + 1;
										if(verificarColumna(solAux,colActual,reglas.columna[3][0],reglas.columna[3][1]) == 1){ // se verifica la cuarta columna
											colActual = colActual + 1;
											if(verificarColumna(solAux,colActual,reglas.columna[4][0],reglas.columna[4][1]) == 1){ // se verifica la quinta columna
												solucionesEncontradas = agregarSolucion(solucionesEncontradas,cantSoluciones,solAux); // se agrega la solucion encontrada al arreglo
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
	}
	fclose(archivo);
	return solucionesEncontradas;
}
int verificarFila(char sol[25],int filActual,int rule1,int rule2){
	int aux = 0;
	switch (rule1){ // buscamos el caso del primer digito
		case 0:
			switch (rule2){ // buscamos el caso del segundo digito
				case 0:
					// se le resta - '0' a cada caracter, puesto que es la unica forma que encontre de pasar un caracter a entero y que no me de el codigo ascii
					// tonto pero eficiente
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					if(aux == 0){ // si la suma da 0, es porque no hay ninguna perforacion en ese fila
						return 1;
					}else{
						return 0;
					}
					break;
				case 1:
					// se suman todos los 1 en la fila
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					if(aux == 1){ // si solamente hay uno , se retorna 1
						return 1;
					}else{
						return 0;
					}
					break;
				case 2:
					// se suman todos los 1 en la fila
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					// recorremos la fila actual hasta el ultimo digito
					for (int i = (filActual*5); i < 5+(filActual*5); ++i){
						// cuando encontramos 1
						if (sol[i] == '1'){
							// si luego de encontrar el 1 encontramos otro y estamos dentro del limite de la fila se retorna 1
							if ((sol[i+1] == '1') && (i+1 < 5+(filActual*5)) && aux == 2){ // restringimos la ultima posicion para evitar que tome el de la siguiente fila
								return 1;
							}else{
								return 0;
							}
						}
					}
					break;
				case 3:
					// se suman todos los 1 en la fila
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					// recorremos la fila actual hasta el ultimo digito
					for (int i = (filActual*5); i < 5+(filActual*5); ++i){
						// cuando encontramos 1
						if (sol[i] == '1'){
							//verificamos que sean 3 "1"s consecutivos y que ademas solo hayan 3 en la fila
							if ( sol[i+1] == '1' && sol[i+2] == '1' && i+2 < 5+filActual*5 && aux == 3 ){ // restringimos la ultima posicion para evitar que tome el de la siguiente fila
								return 1;
							}else{
								return 0;
							}
						}
					}
					return 0;
					break;
				case 4:
					// se suman todos los 1 en la fila
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					// se recorre la fila hasta el ultimo digito
					for (int i = (filActual*5); i < 5+(filActual*5); ++i){
						// se verifica que luego de encontrar el 1, esten los 4 seguidos 
						if (sol[i] == '1'){
							if ((sol[i+1] == '1') && (sol[i+2] == '1') && (sol[i+3] == '1') && (i+3 < 5+(filActual*5)) && aux == 3){ // restringimos la ultima posicion para evitar que tome el de la siguiente fila
								return 1;
							}else{
								return 0;
							}
						}
					}
					break;
				case 5:
					// se suman los 1 totales de la fila
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					// la unica manera que existan cincos 1 en la fila es que el total de 1 sea 5
					if (aux == 5){
						return 1;
					}else{
						return 0;
					}
					break;		
			}
			break;
		case 1:
			switch (rule2){
				case 1: ;
					// se crea un contador
					int counter = 0;
					// se suma el total de unos en la misma fila
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					// se recorre la fila hasta el ultimo digito de esa fila
					for (int i = (filActual*5); i < 5+(filActual*5); ++i){
						// se verifica que al momento que se encuentre un uno, el siguiente sea un cero y luego de ese cero haya otro 1
						if (sol[i] == '1'){
							if(sol[i+1] == '0' && (i+1 < (5+(filActual*5)))){
								for (int k = (i+1); k < (5+(filActual*5)); ++k){
									// ademas se verifica que el total de unos sea 2
									if (sol[k+1] == '1' && k+1< 5+(filActual*5) && aux == 2){
										counter++;
									}
								}
								if (counter == 1){

									return 1;
								}else{
									return 0;
								}
							}
						}
					}
					return 0;
					break;
				case 2:
					// se suma el total de unos en la misma fila
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					// se recorre la fila hasta el ultimo digito de la fila
					for (int i = (filActual*5); i < 5+(filActual*5); ++i){
						// se verifica que luego de encontra un uno, el digito siguiente sea un cero y se mantenga dentro del limite de la fila
						if (sol[i] == '1' && sol[i+1] == '0' && i+1 < 5+(filActual*5)){
							// luego del 0 encontrado se recorre lo que uqede de arreglo
							for (int k = i+1; k < 5+(filActual*5); ++k){
								// si hay 2 unos consecutivos y se encuentran dentro del rango de la fila, ademas el total de unos en la fila es 3, se retorna 1
								if (sol[k+1] == '1' && sol[k+2] == '1' && aux == 3 && k+2 < 5+(filActual*5)){
									return 1;
								}
							}
							return 0;
						}
					}
					return 0;
					break;
				case 3:	
					// se suma el total de unos en la misma fila
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					// se recorre toda la fila hasta el ultimo digito
					for (int i = (filActual*5); i < 5+(filActual*5); ++i){
						// se verifica que luego de encontrar un uno el siguiente sea un 0
						if (sol[i] == '1' && sol[i+1] == '0'){
							// se recorre lo que queda de arreglo desde el 0 hasta el final
							for (int k = i+1; k < 5+(filActual*5); ++k){
								// se verifica que hayan 3 unos consecutivos, el total de unos en la fila sea 4 y se encuentre todo en los limites de la fila
								if (sol[k+1] == '1' && sol[k+2] == '1' && sol[k+3] == '1' && aux == 4 && k+3 < 5+(filActual*5)){
								return 1;
								}
							}
							return 0;
						}
					}
					return 0;
					break;
			}
			break;
		case 2:
			switch (rule2){
				case 1:
					// se suma el total de unos en la misma fila
					aux = (sol[0+(filActual*5)] - '0') + (sol[1+(filActual*5)] - '0') + (sol[2+(filActual*5)] - '0') + (sol[3+(filActual*5)] - '0') + (sol[4+(filActual*5)] - '0');
					// se recorre toda la fila
					for (int i = (filActual*5); i < 5+(filActual*5); ++i){
						// se verifica que al encontrar un uno el siguiente sea un 1 y el siguiente+1 sea un cero
						if (sol[i] == '1' && sol[i+1] == '1' && sol[i+2] == '0' && i+2 < 5+(filActual*5)){
							// se recorre el resto de fila desde el cero hasta encontrar otro 1, que el total de unos sea 3 y se encuentre todo dentro del limite de la fila
							for (int k = i+2; k < 5+(filActual*5); ++k){
								if (sol[k+2] == '1' && aux == 3 && k+2 < 5+(filActual*5)){
									return 1;
								}
							}
							return 0;
						}
					}
					return 0;
					break;
				case 2:
					// la unica forma que exista 22 es tener la fila tipo 11011
					if (sol[0+(filActual*5)] == '1' && sol[1+(filActual*5)] == '1' && sol[2+(filActual*5)] == '0' && sol[3+(filActual*5)] == '1' && sol[4+(filActual*5)] == '1'){
						return 1;
					}else{
						return 0;
					}
					break;					
			}
			break;
		case 3:	
			// la unica forma que exista 31 es tener la fila tipo 11101
			if(sol[0+(filActual*5)] == '1' && sol[1+(filActual*5)] == '1' && sol[2+(filActual*5)] == '1' && sol[3+(filActual*5)] == '0' && sol[4+(filActual*5)] == '1'){
				return 1;
			}else{
				return 0;
			}
			break;
	}
}
int verificarColumna(char sol[25],int colActual,int rule1,int rule2){
	/* El modo de operar para las columnas es exactamente el mismo que el de la las columnas, solamente se tiene cuidado de mover el indice del arreglo
	   de modo que este acorde a las columnas, como si fuese una matriz, es decir, a la colActual, se le suma la operacion (5 * la fila que  queramos)
	*/
	int aux = 0;
	switch (rule1){
		case 0:
			switch(rule2){
				case 0:
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					if (aux == 0){
						return 1; 
					}else{
						return 0;
					}
					break;
				case 1:
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					if (aux == 1){
						return 1;
					}else{
						return 0;
					}
					break;
				case 2:
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					for (int i = colActual; i <= colActual+5*4; i = i + 5){
						if (sol[i] == '1'){
							if(sol[i+5] == '1' && i+5 <=colActual+5*4 && aux == 2){
								return 1;
							}
						}
					}
					return 0;
					break;
				case 3:
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					for (int i = colActual; i <=colActual+5*4; i = i + 5){
						if (sol[i] == '1'){
							if(sol[i+5] == '1' && sol[i+10] == '1' && i+10 <=colActual+5*4 && aux == 3){
								return 1;
							}
						}			
					}
					return 0;
					break;
				case 4:
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					for (int i = colActual; i <=colActual+5*4; i = i + 5){
						if (sol[i] == '1'){
							if(sol[i+5] == '1' && sol[i+10] == '1' && sol[i+15] == '1' && i+15 <=colActual+5*4 && aux == 4){
								return 1;
							}
						}				
					}		
					return 0;
					break;
				case 5:
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					if (aux == 5){
						return 1;
					}else{
						return 0;
					}
					break;		
			}
			break;
		case 1:
			switch (rule2){
				case 1: ;
					int counter = 0;
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					for (int i = colActual; i <=colActual+5*4 ; i = i + 5){				
						if (sol[i] == '1' && sol[i+5] == '0' && i+5 <=colActual+5*4){
							for (int k = i+5; k <=colActual+5*4; k = k + 5){
								if (sol[k+5] == '1' && k+5<=(colActual+5*4) && aux == 2){
									counter++;
								}
							}
							if (counter == 1){
								return 1;
							}else{
								return 0;
							}
						}
					}
					return 0;
					break;
				case 2:
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					for (int i = colActual; i <=colActual+5*4;i = i + 5){
						if (sol[i] == '1' && sol[i+5] == '0' && i+5<=colActual+5*4){
							for (int k = i+5; k <=colActual+5*4;k = k + 5){
								if (sol[k+5] == '1' && sol[k+10] == '1' && aux == 3 && k+10<=colActual+5*4){
									return 1;
								}
							}
							return 0;
						}
					}
					return 0;
					break;
				case 3:
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					for (int i = colActual; i <=colActual+5*4;i = i + 5){
						if (sol[i] == '1' && sol[i+5] == '0'){
							for (int k = i+5; k <= colActual+5*4;k = k + 5){
								if (sol[k+5] == '1' && sol[k+10] == '1' && sol[k+15] == '1' && aux == 4 && k+15<=colActual+5*4){
									return 1;
								}
							}
							return 0;
						}		
					}
					return 0;
					break;	
			}
			break;
		case 2:
			switch (rule2){
				case 1:
					aux = (sol[colActual+5*0] - '0') + (sol[colActual+5*1] - '0') + (sol[colActual+5*2] - '0') + (sol[colActual+5*3] - '0') + (sol[colActual+5*4] - '0');
					for (int i = colActual; i <= colActual+5*4;i = i + 5){
						if (sol[i] == '1' && sol[i+5] == '1' && sol[i+10] == '0' && i+10<=colActual+5*4){
							for (int k = i+10; k < colActual+5*4;k = k + 5 ){
								if (sol[k+10] == '1' && aux == 3 && k+10<=colActual+5*4){
									return 1;
								}
							}
							return 0;
						}
					}
					return 0;
					break;
				case 2:
					// la unica forma de tener 22 es tener la columna tipo 11011
					if (sol[colActual+0*5] == '1' && sol[colActual+1*5] == '1' && sol[colActual+2*5] == '0' && sol[colActual+3*5] == '1' && sol[colActual+4*5] == '1')	{
						return 1;
					}else{
						return 0;
					}
					break;
			}
			break;
		case 3:
			// la unica forma de tener 31 es tener la columna de tipo 11101
			if (sol[colActual+0*5] == '1' && sol[colActual+1*5] == '1' && sol[colActual+2*5] == '1' && sol[colActual+3*5] == '0' && sol[colActual+4*5] == '1')	{
					return 1;
				}else{
					return 0;
				}
			break;
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
						index++;
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
	// liberamos memoria
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
void mostrarSoluciones(char **soluciones,int *cantSoluciones){
	printf("\tSoluciones encontradas:\n\n");
	for (int i = 0; i < *cantSoluciones; ++i){
		printf("\nSolucion numero: %i\n", i+1);
		printf("%c %c %c %c %c\n%c %c %c %c %c\n%c %c %c %c %c\n%c %c %c %c %c\n%c %c %c %c %c\n",soluciones[i][0],soluciones[i][1],soluciones[i][2],soluciones[i][3],soluciones[i][4],
		soluciones[i][5],soluciones[i][6],soluciones[i][7],soluciones[i][8],soluciones[i][9],soluciones[i][10],soluciones[i][11],soluciones[i][12],soluciones[i][13],soluciones[i][14],
		soluciones[i][15],soluciones[i][16],soluciones[i][17],soluciones[i][18],soluciones[i][19],soluciones[i][20],soluciones[i][21],soluciones[i][22],soluciones[i][23],soluciones[i][24]);
	}
}
Entrada lecturaArchivo(char nombreArchivoFilas[20],char nombreArchivoColumnas[20]){
	char nombreFila[50] = "Pistas/"; char nombreColumna[50] = "Pistas/"; // variables donde se guardara el nombre como pistas/nombre
	char filaAux[2]; 
	Entrada retorno;
	// concatenamos los strings
	strcat(nombreFila,nombreArchivoFilas); 
	strcat(nombreColumna,nombreArchivoColumnas);
	// se crean las variables para las entradas
	FILE *archivoFila = fopen(nombreFila,"r");
	FILE *archivoColumna = fopen(nombreColumna,"r");
	// Caso que una entrada o las dos no se encuentren en la carpeta de pistas
	if (archivoFila == NULL || archivoColumna == NULL){ 
		printf("Verifique que ambos archivos esten correctamente colocados en la carpeta Pistas\n");
		printf("La carpeta Pistas se debe encontrar en la misma raiz donde se encuentra el programa\n");
		exit(1);
	}
	// como bien dice el documento, los archivos siempre seran 5 numeros de 2 digitos, entonces
	for (int i = 0; i < 5; ++i){
		fscanf(archivoFila," %[^\n]",filaAux);
		if (verificarEntrada(filaAux) == 0){ // si hay un error en el archivo, se muestra donde se encuentra el error
			printf("ERROR EN EL ARCHIVO: %s, FILA: %i\n",nombreArchivoFilas,i+1 );
			exit(1);
		}
		// se guardan las filas en la struct
		retorno.fila[i][0] = (filaAux[0]) - '0'; 
		retorno.fila[i][1] = (filaAux[1]) - '0';
	}
	for (int i = 0; i < 5; ++i){
		fscanf(archivoColumna," %[^\n]",filaAux);
		if (verificarEntrada(filaAux) == 0){ // si hay un error en el archivo, se muestra donde se encuentra el error
			printf("ERROR EN EL ARCHIVO: %s, FILA: %i\n",nombreArchivoColumnas,i+1 );
			exit(1);
		}
		// se guardan las filas en la struct
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

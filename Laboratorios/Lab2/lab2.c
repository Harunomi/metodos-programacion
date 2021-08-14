#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
SECCIÓN DEL CURSO: L-10
 PROFESOR DE TEORÍA: ALEJANDRO CISTERNA VILLALOBOS
 PROFESOR DE LABORATORIO: MARCELA RIVERA
 AUTOR
 NOMBRE: Cristhofer Parada Salazar
 RUT: 20.387.754-4
 CARRERA: Ingeniería Civil informatica
 Fecha: 07-01-2021
 Version: 1.0
 Objetivo: El programa tiene como objetivo resolver un problema de tiempo, en el cual 4 personas deben cruzar un puente que solo admite 2 personas a la vez,
 ademas para cruzar el puente debe hacerse siempre con una linterna y cada persona tiene un tiempo que se demora en cruzar, en su defecto, al cruzar dos personas
 se considera el tiempo recorrido de aquel que se demore mas. El programa resuelve esto mediante el algorito de Busqueda en Espacios de Estados, anchura iterativo.
*/
/* Estructura la cual define mis estados, las variables persona1 a la persona 4, junto con linterna, corresponden a la posicion en la que se encuentra la persona
sea 0 si se encuentra en la isla (es decir debe cruzar) y 1 si se encuentra en la ciudad(debe devolverse o esperar)*/
typedef struct Estado {
	int id;
	int idAnterior;
	int persona1;
	int persona2;
	int persona3;
	int persona4;
	int linterna;
	int tiempoTotal;
	char transicion[30];
}Estado;
int aux;
/* Entradas: ninguna
	Salidas: ninguna
Objetivo: servir como menu iterativo que al ingresar 1 sale del programa y al ingresar 0 llama a la funcion ejecucion()*/
void menu();

/*Entradas: ninguna
Salidas: ninguna
Objetivo: en esta funcion ocurre todo el llamado de algoritmo y las entradas que ingrese el usuario*/
void ejecucion();

/*Entradas: ninguna
Salidas: ninguna
Objetivo: limpiar el buffer, lee todo lo que tenga el stdin hasta llegar a un '/n'*/
void clearBuffer();

/*Entradas: 4 chars que corresponderian a los nombres del grupo
Salida: ninguna
Objetivo: cambiar por referencia el nombre de las personas por el que quiera el usuario*/
void cambiarNombres(char *nombre1,char *nombre2,char *nombre3, char *nombre4);

/*Entradas: un array de tipo Estado y un entero correspondiente al tamano del arreglo
Salida: ninguna
Objetivo: una vez encontrado el estado final, se printean los pasos necesarios para llegar a este*/
void mostrarResultado(Estado * arreglo,int size);

/*Entradas: un char de tamano 5
Salida:  un entero
Objetivo: si el char ingresado corresponde a un entero, se retorna este, de no ser asi, se pregunta que se ingrese nuevamente un numero
hasta que la entrada sea correcta, y se retorna esta entrada*/ 
int validacionCiclo(char numero[5]);

/*Entradas: un entero
Salida: 0 si el n umero no corresponde a un entero positivo, 1 si lo corresponde
Objetivo: recorre el char valor por valor evaluando si cada uno es un ".", "-" o un caracter en minuscula o mayuscula*/
int validacionEnteroPositivo(char numero[5]);

/*Entradas: un arreglo de tipo arreglo y una variable de tipo estado llamada r, de revisar
Salida: 0 si el estado ingresado no se encuentra en el arreglo, y un 1 si se encuentra
Objetivo: comprobar si dicho estado ya se encuentra en el arreglo dado, ya sea el arreglo de abiertos o cerrados, compara cada variable de personas, la linterna y el tiempoTotal*/
int estaEstado(Estado * arreglo,int size,Estado r);

/*Entradas: una variable de tipo Estado: 
Salida: 0 y 1
Objetivo: revisa el estado actual y comprueba si corresponde al estado final o estado objetivo, si lo es devuelve 1, de no serlo devuelve 0*/
int estadoFinal(Estado revisar);

/*Entradas: dos variables int
Salida: una variable int
Objetivo: compara cual de los dos numeros es el mayor, retornando el mayor de ambos */
int elMayor(int T1,int T2);

/*Entradas: una variable tipo Estado 
Salida: 0 y 1
Objetivo: evalua si a partir del estado actual, se pueden cruzar las personas indicadas en los numeros, para ello dichas personas deben estar en 0,
de ser asi, retorna un 1 indicando que pueden cruzar, caso opuesto retorna 0*/
int verificar1y2(Estado revisar);

/*Entradas: una variable tipo estado, una variable tipo int y 2 variables tipo char
Salida: una variable de tipo Estado
Objetivo: dado que se verifico que pueden cruzar, se crea el estado cambiando las variables de las personas que pueden cruzar por 1, al tiempo total del
estado se le resta la variable tiempoResta y se concatenan los nombres 1 y 2 con otras variables dentro de la funcion para asi tener un string para la transicion*/

/**********para el resto de funciones cruzarNumeroyNumero y verificarNumeroyNumero las entradas y objetivos son los mismos*/
Estado cruzar1y2(Estado estado,int tiempoResta,char *nombre1,char *nombre2);
int verificar1y3(Estado revisar);
Estado cruzar1y3(Estado estado,int tiempoResta,char *nombre1,char *nombre2);
int verificar1y4(Estado revisar);
Estado cruzar1y4(Estado estado,int tiempoResta,char *nombre1,char *nombre2);
int verificar2y3(Estado revisar);
Estado cruzar2y3(Estado estado,int tiempoResta,char *nombre1,char *nombre2);
int verificar2y4(Estado revisar);
Estado cruzar2y4(Estado estado,int tiempoResta,char *nombre1,char *nombre2);
int verificar3y4(Estado revisar);
Estado cruzar3y4(Estado estado,int tiempoResta,char *nombre1,char *nombre2);

/*********** Para el resto de funciones devolverNumero y verificarNumero las entradas y objetivos son los mismos*/
/*Entradas: una variable de tipo Estado 
Salida: un 0 o un 1
Objetivo: verificar si es posible que a partir del estado actual, la persona de pueda devolver, retornando 1 si se puede devolver o 0 si no*/
int verificar1(Estado revisar);

/*Entradas: una variable de tipo Estado, un entero y un arreglo de chars
Salida: una variable de tipo Estado
Objetivo: con esta funcion se pretende crear un estado en la cual la persona indicada se devuelva, es decir su valor pase de 1 a 0, 
al tiempo total del estado se le resta la variable tiempoResta y se concatena el arreglo de nombre con unas variables dentro de la funcion para crear la variable
correspondiente a la transicion realizada*/
Estado devolver1(Estado estado,int tiempoResta,char *nombre);
int verificar2(Estado revisar);
Estado devolver2(Estado estado,int tiempoResta,char *nombre);
int verificar3(Estado revisar);
Estado devolver3(Estado estado,int tiempoResta,char *nombre);
int verificar4(Estado revisar);
Estado devolver4(Estado estado,int tiempoResta,char *nombre);

/*Entradas: 4 varaibles correspondiente a la posicion de las personas, la posicion de la linterna, el tiempo total, el id y un arreglo de chars correspondiente al a transicion
Salida: una variable tipo Estado
Objetivo: crear estados a partir de las variables indicadas, ademas aumenta el valor de AUX que correspodneria al ID de los estados generados*/
Estado crearEstado(int P1, int P2, int P3, int P4,int linterna,int tiempo,int id,char transicion[20]);

/*Entradas: un arreglo del tipo Estado, un entero por puntero y una variable tipo Estado
Salida: un arreglo de tipo Estado
Objetivo: recibe el arreglo con su tamaño, crea un arreglo local que sea del tamano + 1, se copian cada valor del arreglo dado al arreglo local y al ultimo se le agrega el estado paraAgregar*/
Estado *agregarEstado(Estado * abiertos,int * size, Estado paraAgregar);

/*Entradas: un arreglo de tipo Estado y un entero por puntero
Salida: un arreglo de tipo Estado
Objetivo: crea un arreglo local de size-1 como tamano, copia todos los elementos del arreglo dado excepto el primero y lo retorna*/
Estado *eliminarEstado(Estado *abiertos, int *size);

/*Entradas: una variable de tipo Estado
Salida: 0 o 1
Objetivo: Se revisa cada variable del estado dado y se verifica si corresponde al final, es decir uqe todas las personas con la linterna esten en 1
y que el tiempo sea mayor igual a 0, de cumplirse esas condiciones retorna 1, caso opuesto retorna 0*/
int estadoFinal(Estado revisar);


int main(){
	menu();
	return 0;
}
void menu(){
	char seleccion;
	printf("\n\t\t*********************************************************\n");
	printf("\t\tBienvenid@ al programa de busqueda en Espacio de Estados\n");
	printf("\t\t*********************************************************\n");
	while(seleccion!='0'){
		printf("Ingrese una de las opciones:\n");
		printf("1: Si desea ingresar la informacion del grupo que debe cruzar\n");
		printf("0: Si desea salir del programa\n");
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
}
void ejecucion(){
	/*Entradas*/
	char tiempoMaxChar[5]; char tiempoCharP1[5]; char tiempoCharP2[5];char tiempoCharP3[5];char tiempoCharP4[5]; // variables donde se verifica que todo este correcto
	int tiempoMax,tiempoP1,tiempoP2,tiempoP3,tiempoP4,tiempoResta; //una vez verificada las variables anteriores se guardan como entero en estas
	char seleccionNombre; // responsable de recibir la opcion ingresada por el usuario
	char nombre1[20]; char nombre2[20]; char nombre3[20]; char nombre4[20]; // variables donde se guardan los nombres de los integrantes del grupo
	Estado estActual,estSiguiente;
	aux = 0; // variable que corresponderia al ID de los estados
	int canAbiertos = 0; 
	int canCerrados = 0;
	Estado * abiertos = (Estado*)malloc(sizeof(Estado)*canAbiertos);
	Estado * cerrados = (Estado*)malloc(sizeof(Estado)*canCerrados);
	printf("Desea utilizar los nombres por defecto? (Juan, Paola, Diego, Jazmin)\n");
	while(seleccionNombre != '1' || seleccionNombre != '2'){ // se pregunta al usuario si desea ingresar el los nombres de cada integrante o se pregunta si desea utilizar los nombres por defecto
		printf("1: cambiar los nombres de cada integrante\n");
		printf("2: utilizar los nombres por defecto\n");
		seleccionNombre = getc(stdin);
		printf("Seleccion nombre: %c\n",seleccionNombre );
		clearBuffer();
		switch (seleccionNombre){
			case '1': // si el usuario quiere modificar los nombres por defecto
				cambiarNombres(nombre1,nombre2,nombre3,nombre4);
				break;
			case '2': // si el usuario desea utilizar los nombres por defecto
				strcpy(nombre1,"Juan"); strcpy(nombre2,"Paola");strcpy(nombre3,"Diego");strcpy(nombre4,"Jazmin");
				break;
			default: // si el usuario no ingresa una opcion valida el ciclo continua
				printf("\t\tPor favor, ingrese una de las opciones anteriormente mencionadas!!!\n\n");
				break;
		}
		if (seleccionNombre == '2'){
			break;
		}
					
	}
	printf("Nombres: %s, %s, %s, %s\n",nombre1,nombre2,nombre3,nombre4 ); 
	printf("Ingrese el tiempo maximo en que las personas deben cruzar el puente: ");
	/* se pide el tiempo maximo para cruzar y los tiempos de cada persona, ademas de verificarse si son enteros o no*/
	scanf("%s",tiempoMaxChar); printf("\n"); clearBuffer();
	tiempoMax = validacionCiclo(tiempoMaxChar);
	printf("Ingrese el tiempo que se demora %s en cruzar el puente\n",nombre1);
	scanf("%s",tiempoCharP1);
	tiempoP1 = validacionCiclo(tiempoCharP1); clearBuffer();
	printf("Ingrese el tiempo que se demora %s en cruzar el puente\n",nombre2);
	scanf("%s",tiempoCharP2);
	tiempoP2 = validacionCiclo(tiempoCharP2); clearBuffer();
	printf("Ingrese el tiempo que se demora %s en cruzar el puente\n",nombre3);
	scanf("%s",tiempoCharP3);
	tiempoP3 = validacionCiclo(tiempoCharP3); clearBuffer();
	printf("Ingrese el tiempo que se demora %s en cruzar el puente\n",nombre4);
	scanf("%s",tiempoCharP4);
	tiempoP4 = validacionCiclo(tiempoCharP4); clearBuffer();
	printf("%s: %i, %s: %i, %s: %i, %s: %i Tiempo maximo: %i\n",nombre1,tiempoP1,nombre2,tiempoP2,nombre3,tiempoP3,nombre4,tiempoP4,tiempoMax);
	Estado inicial = crearEstado(0,0,0,0,0,tiempoMax,aux,""); // se crea el estado inicial con todas las personas en 0 y la linterna y el tiempo total el ingresado por el usuario
	abiertos = agregarEstado(abiertos,&canAbiertos,inicial); // se agrega al arreglo de estados abiertos
	while (canAbiertos>0){
		estActual = abiertos[0]; // se toma el primer elemento del estado abierto
		abiertos = eliminarEstado(abiertos,&canAbiertos); // se elimina de la lista de abiertos
		cerrados = agregarEstado(cerrados,&canCerrados,estActual); // se agrega a la lista de cerrados
		if (estadoFinal(estActual) == 1){ // se verifica si es el estado final
			mostrarResultado(cerrados,canCerrados-1);
			break;
		}else if (estActual.tiempoTotal <= 0){ // estado fallido, cuando el estado actual no cumple con la restriccion del tiempo dado
			continue;
		}else{
			switch (estActual.linterna){ //dependiendo de la posicion de la linterna del estado actual, se cruza a la ciudad o se devuelve a la isla
				case 0: // cruzo
					if(verificar1y2(estActual) == 1){ // si pueden cruzar la persona 1 y persona 2
						tiempoResta = elMayor(tiempoP1,tiempoP2);
						estSiguiente = cruzar1y2(estActual,tiempoResta,nombre1,nombre2);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}
					if(verificar1y3(estActual) == 1){ // si puede cruzar la persona 1 y 3
						tiempoResta = elMayor(tiempoP1,tiempoP3);
						estSiguiente = cruzar1y3(estActual,tiempoResta,nombre1,nombre3);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}
					if(verificar1y4(estActual) == 1){ // si puede cruzar la persona 1 y 4
						tiempoResta = elMayor(tiempoP1,tiempoP4);
						estSiguiente = cruzar1y4(estActual,tiempoResta,nombre1,nombre4);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}
					if(verificar2y3(estActual) == 1){ // si puede cruzar la persona 2 y 3
						tiempoResta = elMayor(tiempoP2,tiempoP3);
						estSiguiente = cruzar2y3(estActual,tiempoResta,nombre2,nombre3);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}
					if(verificar2y4(estActual) == 1){ // si puede cruzar la persona 2 y 4
						tiempoResta = elMayor(tiempoP2,tiempoP4);
						estSiguiente = cruzar2y4(estActual,tiempoResta,nombre2,nombre4);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}
					if(verificar3y4(estActual) == 1){ // si puede cruzar la persona 3 y 4
						tiempoResta = elMayor(tiempoP3,tiempoP4);
						estSiguiente = cruzar3y4(estActual,tiempoResta,nombre3,nombre4);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}
				case 1: // me devuelvo
					if(verificar1(estActual) == 1){ // verifico si la persona 1 se puede devolver
						tiempoResta = tiempoP1;
						estSiguiente = devolver1(estActual,tiempoResta,nombre1);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}
					if(verificar2(estActual) == 1){// verifico si la persona 2 se puede devolver
						tiempoResta = tiempoP2;
						estSiguiente = devolver2(estActual,tiempoResta,nombre2);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}
					if(verificar3(estActual) == 1){ // verifico si la persona 3 se puede devolver
						tiempoResta = tiempoP3;
						estSiguiente = devolver3(estActual,tiempoResta,nombre3);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}
					if(verificar4(estActual) == 1){ // verifico si la persona 4 se puede devolver
						tiempoResta = tiempoP4;
						estSiguiente = devolver4(estActual,tiempoResta,nombre4);
						if((estaEstado(abiertos,canAbiertos,estSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estSiguiente) == 0)){
							abiertos = agregarEstado(abiertos,&canAbiertos,estSiguiente);
						}else{
							aux = aux - 1;
						}
					}	
			}
		}
	}
	if (canAbiertos == 0) // caso en que no se llego a un estado final
		printf("\nEl grupo no puede cruzar en el tiempo indicado\n");
	free(abiertos);
	free(cerrados);
	printf("\n\t\t****************************************************\n");
	printf("\t\t  El programa termino su ejecucion correctamente!!\n");
	printf("\t\t****************************************************\n");
}
void clearBuffer(){
	while (getchar()!= '\n');
}
void cambiarNombres(char *nombre1,char *nombre2,char *nombre3, char *nombre4){
	printf("Ingrese el nombre por el cual le gustaria reemplazar el de Juan\n");
	scanf("%s",nombre1); clearBuffer();
	printf("Ingrese el nombre por el cual le gustaria reemplazar el de Paola\n");
	scanf("%s",nombre2); clearBuffer();
	printf("Ingrese el nombre por el cual le gustaria reemplazar el de Diego\n");
	scanf("%s",nombre3); clearBuffer();
	printf("Ingrese el nombre por el cual le gustaria reemplazar el de Jazmin\n");
	scanf("%s",nombre4); clearBuffer();
}
void mostrarResultado(Estado * arreglo,int size){
	printf("Los pasos que se hicieron para llegar a la solucion fueron:\n\n");
	while (arreglo[size].id != 0){
		printf("%s\n\n", arreglo[size].transicion);
		size = arreglo[size].idAnterior;
	}
}
int validacionCiclo(char numero[5]){
	int validacion = validacionEnteroPositivo(numero);
	while(validacion == 0){
		printf("Por favor ingrese un numero entero positivo:\n");
		free(numero);
		scanf("%s",numero);
		clearBuffer();
		validacion = validacionEnteroPositivo(numero);
	}
	int resultado = atoi(numero);
	return resultado;
}

int validacionEnteroPositivo(char numero[5]){
	int i = -1;
	while(numero[i++] != '\0'){
		if (numero[i] == '.' || numero[i] == '-' || isalpha(numero[i]) == 1 || isalpha(numero[i]) == 2){
			return 0;
		}
	}	
	return 1;
}
int estadoFinal(Estado e){
	if(e.persona1 == 1 && e.persona2 == 1 && e.persona3 == 1 && e.persona4 == 1 && e.linterna == 1 && e.tiempoTotal >= 0)
		return 1;
	return 0;
}
int elMayor(int T1,int T2){
	if (T1 >= T2)
		return T1;
	else
		return T2;
}
int verificar1y2(Estado verificar){
	if(verificar.persona1 == 0 && verificar.persona2 == 0){
		return 1;
	}return 0;
}
Estado cruzar1y2(Estado estado,int tiempoResta,char *nombre1,char *nombre2){
	char transicion1[20] = "Cruzaron "; char transicion2[20] = " junto con ";
	strcat(transicion1,nombre1); strcat(transicion1,transicion2); strcat(transicion1,nombre2);  
	return crearEstado(1,1,estado.persona3,estado.persona4,1,estado.tiempoTotal-tiempoResta,estado.id,transicion1);
}
int verificar1y3(Estado verificar){
	if(verificar.persona1 == 0 && verificar.persona3 == 0){
		return 1;
	}return 0;
}
Estado cruzar1y3(Estado estado,int tiempoResta,char *nombre1,char *nombre2){
	char transicion1[20] = "Cruzaron "; char transicion2[20] = " junto con ";
	strcat(transicion1,nombre1); strcat(transicion1,transicion2); strcat(transicion1,nombre2);  
	return crearEstado(1,estado.persona2,1,estado.persona4,1,estado.tiempoTotal-tiempoResta,estado.id,transicion1);
}
int verificar1y4(Estado verificar){
	if(verificar.persona1 == 0 && verificar.persona4 == 0){
		return 1;
	}return 0;
}
Estado cruzar1y4(Estado estado,int tiempoResta,char *nombre1,char *nombre2){
	char transicion1[20] = "Cruzaron "; char transicion2[20] = " junto con ";
	strcat(transicion1,nombre1); strcat(transicion1,transicion2); strcat(transicion1,nombre2);  
	return crearEstado(1,estado.persona2,estado.persona3,1,1,estado.tiempoTotal-tiempoResta,estado.id,transicion1);
}
int verificar2y3(Estado verificar){
	if(verificar.persona2 == 0 && verificar.persona2 == 0){
		return 1;
	}return 0;
}
Estado cruzar2y3(Estado estado,int tiempoResta,char *nombre1,char *nombre2){
	char transicion1[20] = "Cruzaron "; char transicion2[20] = " junto con ";
	strcat(transicion1,nombre1); strcat(transicion1,transicion2); strcat(transicion1,nombre2);  
	return crearEstado(estado.persona1,1,1,estado.persona4,1,estado.tiempoTotal-tiempoResta,estado.id,transicion1);
}
int verificar2y4(Estado verificar){
	if(verificar.persona2 == 0 && verificar.persona4 == 0){
		return 1;
	}return 0;
}
Estado cruzar2y4(Estado estado,int tiempoResta,char *nombre1,char *nombre2){
	char transicion1[20] = "Cruzaron "; char transicion2[20] = " junto con ";
	strcat(transicion1,nombre1); strcat(transicion1,transicion2); strcat(transicion1,nombre2);  
	return crearEstado(estado.persona1,1,estado.persona3,1,1,estado.tiempoTotal-tiempoResta,estado.id,transicion1);
}
int verificar3y4(Estado verificar){
	if(verificar.persona3 == 0 && verificar.persona4 ==0){
		return 1;
	}return 0;
}
Estado cruzar3y4(Estado estado,int tiempoResta,char *nombre1,char *nombre2){
	char transicion1[20] = "Cruzaron "; char transicion2[20] = " junto con ";
	strcat(transicion1,nombre1); strcat(transicion1,transicion2); strcat(transicion1,nombre2);  
	return crearEstado(estado.persona1,estado.persona2,1,1,1,estado.tiempoTotal-tiempoResta,estado.id,transicion1);
}
int verificar1(Estado verificar){
	if(verificar.persona1 == 1){
		return 1;
	}return 0;
}
Estado devolver1(Estado estado,int tiempoResta,char *nombre){
	char transicion[20] = "Se devuelve "; strcat(transicion,nombre);
	return crearEstado(0,estado.persona2,estado.persona3,estado.persona4,0,estado.tiempoTotal-tiempoResta,estado.id,transicion);
}
int verificar2(Estado verificar){
	if(verificar.persona2 == 1){
		return 1;
	}return 0;

}
Estado devolver2(Estado estado,int tiempoResta,char *nombre){
	char transicion[20] = "Se devuelve "; strcat(transicion,nombre);
	return crearEstado(estado.persona1,0,estado.persona3,estado.persona4,0,estado.tiempoTotal-tiempoResta,estado.id,transicion);
}
int verificar3(Estado verificar){
	if(verificar.persona3 == 1){
		return 1;
	}return 0;
}
Estado devolver3(Estado estado,int tiempoResta,char *nombre){
	char transicion[20] = "Se devuelve "; strcat(transicion,nombre);
	return crearEstado(estado.persona1,estado.persona2,0,estado.persona4,0,estado.tiempoTotal-tiempoResta,estado.id,transicion);
}
int verificar4(Estado verificar){
	if(verificar.persona4 == 1){
		return 1;
	}return 0;
}
Estado devolver4(Estado estado,int tiempoResta,char *nombre){
	char transicion[20] = "Se devuelve "; strcat(transicion,nombre);
	return crearEstado(estado.persona1,estado.persona2,estado.persona3,0,0,estado.tiempoTotal-tiempoResta,estado.id,transicion);
}
Estado crearEstado(int P1, int P2, int P3, int P4,int linterna,int tiempo,int id,char transicion[20]){
	Estado nuevo;
	nuevo.persona1 = P1;
	nuevo.persona2 = P2;
	nuevo.persona3 = P3;
	nuevo.persona4 = P4;
	nuevo.linterna = linterna;
	nuevo.tiempoTotal = tiempo;
	nuevo.id = aux;
	nuevo.idAnterior = id;
	strcpy(nuevo.transicion,transicion);
	aux = aux + 1;
	return nuevo;
}

Estado *agregarEstado(Estado * abiertos,int * size, Estado paraAgregar){
	Estado * listaNueva = (Estado*)malloc(sizeof(Estado)*(*size+1));
	for (int i = 0; i < *size; ++i){
		listaNueva[i] = abiertos[i];
	}
	listaNueva[*size] = paraAgregar;
	*size = *size + 1;
	free(abiertos);
	return listaNueva;
}
int estaEstado(Estado * arreglo,int size,Estado r){
	for (int i = 0; i < size; ++i){
		if(arreglo[i].persona1 == r.persona1 && arreglo[i].persona2 == r.persona1 && arreglo[i].persona3 == r.persona3 && arreglo[i].persona4 == r.persona4 && arreglo[i].linterna == r.linterna && arreglo[i].tiempoTotal == r.tiempoTotal){
			return 1;
		}
	}return 0;
}
Estado *eliminarEstado(Estado *abiertos, int *size){
	Estado * listaNueva = (Estado*)malloc(sizeof(Estado)*(*size-1));
	for (int i = 1; i < *size; ++i){
		listaNueva[i-1] = abiertos[i];
	}
	*size = *size - 1;
	free(abiertos);
	return listaNueva;
}
#include <stdio.h>
#include <stdlib.h>

/*Este codigo esta lo suficientemente implementado para leer el archivo y tener una matriz con los caminos, simplemente faltaria 
escribir el codigo para cada funcion, hacer el ciclo para el algoritmo y luego de los estados cerrados buscar las ciudades que faltan*/


// estructura que tiene como funcion almacenar todos los datos necesarios del archivo para su posterior uso
typedef struct Matriz{
	int **matriz; // arreglo de 2D en donde estaran todos los caminos que se leyeron del archivo
	int totalCiudades; // el total de las ciudades que hay
	int totalCaminos; // el total de caminos 
}Matriz;

//estructura la cual estara encargada de cada estado que generemos
typedef struct Estados{
	int id; // identificador del estado
	int ciudadActual; // valor de la ciudad en la que nos encontramos
	int idAnterior; // id del estado que origino el actual
}Estado;

//EL desarrollo de este algoritmo es algo complicado, porque a mi parecer no existe algo como transiciones, o al menos en mi caso, mis transiciones son
//encontrar un camino para la ciudad en la que me encuentro, no se si eso contara como transicion, por lo que lo dejo comentado de todas formas


// funcion terminada, que lee el archivo y retorna una struct en la que se encontrara una matriz de 2 dimensiones, el total de ciudades y de caminos
Matriz lecturaArchivo(char *nombreArchivo);

Estado crearEstado(int ciudad,int idAnterior); //  funcion en la que crearemos un estado una vez encontrado un camino existente 

// Con esta funcion se pretende agregar a la lista de estados abiertos un estado adicional si es que se encuentra que es posible realizar una transicion
//El primer parametro seria el arreglo de abiertos, el segundo el tamano del arreglo y el tercero el estado a agregar
Estado *agregarEstado(Estado *arreglo,int *size, Estado estadoAgregado);

/* Con esta funcion, se pretende eliminar el estado abierto actual en el que nos encontramos de la lista de estados abiertos, para asi llevarla a
la lista de estados cerrados (una vez creado las transiciones correspondientes de haberse podido)*/
Estado *eliminarEstado(Estado *arreglo,int *size);
// Con esta funcion, se espera ver si el estado creado, ya se encuentra en la lista de abiertos y en la lista de cerrados, de no encontrarse en ambos, se agrega a abiertos
int estaEstado(Estado * arreglo,int size,Estado r);

//Utilizamos la busqueda binaria para comparar las ciudades Visitadas con las ciudades Totales
int binarySearch(int* array, int size,int numero);
// funcion necesaria para qsort()
int cmpfunc (const void * a, const void * b);

int aux;
int main(){
	Matriz archivo; Estado estadoActual,estadoSiguiente;
	int ciudadComienzo; 
	aux = 0;
	int canAbiertos = 0;
	int canCerrados = 0;
	int *ciudadesVisitadas; int *ciudadesTotales; int ciudadesFaltantes; 
	int j = 1;
	char nombreArchivo[20];
	printf("Ingrese el nombre del archivo a leer:\n");
	scanf("%s",nombreArchivo);
	archivo = lecturaArchivo(nombreArchivo);
	printf("Ingrese un numero entero positivo entre 1 y %i que represente el punto de partida\n",archivo.totalCiudades );
	scanf("%i",&ciudadComienzo);
	Estado * abiertos = (Estado*)malloc(sizeof(Estado)*canAbiertos); 
	Estado * cerrados = (Estado*)malloc(sizeof(Estado)*canCerrados);	
	Estado inicial = crearEstado(ciudadComienzo,aux); // creamos el estado inicial con la ciudad indicada por el usuario
	abiertos = agregarEstado(abiertos,&canAbiertos,inicial); // agregamos el estado inicial al arreglo de estados abiertos 
	while (canAbiertos>0){
		estadoActual = abiertos[0]; // tomamos el primer estado de la lista de abiertos
		abiertos = eliminarEstado(abiertos,&canAbiertos); // lo sacamos de la lista de abiertos
		cerrados = agregarEstado(cerrados,&canCerrados,estadoActual); // lo agregamos a la lista de cerrados
		for (int i = 0; i < archivo.totalCaminos; ++i){ // recorremos toda la matriz correspondiente al archivo leido
			if (archivo.matriz[i][0] == estadoActual.ciudadActual){ // si la ciudad actual es la misma que la ciudad de la primera columna
				estadoSiguiente = crearEstado(archivo.matriz[i][1],estadoActual.id); // creamos el proximo estado con el camino a la proxima ciudad
				if((estaEstado(abiertos,canAbiertos,estadoSiguiente) == 0) && (estaEstado(cerrados,canCerrados,estadoSiguiente) == 0)){
					abiertos = agregarEstado(abiertos,&canAbiertos,estadoSiguiente); // si es un estado unico que no se encuentra en abiertos ni cerrados, se agrega a abiertos
				}else{
					aux = aux - 1; // si ya se encontraba en abiertos y cerrados, entonces retrocedemos el contador de estados
				}
			}
		}
	}
	ciudadesVisitadas = malloc(sizeof(int)*canCerrados);
	ciudadesTotales = malloc(sizeof(int)*archivo.totalCiudades);
	printf("Ciudades Totales: "); // creamos un arreglo con las ciudades totales
	for (int i = 0; i < archivo.totalCiudades; ++i){
		ciudadesTotales[i] = j++;
		printf("%i ",ciudadesTotales[i] );
	}
	printf("\n");

	printf("Las ciudades visitadas fueron: "); // creamos un arreglo con las ciudades visitadas, que se encuentran en la lista de estados cerrados
	for (int i = 0; i < canCerrados; ++i){
		ciudadesVisitadas[i] = cerrados[i].ciudadActual;
		printf("%i ",ciudadesVisitadas[i]);
	}
	printf("\n");
	qsort(ciudadesVisitadas,canCerrados,sizeof(int),cmpfunc);
	printf("Las ciudades que no se pueden visitar desde %i son: ", ciudadComienzo);
	for (int i = 0; i < archivo.totalCiudades; ++i){ // si no encontramos la ciudad del total de ciudades en las ciudades visitadas, lo ponemos en ciudadesFaltantes y printeamos
		if(binarySearch(ciudadesVisitadas,canCerrados,ciudadesTotales[i]) == 0){
			ciudadesFaltantes = ciudadesTotales[i];
			printf("%i ",ciudadesFaltantes );
		}
	}
	return 0;
}
Matriz lecturaArchivo(char *nombreArchivo){
	Matriz retorno;
	FILE *archivo = fopen(nombreArchivo,"r");
	if (archivo == NULL){ // si el archivo no se encuentra en la raiz o no existe
		printf("Lo sentimos, pero el archivo ingresado no existe en la carpeta raiz\n");
		exit(1);
	}
	fscanf(archivo,"%i  %i",&retorno.totalCiudades,&retorno.totalCaminos); // rescatamos la primera fila del archivo
	retorno.matriz = malloc(sizeof(int*)*retorno.totalCaminos); // creamos una matriz con totalCaminos de filas
	for (int i = 0; i < retorno.totalCaminos; ++i){
		retorno.matriz[i] = malloc(sizeof(int)*2); // por cada fila creamos 2 columnas
		fscanf(archivo,"%i  %i",&retorno.matriz[i][0],&retorno.matriz[i][1]); // guardamos cada columna del archivo en la columna correspondiente de la matriz
	}
	fclose(archivo); // cerramos el archivo 
	return retorno;
}
Estado crearEstado(int ciudad,int idAnterior){
	Estado nuevo;
	nuevo.ciudadActual = ciudad;
	nuevo.id = aux;
	nuevo.idAnterior = idAnterior;
	aux = aux + 1;
	return nuevo;
}
Estado *agregarEstado(Estado *arreglo,int *size, Estado estadoAgregado){
	Estado * listaNueva = (Estado*)malloc(sizeof(Estado)*(*size+1));
	for (int i = 0; i < *size; ++i){
		listaNueva[i] = arreglo[i];
	}
	listaNueva[*size] = estadoAgregado;
	*size = *size + 1;
	free(arreglo);
	return listaNueva;
}
int estaEstado(Estado * arreglo,int size,Estado r){
	for (int i = 0; i < size; ++i){
		if(arreglo[i].ciudadActual == r.ciudadActual){
			return 1;
		}
	}return 0;
}
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

Estado *eliminarEstado(Estado *arreglo, int *size){
	Estado * listaNueva = (Estado*)malloc(sizeof(Estado)*(*size-1));
	for (int i = 1; i < *size; ++i){
		listaNueva[i-1] = arreglo[i];
	}
	*size = *size - 1;
	free(arreglo);
	return listaNueva;
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

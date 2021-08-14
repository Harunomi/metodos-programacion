#include "Funciones.h"



//A continuacion se definen todas las funciones del codigo.

//Primero se definen las funciones que verifican las restricciones.
//Estas funciones suponen que la solucion es un arreglo de char con un largo de 25 (5 x 5) (5 casas y 5 caracteristicas).
//La solucion tambien supone que en cada posicion del arreglo char se almacena un numero entre 1 y 5 contabilizando el 1 y 5.
//Cada numero define el valor de una caracteristica, por ejemplo el valor 1 para los colores corresponde al blanco, pero para las nacionalidades
//el 1 corresponde a Noruego, el detalle de esta conversion es realizado en el archivo "Funciones.h".

//Ademas, de las posiciones 0 a 4 son los valores para colores, de tal manera que el valor de la posicion 0 es para la casa 1, la de la posicion 1
//para la casa 2, hasta llegar a la quinta casa.
//Los mismo para el resto de las caracteristicas, pero para las nacionalidades se usan las posiciones 5 hasta la 9.
//Para las bebidas se usan las posiciones 10 hasta la 14.
//Para los cigarrillos se usan las posiciones 15 hasta la 19.
//Para las mascotas se usan las posiciones 20 hasta la 24.


//------------------------Aqui empiezan las funciones para filtrar por las restricciones--------------------------------


/*

Objetivo funcion: Verificar si la solucion cumple la condicion 1.

Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple.

*/

int britanicoRojo(char* solucion)
{
	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//Desde la posicion 5 hasta la 9 son los valores de nacionalidades y 3 es el valor para britanico
	 	//de 0 a 4 son los valores para colores de casa y 4 es el valor para rojo
	 	if (solucion[i+5] == '3' && solucion[i] == '4')
	 	{
	 		return 1;
	 	}
	 }
	

	return 0;
}

/*

Objetivo funcion: Verificar si la solucion cumple la condicion 2.

Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple.

*/

int suecoPerro(char* solucion)
{
	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//Desde la posicion 5 hasta la 9 son los valores de nacionalidades y 5 es el valor para sueco
	 	//de 20 a 24 son los valores para mascotas y 4 es el valor para perro
	 	if (solucion[i+5] == '5' && solucion[i+20] == '4')
	 	{
	 		return 1;
	 	}
	 }
	

	return 0;
}


/*

Objetivo funcion: Verificar si la solucion cumple la condicion 3.

Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple.

*/

int danesTe(char* solucion)
{
	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//Desde la posicion 5 hasta la 9 son los valores de nacionalidades y 2 es el valor para Danes
	 	//de 10 a 14 son los valores para bebidas y 4 es el valor para te
	 	if (solucion[i+5] == '2' && solucion[i+10] == '4')
	 	{
	 		return 1;
	 	}
	 }
	

	return 0;
}


/*

Objetivo funcion: Verificar si la solucion cumple la condicion 4.


Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas -1 (4). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple

*/

int verdeIzquierdaBlanca(char* solucion)
{

	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS-1; ++i)
	 {
	 	//Desde la posicion 0 hasta la 4 son los valores de colores y 2 = verde, 1 = blanco
	 	if (solucion[i] == '2' && solucion[i+1] == '1')
	 	{
	 		return 1;
	 	}
	 }
	

	return 0;
}


/*

Objetivo funcion: Verificar si la solucion cumple la condicion 5.


Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple

*/

int verdeCafe(char* solucion)
{
	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//Desde la posicion 0 hasta la 4 son los valores de colores y 2 es el valor para verde
	 	//de 10 a 14 son los valores para bebidas y 3 es el valor para cafe
	 	if (solucion[i] == '2' && solucion[i+10] == '3')
	 	{
	 		return 1;
	 	}
	 }
	

	return 0;
}



/*

Objetivo funcion: Verificar si la solucion cumple la condicion 6.


Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple.

*/

int pallmallPajaro(char* solucion)
{
	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 1 es el valor para pall mall
	 	//de 20 a 24 son los valores para mascotas y 3 es el valor para pajaro
	 	if (solucion[i+15] == '1' && solucion[i+20] == '3')
	 	{
	 		return 1;
	 	}
	 }
	

	return 0;
}


/*

Objetivo funcion: Verificar si la solucion cumple la condicion 7.


Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple

*/

int amarillaDunhill(char* solucion)
{
	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//Desde la posicion 0 hasta la 4 son los valores de colores y 5 es el valor para amarilla
	 	//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 4 es el valor para dunhill
	 	if (solucion[i] == '5' && solucion[i+15] == '4')
	 	{
	 		return 1;
	 	}
	 }
	

	return 0;
}


//RESTRICCION 8 Y 9 SE VERIFICAN EN LA CREACION DE SOLUCIONES PARA DISMINUIR ALGO EL PROCESAMIENTO


/*

Objetivo funcion: Verificar si la solucion cumple la condicion 10


Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple.

*/

int brendsJuntoGato(char* solucion)
{

	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//son 3 casos:

	 	//caso 1:
	 	//si i == 0, solo hay un vecino
	 	if (i == 0)
	 	{
	 		//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 3 es el valor para Brends
	 		//de 20 a 24 son los valores para mascotas y 1 es el valor para gato
	 		if (solucion[i+15] == '3' && solucion[i+20+1] == '1')
		 	{
		 		return 1;
		 	}
	 	}

	 	//caso 2:
	 	//si i == 4, solo hay un vecino
	 	else if (i == CANTIDAD_CASAS-1)
	 	{
	 		//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 3 es el valor para Brends
	 		//de 20 a 24 son los valores para mascotas y 1 es el valor para gato
	 		if (solucion[i+15] == '3' && solucion[i+20-1] == '1')
		 	{
		 		return 1;
		 	}
	 	}

	 	//caso 3:
	 	//si i != 4 && i != 0, hay dos vecinos
	 	else
	 	{
	 		//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 3 es el valor para Brends
	 		//de 20 a 24 son los valores para mascotas y 1 es el valor para gato
	 		if ((solucion[i+15] == '3' && solucion[i+20-1] == '1') || (solucion[i+15] == '3' && solucion[i+20+1] == '1'))
		 	{
		 		return 1;
		 	}
	 	}
	 	
	 }
	

	return 0;
}



/*

Objetivo funcion: Verificar si la solucion cumple la condicion 11.


Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple.

*/

int caballoJuntoDunhill(char* solucion)
{

	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//son 3 casos:

	 	//caso 1:
	 	//si i == 0, solo hay un vecino
	 	if (i == 0)
	 	{
	 		//de 20 a 24 son los valores para mascotas y 5 es el valor para caballo
	 		//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 4 es el valor para Dunhill
	 		if (solucion[i+20] == '5' && solucion[i+15+1] == '4')
		 	{
		 		return 1;
		 	}
	 	}

	 	//caso 2:
	 	//si i == 4, solo hay un vecino
	 	else if (i == CANTIDAD_CASAS-1)
	 	{
	 		//de 20 a 24 son los valores para mascotas y 5 es el valor para caballo
	 		//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 4 es el valor para Dunhill
	 		if (solucion[i+20] == '5' && solucion[i+15-1] == '4')
		 	{
		 		return 1;
		 	}
	 	}

	 	//caso 3:
	 	//si i != 4 && i != 0, hay dos vecinos
	 	else
	 	{
	 		//de 20 a 24 son los valores para mascotas y 5 es el valor para caballo
	 		//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 4 es el valor para Dunhill
	 		if ((solucion[i+20] == '5' && solucion[i+15-1] == '4') || (solucion[i+20] == '5' && solucion[i+15+1] == '4'))
		 	{
		 		return 1;
		 	}
	 	}
	 	
	 }
	

	return 0;
}




/*

Objetivo funcion: Verificar si la solucion cumple la condicion 12.


Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple.

*/

int bluemastersCerveza(char* solucion)
{

	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 5 es el valor para Bluemasters
	 	//de 10 a 14 son los valores para bebidas y 1 es el valor para cerveza
	 	if (solucion[i+15] == '5' && solucion[i+10] == '1')
	 	{
	 		return 1;
	 	}
	 }
	

	return 0;
}


/*

Objetivo funcion: Verificar si la solucion cumple la condicion 13.


Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple.

*/

int alemanPrince(char* solucion)
{

	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//Desde la posicion 5 hasta la 9 son los valores de nacionalidades y 4 es el valor para aleman
	 	//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 2 es el valor para Prince
	 	if (solucion[i+5] == '4' && solucion[i+15] == '2')
	 	{
	 		return 1;
	 	}
	 }
	

	return 0;
}




//RESTRICCION 14 SE VERIFICA EN LA CREACION DE SOLUCIONES PARA DISMINUIR ALGO EL PROCESAMIENTO




/*

Objetivo funcion: Verificar si la solucion cumple la condicion 15.


Entradas: Un arreglo de char de largo 25.

Detalles funcionamiento: Se realiza un for de 0 hasta la cantidad de casas (5). de tal manera que con eso es posible revisar la solucion.

Salidas: 1 para indicar que si cumple la restriccion y 0 para indicar que no cumple.

*/

int brendsJuntoAgua(char* solucion)
{

	//ciclo for para recorrer la solucion
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	 {
	 	//son 3 casos:

	 	//caso 1:
	 	//si i == 0, solo hay un vecino
	 	if (i == 0)
	 	{
	 		//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 3 es el valor para Brends
	 		//de 10 a 14 son los valores para bebidas y 5 es el valor para agua
	 		if (solucion[i+15] == '3' && solucion[i+10+1] == '5')
		 	{
		 		return 1;
		 	}
	 	}

	 	//caso 2:
	 	//si i == 4, solo hay un vecino
	 	else if (i == CANTIDAD_CASAS-1)
	 	{
	 		//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 3 es el valor para Brends
	 		//de 10 a 14 son los valores para bebidas y 5 es el valor para agua
	 		if (solucion[i+15] == '3' && solucion[i+10-1] == '5')
		 	{
		 		return 1;
		 	}
	 	}

	 	//caso 3:
	 	//si i != 4 && i != 0, hay dos vecinos
	 	else
	 	{
	 		//Desde la posicion 15 hasta la 19 son los valores de cigarrillos y 3 es el valor para Brends
	 		//de 10 a 14 son los valores para bebidas y 5 es el valor para agua
	 		if ((solucion[i+15] == '3' && solucion[i+10-1] == '5') || (solucion[i+15] == '3' && solucion[i+10+1] == '5'))
		 	{
		 		return 1;
		 	}
	 	}
	 	
	 }
	

	return 0;
}



//------------------------Aqui terminan las funciones para filtrar por las restricciones--------------------------------


//A continuacion se definen las funciones que permiten el manejo de las soluciones.


//------------------------Aqui empiezan las funciones para trabajar y printear soluciones--------------------------------


/*

Objetivo funcion: En base a un arreglo de char de largo 5, imprimir las caracteristicas de la casa.

Entradas: Un arreglo de char de largo 5 que representa las caracteristicas de la casa, y el numero de casa a imprimir.

Detalles funcionamiento: Se imprime el string correspondiente segun el numero de la entrada.

Salidas: Ninguna.

*/

void imprimirCasa(char* casaImprimir, int numeroCasa)
{
	printf("\n\n_____Inicio datos casa numero %d_____\n\n", numeroCasa);

	switch(casaImprimir[0])//Color casa
    {
        case '1'://Blanca
            printf("Color casa: Blanca\n");
            break;

        case '2'://Verde
            printf("Color casa: Verde\n");
            break;

        case '3'://Azul
            printf("Color casa: Azul\n");
            break;

        case '4'://Roja
            printf("Color casa: Roja\n");
            break;

        case '5'://Amarilla
            printf("Color casa: Amarilla\n");
            break;

        //Si tiene otro numero
        default:
            printf("Error! numero de color incorrecto\n");
    }


    switch(casaImprimir[1])//nacionalidad
    {
        case '1'://Noruego
            printf("Nacionalidad dueno casa: Noruego\n");
            break;

        case '2'://Danes
            printf("Nacionalidad dueno casa: Danes\n");
            break;

        case '3'://Britanico
            printf("Nacionalidad dueno casa: Britanico\n");
            break;

        case '4'://Aleman
            printf("Nacionalidad dueno casa: Aleman\n");
            break;

        case '5'://Sueco
            printf("Nacionalidad dueno casa: Sueco\n");
            break;

        //Si tiene otro numero
        default:
            printf("Error! numero de nacionalidad incorrecto\n");
    }


    switch(casaImprimir[2])//bebida
    {
        case '1'://Cerveza
            printf("Bebida dueno casa: Cerveza\n");
            break;

        case '2'://Leche
            printf("Bebida dueno casa: Leche\n");
            break;

        case '3'://Cafe
            printf("Bebida dueno casa: Cafe\n");
            break;

        case '4'://Te
            printf("Bebida dueno casa: Te\n");
            break;

        case '5'://Agua
            printf("Bebida dueno casa: Agua\n");
            break;

        //Si tiene otro numero
        default:
            printf("Error! numero de bebida incorrecto\n");
    }


    switch(casaImprimir[3])//cigarrillo
    {
        case '1'://Pall Mall
            printf("Cigarrillo dueno casa: Pall Mall\n");
            break;

        case '2'://Prince
            printf("Cigarrillo dueno casa: Prince\n");
            break;

        case '3'://Brends
            printf("Cigarrillo dueno casa: Brends\n");
            break;

        case '4'://Dunhill
            printf("Cigarrillo dueno casa: Dunhill\n");
            break;

        case '5'://Bluemasters
            printf("Cigarrillo dueno casa: Bluemasters\n");
            break;

        //Si tiene otro numero
        default:
            printf("Error! numero de cigarrillo incorrecto\n");
    }

    switch(casaImprimir[4])//mascota
    {
        case '1'://Gato
            printf("Mascota dueno casa: Gato\n");
            break;

        case '2'://Pez
            printf("Mascota dueno casa: Pez\n");
            break;

        case '3'://Pajaro
            printf("Mascota dueno casa: Pajaro\n");
            break;

        case '4'://Perro
            printf("Mascota dueno casa: Perro\n");
            break;

        case '5'://Caballo
            printf("Mascota dueno casa: Caballo\n");
            break;

        //Si tiene otro numero
        default:
            printf("Error! numero de mascota incorrecto\n");
    }

    printf("\n_____Fin datos casa numero %d_____\n\n", numeroCasa);
}

/*

Objetivo funcion: Dada una solucion, imprimir cada una de las casas de la solucion.

Entradas: Un arreglo de char de largo 25 y un entero que representa el numero de la solucion.

Detalles funcionamiento: Se realica un ciclo for que recorre la solucion
						e imprime con ayuda de la funcion imprimirCasa.

Salidas: Ninguna.

*/

void imprimirSolucion(char* solucionEntrada, int numSolucion)
{
	char casaAux[CANTIDAD_CASAS];
	printf("\n\n--------------Inicio solucion numero %d--------------\n\n", numSolucion);
	for (int i = 0; i < CANTIDAD_CASAS; ++i)
	{
		casaAux[0] = solucionEntrada[i];
		casaAux[1] = solucionEntrada[i+5];
		casaAux[2] = solucionEntrada[i+10];
		casaAux[3] = solucionEntrada[i+15];
		casaAux[4] = solucionEntrada[i+20];
		imprimirCasa(casaAux, i+1);
	}
	printf("\n\n--------------Fin solucion numero %d--------------\n\n", numSolucion);
}

/*

Objetivo funcion: Agregar a un arreglo de soluciones una nueva solucion.

Entradas: Doble puntero char con las soluciones, puntero a int con la cantidad de soluciones en el arreglo y un puntero a char
		que representa la nueva solucion a agregar.

Detalles funcionamiento: Se alocatea memoria para un arreglo de soluciones nuevo pero aumentando en un el largo de este.
						Posteriormente se copian las soluciones existentes y se agrega la solucion nuevas.
						Finalmente, se aumenta en un la cantidad de soluciones del arreglo y se libera memoria.

Salidas: Doble puntero char que representa la matriz con las soluciones.

*/

char** agregarSolucion(char** soluciones, int* largo, char* nuevaSolucion)
{
	//Se crea el nuevo conjunto de soluciones con malloc

	//primero las filas
	char** solucionesAux = (char**)malloc(sizeof(char*)*(*largo+1));

	//segundo las columnas
	for (int i = 0; i < *largo + 1; ++i)
	{
		solucionesAux[i] = (char*)malloc(sizeof(char)*(CANTIDAD_CASAS*CANTIDAD_CARACTERISTICAS));
	}


	//Se copian los soluciones
	for (int i = 0; i < *largo; ++i)
	{
		for (int j = 0; j < CANTIDAD_CASAS*CANTIDAD_CARACTERISTICAS; ++j)
		{
			solucionesAux[i][j] = soluciones[i][j];
		}
	}


	//Se agrega la nueva solucion
	for (int i = 0; i < CANTIDAD_CASAS*CANTIDAD_CARACTERISTICAS; ++i)
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



// Existen muchas maneras de generar las posibles soluciones para este acertijo.
// A continuacion se define la forma que se usa en este programa:

/*

Una forma es generar las soluciones en dos pasos, primero, se generan las permutaciones de las 
posiciones de las caracteristicas, y luego, se generan las variaciones de las permutaciones generadas.
Estos pueden ser generados anidando 5 for para las permutaciones, y anidando 5 for para las
variaciones. De esta manera, es posible obtener mediante fuerza bruta las soluciones (iterando por todo 
el conjunto solucion).

La desventaja de esta forma es que requiere demasiado procesamiento, ya que el programa itera y realiza el calculo
para generar soluciones sin sentido que no cumplen las restricciones.


FALTA EXPLICAR CUAL ES LA MANERA QUE SE USO


*/






/*

Objetivo funcion: generar todas las permutaciones del arreglo [1, 2, 3, 4, 5].


Entradas: Ninguna.

Detalles funcionamiento: Se realizan 5 ciclos for anidados que permiten generar todas las permutaciones.

Salidas: Matriz con todas las permutaciones, donde cada fila corresponde a una permutacion.

*/

void crearPermutacionesEstatico(int** matrizPermutaciones)
{

	//Se crea un indice que permitira guardar las permutaciones
	int indicePermutacion = 0;
	//Se crean los iteradores
	int q,w,e,r,t;
	//Ahora se generan cada una de las permutaciones de manera estatica (osea 5 for anidados)
	for (q = 0; q < CANTIDAD_CARACTERISTICAS; ++q)//1
	{
		for (w = 0; w < CANTIDAD_CARACTERISTICAS; ++w)//2
		{
			for (e = 0; e < CANTIDAD_CARACTERISTICAS; ++e)//3
			{
				for (r = 0; r < CANTIDAD_CARACTERISTICAS; ++r)//4
				{
					for (t = 0; t < CANTIDAD_CARACTERISTICAS; ++t)//5
					{
						if (q != w && q != e && q != r && q != t && w != e
						 && w != r && w != t && e != r && e != t && r != t)
						{
							matrizPermutaciones[indicePermutacion][0] = q+1;
							matrizPermutaciones[indicePermutacion][1] = w+1;
							matrizPermutaciones[indicePermutacion][2] = e+1;
							matrizPermutaciones[indicePermutacion][3] = r+1;
							matrizPermutaciones[indicePermutacion][4] = t+1;
							indicePermutacion = indicePermutacion + 1;
						}
					}
				}
			}
		}
	}

	return;
}




/*

Objetivo funcion: Dada una matriz de permutaciones generar las variaciones para el problema de Einstein y escribirlas en un archivo.


Entradas: Matriz de enteros y puntero a entero.

Detalles funcionamiento: Se recorre la matriz de permutaciones y se generan todas las combinaciones, de tal manera que, estas se van
						escribiendo en un archivo. Notar que se generan vectores de colores, nacionalidades, bebidas, cigarrillos y
						mascotas. Esos arreglos no son necesarios, pero son utiles para explicar como se representa la solucion.

Salidas: Ninguna.

*/

void crearSolucionesEstatico(int** matrizPermutaciones)
{
	int cantidadPermutaciones = 120;

	int colores[CANTIDAD_CASAS], nacionalidades[CANTIDAD_CASAS], bebidas[CANTIDAD_CASAS], cigarrillos[CANTIDAD_CASAS], mascotas[CANTIDAD_CASAS];

	//Se crea un puntero a un archivo 
    FILE *fptr;
	//Se crea un archivo de escritura para guardar las soluciones
    fptr = fopen("soluciones.txt", "w");

    //Si el archivo de escritura no existe, por lo tanto se termina el programa
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }


	//A continuacion se procede a crear todas las posibles variaciones de soluciones con las  permutaciones ya creadas

	//Cabe destacar que la complejidad de los ciclos for anidados a continuacion es de n^5
	//como n es claro, y corresponde a la cantidad de permutaciones, osea n = 120,
	//sabemos que la cantidad de iteraciones es 2.48832 x 10^10
	//como puede ser poco conveniente reservar tanta memoria ram, se decide escribir en un archivo las soluciones

	//Se crean iteradores
	int q,w,e,r,t;
	for (q = 0; q < cantidadPermutaciones; ++q)//colores
	{
		for (w = 0; w < cantidadPermutaciones; ++w)//nacionalidades
		{
			for (e = 0; e < cantidadPermutaciones; ++e)//bebidas
			{
				for (r = 0; r < cantidadPermutaciones; ++r)//cigarrillos
				{
					for (t = 0; t < cantidadPermutaciones; ++t)//mascotas
					{
						//Se generan las soluciones procurando que se cumplan las restricciones 8, 9 y 14
						//Se realiza el primer filtro, para solo ingresar soluciones donde en la casa del medio (casa con indice 2) beban leche
						//Que la primera casa (indice 0) vive el noruego
						//Y que en la casa de al lado del noruego (casa con indice 1) sea azul 
						if (matrizPermutaciones[e][2] == 2 && matrizPermutaciones[w][0] == 1 && matrizPermutaciones[q][1] == 3)
						{

							//Se crea el vector de colores
							colores[0] = matrizPermutaciones[q][0];
							colores[1] = matrizPermutaciones[q][1];
							colores[2] = matrizPermutaciones[q][2];
							colores[3] = matrizPermutaciones[q][3];
							colores[4] = matrizPermutaciones[q][4];

							//Se crea el vector de nacionalidades
							nacionalidades[0] = matrizPermutaciones[w][0];
							nacionalidades[1] = matrizPermutaciones[w][1];
							nacionalidades[2] = matrizPermutaciones[w][2];
							nacionalidades[3] = matrizPermutaciones[w][3];
							nacionalidades[4] = matrizPermutaciones[w][4];

							//Se crea el vector de bebidas
							bebidas[0] = matrizPermutaciones[e][0];
							bebidas[1] = matrizPermutaciones[e][1];
							bebidas[2] = matrizPermutaciones[e][2];
							bebidas[3] = matrizPermutaciones[e][3];
							bebidas[4] = matrizPermutaciones[e][4];

							//Se crea el vector de cigarrillos
							cigarrillos[0] = matrizPermutaciones[r][0];
							cigarrillos[1] = matrizPermutaciones[r][1];
							cigarrillos[2] = matrizPermutaciones[r][2];
							cigarrillos[3] = matrizPermutaciones[r][3];
							cigarrillos[4] = matrizPermutaciones[r][4];

							//Se crea el vector de mascotas
							mascotas[0] = matrizPermutaciones[t][0];
							mascotas[1] = matrizPermutaciones[t][1];
							mascotas[2] = matrizPermutaciones[t][2];
							mascotas[3] = matrizPermutaciones[t][3];
							mascotas[4] = matrizPermutaciones[t][4];

							
							// printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", colores[0],colores[1],colores[2],colores[3],colores[4], 
							// 	nacionalidades[0],nacionalidades[1],nacionalidades[2],nacionalidades[3],nacionalidades[4], 
							// 	bebidas[0],bebidas[1],bebidas[2],bebidas[3],bebidas[4], 
							// 	cigarrillos[0],cigarrillos[1],cigarrillos[2],cigarrillos[3],cigarrillos[4],
							// 	mascotas[0],mascotas[1],mascotas[2],mascotas[3],mascotas[4]);


							//se escribe la solucion en el archivo
							fprintf(fptr,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", colores[0],colores[1],colores[2],colores[3],colores[4], 
								nacionalidades[0],nacionalidades[1],nacionalidades[2],nacionalidades[3],nacionalidades[4], 
								bebidas[0],bebidas[1],bebidas[2],bebidas[3],bebidas[4], 
								cigarrillos[0],cigarrillos[1],cigarrillos[2],cigarrillos[3],cigarrillos[4],
								mascotas[0],mascotas[1],mascotas[2],mascotas[3],mascotas[4]);

							//No era necesario separar en vectores, pero lo hice para que quedara más claro.
						}
					}
				}
			}
		}
	}
	fclose(fptr);
	return;
}




/*

Objetivo funcion: generar todas soluciones del problema suponiendo un vector de caracteristicas de la siguente forma: [1, 2, 3, 4, 5].


Entradas: Ninguna.

Detalles funcionamiento: 

Salidas: Conjunto solucion medianamente reducido.

*/

void crearConjuntoSolucionEstatico()
{
	//Primero se reserva memoria para generar las permutaciones
	//Se sabe que la cantidad de permutaciones es n!, como en este caso n = 5
	//cantidad de permutaciones = 120
	int** matrizPermutaciones = (int**)malloc(sizeof(int*)*120);
	for (int i = 0; i < 120; ++i)
	{
		matrizPermutaciones[i] = (int*)malloc(sizeof(int)*CANTIDAD_CASAS);
	}

	//Se calculan las permutaciones posibles para el vector [1, 2, 3, 4, 5]
	crearPermutacionesEstatico(matrizPermutaciones);


	//Se crean variables para calcular el tiempo en generar las soluciones
	time_t ini1, fin1;

	ini1 = time(NULL);
	crearSolucionesEstatico(matrizPermutaciones);//Se crean las soluciones y se escriben en un archivo
	fin1 = time(NULL);

	//printf("\nTiempo crear variaciones: %f\n",difftime(fin1,ini1));

	//printf("\n\n-------FIN!!!\n");

	//Se libera memoria
	for (int i = 0; i < 120; ++i)
	{
		free(matrizPermutaciones[i]);
	}
	free(matrizPermutaciones);

	return;
}









/*

Objetivo funcion: Abrir el archivo "soluciones.txt" y filtrar las soluciones manteniendo solo las que cumplan todas las restricciones.

Entradas: Puntero a entero donde se almacenara la cantidad de soluciones correctas.

Detalles funcionamiento: Se lee linea por linea el archivo con ayuda de un ciclo while, de tal manera que a cada linea se la
						verifican todas las restricciones.

Salidas: Un puntero a un arreglo de soluciones.

*/

char** filtrarConjuntoSolucion(int* cantidadSoluciones)
{

	FILE *fp;
	char str[30];

	char* solucionAux;
	char** soluciones = (char**)malloc(sizeof(char*)*0);
	*cantidadSoluciones = 0;

	//abrir archivo para leer
	fp = fopen("soluciones.txt" , "r");
	if(fp == NULL) {
		printf("Error!");
        exit(1);
	}
	while( fgets (str, 60, fp)!=NULL ) {
		//se trabaja cada una de las soluciones leidas

		//verificar condicion 15
		if (brendsJuntoAgua(str)==1)
		{
			//verificar condicion 11
			if (caballoJuntoDunhill(str)==1)
			{
				//verificar condicion 10
				if (brendsJuntoGato(str)==1)
				{
					//verificar condicion 4
					if (verdeIzquierdaBlanca(str)==1)
					{
						//verificar condicion 13
						if (alemanPrince(str)==1)
						{
							//verificar condicion 12
							if (bluemastersCerveza(str)==1)
							{
								//verificar condicion 7
								if (amarillaDunhill(str)==1)
								{
									//verificar condicion 6
									if (pallmallPajaro(str)==1)
									{
										//verificar condicion 5
										if (verdeCafe(str)==1)
										{
											//verificar condicion 3
											if (danesTe(str)==1)
											{
												//verificar condicion 2
												if (suecoPerro(str)==1)
												{
													//verificar condicion 1
													if (britanicoRojo(str)==1)
													{
														//Se agrega la solucion a la lista de soluciones
														soluciones = agregarSolucion(soluciones, cantidadSoluciones, str);
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
		}
	}
	fclose(fp);

	return soluciones;
}


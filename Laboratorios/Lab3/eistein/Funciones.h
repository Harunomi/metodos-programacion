#ifndef Funciones_h_
#define Funciones_h_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Se definen variables globales
#define CANTIDAD_CASAS 5
#define CANTIDAD_CARACTERISTICAS 2

//cabeceras de las funciones que permiten generar el conjunto solucion
void crearPermutacionesEstatico(int** matrizPermutaciones);
void crearSolucionesEstatico(int** matrizPermutaciones);
void crearConjuntoSolucionEstatico();
char** filtrarConjuntoSolucion(int* cantidadSoluciones);

//cabeceras de las funciones que permiten trabajar las soluciones
void imprimirCasa(char* casaImprimir, int numeroCasa);
void imprimirSolucion(char* solucionEntrada, int numSolucion);
char** agregarSolucion(char** soluciones, int* largo, char* nuevaSolucion);


//cabeceras de las funciones que verifican restricciones
int britanicoRojo(char* solucion);
int suecoPerro(char* solucion);
int danesTe(char* solucion);
int verdeIzquierdaBlanca(char* solucion);
int verdeCafe(char* solucion);
int pallmallPajaro(char* solucion);
int amarillaDunhill(char* solucion);
int brendsJuntoGato(char* solucion);
int caballoJuntoDunhill(char* solucion);
int bluemastersCerveza(char* solucion);
int alemanPrince(char* solucion);
int brendsJuntoAgua(char* solucion);



#endif // Funciones_h_


/*

Es necesario destacar que para la data se decide trabajar con numeros las caracterisiticas.
Por lo tanto, a continuacion se definen las tablas de conversión de los datos.

Color de las casa:
1 = "Blanca"
2 = "Verde"
3 = "Azul"
4 = "Roja"
5 = "Amarilla"

Nacionalidad dueno casa:
1 = "Noruego"
2 = "Danes"
3 = "Britanico"
4 = "Aleman"
5 = "Sueco"

Bebida que se ingiere en la casa:
1 = "Cerveza"
2 = "Leche"
3 = "Cafe"
4 = "Te"
5 = "Agua"

Marca cigarrillo que se fuma en la casa:
1 = "Pall Mall"
2 = "Prince"
3 = "Brends"
4 = "Dunhill"
5 = "Bluemasters"

Raza animal mascota de la casa:
1 = "Gato"
2 = "Pez"
3 = "Pajaro"
4 = "Perro"
5 = "Caballo"


*/
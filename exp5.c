#include <stdio.h>
#include <stdlib.h>
/* funciones de cabecera */
int esPrimo(int n,int aux,int contador);
int factorizar(int n);
int factores(int n , int divisor);

int main(){
	int numero; // variable que ingresa el usuario
	int contador = 0; // contador de divisores de un numero
	int aux; 
	int resultado; 
	printf("Ingrese un numero cualquiera de menos de 7 digitos\n");
	scanf("%i", &numero );
	aux = numero;
	resultado = esPrimo(numero,aux,contador);
	if (resultado == 2){ // si el numero es directamente primo, tendra 2 divisores y termina el programa
		printf("El numero es primo y su descomposicion es 1 x %i\n",numero );
	}else{
		factorizar(numero); // en caso que el numero no es directamente primo, se factoriza por factores primos
	}
}
int esPrimo(int n,int aux,int contador){ // funcion recursiva que cuenta los divisores de un numero
	if (aux == 0){						// en el caso de que el contador sea 2, el numero es primo
		return contador;
	}
	if (n % aux == 0){ // si el numero es divisible por aux, se le suma 1 al contador 
		contador++;
		return esPrimo(n,aux-1,contador);

	}else{ // si el numero no es divisible, se le resta al auxiliar y el contador se mantiene
		return esPrimo(n,aux-1,contador);
	}
	
}
int factorizar(int n){ // Todo numero se puede descomponer en factores primos
	int copia = n;
	int contador = 0;
	int divisor = 2; 
	if (n == 0 || n == 1){ // caso base donde termina la recursion 
		printf("1  |\n");
		return 0;
	}else if (esPrimo(n,copia,contador) == 2){ // en caso de que ninguno de los numeros anteriores sea un divisor 
		printf("%i | %i \n",n,n);              // se comprueba si el numero es primo
		return factorizar(n/n);
	}else{
		return factorizar(factores(n,divisor)); // en el caso de no ser primo, entra a la funcion divisores
	}	
}  
int factores(int n , int divisor){ // Entrega el numero dividido y printea el factor
	if (n%divisor == 0){ // si se cumple que el numero es divisible por divisor
		printf("%i  |  %i \n",n,divisor );
		return n/divisor; // retornamos el numero dividido
	}else{
		return factores(n,divisor + 1); // en el caso que no sea divisible por el divisor, se le suma 1 a este ultimo y se sigue en el ciclo
	}
}
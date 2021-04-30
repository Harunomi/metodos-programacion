#include <stdio.h> // Biblioteca estandar de C 
/* Funciones a utilizar */
	/* Defino una funcion que me permite establecer si un numero es primo o no
		Retorna 1 si lo es, 0 en caso opuesto */
int primo(int numero){ 
	int divisores = 0;
	int i = 1;
	while (i<=numero){
		int division = numero % i;
		if (division == 0){
			divisores = divisores + 1;
			i++;
		}else{	
			i++;
		}	
	}
	if (divisores == 2){
		return 1;
	}else{
		return 0;
	}
}	
/* Requiero una funcion para saber el mayor valor entre 2 variables */
int max(int numero1, int numero2){
	int max = 0;
	if (numero1 > numero2){
		max = numero1;
	}else{
		max = numero2;
	}
	return max;
}	
/* Funcion correspondiente a cuando el usuario ingresa 1 */
void case1(int * numero){
	int resultado = primo(*numero);
	if (resultado == 1)
	{
		printf("El %i es primo.\n",*numero);	
	}else{
		printf("El %i no es primo.\n",*numero);
	}
}	
/* Funcion correspondiente a cuando el usuario ingresa 2 */
void case2(int *numero1, int *numero2){
	int maximo = max(*numero1,*numero2);
	int low;
	if (*numero1 == *numero2 && primo(*numero1) == 1){ // Necesito verificar el caso en el que ambos numeros sean iguales	
		printf("El numero %i es primo.\n",*numero1); // Sino,  el programa se cae al ingresar dos numeros no primos iguales
	}
	else if (*numero1 == *numero2 && primo(*numero1) == 0){
		printf("El numero %i no es primo.\n",*numero1);
	}
	else if (*numero1 != maximo){
		low = *numero1;	
		printf("tula %i\n",low );
	}else{
		low = *numero2;
		printf("lol %i\n",low );
	}
	while (low<=maximo){
		if (primo(low) == 1){
			printf("Los numeros primos entre %i y %i son: %i \n",*numero1,*numero2, low);
			low++;
		}else{
			low++;
		}
	}
}	
/* Funcion correspondiente a cuando el usuario ingresa 3 */
void case3(int *numero1, int *numero2){
	int maximo = max(*numero1,*numero2);
	int suma = 0;
	int low;
	if (*numero1 != maximo){
		low = *numero1;	
		printf("%i\n",low );
	}else{
		low = *numero2;
		printf("%i\n",low );
	}
	while (low<=maximo){
		if (primo(low) == 1){
			suma = suma + low;
			low++;
		}else{
			low++;
		}
	}	
	printf("La suma de todos los numeros primos entre %i y %i es: %i \n",*numero1,*numero2,suma );
}		


int main(){
/* ENTRADAS Y VARIABLES*/
	int seleccion; 
	int numero1;
	int numero2;
			/* Solicitud de variables */
	while (seleccion !=4){ // Ciclo en el cual solamente se saldrá cuando ingrese como opcion un 4
		printf("Seleccione una de las opciones: \n1\n2\n3\n4\n");
		scanf("%i", &seleccion);
		printf("Tu seleccion fue: %i\n",seleccion );
/* PROCEDIMIENTO */
		if (seleccion == 1){ 
			printf("Ingrese un numero: \n");
			scanf("%d", &numero1);
			case1(&numero1);	
		}	
		else if (seleccion == 2){
			printf("Ingrese un numero: \n");
			scanf("%d", &numero1);
			printf("Ingrese un segundo numero: \n");
			scanf("%d", &numero2);
			case2(&numero1,&numero2);
		}
		else if (seleccion == 3){
			printf("Ingrese un numero: \n");
			scanf("%d", &numero1);
			printf("Ingrese un segundo numero: \n");
			scanf("%d", &numero2);
			case3(&numero1,&numero2);
		}else if (seleccion !=4){ // Esta linea solo se activará cuando el usuario no ingrese uno de los numeros anteriores y no sea un 4	
			printf("   Lo sentimos, pero la opcion %i no existe.\nPor favor ingrese una opcion del listado\n",seleccion);			
		}
	}
/* SALIDA */
	/* En caso que el usuario ingrese el 4, se saldrá del ciclo y este mensaje se imprimirá por pantalla */
	printf("Agradezco tu tiempo por compilar este programa y ejecutarlo, te dejo un gatito\n");
    printf("%c%c%c%c%c%c\n",32,47,92,95,47,92); 
	printf("%c%c%c%c%c%c%c\n",40,32,111,46,111,32,41);
	printf("%c%c%c%c%c%c\n", 32,62,32,94,32,60);   
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definimos la estructura que utilizaremos con las distintas variables*/
struct registro{
	 char *nombre;
	 char *raza;
	 int edad;
	 int genero;
	 int vacuna;
};

void display(struct registro perrito);
/* Se crea la funcion display la cual mostrara cada dato de los perritos*/
void display(struct registro perrito){
	printf("Nombre: %s\n",perrito.nombre);
	printf("Raza: %s \n",perrito.raza );
	printf("Edad: %i primaveras \n",perrito.edad);
	if (perrito.genero == 0){	
		printf("Genero: Masculino\n");
	}else{
		printf("Genero: Femenino\n");
	}
	if (perrito.vacuna == 1){
		printf("El perrito esta vacunado\n");
	}else{
		printf("El perrito NO esta vacunado\n");
	}

}

int main(){
	/*Solicitamos los nombres de los perritos y sus datos*/
	int cantidadPerritos; // se guardara cuantos perritos se ingreseran
	int seleccion; // variable uqe guardara el numero de seleccion en el menu 
	int seleccionGenero; // variable que guarda el numero del genero de un perrito
	int seleccionVacuna; // variable que guarda el estado de vacuna de un perrito
	int i = 0;
	char perritoEntrada[15]; 
	printf("Por favor, ingrese la cantidad de perritos que va a almacenar: \n");
	scanf("%d",&cantidadPerritos);
	struct registro perrito[cantidadPerritos]; // se crean (cantidadPerritos) como perrito
	for (int i = 0; i < cantidadPerritos; ++i){ // iteracion para que el usuario ingrese cada variable 
		printf("Ingrese el nombre de un perrito: \n");
		perrito[i].nombre = malloc(sizeof(char)*15);
		scanf("%s",perrito[i].nombre);
		printf("Ingrese por favor la raza del perrito: %s \n", perrito[i].nombre);	
		perrito[i].raza = malloc(sizeof(char)*20);
		scanf("%s", perrito[i].raza);
		printf("Ingrese la edad del perrito %s en primaveras: \n", perrito[i].nombre );
		scanf("%i",&perrito[i].edad);
		printf("Ingrese el genero del perrito %s (Ingrese un 0 si es masculino o un 1 si es femenino): \n",perrito[i].nombre);
		scanf("%d", &perrito[i].genero);
		printf("Ingrese por favor el estado de vacuna del perrito %s (Ingrese un 0 si no lo esta o un 1 si lo esta)\n", perrito[i].nombre);
		scanf("%d",&perrito[i].vacuna);

	}
	printf("              Los datos de los perritos fueron almacenados exitosamente\n");
	while (seleccion !=4){// Ciclo en el cual solamente se saldrá cuando ingrese como opcion un 4
		printf("Seleccione una de las opciones: \n1.\n2.\n3.\n4.\n");
		scanf("%i", &seleccion);
		printf("Tu seleccion fue: %i\n",seleccion );
		if (seleccion == 1){
			for (int i = 0; i < cantidadPerritos; ++i){
				printf("|%s| ",perrito[i].nombre );
			}	
			printf("\nIntroduzca alguno de los perritos anteriores para mostrar sus datos: ");	
			scanf("%s",&perritoEntrada);
			int i = 0;
			while (i < cantidadPerritos){
				if (strcmp(perritoEntrada, perrito[i].nombre) == 0){ // string compare lo que hace es que si dos string son iguales, retorna 0
					display(perrito[i]);
					i++;
				}else{
					i++;
				}
			}
		}		 
		else if (seleccion == 2){
			printf("Ingrese un 0 para mostrar todos los perritos de genero masculino o un 1 para los perritos femeninos\n");
			scanf("%d",&seleccionGenero);
			int i = 0;
			if (seleccionGenero == 0){
				printf("Los siguientes perritos son de genero MASCULINO\n");
			}else{
				printf("Los siguientes perritos son de genero FEMENINO\n");
			}
			while ( i < cantidadPerritos){
				if (seleccionGenero == perrito[i].genero){
					printf("________\n");
					display(perrito[i]);
					printf("________\n");
					i++;
				}else{
					i++;
				}
			}

		}
		else if (seleccion == 3){	
			printf("Ingrese un 0 para mostrar todos los perritos que NO estan vacunados y un 1 para los que SI lo estan\n");
			scanf("%d",&seleccionVacuna);
			int i = 0;
			if (seleccionVacuna == 0){
				printf("Los siguientes perritos NO estan vacunados\n");
			}else{
				printf("Los siguientes perritos ESTAN vacunados\n");
			}
			while ( i < cantidadPerritos){
				if (seleccionVacuna == perrito[i].vacuna){
					printf("________\n");
					display(perrito[i]);
					printf("________\n");
					i++;
				}else{
					i++;
				}
			}
	
		}else if (seleccion !=4){ // Esta linea solo se activará cuando el usuario no ingrese uno de los numeros anteriores y no sea un 4	
			printf("   Lo sentimos, pero la opcion %i no existe.\nPor favor ingrese una opcion del listado\n",seleccion);			
		}
	
	}
	return 0;
} 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printearTexto(FILE *archivoSalida);

int main(){
	char text[20] = "generacion_";
	char numero[5] = "1";
	char output[5] = ".out";
	strcat(text,numero); strcat(text,output);
	printf("%s\n", text);
	FILE *archivo = fopen(text,"a");
	printearTexto(archivo);
	fclose(archivo);
	return 0;

}
void printearTexto(FILE *archivoSalida){
	for (int i = 0; i < 5; ++i){
		fprintf(archivoSalida,"Cum\n" );
	}
}
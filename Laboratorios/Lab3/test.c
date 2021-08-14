#include <stdio.h>
#include <stdlib.h>
void crearSoluciones();
int main(){
	for (int i = 0; i < 21; i = i + 5){
		printf("%i\n",i );
	}
	return 0;
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
	// se libera memoria y cierra el archivo
	for (int i = 0; i < 32; ++i)
	{
		free(matriz[i]);
	}
	free(matriz);
	fclose(fp);
}
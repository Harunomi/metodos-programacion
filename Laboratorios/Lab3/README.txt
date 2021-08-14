Este programa tiene la funcionalidad de a partir de unas instrucciones dadas
generar un nonograma (si es que existe solucion).

Las instrucciones deben ubicarse en una carpeta llamada Pistas, que se 
debe encontrar en la misma raiz del ejecutable. Estas instrucciones deben 
seguir un formato especifico y solo a admite los siguientes numeros:

00, 01, 02, 03, 04, 05, 11, 12, 13, 21,22 y 31

De cualquier forma cualquier error en la escritura se vera informado por 
pantalla, indicando el archivo y en que linea.

Al ejecutarlo se podra encontrar con un menu con 2 opciones: la primera para
ejecutar el programa escribiendo 1 y la segunda para cerrar el programa.

Luego de ejecutar el programa se le preguntara al usuario los nombres de 
los archivos a leer, un archivo para las filas y otro para las columnas.
El nombre del archivo debe incluir la extension de este.

El programa generaria todas las soluciones posibles en un archivo de texto
plano llamado soluciones.txt, si se ejecuta por segunda vez, el programa
no volvera a generar las soluciones para ahorrar tiempo, asi que tener
cuidado con que en la carpeta de raiz no haya otro archivo llamado
"soluciones.txt" ya que el programa lo tomara como si ya se hubiesen
generado cuando no es asi.

De encontrarse solucion, esta se mostrara por pantalla, si hay mas de una 
solucion, se mostraran todas las soluciones. Caso contrario de no encontrar
ninguna solucion, se le informara al usuario.

Por pantalla se mostraran una cuadricula como si fuese una matriz
en donde los 0 representan los espacios en blanco y los 1 los espacios 
pintados

Una vez mostradas las soluciones (caso de existir), el programa volvera
al menu donde se le preguntara al usuario si quiere ingresar otro par
de instrucciones o si quiere salir del programa.
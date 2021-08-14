El siguiente programa es el juego de la vida version sin interfaz bonita.
Las reglas del juego son  bastante simples: tienes un tablero representado
por una matriz cuadrada de potencia 2 en donde hay 2 tipos de celulas 
Vivas (X) y muertas (_), cada celula tiene sus reglas, para las celulas 
vivas deben tener 2 o 3 celulas vecinas para seguir viviendo y en caso
contario muere por soledad o sobrepoblacion; para las celulas muertas,
debe tener 3 celulas vecinas para revivir por reproduccion, caso contario
sigue muerta. Con estas simples reglas, puedes darle vida a poblaciones 
empezando con algo bastante simple y llegando a algo bastante complejo.

El programa se asegura de leer cualquier archivo de entrada que cumpla 
con las caracteristicas de poseer solamente _ y X en su texto, ademas
de la primera linea ser el tamano de la matriz y que deba ser potencia de 2
El numero de generaciones ingresado por el usuario debe ser un entero
positivo y ademas cuenta con 2 archivos de prueba "smoker.in" y
"civilization.in". Puedes crear tus propios archivos siempre y cuando
sigas las reglas antes mencionadas.
from random import randint
def generarMatriz(fil,col):
    matriz=[]
    for f in range(fil):
        nuevaFila = []
        for c in range(col):
            nuevaFila.append(0)
        matriz.append(nuevaFila)
    return matriz

def rellenar(matriz, fil,col):
    matriz[0][0] = randint(1,100)
    i=0
    while i < fil:
        j=0
        while j < col:
            if i == 0:
                if j > 0:
                    matriz[i][j] = matriz[i][j-1]+ randint(0,3) 

            else:
                if j==0:
                    matriz[i][j] = matriz[i-1][j]+ randint(0,3)

                else:
                    matriz[i][j] = max(matriz[i-1][j],matriz[i][j-1])+ randint(0,3)
                    
            j+=1
        i+=1
    return True

def matriz_a_texto(matriz, fil,col):
    texto = str(fil)+" "+str(col)
    for f in matriz:
        texto += "\n"
        for c in f:
            texto += str(c)+" "
        texto = texto.strip()
    return texto

def escribir(texto):
    a = open("Matriz.in","w")
    a.write(texto)
    a.close()
    return True

## Main ##
fil = randint(10,20)
col = randint(10,20)
matriz = generarMatriz(fil,col)
rellenar(matriz, fil,col)
texto = matriz_a_texto(matriz, fil,col)
print(texto)
escribir(texto)


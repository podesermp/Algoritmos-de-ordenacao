import matplotlib.pyplot as plt
import numpy as np

#x = np.loadtxt('resultadoQuick.txt')    
#y = np.loadtxt('resultadoSelectionIt.txt')
#tam = x[:,0]
#TI = x[:,1]
#TR = y[:,2]
#plt.plot(tam,TI, '*:r', label='Quick Sort Recursivo')
#plt.plot(tam,TR, '*:g', label='Recursivo')
#plt.title('Quick Sort Recursivo',fontsize=20)
#plt.xlabel(' Tamanhos')
#plt.ylabel('microsegundos')
#plt.legend()
#plt.show()


x=[]
y=[]
b = []
c = []

dataset = open('resultadoInsertionIt.txt', 'r')
dataset2 = open('resultadoSelectionIt.txt', 'r')
for line in dataset:
    line = line.strip()
    X, Y = line.split(' ')
    B, C = line.split(' ')
    x.append(X)
    y.append(Y)
    b.append(B)
    c.append(C)
dataset.close()
dataset2.close()
a = np.linspace(0, 2, num=100)
plt.plot(x,y, '*:r', label='Insertion')
plt.plot(b,c, '*:r', label='Selection')
plt.title('Insertion Sort Iterativo', fontsize=20)
plt.xlabel('Tamanhos')
plt.ylabel('microsegundos')
plt.show()
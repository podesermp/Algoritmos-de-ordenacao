#include <iostream>
#include "ordenacaoVetor.h"

using namespace std;

/*
Recebe um vetor e seu tamanho e ordena iteraticamente o vetor em ordem crescente
usando algoritmo SelectionSort
Recebe: tamanho do vetor e os elementos do vetor
Retorna: não há retorno mas o vetor está ordenado
*/
void Ordena::selectionSort(int n, int A[]){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i +1; j < n; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        swap(A[i], A[min]);
    }
}

/*
Recebe um vetor e seu tamanho e ordena iteraticamente o vetor em ordem crescente
usando algoritmo InserctionSort
Recebe: tamanho do vetor e os elementos do vetor
Retorna: não há retorno mas o vetor está ordenado
*/
void Ordena::inserctionSort(int n, int A[]){
   int i, j, key;
   for(j = 1; j < n; j++){
       key = A[j];
       i = j-1;
       while(i >= 0 && A[i] > key){
           A[i+1] = A[i];
           i--;
       }
       A[i+1] = key;
   }
}

void Ordena::intercala(int *A, int p, int q, int r){
    int *W  = new int[r-p+1];
    int i = p;
    int j = q+1;
    int k = 0;

    //Intercala A[p..q] e A[q+1...r]
    while(i <= q && j <= r){
        if(A[i] <= A[j]){
            W[k++] = A[i++];
        }else{
            W[k++] = A[j++];
        }
    }
    while(i <= q) W[k++] = A[i++];
    while(j <= r) W[k++] = A[j++];

    //Copia vetor W para vetor A
    for(i = p; i <= r; i++){
        A[i] = W[i-p];
    }
    delete[] W;
}
void Ordena::mergeSort(int A[], int p, int r){
    if(p < r){
        int q = (p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        intercala(A,p,q,r);
    }
}


void Ordena::mergeSortIterativo(int n, int A[]){
    int r, p, b = 1;
    while(b < n){
        p = 0; 
        while(p+b<n){
            r = p+2*b;
            if(r>n){
                r=n;
            }
            intercala(A,p,p+b,r);
            p=p+2*b;
        }
        b = 2*b;
    }
}

int Ordena::separa(int A[], int p, int r){
    int c = A[r];
    int j = p;
    for(int k = p; k < r; k++){
        if(A[k] <= c){
            swap(A[k], A[j]);
            j++;
        }
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}

void Ordena::quickSort(int A[], int p, int r){
    if(p < r){
        int i = separa(A, p, r);
        quickSort(A, p, i-1);
        quickSort(A, i+1, r);
    }
}
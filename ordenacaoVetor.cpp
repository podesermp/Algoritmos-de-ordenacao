#include <iostream>
#include "ordenacaoVetor.h"
using namespace std;
//Marcos Paulo Rocha Rodrigues - 403581

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
Recebe um vetor(A) com A[p...r] e ordena o vetor recursivamente
Recebe: um vetor de inteiros, o indice do primeiro elemento do vetor e o indice do ultimo elemento do vetor
Retorna: não há um retorno mas o vetor A[] é ordenado crescentemente
*/
void Ordena::selectionSortRecursivo(int A[], int p, int r){
    if(p <= r){
        int min = p;
        for(int j = p + 1; j <= r; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        swap(A[p], A[min]);
        selectionSortRecursivo(A,p+1,r);
    }
}

/*
Recebe um vetor(A) e seu tamanho(n) e ordena iteraticamente o vetor em ordem crescente
usando algoritmo InserctionSort
Recebe: tamanho do vetor e os elementos do vetor
Retorna: não há retorno mas o vetor está ordenado crescentemente
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
/*
Recebe um vetor(A) com A[p...r] e ordena o vetor recursivamente
Recebe: um vetor de inteiros, o indice do primeiro elemento do vetor e o indice do ultimo elemento do vetor
Retorna: não há um retorno mas o vetor A[] é ordenado crescentemente
*/
void Ordena::inserctionSortRecursivo(int A[], int p, int r){
    if(p <= r){
        int i;
        int key = A[p];
        i = p-1;
        while(i >= 0 && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
        inserctionSortRecursivo(A,p+1,r);
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
/*
Recebe um vetor(A) com A[p,...,r] e retorna o vetor ordenado recursivamente
Recebe: um vetor de inteiros, o indice do primeiro elemento e o indice do ultimo elemento do vetor
Retorna: não retorna nada mas o vetor A[] é ordenado crescentemente
*/
void Ordena::mergeSort(int A[], int p, int r){
    if(p < r){
        int q = (p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        intercala(A,p,q,r);
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
/*
Recebe um vetor(A) com A[p,...,r] e retorna o vetor ordenado recursivamente
Recebe: um vetor de inteiros, o indice do primeiro elemento e o indice do ultimo elemento do vetor
Retorna: não retorna nada mas o vetor A[] é ordenado crescentemente
*/
void Ordena::quickSort(int A[], int p, int r){
    if(p < r){
        int i = separa(A, p, r);
        quickSort(A, p, i-1);
        quickSort(A, i+1, r);
    }
}
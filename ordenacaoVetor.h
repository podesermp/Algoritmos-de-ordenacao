#ifndef ORDENACAO_H
#define ORDENACAO_H
//Marcos Paulo Rocha Rodrigues - 403581
class Ordena{
    private:
        void intercala(int *A, int p, int q, int r);
        int separa(int A[], int p, int r);
    public:
        void inserctionSort(int n, int A[]);                        //Ordena um vetor(A) iterativamente usando o algoritmo Insertion Sort   ok
        void inserctionSortRecursivo(int A[], int p, int r);        //Ordena um vetor(A) recursivamente usando o algoritmo Insertion Sort   ok
        void selectionSort(int n, int A[]);                         //Ordena um vetor(A) iterativamente usando o algoritmo Selection Sort   ok
        void selectionSortRecursivo(int A[], int p, int r);         //Ordena um vetor(A) recursivamente usando o algoritmo Selection Sort   ok
        void mergeSort(int A[], int p, int r);                      //Ordena um vetor(A) recursivamente usando o algoritmo Merge Sort
        void mergeSortIterativo(int n, int A[]);                    //
        void quickSort(int A[], int p, int r);                      //Ordena um vetor(A) recursivamente usando o algortimo Quick Sort
        void quickSortIterativo(int n, int A[]);                    //
};
#endif
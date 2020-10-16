#ifndef ORDENACAO_H
#define ORDENACAO_H

class Ordena{
    private:
        void intercala(int *A, int p, int q, int r);
        int separa(int A[], int p, int r);
    public:
        void inserctionSort(int n, int A[]);                //ok
        void inserctionSortRecursivo(int n, int A[]);       //
        void selectionSort(int n, int A[]);                 //ok
        void selectionSortRecursivo(int n, int A[]);        //
        void mergeSort(int A[], int p, int r);              //ok
        void mergeSortIterativo(int n, int A[]);            //
        void quickSort(int A[], int p, int r);              //ok
        void quickSortIterativo(int n, int A[]);            //
};
#endif
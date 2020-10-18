#include <iostream>
#include <fstream>
#include <chrono>
#include "ordenacaoVetor.h"
using namespace std;
//Marcos Paulo Rocha Rodrigues - 403581

void gera_dados(int num_iteracoes, const int vetor_tam[]){
    for(int n = 0; n < num_iteracoes;n++){
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(n)+"_"+to_string(semente)+".dat";
            ofstream fout(nome_arquivo.c_str(), ios::binary);
            srand(time(NULL));
            int r;
            int tamanho_vetor = vetor_tam[n];
            for(int i = 0; i < tamanho_vetor; i++){
                r = rand();
                fout.write((char*)&r, sizeof(r));
            }
            fout.close();
        }
    }
}

void ler_dados(int n, int A[], const char *nomeArquivo){
    ifstream fin(nomeArquivo, ios::binary);
    for(int i = 0; i < n; i++){
        fin.read((char*)&A[i], sizeof(int));
    }
    fin.close();
}

int main(){
    Ordena ordenador;

    const int tam[] = {500,1000,2000,3000,4000,5000,6000,7000,8000,9000,
	10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000};
    int TOTAL_N = sizeof(tam)/sizeof(tam[0]);

//-----------------------------------------------------------------------------------------------------------------------------------------------------
    //Insertion Sort Iterativo
    ofstream ofs("resultados/resultadoInsertionIt.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_insertionIt = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini = chrono::high_resolution_clock::now();
            ordenador.inserctionSort(tamanho_vetor,vetor);
            auto fim = chrono::high_resolution_clock::now();
            auto duracao_insertionIt = chrono::duration_cast<chrono::microseconds>(fim - ini).count();
            duracao_media_insertionIt += duracao_insertionIt;
        }
        duracao_media_insertionIt = duracao_media_insertionIt/5.0;
        cout << "[InsertionIt] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertionIt << " microssegundos" << endl;
        ofs << tamanho_vetor << " " << duracao_media_insertionIt << "\n";
    }
    ofs.close();

    //Insertion Sort Recursivo
    ofstream ofs1("resultados/resultadoInsertionRec.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_insertionRec = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini1 = chrono::high_resolution_clock::now();
            ordenador.inserctionSortRecursivo(vetor,1,tamanho_vetor-1);
            auto fim1 = chrono::high_resolution_clock::now();
            auto duracao_insertionRec = chrono::duration_cast<chrono::microseconds>(fim1 - ini1).count();
            duracao_media_insertionRec += duracao_insertionRec;
        }
        duracao_media_insertionRec = duracao_media_insertionRec/5.0;
        cout << "[InsertionRec] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertionRec << " microssegundos" << endl;
        ofs1 << tamanho_vetor << " " << duracao_media_insertionRec << "\n";
    }
    ofs1.close();

//-----------------------------------------------------------------------------------------------------------------------------------------------------
    //Selection Sort Iterativo
    ofstream ofs2("resultados/resultadoSelectionIt.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_selectionIt = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini2 = chrono::high_resolution_clock::now();
            ordenador.selectionSort(tamanho_vetor,vetor);
            auto fim2 = chrono::high_resolution_clock::now();
            auto duracao_selectionIt = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
            duracao_media_selectionIt += duracao_selectionIt;
        }
        duracao_media_selectionIt = duracao_media_selectionIt/5.0;
        cout << "[SelectionIt] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_selectionIt << " microssegundos" << endl;
        ofs2 << tamanho_vetor << " " << duracao_media_selectionIt << "\n";
    }
    ofs2.close();

    //Selection Sort Recursivo
    ofstream ofs3("resultados/resultadoSelectionRec.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_selectionRec = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini3 = chrono::high_resolution_clock::now();
            ordenador.selectionSortRecursivo(vetor,0,tamanho_vetor-1);
            auto fim3 = chrono::high_resolution_clock::now();
            auto duracao_selectionRec = chrono::duration_cast<chrono::microseconds>(fim3 - ini3).count();
            duracao_media_selectionRec += duracao_selectionRec;
        }
        duracao_media_selectionRec = duracao_media_selectionRec/5.0;
        cout << "[SelectionRec] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_selectionRec << " microssegundos" << endl;
        ofs3 << tamanho_vetor << " " << duracao_media_selectionRec << "\n";
    }
    ofs3.close();

//-----------------------------------------------------------------------------------------------------------------------------------------------------
    //Merge Sort Recursivo
    ofstream ofs4("resultados/resultadoMergeRec.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_mergeRec = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini4 = chrono::high_resolution_clock::now();
            ordenador.mergeSort(vetor,0,tamanho_vetor-1);
            auto fim4 = chrono::high_resolution_clock::now();
            auto duracao_mergeRec = chrono::duration_cast<chrono::microseconds>(fim4 - ini4).count();
            duracao_media_mergeRec += duracao_mergeRec;
        }
        duracao_media_mergeRec = duracao_media_mergeRec/5.0;
        cout << "[MergeRec] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_mergeRec << " microssegundos" << endl;
        ofs4 << tamanho_vetor << " " << duracao_media_mergeRec << "\n";
    }
    ofs4.close();

//-----------------------------------------------------------------------------------------------------------------------------------------------------
    //Quick Sort Recursivo
    ofstream ofs5("resultados/resultadoQuickRec.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_quickRec = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini5 = chrono::high_resolution_clock::now();
            ordenador.quickSort(vetor,0,tamanho_vetor-1);
            auto fim5 = chrono::high_resolution_clock::now();
            auto duracao_quickRec = chrono::duration_cast<chrono::microseconds>(fim5 - ini5).count();
            duracao_media_quickRec += duracao_quickRec;
        }
        duracao_media_quickRec = duracao_media_quickRec/5.0;
        cout << "[QuickRec] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_quickRec << " microssegundos" << endl;
        ofs5 << tamanho_vetor << " " << duracao_media_quickRec << "\n";
    }
    ofs5.close();
    
    return 0;
}
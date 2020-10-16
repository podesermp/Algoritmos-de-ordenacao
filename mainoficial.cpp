#include <iostream>
#include <fstream>
#include <chrono>
#include "ordenacaoVetor.h"
using namespace std;

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

    //INSERTION SORT
    ofstream ofs("resultados/resultadoInsertionIt.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_insertion = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini = chrono::high_resolution_clock::now();
            ordenador.inserctionSort(tamanho_vetor,vetor);
            auto fim = chrono::high_resolution_clock::now();
            auto duracao_insertion = chrono::duration_cast<chrono::microseconds>(fim - ini).count();
            duracao_media_insertion += duracao_insertion;
        }
        duracao_media_insertion = duracao_media_insertion/5.0;
        cout << "[InsertionIt] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertion << " microssegundos" << endl;
        ofs << tamanho_vetor << " " << duracao_media_insertion << "\n";
    }
    ofs.close();


	//QUICK SORT
    ofstream ofs4("resultados/resultadoQuick.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_quick = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini4 = chrono::high_resolution_clock::now();
            ordenador.quickSort(vetor,0, tamanho_vetor-1);
            auto fim4 = chrono::high_resolution_clock::now();
            auto duracao_quick = chrono::duration_cast<chrono::microseconds>(fim4 - ini4).count();
            duracao_media_quick += duracao_quick;
        }
        duracao_media_quick = duracao_media_quick/5.0;
        cout << "[Quick] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_quick << " microssegundos" << endl;
        ofs4 << tamanho_vetor << " " << duracao_media_quick << "\n";
    }
    ofs4.close();


    //SELECTION SORT
    ofstream ofs2("resultados/resultadoSelectionIt.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_selection = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini2 = chrono::high_resolution_clock::now();
            ordenador.selectionSort(tamanho_vetor,vetor);
            auto fim2 = chrono::high_resolution_clock::now();
            auto duracao_selection = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
            duracao_media_selection += duracao_selection;
        }
        duracao_media_selection = duracao_media_selection/5.0;
        cout << "[SelectionIt] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_selection << " microssegundos" << endl;
        ofs2 << tamanho_vetor << " " << duracao_media_selection << "\n";
    }
    ofs2.close();


	//MERGE SORT
    ofstream ofs3("resultados/resultadoMerge.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_merge = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini3 = chrono::high_resolution_clock::now();
            ordenador.mergeSort(vetor,0, tamanho_vetor-1);
            auto fim3 = chrono::high_resolution_clock::now();
            auto duracao_merge = chrono::duration_cast<chrono::microseconds>(fim3 - ini3).count();
            duracao_media_merge += duracao_merge;
        }
        duracao_media_merge = duracao_media_merge/5.0;
        cout << "[Merge] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_merge << " microssegundos" << endl;
        ofs3 << tamanho_vetor << " " << duracao_media_merge << "\n";
    }
    ofs3.close();	
    return 0;
}
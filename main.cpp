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
    /*
    const int tam[] = {500,1000,2000,3000,4000,5000,6000,7000,8000,9000,
	10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000};
    int TOTAL_N = sizeof(tam)/sizeof(tam[0]);
    
    //QUICK SORT
    ofstream ofs("resultados/resultadoQuick.txt", ofstream::out);
    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
        long double duracao_media_quick = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];
        for(int semente = 0; semente < 5; semente++){
            string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
            ler_dados(tamanho_vetor, vetor,nome_arquivo.c_str());
            auto ini = chrono::high_resolution_clock::now();
            ordenador.quickSort(vetor,0, tamanho_vetor-1);
            auto fim = chrono::high_resolution_clock::now();
            auto duracao_quick = chrono::duration_cast<chrono::microseconds>(fim - ini).count();
            duracao_media_quick += duracao_quick;
        }
        duracao_media_quick = duracao_media_quick/5.0;
        cout << "[Quick] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_quick << " microssegundos" << endl;
        ofs << tamanho_vetor << " " << duracao_media_quick << "\n";
    }
    ofs.close();
    */
    int n;
    cin >> n;
    int vec[n];
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    ordenador.mergeSortIterativo(n,vec);
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    
    return 0;
}
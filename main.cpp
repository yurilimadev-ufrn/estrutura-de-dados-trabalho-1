#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip> // Para ajustar a precisão decimal
#include "algoritmos.h"
#include "benchmarking.h"

int main() {
    // 1. Benchmarking de Buscas (Tamanhos Grandes)
    std::vector<int> tamanhosBusca = {10000, 100000, 500000, 1000000};
    std::ofstream arqBusca("resultados_busca.csv");
    arqBusca << "n,busca_sequencial,busca_binaria\n";

    std::cout << std::fixed << std::setprecision(6); // Mostra 6 casas decimais
    std::cout << "--- Benchmarking de Buscas ---" << std::endl;

    for (int n : tamanhosBusca) {
        std::vector<int> dados(n);
        std::iota(dados.begin(), dados.end(), 0);
        double tSeq = medirTempo([&]() { return buscaSequencial(dados, -1); }, 1000);
        double tBin = medirTempo([&]() { return buscaBinaria(dados, -1); }, 10000);
        
        std::cout << "N: " << n << " | Seq: " << tSeq << "ms | Bin: " << tBin << "ms" << std::endl;
        arqBusca << n << "," << tSeq << "," << tBin << "\n";
    }

    // 2. Benchmarking de Ordenação (Tamanhos Menores devido ao O(n^2)) [cite: 7, 14]
    std::vector<int> tamanhosOrd = {1000, 5000, 10000, 20000};
    std::ofstream arqOrd("resultados_ordenacao.csv");
    arqOrd << "n,insertion_sort,quick_sort\n";

    std::cout << "\n--- Benchmarking de Ordenacao ---" << std::endl;

    for (int n : tamanhosOrd) {
        // Criar vetores aleatórios para o teste de ordenação [cite: 15]
        std::vector<int> dadosBase(n);
        std::generate(dadosBase.begin(), dadosBase.end(), std::rand);

        double tInsert = medirTempo([&]() {
            std::vector<int> copia = dadosBase;
            insertionSort(copia);
            return copia[0]; // Retorno apenas para evitar otimização
        }, 5); // Poucas repetições porque Insertion Sort é lento

        double tQuick = medirTempo([&]() {
            std::vector<int> copia = dadosBase;
            quickSort(copia, 0, copia.size() - 1);
            return copia[0];
        }, 50);

        std::cout << "N: " << n << " | Insertion: " << tInsert << "ms | Quick: " << tQuick << "ms" << std::endl;
        arqOrd << n << "," << tInsert << "," << tQuick << "\n";
    }

    return 0;
}
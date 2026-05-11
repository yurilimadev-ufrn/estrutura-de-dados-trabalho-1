#ifndef BENCHMARKING_H
#define BENCHMARKING_H

#include <iostream>
#include <chrono>

template<typename Func>
double medirTempo(Func algoritmo, int repeticoes = 1000) { // Aumentamos o padrão para 1000
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < repeticoes; ++i) {
        // O result é usado para "enganar" o otimizador do compilador
        auto result = algoritmo(); 
        (void)result; 
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculamos o tempo total em microssegundos e depois tiramos a média
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    return static_cast<double>(duration) / repeticoes / 1000.0; // Retorna média em milissegundos
}

#endif
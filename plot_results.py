import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

def plot_grafico(arquivo, titulo, algoritmos, complexidades_teoricas):
    
    df = pd.read_csv(arquivo)
    n = df['n']
    
    plt.figure(figsize=(10, 6))
    
    for algo in algoritmos:
        plt.scatter(n, df[algo], label=f'Empírico: {algo}')
        plt.plot(n, df[algo], alpha=0.3) # Linha guia suave
    
    
    for label, func in complexidades_teoricas.items():
        valores_teoricos = [func(i) for i in n]
        escala = df[algoritmos[0]].max() / max(valores_teoricos)
        plt.plot(n, np.array(valores_teoricos) * escala, '--', label=f'Teórico: {label}')

    plt.title(titulo)
    plt.xlabel('Tamanho da Entrada (n)')
    plt.ylabel('Tempo (ms)')
    plt.legend()
    plt.grid(True)
    plt.savefig(f"{titulo.replace(' ', '_').lower()}.png")
    plt.show()


plot_grafico('resultados_busca.csv', 'Analise de Algoritmos de Busca', 
             ['busca_sequencial', 'busca_binaria'],
             {'O(n)': lambda x: x, 'O(log n)': lambda x: np.log2(x) if x > 0 else 0})


plot_grafico('resultados_ordenacao.csv', 'Analise de Algoritmos de Ordenacao', 
             ['insertion_sort', 'quick_sort'],
             {'O(n^2)': lambda x: x**2, 'O(n log n)': lambda x: x * np.log2(x) if x > 0 else 0})
# Análise Empírica de Complexidade de Algoritmos

Este projeto foi desenvolvido para a disciplina de Estruturas de Dados Básicos I. O objetivo é avaliar o tempo de execução de algoritmos de busca e ordenação, comparando os resultados empíricos com as complexidades assintóticas teóricas.

## 🚀 Algoritmos Analisados
- **Busca:** Sequencial ($O(n)$) e Binária ($O(\log n)$).
- **Ordenação:** Insertion Sort ($O(n^2)$) e QuickSort ($O(n \log n)$).

## 🛠️ Tecnologias Utilizadas
- **C++**: Implementação dos algoritmos e coleta de tempos (`std::chrono`).
- **Python (Matplotlib/Pandas)**: Geração de gráficos e análise de dados.
- **Git/GitHub**: Controle de versão.

## 📋 Como Executar

### Pré-requisitos
- Compilador G++ (GCC)
- Python 3.x e `venv`

### Passo a Passo
1. **Compilar e Rodar o Benchmarking (C++):**
   ```bash
   g++ -O3 main.cpp -o programa
   ./programa
   ```
2. **Configurar Ambiente Python (Matplotlib/Pandas):**
   ```
   python -m venv venv
   source venv/Scripts/activate  # Windows: .\venv\Scripts\activate
   pip install -r requirements.txt
   ```
3. **Gerar Gráficos:**
   ```
   python plot_results.py
   ```
### Integrantes

- Yuri Dimitri Ribeiro Lima

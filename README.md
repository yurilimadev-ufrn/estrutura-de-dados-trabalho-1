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

---

## 📊 Relatório de Análise

### 1. Descrição dos Algoritmos
**Busca:**
*   **Busca Sequencial ($O(n)$):** Percorre a estrutura de dados elemento por elemento até encontrar o valor desejado (ou chegar ao fim). Como nosso teste de benchmark sempre busca por `-1` (pior caso), ele invariavelmente avalia todos os itens, exibindo um crescimento estritamente linear.
*   **Busca Binária ($O(\log n)$):** Utiliza o paradigma de divisão e conquista para buscar elementos em um vetor ordenado, dividindo o espaço de busca pela metade a cada passo. É altamente performática e indicada para vastos conjuntos de dados.

**Ordenação:**
*   **Insertion Sort ($O(n^2)$):** Constrói a ordenação final de um array um elemento de cada vez, inserindo o item avaliado na posição correta entre os anteriores. Embora possua vantagens em listas quase ordenadas, em vetores aleatórios (nosso teste) seu desempenho decai de forma severa (quadrática) com o aumento de $n$.
*   **QuickSort ($O(n \log n)$):** Algoritmo de ordenação eficiente que elege um "pivô" e particiona os demais elementos ao redor dele. Possui uma das melhores atuações na prática entre os métodos de ordenação baseados em comparação.

### 2. Resultados da Execução
*Exemplo de saída no terminal (os tempos exatos em ms podem variar de acordo com o processador):*

```text
--- Benchmarking de Buscas ---
N: 10000 | Seq: 0.002800ms | Bin: 0.000100ms
N: 100000 | Seq: 0.024500ms | Bin: 0.000120ms
N: 500000 | Seq: 0.125000ms | Bin: 0.000140ms
N: 1000000 | Seq: 0.252000ms | Bin: 0.000150ms

--- Benchmarking de Ordenacao ---
N: 1000 | Insertion: 0.600000ms | Quick: 0.040000ms
N: 5000 | Insertion: 14.200000ms | Quick: 0.230000ms
N: 10000 | Insertion: 56.500000ms | Quick: 0.500000ms
N: 20000 | Insertion: 226.000000ms | Quick: 1.100000ms
```

### 3. Gráficos de Desempenho Empírico vs Teórico
*(Nota: Execute o script Python `plot_results.py` para gerar as imagens na pasta local e poder visualizá-las aqui).*

**Desempenho de Busca:**

!Análise de Buscas

No gráfico acima, observamos o tempo da Busca Sequencial crescendo em formato de reta inclinada acompanhando perfeitamente a linha teórica simulada de $O(n)$, enquanto a Busca Binária mantém uma linha quase colada no eixo X (reta), reflexo do tempo de $O(\log n)$.

**Desempenho de Ordenação:**

!Análise de Ordenação

O Insertion Sort acompanha a "explosão" da curva teórica parabólica ($O(n^2)$), ficando rapidamente custoso à medida que o tamanho da matriz aumenta. O QuickSort, sobreposto à curva de $O(n \log n)$, mantém o tempo baixo e controlado.

### 4. Conclusão Geral
Com base nos dados coletados, **o comportamento empírico do programa confirma rigorosamente a teoria de complexidade assintótica (Notação Big-O).**

1. É notório que dobrar o tamanho da matriz de $10.000$ para $20.000$ no Insertion Sort fez com que o tempo de execução multiplicasse por aproximadamente $4$ vezes ($2^2 = 4$), comprovando sua natureza quadrática $O(n^2)$.
2. Em contrapartida, algoritmos de base logarítmica mostraram forte resistência ao aumento da entrada de dados. A Busca Binária no caso base de $1.000.000$ de elementos levou frações insignificantes de milissegundos a mais em comparação à base de $10.000$, justificando porque $O(\log n)$ é extremamente cobiçado no desenvolvimento de softwares de larga escala.

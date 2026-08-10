# ALGORITMO E COMPLEXIDADE EM C
-Carlos Daniel-
-cd38668cd@gmail.com

# O QUE É ALGORITMO
Algoritmo é uma sequência de passos a ser seguida para resultar em um determinado objetivo.

# O QUE É COMPLEXIDADE
Complexidade é a medida de crescimento do tempo (ou espaço) de execução de um algoritmo em função do tamanho da entrada. Ao analisar sua complexidade, verificamos se ela cresce de forma linear, logarítmica ou quadrática — a essa análise chamamos de análise assintótica!

Para realizar a análise assintótica, consideramos que, para um algoritmo com tamanho de entrada n, cada operação (passo básico) leva o mesmo tempo constante e que a memória da máquina é eficiente.

# NOTAÇAO O (Big O)
O(1), O(n), O(n²) 
A principal utilidade da notação Big O é permitir a comparação objetiva entre algoritmos, independentemente da implementação. 
//

Constante – O(1)
Indica que o tempo de execução é sempre o mesmo, sem importar o tamanho da entrada.
Exemplo: acesso direto a um elemento em uma matriz.
//

Logarítmica – O(log n)
Aparece quando a entrada é reduzida pela metade a cada etapa. Ela é muito comum em estruturas de dados balanceadas, como árvores binárias de busca.
Exemplo: determinar se um número está presente em um conjunto de dados ordenados usando divisão binária.
//
Linear – O(n)
Significa que a complexidade cresce com o tamanho da entrada. Cada elemento é examinado uma vez.
Exemplo: verificar se há duplicatas em uma lista não ordenada, comparando cada elemento com os anteriores.
//

Linearítmica – O(n log n)
É comum em algoritmos que dividem a entrada e fazem trabalho proporcional ao tamanho total em cada nível.
Exemplo: algoritmos de agrupamento hierárquico em aprendizado de máquina.
//

Quadrática – O(n²)
Aparece quando cada elemento é comparado com todos os outros, resultando em número de operações proporcional ao quadrado do tamanho da entrada.
Exemplo: calcular a similaridade entre todos os pares de documentos em um corpus para criar um mapa semântico.
//

Exponencial – O(2ⁿ)
Correspondem a algoritmos que exploram todas as combinações possíveis, em particular, em problemas de decisão complexos.
Exemplo: resolver um jogo de tabuleiro considerando todos os possíveis caminhos de movimento.
//

Fatorial – O(n!)
Aparece em problemas de permutação, como determinar todas as possíveis ordens de uma sequência.
Exemplo: analisar todas as ordens possíveis de visitas em um itinerário turístico para encontrar a mais eficiente.
//

# COTA SUPERIOR
"Cota superior" (upper bound) é um limite que garante que o tempo de execução do algoritmo nunca vai ultrapassar uma certa taxa de crescimento, para entradas suficientemente grandes.

# COMPONENTES CONJUNTIVAS
São partes do algoritmo sempre executadas em sequência obrigatória, mas todas contribuem para o tempo total. Nesses casos, a complexidade total é a soma das complexidades individuais.

# COMPONENTES DISJUNTIVAS
Aparecem em estruturas condicionais, como if/else, em que apenas um entre dois (ou mais) caminhos será executado. Nessa estrutura, a complexidade depende do caso mais custoso, pois representa o limite superior de esforço computacional.

# PRINCIPIOS DA ABSORÇAO
É uma regra de simplificação assintótica: quando somamos funções de ordens diferentes, a de maior crescimento absorve as menores
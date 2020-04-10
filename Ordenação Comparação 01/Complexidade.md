# Complexidade dos algoritmos de acordo com o tempo de execução

|       Selection Sort        |       Insertion Sort        |
|-----------------------------|-----------------------------|
|     Entrada     | Tempo (s) |     Entrada     | Tempo (s) |
| num.1000.1.in   |  0.003123 | num.1000.1.in   |  0.007181 |
| num.1000.2.in   |  0.005573 | num.1000.2.in   |  0.006574 |
| num.1000.3.in   |  0.005061 | num.1000.3.in   |  0.006108 |
| num.1000.4.in   |  0.005627 | num.1000.4.in   |  0.007332 |
| num.10000.1.in  |  0.271648 | num.10000.1.in  |  0.355231 |
| num.10000.2.in  |  0.296806 | num.10000.2.in  |  0.353031 |
| num.10000.3.in  |  0.271848 | num.10000.3.in  |  0.383003 |
| num.10000.4.in  |  0.296955 | num.10000.4.in  |  0.366636 |
| num.100000.1.in | 26.431163 | num.100000.1.in | 34.498979 |
| num.100000.2.in | 26.431435 | num.100000.2.in | 34.509247 |
| num.100000.3.in | 26.523428 | num.100000.3.in | 34.521854 |
| num.100000.4.in | 26.399106 | num.100000.4.in | 34.610037 |

  > Observação:
  > Os tempos de execução obtidos foram adquiridos por meio da execução do programa `main` no meu computador pessoal, os tempos de execução tiveram pequenas variações para cada execução com a memsma entrada e com o mesmo algoritmo de ordenação.

## Funções de complexidade teóricas para os algoritmos de ordenação

### Selection Sort - C(n) = O(n2) para todos os casos
### Insertion Sort - C(n) = O(n) para o melhor caso e C(n) = O(n2) para médio e pior casos.

|         Selection Sort          |
|-----------------|---------------|
| Tamanho Entrada | Complexidade  |
| -               | Todos         |
| 1.000           | 1.000.000     |
| 10.000          | 100.000.000   |
| 100.000         | 1.000.000.000 |

|              Insertion Sort               |
|-----------------|-------------------------|
| Tamanho Entrada | Complexidade            |
| -               | Melhor  | Pior e Médio  |
| 1.000           | 1.000   | 1.000.000     |
| 10.000          | 10.000  | 100.000.000   |
| 100.000         | 100.000 | 1.000.000.000 |


/**
 * Conheça os principais algoritmos de ordenação
 * 
A ordenação de registros consiste em organizar os dados em ordem crescente ou decrescente. Veja os principais métodos de ordenação e a teoria por trás deles.

Daniel Viana 26 de dezembro de 2016

Imagine como seria buscar um número em um catálogo telefônico se os nomes das pessoas não estivessem listados em ordem alfabética? Seria muito complicado. A ordenação ou classificação de registros consiste em organizá-los em ordem crescente ou decrescente e assim facilitar a recuperação desses dados. A ordenação tem como objetivo facilitar as buscas e pesquisas de ocorrências de determinado elemento em um conjunto ordenado.

Como preza a estratégia algorítmica: “Primeiro coloque os números em ordem. Depois decidimos o que fazer.”

Na computação existe uma série de algoritmos que utilizam diferentes técnicas de ordenação para organizar um conjunto de dados, eles são conhecidos como Métodos de Ordenação ou Algoritmos de Ordenação. Vamos conhecer um pouco mais sobre eles.

Os métodos de ordenação se classificam em:

Ordenação Interna: onde todos os elementos a serem ordenados cabem na memória principal e qualquer registro pode ser imediatamente acessado.
Ordenação Externa: onde os elementos a serem ordenados não cabem na memória principal e os registros são acessados sequencialmente ou em grandes blocos.

Hoje veremos apenas os métodos de ordenação interna.

Dentro da ordenação interna temos os Métodos Simples e os Métodos Eficientes:

C Básico
CURSO DE C BÁSICO
CONHEÇA O CURSO
Métodos Simples
Os métodos simples são adequados para pequenos vetores, são programas pequenos e fáceis de entender. Possuem complexidade C(n) = O(n²), ou seja, requerem O(n²) comparações. Exemplos: Insertion Sort, Selection Sort, Bubble Sort, Comb Sort.

Dica: Veja uma breve introdução à análise de algoritmos

Nos algoritmos de ordenação as medidas de complexidade relevantes são:

Número de comparações C(n) entre chaves.
Número de movimentações M(n) dos registros dos vetores.
Onde n é o número de registros.
/**Shell Sort
 * 
 * Criado por Donald Shell em 1959, o método Shell Sort é uma extensão do algoritmo de ordenação por inserção. Ele permite a troca de registros distantes um do outro, diferente do algoritmo de ordenação por inserção que possui a troca de itens adjacentes para determinar o ponto de inserção. A complexidade do algoritmo é desconhecida, ninguém ainda foi capaz de encontrar uma fórmula fechada para sua função de complexidade e o método não é estável.
 * Os itens separados de h posições (itens distantes) são ordenados: o elemento na posição x é comparado e trocado (caso satisfaça a condição de ordenação) com o elemento na posição x-h. Este processo repete até h=1, quando esta condição é satisfeita o algoritmo é equivalente ao método de inserção.
 * A escolha do salto h pode ser qualquer sequência terminando com h=1. Um exemplo é a sequencia abaixo:
 * h(s) = 1, para s = 1
 * h(s) = 3h(s - 1) + 1, para s > 1
 * A sequência corresponde a 1, 4, 13, 40, 121, …
 * Knuth (1973) mostrou experimentalmente que esta sequencia é difícil de ser batida por mais de 20% em eficiência.
 * Veja o vídeo que demonstra o passo a passo da execução do algoritmo:
 * https://www.youtube.com/watch?v=CmPA7zE8mx0
 * */

void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}

/**Conclusão
 * Neste artigo foi apresentado os principais métodos de ordenação com foco no conceito e funcionamento de cada um deles.
**/


/****
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

Os métodos simples são adequados para pequenos vetores, são programas pequenos e fáceis de entender. Possuem complexidade C(n) = O(n²), ou seja, requerem O(n²) comparações. Exemplos: Insertion Sort, Selection Sort, Bubble Sort, Comb Sort.

Dica: Veja uma breve introdução à análise de algoritmos

Nos algoritmos de ordenação as medidas de complexidade relevantes são:

Número de comparações C(n) entre chaves.
Número de movimentações M(n) dos registros dos vetores.
Onde n é o número de registros.



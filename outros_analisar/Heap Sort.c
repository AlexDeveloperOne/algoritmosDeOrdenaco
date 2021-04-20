/**
 * Métodos Eficientes
 * Os métodos eficientes são mais complexos nos detalhes, requerem um número menor de
 * comparações. São projetados para trabalhar com uma quantidade maior de dados e possuem
 * complexidade C(n) = O(n log n). Exemplos Quick sort, Merge sort, Shell sort, Heap sort,
 * Radix sort, Gnome sort, Count sort, Bucket sort, Cocktail sort, Timsort.
 * */

Heapsort
Origem: Wikipédia, a enciclopédia livre.
Saltar para a navegaçãoSaltar para a pesquisa
Heapsort

algoritmo heapsort
classe	Algoritmo de ordenação
estrutura de dados	Array, Listas ligadas
complexidade pior caso	{\displaystyle \Theta (n\log n)}\Theta (n\log n)
complexidade caso médio	{\displaystyle \Theta (n\log n)}\Theta (n\log n)
complexidade melhor caso	{\displaystyle \Theta (n\log n)}\Theta (n\log n)[1]
complexidade de espaços pior caso	{\displaystyle \Theta (n)}{\displaystyle \Theta (n)} total, {\displaystyle \Theta (1)}{\displaystyle \Theta (1)} auxiliar
Algoritmos
Esta caixa: verdiscutir

Exemplo de execução do heapsort
 Schaffer, Russel; Sedgewick, Robert (julho de 1993). «The Analysis of Heapsort». Journal of Algorithms. 15 (1): 76–100. doi:10.1006/jagm.1993.1031
O algoritmo heapsort é um algoritmo de ordenação generalista, e faz parte da família de algoritmos de ordenação por seleção. Foi desenvolvido em 1964 por Robert W. Floyd e J.W.J Williams.


Índice
1	Definição
2	Características
2.1	Estabilidade
3	Funcionamento
4	Implementação em C
5	Referências
6	Ligações externas
Definição
Tem um desempenho em tempo de execução muito bom em conjuntos ordenados aleatoriamente, tem um uso de memória bem comportado e o seu desempenho em pior cenário é praticamente igual ao desempenho em cenário médio. Alguns algoritmos de ordenação rápidos têm desempenhos espectacularmente ruins no pior cenário, quer em tempo de execução, quer no uso da memória. O heapsort trabalha no lugar e o tempo de execução em pior cenário para ordenar n elementos é de O (n lg n). Lê-se logaritmo (ou log) de "n" na base 2. Para valores de n, razoavelmente grandes, o termo log n é quase constante, de modo que o tempo de ordenação é quase linear com o número de itens a ordenar.

Características
Comparações no pior caso: 2n log2n + O(n) é o mesmo que 2n log n + O(n)
Trocas no pior caso: n log2n + O(n) é o mesmo que n log n + O(n)
Melhor e pior caso: O(n log2n) é o mesmo que O(n log n)
Estabilidade
O heapsort não é um algoritmo de ordenação estável. Porém, é possível adaptar a estrutura a ser ordenada de forma a tornar a ordenação estável. Cada elemento da estrutura adaptada deve ficar no formato de um par (elemento original, índice original). Assim, caso dois elementos sejam iguais, o desempate ocorrerá pelo índice na estrutura original.

Funcionamento
O heapsort utiliza uma estrutura de dados chamada heap, para ordenar os elementos à medida que os insere na estrutura. Assim, ao final das inserções, os elementos podem ser sucessivamente removidos da raiz da heap, na ordem desejada, lembrando-se sempre de manter a propriedade de max-heap.

A heap pode ser representada como uma árvore (uma árvore binária com propriedades especiais[1]) ou como um vetor. Para uma ordenação decrescente, deve ser construída uma heap mínima (o menor elemento fica na raiz). Para uma ordenação crescente, deve ser construído uma heap máxima (o maior elemento fica na raiz).

Implementação em C

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}
Implementação em Java:

    public static void heapSort(int[] vetor){
        int tamanho = vetor.length;
        int i = tamanho / 2, pai, filho, t;
        while (true){
            if (i > 0){
                i--; t = vetor[i];
            }else{
                tamanho--;
                if (tamanho <= 0) {return;}
                t = vetor[tamanho];
                vetor[tamanho] = vetor[0];
            }
            pai = i;
            filho = ((i * 2) + 1);
            while (filho < tamanho){
                if ((filho + 1 < tamanho) && (vetor[filho + 1] > vetor[filho])) {filho++;}
                if (vetor[filho] > t){
                    vetor[pai] = vetor[filho];
                    pai = filho;
                    filho = pai * 2 + 1;
                }else {break;}
            }
            vetor[pai] = t;
        }
    }
    
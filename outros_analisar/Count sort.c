/**
 * Métodos Eficientes
 * Os métodos eficientes são mais complexos nos detalhes, requerem um número menor de
 * comparações. São projetados para trabalhar com uma quantidade maior de dados e possuem
 * complexidade C(n) = O(n log n). Exemplos Quick sort, Merge sort, Shell sort, Heap sort,
 * Radix sort, Gnome sort, Count sort, Bucket sort, Cocktail sort, Timsort.
 * */
Counting sort
Origem: Wikipédia, a enciclopédia livre.
Saltar para a navegaçãoSaltar para a pesquisa

Esta página cita fontes confiáveis, mas que não cobrem todo o conteúdo. Ajude a inserir referências. Conteúdo não verificável poderá ser removido.—Encontre fontes: Google (notícias, livros e acadêmico) (Agosto de 2012)
Counting sort
classe	Algoritmo de ordenação
estrutura de dados	Array, Listas ligadas
complexidade pior caso	{\displaystyle O(n+k)}{\displaystyle O(n+k)}
complexidade caso médio	{\displaystyle O(n+k)}{\displaystyle O(n+k)}
complexidade melhor caso	{\displaystyle O(n+k)}{\displaystyle O(n+k)}
Algoritmos
Esta caixa: verdiscutir
Counting sort é um algoritmo de ordenação estável cuja complexidade é O(n). As chaves podem tomar valores entre 0 e M-1. Se existirem k0 chaves com valor 0, então ocupam as primeiras k0 posições do vetor final: de 0 a k0-1.

A ideia básica do counting sort é determinar, para cada entrada x, o número de elementos menor que x. Essa informação pode ser usada para colocar o elemento x diretamente em sua posição no array de saída. Por exemplo, se há 17 elementos menores que x, então x pertence a posição 18. Esse esquema deve ser ligeiramente modificado quando houver vários elementos com o mesmo valor, uma vez que nós não queremos que sejam colocados na mesma posição.[1]


Índice
1	Pseudocódigo
2	Implementações
2.1	Código em C++
2.2	Código em C
2.3	Código em Java 1.0
2.4	Código em Java 1.1
3	Referências
Pseudocódigo
//k é o maior valor do vetor A

//Criar vetor auxiliar com k+1 elementos e inicializar com zeros
for i ← 0 to k
    do C[i]←0
    
for j ← 1 to length[A]
    do C[A[j]] ← C[A[j]] + 1
//Agora C[i] contem o numero de elementos igual a i.

for i ← 1 to k
    do C[i] ← C[i] + C[i - 1]
//Agora C[i] contem o numero de elementos menor que ou igual a i.

for j ← length[A] downto 1
    do B[C[A[j]]] ← A[j]
        C[A[j]] ← C[A[j]] - 1
        
//Pseudocodigo do livro "Introduction to Algorithms" 
//de Thomas H. Cormen...[et al.] - 2nd ed.
//The MIT Press (p. 168)
Implementações
Cria cnt[M+1] e b[max N]
Inicializa todas as posições de cnt a 0.
Percorre o vector a e, para cada posição i de a faz cnt[a[i]-1]++ o que faz com que, no final, cada posição i de cnt contem o nº de vezes que a chave i-1 aparece em a.
Acumula em cada elemento de cnt o elemento somado ao elemento anterior: cnt[i] indica a posição ordenada do primeiro elemento de chave i.
Guarda em b os valores de a ordenados de acordo com b[cnt[a[i]++]=a[i]
Copia b para a.
Counting-Sort trabalha como uma contadora de ocorrências dentro de um programa, especificamente dentro de um vetor. Quando determinado vetor tem números repetidos, números únicos e números que não existem um outro vetor indica a quantidade de ocorrências.
Esta implementação tem a desvantagem de precisar de vectores auxiliares. O Counting Sort ordena exclusivamente números inteiros pelo fato de seus valores servirem como índices no vetor de contagem.

Características

Estável
Necessita de memória auxiliar. Logo, não é in-place
Complexidade linear
Código em C++
template<class T>
std::vector<T> counting_sort( const std::vector<T> &op )
{
   if ( op.empty() )
      return std::vector<T> {};

   auto min = *std::min_element( op.begin(), op.end() );
   auto max = *std::max_element( op.begin(), op.end() );

   std::vector<int> contagem( max - min + 1, 0 );
   for ( auto it = op.begin(); it != op.end(); ++it )
      ++contagem[ *it - min ];

   std::partial_sum( contagem.begin(), contagem.end(), contagem.begin() );

   std::vector<T> ordenado( op.size() );
   for ( auto it2 = op.rbegin(); it2 != op.rend(); ++it2 )
      ordenado[ --contagem[ *it2 - min ] ] = *it2;

   return ordenado;
}
Código em C
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# define MAX 100001

struct data
{
    int number;
    char key[100];
} DataBase[MAX], VectorSort[MAX];

int CounterNum[MAX];
int size = 0;

int main (void)
{
    int i = 0;

    while (scanf("%d%s", &DataBase[size].number, DataBase[size].key) >= 1)
        size++;

    int aux[2] = {0, 0};
    for (i = 0; i <= size; i++)
        aux[DataBase[i].number]++;

    aux[1] += aux[0];

    for (i = size - 1; i >= 0; i--)
        VectorSort[--aux[DataBase[i].number]] = DataBase[i];

    for (i = 0; i < size; i++)
        printf("Number: %d  ---  Key: %s\n", VectorSort[i].number, VectorSort[i].key);

    return 0;
}
Código em Java 1.0
public Integer[] CountingSort(Integer[] v) {
	
//encontra o maior valor em v[]	
	int maior = v[0];
	for (int i = 1; i < v.length; i++) {
		if (v[i] > maior) {
			maior = v[i];
		}
	}
		
//conta quantas vezes cada valor de v[] aparece
	int[] c = new int[maior+1];//+1 pois se 10 for o maior valor, ele iria apenas de 0 a 9
	for (int i = 0; i < v.length; i++) {
		c[v[i]] += 1;
	}
		
//acumula as vezes de cada elemento de v[] com os elementos anteriores a este
	for (int i = 1; i < c.length; i++) {
		c[i] += c[i-1];
	}
		
//adiciona os elementos em suas posições conforme o acumulo de suas frequencias
	Integer[] b = new Integer[v.length];
	for (int i = b.length-1; i >= 0; i--) {//percorre do fim para o inicio para manter estavel, mas não haveria problema em i = 0; i < b.lenght; i++
		b[c[v[i]] -1] = v[i];
		c[v[i]]--;
	}
	
	return b;
}
Código em Java 1.1
public void CountingSort(Integer[] array, int leftIndex, int rightIndex) {
		
		//Encontrar o maior valor 
		int k = 0;
		for(int m = leftIndex; m < rightIndex; m++){
			if(array[m] > k){
				k = array[m];
			}
		}
		
		//Cria vetor com o tamanho do maior elemento
		int[] vetorTemporario = new int[k];
		
		//Inicializar com zero o vetor temporario
		for(int i = 0; i < vetorTemporario.length; i++){
			vetorTemporario[i] = 0;
		}
		
		//Contagem das ocorrencias no vetor desordenado
		for(int j = leftIndex; j < rightIndex; j++){
			vetorTemporario[array[j]] += 1;
		}
		
		//Fazendo o  complemento do numero anterior 
		for(int i = leftIndex; i < k; i++){
			vetorTemporario[i] = vetorTemporario[i] + vetorTemporario[i - 1];
		}
		
		//Ordenando o array da direita para a esquerda
		int[] vetorAuxiliar = new int[array.length];
		for(int j = rightIndex; j > leftIndex; j--) {
			vetorAuxiliar[vetorTemporario[array[j]]] = array[j];
			vetorTemporario[array[j]] -= 1; 
		}
		
		//Retornando os valores ordenados para o vetor de entrada
		for (int i = leftIndex; i < rightIndex; i++){
			array[i] = vetorAuxiliar[i];
		}
	}
Referências
 Cormen, Thomas (2001). Introduction to Algorithms. London, England: MIT Press & McGraw-Hill. 168 páginas
 
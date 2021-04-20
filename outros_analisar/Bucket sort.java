/**
 * Métodos Eficientes
 * Os métodos eficientes são mais complexos nos detalhes, requerem um número menor de
 * comparações. São projetados para trabalhar com uma quantidade maior de dados e possuem
 * complexidade C(n) = O(n log n). Exemplos Quick sort, Merge sort, Shell sort, Heap sort,
 * Radix sort, Gnome sort, Count sort, Bucket sort, Cocktail sort, Timsort.
 * */
Bucket sort
Origem: Wikipédia, a enciclopédia livre.
Saltar para a navegaçãoSaltar para a pesquisa
Bucket sort
classe	Algoritmo de ordenação
estrutura de dados	Array, Listas ligadas
complexidade pior caso	{\displaystyle O(n^{2})}O(n^{2})
complexidade caso médio	{\displaystyle O(n+k)}{\displaystyle O(n+k)}
complexidade melhor caso	{\displaystyle O(n+k)}{\displaystyle O(n+k)}
Algoritmos
Esta caixa: verdiscutir

Conceito de base do bucket sort.
Bucket sort, ou bin sort, é um algoritmo de ordenação que funciona dividindo um vetor em um número finito de recipientes. Cada recipiente é então ordenado individualmente, seja usando um algoritmo de ordenação diferente, ou usando o algoritmo bucket sort recursivamente. O Bucket Sort tem complexidade linear {\displaystyle \Theta (n)}{\displaystyle \Theta (n)} quando o vetor a ser ordenado contém valores que são uniformemente distribuídos[1].


Índice
1	Funcionamento
2	Exemplo em C
3	Explicação do código
4	Exemplo em C++ com matriz
5	Exemplo em Java com LinkedList
6	Ver também
7	Referências
8	Ligações externas
Funcionamento
Bucket sort funciona do seguinte modo:

Inicialize um vetor de "baldes", inicialmente vazios.
Vá para o vetor original, incluindo cada elemento em um balde.
Ordene todos os baldes não vazios.
Coloque os elementos dos baldes que não estão vazios no vetor original.

Exemplo em Java com LinkedList
/*
* Autor: wilhs
* Data: 28/04/2011
* Crédito: Implementação com base neste Artigo.
*/

public static void BucketSort(int[] vetor, int maiorValor)
{
	int numBaldes = maiorValor/5;

	LinkedList[] B = new LinkedList[numBaldes];

	for (int i = 0; i < numBaldes; i++){
		B[i] = new LinkedList<Integer>();
	}

	//Coloca os valores no balde respectivo:
	for (int i = 0; i < vetor.length; i++) {
		int j = numBaldes-1;
		while (true){
			if(j<0){
				 break;
			}
			if(vetor[i] >= (j*5)){
				 B[j].add(vetor[i]);
				 break;
			}
			j--;
		}
	}

	//Ordena e atualiza o vetor:
	int indice = 0;
	for (int i = 0; i < numBaldes; i++){

		int[] aux = new int[B[i].size()];

		//Coloca cada balde num vetor:
		for (int j = 0; j < aux.length; j++){
				aux[j] = (Integer)B[i].get(j);
		}

		insertionSort(aux); //algoritmo escolhido para ordenação.

		// Devolve os valores ao vetor de entrada:
		for (int j = 0; j < aux.length; j++, indice++){
			vetor[indice] = aux[j];
		}

	}
}

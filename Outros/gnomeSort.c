/**
 * Mergesort
 * 
 * 
 * Criado em 1945 pelo matemático americano John Von Neumann o Mergesort é um exemplo de algoritmo de ordenação que faz uso da estratégia “dividir para conquistar” para resolver problemas. É um método estável e possui complexidade C(n) = O(n log n) para todos os casos.
 * 
 * Esse algoritmo divide o problema em pedaços menores, resolve cada pedaço e depois junta (merge) os resultados. O vetor será dividido em duas partes iguais, que serão cada uma divididas em duas partes, e assim até ficar um ou dois elementos cuja ordenação é trivial.
 * 
 * Para juntar as partes ordenadas os dois elementos de cada parte são separados e o menor deles é selecionado e retirado de sua parte. Em seguida os menores entre os restantes são comparados e assim se prossegue até juntar as partes.
 * 
 * Veja o vídeo para conhecer o passo a passo da execução do algoritmo:
 * 
 * https://www.youtube.com/watch?v=XaqR3G_NVoo&feature=youtu.be
 * 
 * */

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void selecao (int vet, int tam){
    int i, j, min, x;
    for (i=1; i=n-1; i++){
        min = i;
    for (j=i+1; j=n; j++){
            if (vet[j]  vet[min])
            min = j;
    }
    x = vet[min];
    vet[min] = vet[i];
    vet[i] = x;
    }
}

/**
 * Métodos Eficientes
 * Os métodos eficientes são mais complexos nos detalhes, requerem um número menor de
 * comparações. São projetados para trabalhar com uma quantidade maior de dados e possuem
 * complexidade C(n) = O(n log n). Exemplos Quick sort, Merge sort, Shell sort, Heap sort,
 * Radix sort, Gnome sort, Count sort, Bucket sort, Cocktail sort, Timsort.
 * */





Código em C
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>

# define MAX 100001

int VectorSort[MAX];
int size = 0;

void swap(int * ,int *);
void GnomeSort();

int main (void){
 while(scanf("%d",&VectorSort[size]),VectorSort[size] >= 1)
 size++;

 GnomeSort();

 return 0;
}

void swap(int *A, int *B){
 int C = *A;
* A = *B;
* B = C;
}

void GnomeSort(){
 int next = 0, previous = 0;
 int i = 0;

 for(i = 0; i < size ; i++) {
 if(VectorSort[i] > VectorSort[i + 1]) {
  previous = i;
  next = i + 1;
  while(VectorSort[previous] > VectorSort[next])  {
 swap(&VectorSort[previous],&VectorSort[next]);
 if(previous > 0)
    previous--;
 if(next > 0) 
    next--;
  }
 }
 }

 for(i = 0; i < size; i++) printf("%d\n",VectorSort[i]);
}
Código em C++ versão 1
template<class T>
void gnome_sort( std::vector<T> &lista )
{
  std::vector<T>::size_type i = 1;

  while( i < lista.size() )
  {
    if( i == 0 || lista.at( i-1 ) <= lista.at( i ) )
    {
      i++;
    }
    else
    {
      std::swap( lista[ i - 1 ], lista [ i ] );
      --i;
    }
  }
}
Código em C++ versão 2
template<class T>
void gnome_sort( std::vector<T> &lista )
{
  std::vector<T>::iterator elem = lista.begin()+1;

  while( elem != lista.end() )
  {
    if( elem == lista.begin() || *(elem-1) <= *elem )
    {
      ++elem;
    }
    else
    {
      std::iter_swap( elem-1, elem );
      --elem;
    }
  }
}
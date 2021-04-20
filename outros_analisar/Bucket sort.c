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
Exemplo em C
//Compilado em Linux.Sujeito a mudanças caso outro sistema seja utilizado.
 
 #include <stdio.h>
 
 #define tam_bucket 100
 #define num_bucket 10
 #define max 10
 
 typedef struct {
         int topo;
         int balde[tam_bucket];
 }bucket;
 
 void bucket_sort(int v[],int tam);                   //cabeçalho das funções
 void bubble(int v[],int tam);                                                 
                                                                  
 void bucket_sort(int v[],int tam){                                     
         bucket b[num_bucket];                                      
         int i,j,k;                                                 
 /* 1 */ for(i=0;i<num_bucket;i++)                    //inicializa todos os "topo"
                 b[i].topo=0;
         
 /* 2 */ for(i=0;i<tam;i++){                          //verifica em que balde o elemento deve ficar
                j=(num_bucket)-1;
                 while(1){
                         if(j<0)
                                 break;
                         if(v[i]>=j*10){
                                 b[j].balde[b[j].topo]=v[i];
                                 (b[j].topo)++;
                                 break;
                         }
                         j--;
                 }
         }
         
 /* 3 */ for(i=0;i<num_bucket;i++)                     //ordena os baldes
                 if(b[i].topo)
                         bubble(b[i].balde,b[i].topo);
         
         i=0;
 /* 4 */ for(j=0;j<num_bucket;j++){                    //põe os elementos dos baldes de volta no vetor
                 for(k=0;k<b[j].topo;k++){
                         v[i]=b[j].balde[k];
                         i++;
                 }
         }
 }
 
 void bubble(int v[],int tam){
         int i,j,temp,flag;
         if(tam)
                 for(j=0;j<tam-1;j++){
                         flag=0;
                         for(i=0;i<tam-1;i++){
                                 if(v[i+1]<v[i]){
                                         temp=v[i];
                                         v[i]=v[i+1];
                                         v[i+1]=temp;
                                         flag=1;
                                 }
                         }
                         if(!flag)
                                 break;
                 }
 }
// Explicação do código

Bucket sort - fase 1.

Bucket sort - fase 2.
Antes de mais nada, é preciso saber o que cada #define significa.
tam_bucket é o tamanho de cada balde da estrutura bucket;
num_bucket é o número de baldes, isto é, o tamanho do vetor de bucket;
max é o tamanho do vetor a ser ordenado.
A estrutura bucket consiste de um vetor de inteiros (int balde[tam_bucket]) e de uma variável que serve para dizer quantos números estão armazenados no balde.
O parâmetro tam, tanto na função bucket_sort como na bubble, é o tamanho do vetor a ser ordenado.
A explicação dos for agora:
Inicializa o topo de cada bucket que o vetor de bucket b[num_bucket] contém;
Isso é importante, pois, a princípio, os baldes estão vazios;
Verifica em que balde o elemento deve ficar;
Cada elemento do vetor a ser ordenado é colocado em seu lugar no vetor de bucket. Por exemplo, suponha o número 26. A variável j receberia num_bucket-1, isto é, 9 no exemplo acima. O while verifica se 26 é maior do que j*10 (90). Como isto não é válido, j é decrementado em 1, e o processo se repete até que j=2, já que 26>=20. Então, o balde de posição 2 recebe 26. Caso não haja nenhum outro elemento no balde 2, isso significa que topo daquele balde vale 0, portanto balde[0] recebe o 26. Caso haja, por exemplo, 3 elementos no balde, isso quer dizer que topo=2, portanto balde[2] recebe 26. Depois disso, topo daquele balde é incrementado em 1 e o processo se repete para os outros elementos do vetor que queremos ordenar;
Ordena cada balde;
Ordena os baldes cujos topos sejam diferentes de 0, ou seja, não estão vazios. No algoritmo acima, o bubble sort foi utilizado, mas métodos mais eficientes podem ser utilizados;
Por fim, os baldes são percorridos e seus elementos são devolvidos para o vetor original.
Atente-se para o fato de que o exemplo não ordena elementos negativos. Um tratamento especial para eles seria necessário. Além do mais, o método de separar cada elemento pode ser diferente. O utilizado foi verificar se o elemento está entre 0 e 10, 11 e 20, e assim por diante.

Exemplo em C++ com matriz
Aqui uma matriz linear de inteiros com n elementos, é usado para ordenar os elementos do vetor.

/*************************INICIO*****************************************/
//==================================================================
//
//   Projeto: Bucket Sort
//   Data de Criacao: 27/02/09
//   Autor: Albany Timbo Mesquita
//   Colaboracao:Pedro Henrique Fernandes Marques Leitao         
//
//==================================================================

#include <iostream>
#define TAM 20 /*Tamanho do vetor*/
#define NUM 10000 /*base para gerador de numeros aleatorios*/

using std::cout;
using std::cin;
using std::endl;

void gerarVet(int*);
void bucketSort(int*);
void imprimaVet(int*);

int main(){
    int vet[TAM],tinicio,tfim,tempo;
   
   tinicio=time(NULL);
   
   gerarVet(vet);
   imprimaVet(vet);
   bucketSort(vet);   
   imprimaVet(vet);
        
   tfim=time(NULL);
   tempo=difftime(tfim,tinicio);
   cout<<"Tempo de execucao "<<tempo/60<<" Minutos e "<<tempo%60<<" segundos.\n";
    system("pause");
    return 0;
    
    }
/***********************************************************************/
/*******************************FUNCOES*********************************/
/***********************************************************************/
void bucketSort(int *vet){
    int mat[10][TAM],aux[TAM],cont=1,num,w=0,i,j; 
    

    do{
      for(i=0;i<TAM;i++){aux[i] = 0;}//Zerando o vetor auxiliar.
      for(i=0;i<10;i++)  {//Setando a Matriz com valores -1
	          for(j=0;j<TAM;j++){
              mat[i][j] = -1;
              }
      }
      for (i=0;i<TAM;i++) {
    	  num = (vet[i]/cont)%10;//verificando o valor da esquerda para direita
    	  mat[num][aux[num]] = vet[i];//colocando o valor na sua posicao na matriz
    	  aux[num]++; //contador de colunas da matriz
      }
      
      for(i=0;i<10;i++) {//volta com os valores da Matriz para o vetor
       	  for(j=0;j<TAM;j++){
     	      if(mat[i][j] != -1){
     	      vet[w] = mat[i][j];
     	      w++;
    	      }
          }
      }
      w = 0; 
      cont=cont*10;
      }while(aux[0] < TAM);//condicao :Enquanto vetor auxiliar < tamanho vetor
}                          //         

/******************GERADOR DE NUMEROS ALEATORIOS**************************/
void gerarVet(int *vet){
     
     srand(time(NULL));
     for (int i=0;i<TAM;i++){
         vet[i]=rand()%NUM;
         }
     }
/*******************FUNCAO PARA IMPRIMIR VETOR************************/
void imprimaVet(int *vet){
     for (int i=0;i<TAM;i++){
         cout<<vet[i]<<"|";
         }
     cout<<"**************************************************************\n";     
     }
/********************************FIM*************************************/
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
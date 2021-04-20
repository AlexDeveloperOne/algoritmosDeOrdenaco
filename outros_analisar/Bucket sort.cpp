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

//Exemplo em C++ com matriz
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


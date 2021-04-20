/**
 * Métodos Eficientes
 * Os métodos eficientes são mais complexos nos detalhes, requerem um número menor de
 * comparações. São projetados para trabalhar com uma quantidade maior de dados e possuem
 * complexidade C(n) = O(n log n). Exemplos Quick sort, Merge sort, Shell sort, Heap sort,
 * Radix sort, Gnome sort, Count sort, Bucket sort, Cocktail sort, Timsort.
 * */

Gnome sort
Origem: Wikipédia, a enciclopédia livre.
Saltar para a navegaçãoSaltar para a pesquisa
Algoritmo similiar ao Insertion sort com a diferença que o Gnome sort leva um elemento para sua posição correta, com uma seqüencia grande de trocas assim como o Bubble sort

O algoritmo percorre o vetor comparando seus elementos dois a dois, assim que ele encontra um elemento que está na posição incorreta, ou seja, um número maior antes de um menor, ele troca a posição dos elementos, e volta com este elemento até que encontre o seu respectivo lugar.

Características

Complexidade de tempo: Θ(n²)


Índice
1	Implementações
1.1	Código em Python
1.2	Código em C
1.3	Código em C++ versão 1
1.4	Código em C++ versão 2
1.5	Código em Java
1.6	Código em Java
1.7	Código em C#
Implementações
Código em Python
# coding: utf-8

def gnome(lista):
  pivot = 0
  lista_length = len(lista) 
  while pivot < lista_length - 1:
    if lista[pivot] > lista[pivot + 1]:
      lista[pivot + 1], lista[pivot] = lista[pivot], lista[pivot + 1]
      if pivot > 0:
        pivot -= 2
    pivot += 1

# Paulo Sérgio dos Santos Araujo
# Bacharelando em Ciência da Computação - Ufcg
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
Código em Java
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;

/**
* Implementa e executa o algoritmo Gnome Sort
*
* @author Dielson Sales, Marcos Paulo J. Melo Silva
*/
public class GnomeSort<E extends Comparable<? super E>> {

    /**
* Ordena uma coleção de dados comparáveis usando o Gnome Sort.
* @param vector uma lista de dados comparáveis
* @return uma lista com os dados ordenados
*/
    public Collection<E> sort(Collection<E> vector) {

        int i = 1;
        List<E> result = new ArrayList<E>(vector);

        while (i < result.size()) {

            if (i == 0 || result.get(i - 1).compareTo(result.get(i))<= 0) {
                i++;
            } else {
                E temp = result.get(i - 1);

                result.set(i - 1, result.get(i));

                result.set(i, temp);
                i--;
            }
        }

        return result;
    }

    /**
* Execução do algoritmo de ordenação Gnome Sort.
*/
    public static void main(String[] args) {

        GnomeSort<Integer> gnomeSort = new GnomeSort<Integer>();

        final int size = 50;

        final Random random = new Random();

        List<Integer> list = new ArrayList<Integer>(size);

        for (int i = 0; i < size; i++) {
            list.add(random.nextInt());
        }

        // Lista com os dados já ordenados.
        Set<Integer> sortedList = new HashSet<Integer>(gnomeSort.sort(list));
    }
}

/**
* Exemplo de código em Java
* Autores: Marcos Paulo J. de Melo Silva e Dielson Sales de Carvalho;
* Instituição: Universidade Federal de Alagoas (UFAL);
*/
Código em Java
/*
* Autor: Felipe da Silva Travassos
* Graduando em Ciência da Computação - UFCG
*/
public static Integer[] gnomeSort(Integer[] array){
  int pivout = 0;
  int aux;
  while(pivout<(array.length-1)){
    if(array[pivout]>array[pivout+1]){
      aux = array[pivout];
      array[pivout] = array[pivout+1];
      array[pivout+1] = aux;
      if(pivout>0){
        pivout-=2;
      }
    }
    pivout++;
  }
  return array;
}
Código em C#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace gnome_sort
{
    class Program
    {
        static void Main(string[] args)
        {
            int men = 1;
            int[] vetor = new int[19];
            Random r = new Random(50);
            while (men != 0)
            {
                Menu();
                ImprimeVetor(vetor);
                Console.WriteLine();
                Console.WriteLine("Opcao:");
                men = int.Parse(Console.ReadLine());
                CaseMenu(men, vetor, r);
                Console.Clear();
            }
        }
        /* Case do Menu */
        private static void CaseMenu(int men, int[] vetor, Random r)
        {
            switch (men)
            {
                case 1: NovoVetor(vetor, r);
                    break;
                case 2: GnomeSort(vetor);
                    break;
                case 0: break;
                default: Console.WriteLine("INVALIDO! Digite 1 ou 2");
                    break;
            }
        }
        /* Imprime o Vetor */
        private static void ImprimeVetor(int[] vetor)
        {
            foreach (var item in vetor)
            {
                Console.Write(item);
                Console.Write(" ");
            }
        }

        /* Gera os os números aleatórios no vetor */
        private static void NovoVetor(int[] vetor, Random r)
        {
            for (int i = 0; i < vetor.Length; i++)
            {
                vetor[i] = r.Next(1, 100);
            }
        }

        /* Menu do programa */
        static void Menu()
        {
            Console.WriteLine("***************** MENU *******************");
            Console.WriteLine("                                          ");
            Console.WriteLine("1 - Gerar um conjunto de números aleatório");
            Console.WriteLine("2 - Utilizar o algoritmo para a ordenação ");
            Console.WriteLine("                                          ");
            Console.WriteLine("0 - Sair                                  ");
            Console.WriteLine("******************************************");
        }

        /* Algoritmo de Ordenação */
        static void GnomeSort( int[] array )
        {
            for ( int i = 1, temp_value; i < array.Length; )
            {
                if ( array[i-1] <= array[i] )
                i += 1;
                else
                {
                    temp_value = array[i-1];
                    array[i-1] = array[i];
                    array[i] = temp_value;
                    i -= 1;
                    if ( i == 0 )
                    i = 1;
                }
                Console.Clear();
                Console.WriteLine("Ordenando...");
                ImprimeVetor(array);
                System.Threading.Thread.Sleep(10);
            }
        }
    }
}

Código de um programa em C#. Gera números aleatórios e ordena com o Gnome Sort
Autor: Marcos Latchuk
Universidade: UNICENTRO      Guarapuava - Pr

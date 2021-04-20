/**
 * Métodos Eficientes
 * Os métodos eficientes são mais complexos nos detalhes, requerem um número menor de
 * comparações. São projetados para trabalhar com uma quantidade maior de dados e possuem
 * complexidade C(n) = O(n log n). Exemplos Quick sort, Merge sort, Shell sort, Heap sort,
 * Radix sort, Gnome sort, Count sort, Bucket sort, Cocktail sort, Timsort.
 * */

Cocktail sort
Origem: Wikipédia, a enciclopédia livre.
Saltar para a navegaçãoSaltar para a pesquisa
Cocktail sort

Visualização do Cocktail sort
classe	Algoritmo de ordenação
estrutura de dados	Array, Listas ligadas
complexidade pior caso	{\displaystyle {O}(n^{2})}{\displaystyle {O}(n^{2})}
complexidade caso médio	{\displaystyle {O}(n^{2})}{\displaystyle {O}(n^{2})}
complexidade melhor caso	{\displaystyle {O}(n)}{\displaystyle {O}(n)}
otimo	Não
estabilidade	não-estável
Algoritmos
Esta caixa: verdiscutir
Cocktail shaker sort,[1] também conhecido como bubble sort bidirecional,[2] cocktail sort, shaker sort (o qual também pode se referir a uma variação do insertion sort), ripple sort, shuffle sort,[3] ou shuttle sort, é uma variante do bubble sort, que é um algoritmo com não-estável e efetua Ordenação por comparação. O algoritmo difere de um bubble sort no qual ordena em ambas as direções a cada iteração sobre a lista. Esse algoritmo de ordenação é levemente mais difícil de implementar que o bubble sort, e e resolve o problema com os chamados coelhos e tartarugas no bubble sort. Ele possui performance levemente superior ao bubble sort, mas não melhora a performance assintótica; assim como o bubble sort, não é muito usado na prática (insertion sort é escolhido para ordenação simples), embora seja usado para fins didáticos.


Índice
1	Complexidade
2	Implementações
2.1	Código em C
2.2	Código em C# e Java (sintaxe idêntica)
2.3	Código em Pascal
2.4	Código em Ruby
2.5	Código em Python
3	Referências
Complexidade
A complexidade do Cocktail shaker sort em notação big-O é {\displaystyle O(n^{2})}O(n^{2}) para o pior caso e caso médio, mas tende a se aproximar de {\displaystyle O(n)}O(n) se a lista se encontra parcialmente ordenada antes da execução do algoritmo. Por exemplo, se cada elemento se encontra em uma posição cuja distância até sua posição ordenada é k (k ≥ 1), a complexidade do algoritmo se torna {\displaystyle O(kn)}{\displaystyle O(kn)}.

{\displaystyle 1+1+1+1+n(1+n(1(1+1+1+1))+1+n(1(1+1+1+1))+1)}1+1+1+1+n(1+n(1(1+1+1+1))+1+n(1(1+1+1+1))+1)
{\displaystyle 4+n(3+4n+4n)}4+n(3+4n+4n)
{\displaystyle 4+n(3+8n)}4+n(3+8n)
{\displaystyle n(n)}n(n)
O(n²)

Implementações
Código em C
 void cocktail_sort(int list[10]) {
    int length,bottom,top, swapped,i,aux;
    length=10;
    bottom = 0;
    top = length - 1;
    swapped = 0; 
    while(swapped == 0 && bottom < top)//Se não houver troca de posições ou o ponteiro que
    {                                   //sobe ultrapassar o que desce, o vetor esta ordenado
        swapped = 1; 
        //Este for é a “ida” para a direita
        for(i = bottom; i < top; i = i + 1)
        {
            if(list[i] > list[i + 1])   //indo pra direita:testa se o próximo é maior
            {   //indo pra direita:se o proximo é maior que o atual,
                //troca as posições
                aux=list[i];
                list[i]=list[i+1];
                list[i+1]=aux;
                swapped = 0;
            }
        }//fecha for
        // diminui o  `top` porque o elemento com o maior valor 
        // já está na direita (atual posição top)
        top = top - 1; 
        //Este for é a “ida” para a esquerda
        for(i = top; i > bottom; i = i - 1)
        {  if(list[i] < list[i - 1]) 
            {
                aux=list[i];
                list[i]=list[i-1];
                list[i-1]=aux;
                swapped = 0;
            }
        }
        //aumenta o `bottom` porque o menor valor já está
        //na posição inicial (bottom) 
        bottom = bottom + 1;  
    }//fecha while 
 }// fim da funçao
Código em C# e Java (sintaxe idêntica)
        
private static void cocktail(int[] vetor)
{
    int tamanho, inicio, fim, swap, aux;
    tamanho = 10; // para um vetor de 20 elementos
    inicio = 0;
    fim = tamanho - 1;
    swap = 0;
    while (swap == 0 && inicio < fim)
    {
        swap = 1;
        for (int i = inicio; i < fim; i = i + 1)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                swap = 0;
            }
        }
        fim = fim - 1;
        for (int i = fim; i > inicio; i = i - 1)
        {
            if (vetor[i] < vetor[i - 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i - 1];
                vetor[i - 1] = aux;
                swap = 0;
            }
        }
        inicio = inicio + 1;
    }
}
Código em Pascal
   
procedure ShakerSort(var A:vetor; n:integer);

var L,R,k,i:integer;

begin
    L:=2;
    R:=n;
    k:=2;
    repeat
        for i:=L to R do
        begin
            if A[i-1]>A[i] then
            begin
                aux := A[i-1];
                A[i-1] := A[i];
                A[i]:= aux;         
                k:=i;
            end;
        end;
        R:=k-1;

        for i:=R downto L do
        begin
            if A[i-1]>A[i] then
            begin
                aux := A[i-1];
                A[i-1] := A[i];
                A[i]:= aux;         
                k:=i;
            end;
        end;
        L:=k+1;
    until L>R;
end;
Código em Ruby
def sort(array)
	swap = true
	begining = 0
	ending = array.length-1
	while(swap)
		swap = false
		begining.upto ending-1 do |i|
			if(array[i] > array[i+1])
				aux = array[i]
				array[i] = array[i+1]
				array[i+1] = aux
				swap = true
			end
		end
		ending -= 1
		ending.downto begining+1 do |i|
			if(array[i] < array[i-1])
				aux = array[i]
				array[i] = array[i-1]
				array[i-1] = aux
				swap = true
			end
		end
		begining += 1
	end
	return array
end
Código em Python
#coding: utf-8

def cocktailSort(lista):
	
	nova_lista = []
	for j in range(len(lista)):
		for i in range(len(lista)-1):
			if lista[len(lista)-1 - i] < lista[len(lista)-2 - i]:
				lista[len(lista)-1-i],lista[len(lista)-2-i] = lista[len(lista)-2-i],lista[len(lista)-1-i]
			if lista[i] > lista[i+1]:
				lista[i],lista[i+1] = lista[i+1],lista[i]
	return lista
		
print cocktailSort([3, 4, 2, 0, 5, 6, 7,1])


Referências
 Knuth, Donald E. (1973). «Sorting by Exchanging». Art of Computer Programming. 3. Sorting and Searching 1st ed. [S.l.]: Addison-Wesley. pp. 110–111. ISBN 0-201-03803-X
 Black, Paul E.; Bockholt, Bob (24 de agosto de 2009). «bidirectional bubble sort». In: Black, Paul E. Dictionary of Algorithms and Data Structures. [S.l.]: National Institute of Standards and Technology. Consultado em 5 fevereiro de 2010
 Duhl, Martin (1986). «Die schrittweise Entwicklung und Beschreibung einer Shuffle-Sort-Array Schaltung». HYPERKARL aus der Algorithmischen Darstellung des BUBBLE-SORT-ALGORITHMUS. Projektarbeit (em German). [S.l.]: Technical University of Kaiserslautern

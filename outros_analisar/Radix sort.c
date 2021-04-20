/**
 * Métodos Eficientes
 * Os métodos eficientes são mais complexos nos detalhes, requerem um número menor de
 * comparações. São projetados para trabalhar com uma quantidade maior de dados e possuem
 * complexidade C(n) = O(n log n). Exemplos Quick sort, Merge sort, Shell sort, Heap sort,
 * Radix sort, Gnome sort, Count sort, Bucket sort, Cocktail sort, Timsort.
 * */
Radix sort
Origem: Wikipédia, a enciclopédia livre.
Saltar para a navegaçãoSaltar para a pesquisa

Este artigo ou secção não cita fontes confiáveis e independentes. Ajude a inserir referências.
O conteúdo não verificável pode ser removido.—Encontre fontes: Google (notícias, livros e acadêmico) (Julho de 2015)
Radix sort
classe	Algoritmo de ordenação
estrutura de dados	Array, Listas ligadas
complexidade pior caso	{\displaystyle \Theta (nk)}{\displaystyle \Theta (nk)}
complexidade de espaços pior caso	{\displaystyle \Theta (n+s)}{\displaystyle \Theta (n+s)}
otimo	exatamente correto
estabilidade	estável
Algoritmos
Esta caixa: verdiscutir
O Radix sort é um algoritmo de ordenação rápido e estável que pode ser usado para ordenar itens que estão identificados por chaves únicas. Cada chave é uma cadeia de caracteres ou número, e o radix sort ordena estas chaves em qualquer ordem relacionada com a lexicografia.

Na ciência da computação, radix sort é um algoritmo de ordenação que ordena inteiros processando dígitos individuais. Como os inteiros podem representar strings compostas de caracteres (como nomes ou datas) e pontos flutuantes especialmente formatados, radix sort não é limitado somente a inteiros.


Índice
1	Funcionamento do algoritmo
2	Complexidade assintótica
3	Implementações
3.1	Código em MATLAB
3.2	Código em C
3.3	Código em C#
3.4	Código em Java [1]
3.5	Código em Java [2]
3.6	Código em Python
3.7	Código em PHP
4	Ver também
5	Ligações externas
Funcionamento do algoritmo
Computadores, na sua maioria, representam internamente todos os tipo de dados como números binários, por isso processar os dígitos na forma de inteiros em grupos representados por dígitos binários se torna mais conveniente. Existem duas classificações do radix sort, que são:

Least significant digit (LSD – Dígito menos significativo) radix sort;
Most significant digit (MSD – Dígito mais significativo) radix sort.
O radix sort LSD começa do dígito menos significativo até o mais significativo, ordenando tipicamente da seguinte forma: chaves curtas vem antes de chaves longas, e chaves de mesmo tamanho são ordenadas lexicograficamente. Isso coincide com a ordem normal de representação dos inteiros, como a sequência "1, 2, 3, 4, 5, 6, 7, 8, 9, 10". Os valores processados pelo algoritmo de ordenação são frequentemente chamados de “chaves”, que podem existir por si próprias ou associadas a outros dados. As chaves podem ser strings de caracteres ou números.

Já o radix sort MSD trabalha no sentido contrário, usando sempre a ordem lexicográfica, que é adequada para ordenação de strings, como palavras, ou representações de inteiros com tamanho fixo. A seqüência "b, c, d, e, f, g, h, i, j, ba" será ordenada lexicograficamente como "b, ba, c, d, e, f, g, h, i, j". Se essa ordenação for usada para ordenar representações de inteiros com tamanho variável, então a representação dos números inteiros de 1 a 10 terá a saída "1, 10, 2, 3, 4, 5, 6, 7, 8, 9".

O radix sort LSD opera na notação Big-O, em {\displaystyle O(nk)}{\displaystyle O(nk)}, onde {\displaystyle n}n é o número de chaves, e {\displaystyle k}k é o comprimento médio da chave. É possível garantir esse desempenho para chaves com comprimento variável agrupando todas as chaves que tem o mesmo comprimento e ordenando separadamente cada grupo de chaves, do mais curto para o mais comprido, de modo a evitar o processamento de uma lista inteira de chaves em cada passo da ordenação.

Em muitas aplicações em que é necessário velocidade, o radix sort melhora as ordenações por comparação, como heapsort e o mergesort, que necessitam de {\displaystyle \Omega (n\log n)}{\displaystyle \Omega (n\log n)} comparações, onde {\displaystyle n}n é o número de itens a serem ordenados. Em compensação, algoritmos de ordenação baseados em comparações oferecem flexibilidade por serem aptos a ordenar de outras formas que não a lexicográfica. No entanto, essa habilidade é de pouca importância em várias aplicações práticas.

O algoritmo de ordenação radix sort foi originalmente usado para ordenar cartões perfurados. Um algoritmo computacional para o radix sort foi inventado em 1954 no MIT por Harold H. Seward.

Complexidade assintótica
A complexidade no tempo do algoritmo é {\displaystyle \Theta (nk)}{\displaystyle \Theta (nk)}e a complexidade no espaço: {\displaystyle \Theta (n+s)}{\displaystyle \Theta (n+s)}, onde

{\displaystyle n}n = número de elementos.
{\displaystyle k}k = tamanho string.
{\displaystyle s}s = tamanho do alfabeto.
Implementações
Código em MATLAB
function  vetor = radixsort(vetor, tamanho)
	%
	% Ordena vetor de inteiros, exemplo:
	%	tamanho = 10000;
	%	vetor = floor(10000*rand(tamanho,1));
	%	vetor = radixsort(vetor, tamanho);
	%
	ep = 1;
	maior = max(vetor);
	
	while floor(maior/ep) > 0
		V = sortrows([mod(floor(vetor/ep), 10), (1:tamanho)']);
		vetor = vetor(V(:,2));
		ep = ep*10;
	end
end
Código em C
void radixsort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}
Código em C#
static void RadixSort(int[] vetor) {
	int i;
	int[] b;
	int maior = vetor[0];
	int exp = 1;

	b = new int[vetor.Length];

	for (i = 0; i < vetor.Length; i++) {
		if (vetor[i] > maior)
			maior = vetor[i];
	}

	while (maior/exp > 0) {
		int[] bucket = new int[10];
		for (i = 0; i < vetor.Length; i++)
			bucket[(vetor[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = vetor.Length - 1; i >= 0; i--)
			b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
		for (i = 0; i < vetor.Length; i++)
			vetor[i] = b[i];
		exp *= 10;
	}
}
Código em Java [1]
import java.util.*;

public class TestRadix {
    private static final int MAX_CHARS = 28;
	
    private static void radixSort(String[] v) {
		Queue<String> queues[] = createQueues();
		for (int pos = maxSize(v) - 1; pos >= 0; pos--) {
			for (int i = 0; i < v.length; i++) {
				int q = queueNo(v[i], pos);
				queues[q].add(v[i]);
			}
			restore(queues, v);
		}
	}

	private static void restore(Queue<String>[] qs, String[] v) {
		int contv = 0;
		for (int q = 0; q < qs.length; q++)
			while (qs[q].size() > 0)
				v[contv++] = qs[q].remove();
	}

	private static Queue<String>[] createQueues() {
		LinkedList<String>[] result = new LinkedList[MAX_CHARS];
		for (int i = 0; i < MAX_CHARS; i++) {
			result[i] = new LinkedList<String>();
		}
		return result;
	}

	private static int queueNo(String string, int pos) {
		if (pos >= string.length()) {
			return 0;
		}
		char ch = string.charAt(pos);
		if ((ch >= 'A') && (ch <= 'Z')) {
			return (ch - 'A' + 1);
		}
		else if (ch >= 'a' && ch <= 'z') {
			return ch - 'a' + 1;
		}
		else {
			return 27;
		}
	}

	private static int maxSize(String[] v) {
		int maxValue = v[0].length();

		for (int i = 1; i < v.length; i++) {
			if (maxValue < v[i].length()) {
				maxValue = v[i].length();
			}
		}
		return maxValue;
	}

	public static void printStringArray(String[] arrToPrint) {
		for (int i = 0; i < arrToPrint.length; i++) {
			System.out.print(arrToPrint[i]+" ");
		}
		System.out.println();
	}
	
	/**
	 * @param args Array of strings (set of words) to be sorted (ordered) - Must be passed as parameters
	 */
	public static void main(String[] args) {
		System.out.print("Input: ");
		printStringArray(args);
		radixSort(args);
		System.out.print("\nOutput: ");
		printStringArray(args);
	}

}
Código em Java [2]
	public void radixSort(int vector[]){
		for(int digit = 0; digit < 3; digit ++){
			int power = (int) Math.pow(10, digit+1);
			
			int z[][] = new int[vector.length][10];
			int n[] = new int[10];

			for(int i = 0; i < vector.length; i ++){
				int num = vector[i];
				z[n[(num%power)/(power/10)]][(num%power)/(power/10)] = num;
				n[(num%power)/(power/10)]++;
				
			}
			int c = 0;
			for(int i = 0; i < 10; i ++){
				
				for(int j = 0; j < vector.length; j ++){
					if(j < n[i]){
						vector[c] = z[j][i];
						c++;
					}else{break;}
				}
			}
			
		}
	}
Código em Python
MAX_CHARS = 28

def radix_sort(lista):
        tamanho_maximo = max([len(palavra) for palavra in lista])

        for pos in range(tamanho_maximo*1, 1, -1):
                baldes = [list() for y in range(MAX_CHARS)]
                for palavra in lista:
                        balde = numero_do_balde(palavra, pos)
                        baldes[balde] += [palavra]
                lista = sum(baldes, [])

        return lista

def numero_do_balde(palavra, pos):
        if (pos >= len(palavra)): return 0
        ch = palavra[pos]
        if (ch >= 'A' and ch <= 'Z'): return ord(ch) - ord('A') + 1
        if (ch >= 'a' and ch <= 'z'): return ord(ch) - ord('a') + 1
        return MAX_CHARS-1
Código em PHP
function radix_sort (&$a, $n)
{
    $r = 8;
    $R = 256;
    $p = 4;
    $count = null;

    for ($i = 0; $i < $p; ++$i)
    {
        for ($j = 0; $j < $R; ++$j)
            $count[$j] = 0;
        for ($k = 0; $k < $n; ++$k)
        {
            $pos = ($a[$k] >> (r * $i)) & ($R - 1);
            $count[pos] += 1;
            $tempArray[$k] = $a[$k];
        }
        $pos = 0;
        for ($j = 0; $j < $R; ++$j)
        {
            $tmp = $pos;
            $pos += $count[$j];
            $count[$j] = $tmp;
        }
        for ($k = 0; $k < $n; ++$k)
        {
            $pos = (tempArray[$k] >> ($r * $j)) & ($R - 2);
            $a[$count[$pos]] = $tempArray[$k];
            $count[$pos] += 1;
        }
    }
}

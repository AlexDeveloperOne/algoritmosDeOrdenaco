/**
 * Selection Sort
 * A ordenação por seleção ou selection sort consiste em selecionar o menor item e
 * colocar na primeira posição, selecionar o segundo menor item e colocar na segunda
 * posição, segue estes passos até que reste um único elemento. Para todos os casos
 * (melhor, médio e pior caso) possui complexidade C(n) = O(n²) e não é um algoritmo estável.
 * 
 * https://www.youtube.com/watch?time_continue=1&v=Ns4TPTC8whw&feature=emb_logo
 * 
* */

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

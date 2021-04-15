/**
 * Insertion Sort
 * Insertion Sort ou ordenação por inserção é o método que percorre um vetor de elementos da esquerda para a direita e à medida que avança vai ordenando os elementos à esquerda. Possui complexidade C(n) = O(n) no melhor caso e C(n) = O(n²) no caso médio e pior caso. É considerado um método de ordenação estável.
 * 
 * Um método de ordenação é estável se a ordem relativa dos itens iguais não se altera durante a ordenação.
 * 
 * O funcionamento do algoritmo é bem simples: consiste em cada passo a partir do segundo elemento selecionar o próximo item da sequência e colocá-lo no local apropriado de acordo com o critério de ordenação.
 * 
 * Vejamos a implementação:
 * */

void insercao (int vet, int tam){
int i, j, x;
for (i=2; i<=tam; i++){
    x = vet[i];
    j=i-1;
    vet[0] = x; 
    while (x < vet[j]){
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = x;
}

/*
 *
 * Para compreender melhor o funcionamento do algoritmo veja este vídeo:
 * https://www.youtube.com/watch?v=ROalU379l3U&feature=youtu.be
 * 

#include <iostream>
using namespace std;

//Ordena??o de array - Insertion Sort;

int main(int argc, char** argv){
	
	double notas[10] = {9, 9.7, 5, 0, 10, 5.5, 8.2, 7.3, 7.2, 7.1};
	double aux;
	
	////////////// INSERTION SORT //////////////
	for(int i=0; i<9 ; i++){
		for(int j=i+1 ; j>0 ; j--){
			if(notas[j] < notas[j-1]){
				aux = notas[j];
				notas[j] = notas[j-1];
				notas[j-1] = aux;
			}
		}
	}
	////////////////////////////////////////
	
	for(int i=0 ; i<10 ; i++){
		cout << notas[i] << " | ";
	}
	cout << endl;

	return 0;
}

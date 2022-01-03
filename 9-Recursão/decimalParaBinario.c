#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* binario(int numero, int* vet){
	static int aux = 0;
	aux +=1;
	vet[0]=aux;
    if(numero/2 == 0){
    	vet = realloc(vet,sizeof(int)*(aux+1));
        vet[aux] = numero %  2;
        return vet;
    }else{
    	vet = realloc(vet,sizeof(int)*(aux+1));
    	vet[aux] = numero %  2;
    	binario(numero/2, vet);
    }

}

int main(){
	int n, *vet;
	vet = malloc(sizeof(int));
	scanf("%d", &n);
	int *numeros = binario(n, vet);
	for (int i = numeros[0]; i >=1 ; --i){
		printf("%d", numeros[i]);
	}
	return 0;
}
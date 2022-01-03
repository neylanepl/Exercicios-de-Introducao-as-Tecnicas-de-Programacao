#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* fromJsonString_int(char* string, int* tam){
	int *vetor_numeros;
	char *numero ;
	*tam=0;

	vetor_numeros = malloc(sizeof(int) * 100);

	numero = strtok(string, "[ ,");

	while(numero != NULL){
		sscanf(numero, "%d", &vetor_numeros[*tam]);
		(*tam)++;
		numero = strtok(NULL, " ,");
	}
	
	return vetor_numeros;
	
}

double* fromJsonString_double(char* string, int* tam){
	double *vetor_numeros;
	char *numero ;
	*tam=0;

	vetor_numeros = malloc(sizeof(int) * 100);

	numero = strtok(string, "[ ,");

	while(numero != NULL){
		sscanf(numero, "%lf", &vetor_numeros[*tam]);
		(*tam)++;
		numero = strtok(NULL, " ,");
	}
	
	return vetor_numeros;
}



int main()
{	
	char entrada[202];
	int n, tamanho, max, decimal;

	scanf(" %d\n", &n);

	for (int i = 0; i < n; ++i){

		fgets(entrada, 200, stdin);
		max=(int)strlen(entrada);
		max--;

		decimal=0;
		for (int j = 0; j < max; ++j){

			if (entrada[j]=='[' && entrada[j+1]==']'){
				printf("vetor vazio\n");
				decimal=-1;
				break;
			}

			if (entrada[j]=='.'){
				decimal=1;
				break;
			}
		}

		if (decimal==1){	
			double *nuremos_deci = fromJsonString_double(entrada, &tamanho);
			for (int i = 0; i < tamanho; ++i){
				printf("%.6lf ", nuremos_deci[i]);
			}
				printf("\n");
			

		}else if (decimal==0){
			int *numeros = fromJsonString_int(entrada, &tamanho);
			for (int k = 0; k < tamanho; ++k){
				printf("%d ", numeros[k]);
			}
			printf("\n");
		}
	}

	return 0;
}
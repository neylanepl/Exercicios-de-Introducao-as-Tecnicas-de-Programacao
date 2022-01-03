#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
@brief gera um número aleatório no intervalo [min,max]
@param min o número minimo no range
@param max o número máximo no range
@return um número aleatório no intervalo [min,max]
*/
int rand_int_range(int min, int max){
   int range = max - min + 1;
   return min + rand()%range;
}

int* criarVetorAleatorio(int tam, int min, int max){
	int *vetor_numeros;
	int numero;

	vetor_numeros = malloc(sizeof(int)* (tam+3));

	vetor_numeros[0]=tam;
	vetor_numeros[1]=min;
	vetor_numeros[2]=max;
	for (int i = 3; i < (tam+3); ++i){
		vetor_numeros[i] = rand_int_range(min,max);
	}
	/*for (int i = 0; i < tam; ++i)
	{
		printf("%d\n", vetor_numeros[i]);
	}*/
	return vetor_numeros;
}

int* criarHistograma(int *valores){
	int tam_vetor, min, max, tam;
	int *histo;

	tam = valores[0];
	min = valores[1];
	max = valores[2];
	tam_vetor=(valores[2]-valores[1])+1;

	histo = malloc(sizeof(int)* (tam_vetor+2));
	histo[0] = min;
	histo[1]= max;

	for (int i = 3; i < (tam+3); ++i)
	{
		for (int j = 0; j < tam_vetor; ++j)
		{	
			if ((j+min)==valores[i])
			{	//printf("%d %d\n", valores[i], j);
				histo[j+2]=histo[j+2]+1;
			}
		}
		
	}

	/*for (int i = 0; i < tam_vetor+2; ++i)
	{
		printf("%d\n", histo[i]);
	}*/
	return histo;
}


float* criarPorcentagens(int *histograma){
	float *porcentagen, total=0;
	int tam_vetor;

	tam_vetor=(histograma[1]-histograma[0])+1;

	porcentagen = malloc(sizeof(float)* (tam_vetor+2));

	for (int i = 2; i < tam_vetor+2; ++i)
	{	
		total= total + histograma[i];
	}

	for (int j = 0; j < tam_vetor; ++j){
		porcentagen[j]= ((histograma[2+j]/total)*100);
		//printf("%f\n", porcentagen[j]);
	}

	/*for (int i = 0; i < tam_vetor+2; ++i)
	{
		printf("%f\n", porcentagen[i]);
	}*/

	return porcentagen;
}

void imprimePorcentagens(float *porcentagen, int *histograma){
	int tam_vetor, aux=0;


	tam_vetor=(histograma[1]-histograma[0])+1;

	int sequencia[tam_vetor];
	for (int i = histograma[0]; i < histograma[1]+1; ++i)
	{	
		sequencia[aux]= i;
		aux++;
	}
	printf("Valor |Qtdade |Porcent\n");
	for (int i = 0; i < tam_vetor; ++i)
	{
		printf("%d|%d|%.2f%%\n", sequencia[i],histograma[2+i], porcentagen[i]);
	}

}

void liberar(int *valores,float *porcentagen, int *histograma){
	free(valores);
	free(porcentagen);
	free(histograma);
}


int main(){
   int tamanho, maximo, minimo;
   scanf("%d", &tamanho);
   scanf("%d %d", &minimo, &maximo);
   int *valores = criarVetorAleatorio(tamanho, minimo, maximo);
   int *histograma = criarHistograma(valores);
   float *porcentagens = criarPorcentagens(histograma);
   imprimePorcentagens(porcentagens, histograma);
   liberar(valores, porcentagens, histograma);
   return 0;
}
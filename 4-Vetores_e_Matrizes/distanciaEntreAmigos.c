#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void maior(int tam, int* distancia){
  int aux[tam];
  int i, j, menor, maior, menor_pos, pos = 0;

  maior = distancia[0];
  menor_pos = 0;

  for(i=0; i<tam; i++){
    menor = maior;

    for(j=0; j<tam; j++){
      if(distancia[j] < menor){
        menor = distancia[j];
        menor_pos = j;
      }
      else if(distancia[j] > maior){
        maior = distancia[j];
      }
    }

    aux[pos] = menor;
    pos++;
    distancia[menor_pos] = maior+1;
  }

  for(i=0; i<tam; i++)
    distancia[i] = aux[i];
}




int main()
{
	int N, dis, possibilidades=0, cont = 0, k, posi, terrio;

	scanf("%i", &N);
	int aux = N-1;
	for(int a = 1; aux >= 1; aux--){
		possibilidades = possibilidades + aux;
	}

	int andares[N], distancia[possibilidades];

	for (int i = 0; i < N; ++i){
		scanf("%i", &andares[i]);
	}

	for (int j = 0; j < N; ++j){	
		terrio = 1;
		k = 1;
		k = k + j;
		while (k < N){	
			dis = andares[j] +  andares[k] + (terrio);
			distancia[cont] = dis;
			cont = cont + 1;
			terrio += 1;
			k = k + 1;
		}
	}

	maior(possibilidades, distancia);
	posi = possibilidades - 1;
	printf("%d\n", distancia[posi]);

	return 0;
	
}




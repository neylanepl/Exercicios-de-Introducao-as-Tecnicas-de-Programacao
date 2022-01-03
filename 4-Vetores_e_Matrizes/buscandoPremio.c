#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void faltam(int S, int quant_sim,  int* simbolos, int* coletados, int especial){
	for (int l = 0; l < quant_sim; ++l){
			for (int m = 0; m < S; ++m){
				if (simbolos[m] == coletados[l]){
					simbolos[m] = 0;
				}else if (simbolos[m]==0){
						especial = m;
					}
			}		
	}
}

int main()
{
	int S, N, quant_sim, especial=1;

	scanf("%i %i", &S, &N);

	int simbolos[S];
	for (int i = 0; i < S; ++i)
	{
		simbolos[i] = i;
	}

    for (int j = 0; j < N; ++j){
		scanf("%i", &quant_sim);

		int coletados[quant_sim];
		for (int k = 0; k < quant_sim; ++k){
			scanf("%i", &coletados[k]);	
		}
        
        faltam(S, quant_sim, simbolos, coletados, especial);
		
	}
	
	printf("%i\n", especial);

	printf("[");
	for (int n = 0; n < S; ++n){
		if (simbolos[n] != 0 || n == especial){
			printf(" %i", simbolos[n]);
			if (n != (S-1))
			{
				printf(",");
			}
		}	
	}
	printf(" ]\n");
	


	return 0;
}

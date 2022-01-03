#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int N, i, j, fat, cont_for, cont_repeticao, total;
	char fatorador, quant;
	
	scanf("%i", &N);

	if (N <= 1)
	{
		printf("Erro, número precisa ser maior do que 1!\n");
	}
	else{
		fat = 1;
			cont_for = 0;
			for(j=2; j<=N; j++){
				cont_repeticao = 0;
				while(N%j == 0){
					cont_repeticao += 1;
					fat = N / j;
					N = fat;
					
				}
				if (cont_repeticao != 0)
				{
					cont_for += 1;
					if (N == 1 && cont_for == 1)
					{
						printf("%i^%i\n",j,cont_repeticao);
					}else if (N == 1 && cont_for != 1)
					{
						printf("*%i^%i\n",j,cont_repeticao);
					}

					else if (cont_for%2 == 0 && fat != 0)
					{
						printf("*%i^%i",j,cont_repeticao);
						
					}
					else {
						printf("%i^%i",j,cont_repeticao);
					}
				}

				
				
			}

	}
	

	return 0;
}
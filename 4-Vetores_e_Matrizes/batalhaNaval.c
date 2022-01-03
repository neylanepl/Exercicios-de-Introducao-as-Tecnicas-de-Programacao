#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int linha[10], coluna[10],posi_c=0, posi_l=0;
	char tabuleiro[10][10];

	for (int i = 0; i < 10; ++i){
		for (int j = 0; j < 10; ++j){
			tabuleiro[i][j] = '~';
		}
	}

	for (int k = 0; k < 10; ++k){
		scanf("%i %i", &linha[k], &coluna[k]);
	}


	for (int l = 0; l < 7; ++l){
		posi_l = linha[l];
		posi_c = coluna[l];
		posi_l1 = linha[l+1];
		posi_c1 = coluna[l+1];
		if (l==0)
		{	
			posi_l = linha[l];
			posi_c = coluna[l];
			tabuleiro[posi_l][posi_c] = '*';
		}
		else if (l==1)
		{
			
			if (posi_l == posi_l1)
			{
				tabuleiro[posi_l][posi_c] = '<';
				tabuleiro[posi_l][posi_c1] = '>';
			}else if (posi_c == posi_c1)
			{
				tabuleiro[posi_l][posi_c] = '^';
				tabuleiro[posi_l1][posi_c] = 'v';

			}
			
		}

		else if (l>=3)
		{	
			if (l==3 || l==6)
			{
				int cont=2;
				if (posi_l == posi_l1)
				{	
					tabuleiro[posi_l][posi_c] = '<';
					tabuleiro[posi_l][posi_c1] = '=';
					if (l==6)
					{
						tabuleiro[posi_l][coluna[l+2]] = '=';
						cont += 1;
					}
					tabuleiro[posi_l][coluna[l+cont]] = '>';
				}else if (posi_c == posi_c1)
				{   cont = 2;
					tabuleiro[posi_l][posi_c] = '^';
					tabuleiro[posi_l1][posi_c] = '|';
					if (l==6)
					{
						tabuleiro[posi_l1]][posi_c] = '|';
						cont += 1;
					}
					tabuleiro[linha[l+cont]][posi_c] = 'v';
				}
			}
			
		}
	}

	for (int n = 0; n < 10; ++n){
		for (int o = 0; o < 10; ++o){
			printf("%c", tabuleiro[n][o]);
		}
		printf("\n");
	}

	return 0;
}
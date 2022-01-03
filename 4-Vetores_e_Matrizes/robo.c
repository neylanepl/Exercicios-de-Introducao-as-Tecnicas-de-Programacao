#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{   
    char D;
    int L, C, I, J, M;

    scanf("%d %d", &L, &C);
    //Leitura do mapa
    char mat[L][C];
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            scanf(" %c", &mat[i][j]);

    scanf("%d %d %c", &I, &J, &D);
    I--;
    J--;

    scanf("%i", &M);
    int l_frente=I, c_frente=J;
    for (int k = 0; k < M; ++k)
    {
    	switch(D){
	            case 'L': c_frente++;break;
	            case 'O': c_frente--;break;
	            case 'N': l_frente--;break;
	            case 'S': l_frente++;break;
				}

		if (l_frente < 0 || c_frente >=L || l_frente <0 || c_frente >= C || c_frente<0)
		{	
			if (D=='L')
			{	c_frente--;
				D='S';	
			}else if (D=='O')
			{	
				c_frente++;
				D='N';
			}
		}
		else{
			if (mat[l_frente][c_frente]=='.')
			{
				I=l_frente;
				J=c_frente;
			}else if (mat[l_frente][c_frente]=='*')
			{
				D = 'O';
			}else if (mat[l_frente][c_frente]=='_' || mat[l_frente][c_frente]=='|')
			{	
				if (D=='S')
				{	l_frente--;
					D='O';
				}else if (D=='N')
				{
					l_frente++;
					D='L';
				}else if (D=='L')
				{
					c_frente--;
					D='S';
				}
			}
		}		
    }

    printf("Posição final: %i %i\n", I+1, J+1);
    

	return 0;
}

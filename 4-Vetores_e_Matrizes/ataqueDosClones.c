#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int N, M, x, y;

	scanf("%i %i", &N, &M);
	scanf("%i %i", &x, &y);

	x--;
	y--;

	int mapa[N][M];
	int aux[N][M];
	for (int e = 0; e < N; ++e)
	{
		for (int f = 0; f < M; ++f)
		{
			 scanf("%i", &mapa[e][f]);
		}
	}

	for (int g = 0; g < N; ++g)
	{
		for (int h = 0; h < M; ++h)
		{
			aux[g][h]=0;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{		
			if (i > 0 && i<(N-1) && j > 0 && j<(M-1))
			{
				if(mapa[i][j]>mapa[i-1][j]){
	            	if (mapa[i][j]>mapa[i-1][j-1])
	            	{
	            		if (mapa[i][j]>mapa[i-1][j+1])
	           			{
	           				if (mapa[i][j]>mapa[i+1][j])
	           				{
	           					if (mapa[i][j]>mapa[i+1][j-1])
	           					{
	          						if (mapa[i][j]>mapa[i+1][j+1])
	           						{
	           							if (mapa[i][j]>mapa[i][j-1])
	           							{
	           								if (mapa[i][j]>mapa[i][j+1])
	           								{
	           									aux[i][j]=1;
	           								}
	           							}
	           						}
	           					}
	       					}
	           			}
	            	}	
           		}
           	}else if (i==0 && j==0)
           	{	
           		if (mapa[i][j]>mapa[i+1][j])
	           	{
	           		if (mapa[i][j]>mapa[i+1][j+1]){
	           			if (mapa[i][j]>mapa[i][j+1])
	           			{
	           				aux[i][j]=1;
	           			}

	           		}
	           	}
           		
           	}else if (i ==0 && j!=(M-1))
           	{
           		if (mapa[i][j]>mapa[i+1][j])
	           				{
	           					if (mapa[i][j]>mapa[i+1][j-1])
	           					{
	          						if (mapa[i][j]>mapa[i+1][j+1])
	           						{
	           							if (mapa[i][j]>mapa[i][j-1])
	           							{
	           								if (mapa[i][j]>mapa[i][j+1])
	           								{
	           									aux[i][j]=1;
	           								}
	           							}
	           						}
	           					}
	       					}
           	}else if (i==0 && j==(M-1))
           	{
           		if (mapa[i][j]>mapa[i+1][j])
	           	{
	           		if (mapa[i][j]>mapa[i+1][j-1])
	           		{
	           			if (mapa[i][j]>mapa[i][j-1])
	           			{
	           				aux[i][j]=1;
	           			}
	           		}
	           	}
           	}else if ( j==0 && i>0 && i!=(N-1))
           	{	
           		if(mapa[i][j]>mapa[i-1][j]){
           			if (mapa[i][j]>mapa[i-1][j+1])
	           		{
	           			if (mapa[i][j]>mapa[i][j+1])
	           			{
			           			if (mapa[i][j]>mapa[i+1][j+1])
				           		{
				           			if (mapa[i][j]>mapa[i+1][j])
				           			{
				           				aux[i][j]=1;
				           			}
				           		}

				        }
				    }
           		}
           		

           	}else if(j==0 && i==(N-1))
           	{
           		if (mapa[i][j]>mapa[i][j+1])
	           	{
			        if (mapa[i][j]>mapa[i-1][j+1])
				    {
				        if (mapa[i][j]>mapa[i-1][j])
				        {
				           	aux[i][j]=1;
				        }
				    }

				}
           	}



           	else if (i == (N-1) && j > 0)
           	{
 				if (mapa[i][j] > mapa[i-1][j])
	           	{
	   				if (mapa[i][j]>mapa[i-1][j-1])
	       			{
   						if (mapa[i][j]>mapa[i][j-1])
	  					{
	           				if (j!= (M-1))
	           				{
		           				if (mapa[i][j]>mapa[i-1][j+1])
		       					{
		           					if (mapa[i][j]>mapa[i][j+1])
		   							{
		   								aux[i][j]=1;
		           					}
		           				}	
		           			}else if (j== (M-1))
		           			{
		           				aux[i][j]=1;
		           			}
						}
	           		}
	   			}       
           	
           	}else if (i>0 && i!=(N-1) && j==(M-1))
           	{
           		if (mapa[i][j]>mapa[i+1][j])
	           	{
	           		if (mapa[i][j]>mapa[i+1][j-1])
	           		{
	           			if (mapa[i][j]>mapa[i][j-1])
	           			{	
	           				if(mapa[i][j]>mapa[i-1][j]){
	            				if (mapa[i][j]>mapa[i-1][j-1])
	            				{
	           						aux[i][j]=1;
	           					}
	           				}
	           			}
	           		}
	           	}
           	}

		}

	}

	int cont=1, morte=0;
	for (int k = 0; k < N; ++k)
	{
		for (int l = 0; l < M; ++l)
		{
			if(aux[k][l]==1){
				printf("Local %i: %i %i\n", cont, k+1, l+1);
				cont=cont+1;
				if (k==x && l==y)
				{
					morte=1;
				}
			}
			
		}
	}
	if (morte==1)
	{
		printf("Descanse na Força...\n");
	}else{
		printf("Ao resgate!\n");
	}


	return 0;
}
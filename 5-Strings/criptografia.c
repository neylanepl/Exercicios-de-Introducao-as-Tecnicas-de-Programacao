#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void crip(char p[201], int k[4]){
	int max, igual=0, para=0, cont=0, falta=0;
	max=(int)strlen(p);
	char c[max+1], k2[max+1];

	for (int i = 0; i < max+1; ++i)
	{
		c[i]=0;
	}

	const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};

    for (int j = 0; j < max-1; ++j){
    	igual=0;
    	for (int l = 0; l < 40; ++l){
    		if (p[j] == S[l]){
    			igual+=1;
    		}
    	}
    	if (igual == 0){
	    	printf("Caractere invalido na entrada!\n");
	    	para+=1;
	    	break;
    	}
    }
    

    if (para==0)
    {
    	for (int m = 0; m < max+1; ++m)
	    {
	    	k2[m] = k[cont];
	    	cont+=1;
	    	if (cont==4)
	    	{
	    		cont = 0;
	    	}
	    }

	    for (int n = 0; n < max-1; ++n){
	    	for (int o = 0; o < 40; ++o){
	    		if (p[n] == S[o]){
	    			if (o+k2[n]>39 && k2[n]!=0)
	    			{
	    				falta = (o+k2[n])-39;
	    				c[n] = S[falta-1];
	    			}else{
						c[n] = S[o+k2[n]];
	    			}
	    			
	    		}
	    	}
	    }


	    printf("%s\n",c);
    }
	    
}

int main()
{	
	int k[5], cont=0,val, max, dig, sobra;
	char p[201], x[100];
	char quebra[2];
	

	for (int i = 0; i < 4; ++i)
	{
		k[i]=0;
	}

	fgets(x, 99, stdin);

	max=(int)strlen(x);
	max--;
	printf("%i\n", max);
	if (max!=4)
	{
		printf("Chave invalida!\n");
	}
	else{

    	val = atoi(x);
    
    	for (int i = 0; i < 4; ++i)
    	{
    		dig = val % 10;
    		sobra = (int)(val/ 10);
    		k[3-i] = dig;
    		val=sobra;
    	} 
    	

    	fgets(p, 200, stdin);
    	crip(p, k);
	}

	return 0;
}
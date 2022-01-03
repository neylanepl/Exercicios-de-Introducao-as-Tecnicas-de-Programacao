#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int chave(char c[201], char kp[9], int k[5], const char S[40]){
	int auxk[9], cont=0, para=0, auxl, falta, posik=0, max, invald=0;

	max=(int)strlen(c);

	for (int i = 0; i < max-9; ++i){
		if (posik==4){
			posik=0;
		}
		for (int j = 0; j < 8; ++j){
	    	cont=0;
	    	for (int l = 0; l < 40; ++l){
	    		if (kp[j] == S[l]){
	    			auxl=l;
	    			while(S[auxl]!=c[i+j]){
	    				cont+=1;
	    				auxl+=1;
	    				if (auxl>39)
		    			{
		    				falta = auxl-39;
		    				auxl=falta-1;
		    				cont=1;
		    			}
	    			}
	    			
	    			auxk[j] = cont;
	    			break;	
	    		}
	    	}
    	}
    	
    	para=0;
    	for (int m = 0; m < 4; ++m){
			if (auxk[m]==auxk[4+m]){
				para+=1;
			}
		}

		invald=0;
		if (para==4){
			break;
		}else{
			invald=1;
		}
		posik+=1;
	}

	if (invald==1){
		return 0;
	}else{
		if (posik==0){
			k[0]=auxk[0];
			k[1]=auxk[1];
			k[2]=auxk[2];
			k[3]=auxk[3];
		}else if (posik==1){
			k[0]=auxk[3];
			k[1]=auxk[0];
			k[2]=auxk[1];
			k[3]=auxk[2];

		}else if (posik==2){
			k[0]=auxk[2];
			k[1]=auxk[3];
			k[2]=auxk[0];
			k[3]=auxk[1];
		}else if (posik==3){
			k[0]=auxk[1];
			k[1]=auxk[2];
			k[2]=auxk[3];
			k[3]=auxk[0];
			
		}

		return 1;
		
		
	}
	
}

void decifrar(char c[201],int k[5], const char S[40]){
	int max, cont=0, falta=0;

	max=(int)strlen(c);

	char k2[max+1], p[max+1];

	for (int l = 0; l < max+1; ++l){
		p[l]=0;
	}

	for (int m = 0; m < max+1; ++m){
	    	k2[m] = k[cont];
	    	cont+=1;
	    	if (cont==4){
	    		cont = 0;
	    	}
	}

	for (int n = 0; n < max-1; ++n){
	    for (int o = 0; o < 40; ++o){
	   		if (c[n] == S[o]){
	   			if (o-k2[n]<0)  			{
	    			falta = (o-k2[n])+40;
	    			p[n] = S[falta];
	    		}else{
					p[n] = S[o-k2[n]];
	    		}
	    			
	   		}
	   	}
	}
	
	printf("%s",p);

}


int main()
{	
	char c[201];
	char kp[]={'Q','U','E',' ','A',' ','F','O','\0'};
	int k[5];

	fgets(c, 200, stdin);

	const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};

	
	if (chave(c,kp,k, S))
	{
		for (int i = 0; i < 4; ++i)
		{
			printf("%i", k[i]);
		}

		printf("\n");
		decifrar(c,k, S);
	}else{
		printf("Mensagem nao e da Resistencia!\n");
	}
	
	return 0;
}
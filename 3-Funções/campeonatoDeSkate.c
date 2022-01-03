#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int numero_meio(int X, int Y, int Z){
    int maior, menor,meio;

    if (X==Y)
    {	
    	return X;

    }else if(X > Y){

    	maior = X;
    	menor = Y;
    }
    else{
        maior = Y;
        menor = X;
    }


    if (Z == maior || Z== menor)
    {
    	return Z;
    }
    else if(Z > maior){
    	meio = maior;
        maior = Z;
    }
	else if(Z < menor){
    	meio = menor;
        menor = Z;
       
    }
    else{
    	return Z;
    }

    return(meio);
    
}


void score_final(int scoreA, int scoreB){
	
	if (scoreA > scoreB)
	{
		printf("A\n");
	}else if (scoreA < scoreB)
	{
		printf("B\n");
	}else{
		printf("empate\n");;
	}
	
}

int main()
{
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r, meio1, meio2, meio3, meio4, meio5, meio6, scoreA, scoreB;

	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p, &q, &r);
	

	meio1 = numero_meio(a,b,c);
	meio2 = numero_meio(d,e,f);
	meio3 = numero_meio(g,h,i);

	scoreA = numero_meio(meio1, meio2, meio3);

	meio4 = numero_meio(j,k,l);
	meio5 = numero_meio(m,n,o);
	meio6 = numero_meio(p,q,r);

	scoreB = numero_meio(meio4, meio5, meio6);
  
    score_final(scoreA, scoreB);

	return 0;
}
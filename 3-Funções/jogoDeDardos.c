#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
float distancia_euclidiana(double xo,double yo, double x2,double y2){
	double dis;
	dis = sqrt(pow(xo-x2,2) + pow(yo-y2,2));
	return dis;
}

int pontuacao(double distancia1){
	int ponto;
	

	if (distancia1 >= 0 && distancia1 <=1)
	{
		ponto = 10;
	}
	else if (distancia1 > 1 && distancia1 <=2)
	{
		ponto = 6;
	}
	else if (distancia1 > 2 && distancia1 <=3)
	{
		ponto = 4;
		
	}
	else if (distancia1 > 3)
	{
		ponto = 0;
	}

	return ponto;
}


int main()
{
	double x1=0, y1=0, x2, y2, xo=0, yo=0, distancia_alvo, distancia_ponto ;
	int total = 0, pontos;


	for (int i = 0; i < 10; ++i)
	{
		scanf("%lf %lf", &x2, &y2);

		distancia_alvo = distancia_euclidiana(xo, yo, x2, y2);
		
		distancia_ponto = distancia_euclidiana(x1, y1, x2, y2);
		
		if (i == 0)
		{
			pontos = pontuacao(distancia_alvo);

		}else{
			pontos = pontuacao(distancia_alvo) + (pontuacao(distancia_ponto)/2);
		}
		
		total += pontos;

		x1 = x2;
		y1 = y2;
			
	}
	
	printf("%i\n", total);
	

	return 0;
	
}



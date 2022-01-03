#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int somar_dividores(int n){
	int s=0;

	for (int i = 1; i < n; ++i)
	{
		if (n % i == 0)
		{
			s += i;
		}
	}
	return s;

}

char colegas(int A, int B, int somaA, int somaB){
	if ((abs(somaA - B) <= 2) && (abs(somaB - A) <= 2))
	{
		return 'S';
	}else
	{
		return 'N';
	}
}


int main()
{
	int A, B, somaA, somaB;
	scanf("%i %i",&A,&B);
	somaA = somar_dividores(A);
	somaB = somar_dividores(B);
	
	printf("%c\n", colegas(A, B, somaA,somaB));
	
	


	return 0;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int main()
{
	int N, V, A;
	char C;

	scanf("%i %i", &N, &V);

	for (int i = 0; i < N; ++i)
	{
		scanf(" %c %i", &C, &A);

		if (A > 14 && V > 0) {
			switch (C){
			case 'A':
				V -= 10;
				if (V <= 0){
					printf("Alyson derrotou o dragão!\n");
				}
				break;
			case 'I': 
				V -= 10;
				if (V <= 0){
					printf("Isaac derrotou o dragão!\n");
				}
				break;
			case 'R':
				V -= 6;
				if (V <= 0){
					printf("Rafaela derrotou o dragão!\n");
				}
				break;
			case 'W':
				V -= 8;
				if (V <= 0){
					printf("Wellington derrotou o dragão!\n");
				}
				break;
			case 'S':
				V -= 4;
				if (V <= 0){
					printf("Salgado derrotou o dragão!\n");
				}
				break;
			case 'C':
				V -= 1;
				if (V <= 0){
					printf("Careca derrotou o dragão!\n");
				}
				break;
			}
		}
	
	}
	
	if (V > 0)
		{
			printf("Casa caiu!\n");
		}



	return 0;
	
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int main(void)
{
	double C, F, K, temperatura;
	char escala;


	scanf("%lf %s", &temperatura, &escala);

	if (escala == 'C') {
		C = temperatura;
		printf("Celsius: %.2lf\n", C);
		F = C * 1.8 + 32;
		printf("Farenheit: %.2lf\n", F);
		K = C + 273.15;
		printf("Kelvin: %.2lf\n", K);
	} 
	else if (escala == 'F') {
		F = temperatura;
		C = (F - 32.0)/1.8;
		printf("Celsius: %.2lf\n", C);
		printf("Farenheit: %.2lf\n", F);
		K = (F + 459.67) / 1.8;
		printf("Kelvin: %.2lf\n", K);
	}
	else if (escala == 'K') {
		K = temperatura;
		C = K - 273.15;
		printf("Celsius: %.2lf\n", C);
		F = K * 1.8 - 459.67;
		printf("Farenheit: %.2lf\n", F);
		printf("Kelvin: %.2lf\n", K);
	}
	else {
		printf("Opção Inválida!");
	}
	

	;

	return 0;
	
}
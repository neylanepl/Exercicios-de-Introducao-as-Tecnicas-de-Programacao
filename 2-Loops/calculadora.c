#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int main()
{
	double soma1, soma2, sub1, sub2, div1, div2, mult1, mult2, pot1;
	double soma, sub, div, mult;
	float pot;
	int pot2;
	char op;

	scanf("%s",&op);

	while (op != 'e'){
		switch (op){
		case '+':
			scanf("%lf %lf",&soma1, &soma2);
			soma = soma1 + soma2;
			printf("%.3lf+%.3lf=%.3lf\n", soma1, soma2, soma);
			break;
		case '-': 
			scanf("%lf %lf", &sub1, &sub2);
			sub = sub1 - sub2;
			printf("%.3lf-%.3lf=%.3lf\n", sub1, sub2, sub);
			break;
		case '*':
			scanf("%lf %lf", &mult1, &mult2);
			mult = mult1 * mult2;
			printf("%.3lf*%.3lf=%.3lf\n", mult1, mult2, mult);
			break;
		case '/':
			scanf("%lf %lf", &div1, &div2);
			div = div1 / div2;
			printf("%.3lf/%.3lf=%.3lf\n", div1, div2, div);
			break;
		case '^':
			scanf("%lf %i", &pot1, &pot2);
			pot = pow(pot1, pot2);
			printf("%.3lf^%i=%.3f\n", pot1, pot2, pot);
			break;
	}

	scanf("%s",&op);

	}
	

	return 0;
	
}
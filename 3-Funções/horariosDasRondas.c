#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void escreve_horario(int h, int m, int s){
	if (h < 10 && m > 9 && s >9)
	{
		printf("0%i:%i:%i\n", h,m,s);
	}else if (h < 10 && m < 10 && s >9)
	{
		printf("0%i:0%i:%i\n", h,m,s);
	}else if (h < 10 && m < 10 && s < 10)
	{
		printf("0%i:0%i:0%i\n", h,m,s);
	}else if (h >9 && m < 10 && s > 9)
	{
		printf("%i:0%i:%i\n", h,m,s);
	}else if (h >9 && m < 10 && s < 10)
	{
		printf("%i:0%i:0%i\n", h,m,s);
	}else if (h >9 && m > 9 && s < 10)
	{
		printf("%i:%i:0%i\n", h,m,s);
	}
	else if (h < 10 && m > 9 && s < 10)
	{
		printf("0%i:%i:0%i\n", h,m,s);
	}
	else{
		printf("%i:%i:%i\n", h,m,s);
	}

}

int main()
{
	int h,m,s,novaH, novaM,novaS, transformarH, transformarM, transformarS, minuto, hora;

	scanf("%i %i %i", &h, &m, &s);

	for (int i = 0; i < 4; ++i)
	{	
			minuto = 0;
			hora = 0;

			if (i == 0){
				novaS = s;
				novaM = m;
				novaH = h + 1;
			}else if (i == 1){	
				novaS = s + 30;
				novaM = m + 10;
				novaH = h  + 2;
			}else if (i == 2){	
				novaS = s + 50;
				novaM = m  + 40;
				novaH = h + 4;
						
			}else if (i==3){
				novaS = s + 5;
				novaM = m + 5;
				novaH = h + 12;
			}


			if (i != 0){
				if ( novaS > 59){
					transformarS = novaS - 60;
					minuto += 1;
					novaS = transformarS;}
				
				if ( novaM + minuto > 59){
					transformarM = (novaM + minuto) - 60;
					hora += 1;
					novaM = transformarM;}
				else if (minuto > 0 && novaM < 59)
				{
					novaM = m + minuto  + 40;
				}	
			}

			if ( novaH + hora > 23){
				transformarH = (novaH + hora) - 23;
				transformarH = transformarH - 1;
				if (transformarH == 0){
					novaH = 0;
				}else{ 
					novaH = transformarH; }}
			else if (hora > 0 && novaH < 59)
				{
					novaH = h + hora  + 4;
				}
			escreve_horario(novaH,novaM,novaS);

	}
	

	return 0;
}
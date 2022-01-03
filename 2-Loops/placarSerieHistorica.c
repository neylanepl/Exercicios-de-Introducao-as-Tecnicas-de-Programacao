#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int main()
{
	// 1 para Saints e 2 para Bucaneers
	int TD1, FG1, PAT1, placar_Saints, TD2, FG2, PAT2, placar_Burcaneers;
	int  N, cont, somaTD1=0, somaFG1=0, somaPAT1=0,somaTD2=0, somaFG2=0, somaPAT2=0;

	scanf("%i", &N);

	cont = 1;
	while (cont<= N){
		scanf("%i %i %i", &TD1, &FG1, &PAT1);
		scanf("%i %i %i", &TD2, &FG2, &PAT2);

		somaTD1 += TD1;
		somaTD2 += TD2;
		somaFG1 += FG1;
		somaFG2 += FG2;
		somaPAT1 += PAT1;
		somaPAT2 += PAT2;
		cont = cont + 1;
	}
	

	placar_Burcaneers = (somaTD2 * 6) + (somaFG2 * 3) + (somaPAT2 * 1);
	placar_Saints = (somaTD1 * 6) + (somaFG1 * 3) + (somaPAT1 * 1);
	

	
	if (placar_Burcaneers > placar_Saints) {
		printf("Bucaneers é o campeão na série histórica!\n");
		printf("Placar: %i x %i\n", placar_Burcaneers, placar_Saints);
	} 
	else if (placar_Burcaneers < placar_Saints) {
		printf("Saints é o campeão na série histórica!\n");
		printf("Placar: %i x %i\n", placar_Burcaneers, placar_Saints);
	}
	
	else if (placar_Burcaneers == placar_Saints) {
		printf("Série histórica empatada em %i pontos!\n", placar_Burcaneers);
	}


	if (somaTD1 > somaTD2)
	{
		printf("Saints marcou mais Touch Downs(%i)\n", somaTD1);
	}
	else if (somaTD1 < somaTD2)
	{
		printf("Bucaneers marcou mais Touch Downs(%i)\n", somaTD2);
	}
	else if (somaTD1 == somaTD2)
	{
		printf("Número de Touch Downs empatado(%i)\n", somaTD1);
	}


	if (somaFG1 > somaFG2)
	{
		printf("Saints marcou mais Field Goals(%i)\n", somaFG1);
	}
	else if (somaFG1 < somaFG2)
	{
		printf("Bucaneers marcou mais Field Goals(%i)\n", somaFG2);
	}
	else if (somaFG1 == somaFG2)
	{
		printf("Número de Field Goals empatado(%i)\n", somaFG1);
	}

	if (somaPAT1 > somaPAT2)
	{
		printf("Saints marcou mais Pontos Extras(%i)\n", somaPAT1);
	}
	else if (somaPAT1 < somaPAT2)
	{
		printf("Bucaneers marcou mais Pontos Extras(%i)\n", somaPAT2);
	}
	else if (somaPAT1 == somaPAT2)
	{
		printf("Número de Pontos Extras empatado(%i)\n", somaPAT1);
	}


	return 0;
	
}

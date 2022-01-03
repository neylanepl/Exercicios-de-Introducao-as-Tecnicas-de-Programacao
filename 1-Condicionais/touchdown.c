#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int TD_saints, FG_saints, PAT_saints, TD_buc, FG_buc, PAT_buc, placar_saints, placar_buc;
    
	scanf("%d %d %d\n%d %d %d", &TD_saints, &FG_saints, &PAT_saints, &TD_buc, &FG_buc, &PAT_buc );

	placar_saints = (6*TD_saints) + (1*PAT_saints) + (3*FG_saints);
	placar_buc =  (6*TD_buc) + (1*PAT_buc) + (3*FG_buc);


	if (placar_buc == placar_saints) {
		printf("Placar: Saints %d x %d Bucaneers\nEmpate!\n", placar_saints, placar_buc);
	}
	else if (placar_buc > placar_saints) {
		printf("Placar: Saints %d x %d Bucaneers\nBucaneers venceu!\n", placar_saints, placar_buc);
	}
	else {
		printf("Placar: Saints %d x %d Bucaneers\nSaints venceu!\n", placar_saints, placar_buc);
	}

	return 0;
}

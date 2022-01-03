#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	int jafoi;
	char bomba;
}camp;

void abrir_casa(camp **campo, int l, int c){
	if (campo[l][c].jafoi == 0){
		return;
	}else{
    
	    campo[l][c].jafoi = 0;
	    
		if(campo[l][c].bomba == '0'){
			abrir_casa(campo, l-1, c-1);
			abrir_casa(campo, l-1, c);
			abrir_casa(campo, l-1, c+1);
			abrir_casa(campo, l+1, c-1);
			abrir_casa(campo, l+1, c);
			abrir_casa(campo, l+1, c+1);
			abrir_casa(campo, l, c-1);
			abrir_casa(campo, l, c+1);
		}
	}

}

int main(){
	int n, m, b, lB, cB, j, l, c, cont;
	char tiposJ[6];
	camp **campo;

	scanf("%d %d\n", &n, &m);

	
	campo = malloc(sizeof(camp *) * (n+2));
  	for(int i=0; i < n+2; ++i){
    	campo[i] = malloc(sizeof(camp) * (m+2));
  	}
	

	for (int j = 0; j < n+2; ++j){
		for (int k = 0; k < m+2; ++k){
			campo[j][k].bomba = '*';
			if(j ==0 || k == 0 || j == n+1 || k == m+1){
				campo[j][k].jafoi = 0;
			}else{
				campo[j][k].jafoi = 1;
			}
			
		}
	}

	scanf("%d\n", &b);

	for (int o = 0; o < b; ++o){
		scanf("%d %d", &lB, &cB);
		campo[lB][cB].bomba = 'B';
	}

	for (int p = 1; p < n+1; ++p){
		for (int q = 1; q < m+1; ++q){
			cont=0;
			if (campo[p][q].bomba != 'B'){
			        //LINHA 1
					if(campo[p-1][q-1].bomba=='B'){
						cont+=1;
					}
					if (campo[p-1][q].bomba=='B'){
						cont+=1;
					}
					if (campo[p-1][q+1].bomba=='B'){
						cont+=1;
					}
					//LINHA 3
					if (campo[p+1][q-1].bomba=='B'){
						cont+=1;
					}
					if (campo[p+1][q].bomba=='B'){
						cont+=1;
					}
					if (campo[p+1][q+1].bomba=='B'){
						cont+=1;
					}
					//LINHA 2
					if (campo[p][q-1].bomba=='B'){
						cont+=1;
					}
					if (campo[p][q+1].bomba=='B'){
						cont+=1;
					}

					campo[p][q].bomba = cont + '0';
			}
		}
	
	}


	scanf("%d\n", &j);

	for (int r = 0; r < j; ++r){
		scanf("%s %d %d", tiposJ, &l, &c);
		if (tiposJ[0] =='C'){
			if (campo[l][c].bomba == 'B'){
			    campo[l][c].bomba = 'X';
				printf("CABUUUUM!\n");
				printf("Game Over....\n");
				break;
			}
			
			abrir_casa(campo, l, c);
			
		}else if (tiposJ[0] =='M'){
			campo[l][c].jafoi = 0;		
		}
		

		for (int s = 0; s < m+2; ++s){
		 	printf("=");
		}

		printf("\n");

		for (int t = 1; t < n+1; ++t){
			for (int u = 1; u < m+1; ++u){
				if(campo[t][u].jafoi == 1){
					printf("*");
				}else{
					printf("%c", campo[t][u].bomba);
				}
				
			}
			printf("\n");
		}

		if (r == j-1){
			printf("Você sobreviveu!\n");
		}

	}

	for (int v = 0; v < m+2; ++v){
		 printf("=");
	}
	printf("\n");

	for (int x = 1; x < n+1; ++x){
		for (int y = 1; y < m+1; ++y){
			printf("%c", campo[x][y].bomba);
		}
		printf("\n");
	}

	return 0;
}
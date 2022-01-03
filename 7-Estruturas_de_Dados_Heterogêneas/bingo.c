#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id_cartela;
    int tam_cartela;
    int *numeros;
    int *marcacao;
}Cartela;

void criar_Cartela(int id, Cartela* aux, int N, int M){
	int n, cont=0, i, j;
	aux->marcacao = malloc(sizeof(int)* M);
	aux->numeros = malloc(sizeof(int)* M);
	srand(id);
	//printf("iD%d\n", id);
	for ( i = 0; i < N; ++i){
	    
		n = (rand()%(M))+1;

		if (i>0){
			for (j = 0; j < i; ++j){
				if (n != aux->numeros[j]){
				}else{
					cont = 1;
				}
			}
		}else if (i==0){
			aux->numeros[i] = n;
			aux->marcacao[i]=0;
		}

		if (cont==1){
			i--;
		}else if (cont ==0)
		{	
			aux->numeros[i] = n;
			aux->marcacao[i]=0;
			//printf("num%d\n", n);
		}

		cont = 0;
		
	}
	
	aux->id_cartela = id;
	aux->tam_cartela = N;
}

int leitura(int **ids, char *linha, int *T){
	int num_int;
	
	if (linha[0]=='C'){
		return 0;
	}

	num_int=atoi(linha);
	
	*T = (*T)+1;
	if ((*T) != 1){
			*ids =  realloc(*ids, sizeof(int)*(*T));
	}
	(*ids)[(*T)-1]=num_int;
	
	return 1;

}

int checa_repetido(int num_sort, int** sort_glob){
	static int cont = 0;
	
	if(cont == 0){
		(*sort_glob)= realloc((*sort_glob),(sizeof(int)*(cont+1)));
	    (*sort_glob)[cont] = num_sort;
	    cont+=1;
	    return 0;
	}else if(cont > 0){
        for(int i=0 ; i< cont; ++i){
            if(num_sort == (*sort_glob)[i]){
                return 1;
            }
        }
        
        (*sort_glob)= realloc((*sort_glob),(sizeof(int)*(cont+1)));
	    (*sort_glob)[cont] = num_sort;
	    cont+=1;
	    
	    return 0;
    }
    
}

int marca(int n, Cartela* aux){
	int cont =0;
	
    for(int i=0; i < aux->tam_cartela;++i){
        if(aux->numeros[i] == n){
            aux->marcacao[i] = 1;
        }
        cont += aux->marcacao[i];
    }
    
    
    if (cont != aux->tam_cartela){
    	return 0;
    }else if(cont == aux->tam_cartela){
        return 1;
    }
        
}


void sorteia_globo(int S, int M, Cartela* carts, int T){
  	srand(S);
  	int aux = 1, ganhou, num_sort;
  	int *sort_glob = malloc(sizeof(int));
  	
  	while(aux){
	  	do{
	  		num_sort = (rand()%(M))+1;
	  	}while(checa_repetido(num_sort, &sort_glob));
	  	
	  	printf("%d ",num_sort);
	  	
	  	for (int j = 0; j < T; ++j){
	  		ganhou = marca(num_sort,&carts[j]);
	  		if (ganhou == 1){	
	  			aux =0;
	  			break;
	  		}
	  	}
  	}
  	printf("\n");
}

void imprime_ganhador(int T, int N, Cartela* carts){
		int cont;
		
  		for(int i=0; i <T; ++i){
     		cont = 0;
	        for(int j=0; j<N;++j){
	            if(carts[i].marcacao[j] == 1){
	                cont+=1;
	            }
	        }
	        if(cont == N){
	            printf("Bingo! Cartela %d: ",carts[i].id_cartela);
	            for(int k=0; k <N; ++k){
	        		printf("%d ", carts[i].numeros[k]);      
	    		}
	        }
	    }   
}

int main()
{
	int N, M, S, T=0;
	char linha[50];
	
	scanf("%d %d %d", &N, &M, &S);
	
	int *ids = malloc(sizeof(int));
	
	
	do{
    	scanf(" %[^\n]",linha);
  	}while(leitura(&ids, linha,&T));

  	Cartela carts[T];

  	for (int i = 0; i < T; ++i){
  		criar_Cartela(ids[i], &carts[i], N, M);
  	}

  	sorteia_globo(S, M, carts, T);

  	imprime_ganhador(T, N , carts);
  	
  	printf("\n");
  		

	return 0;
}
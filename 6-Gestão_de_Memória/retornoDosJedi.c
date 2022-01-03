#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAVE 5940

char** separa(char *str, int *quantidadeTextos){
  char **textoSeparado;
  char *texto = strtok(str," ");
  int cont = 0;

  while(texto != NULL){
  	if(cont == 0){
        textoSeparado = malloc(sizeof(char*));
      }
    else{
        textoSeparado = realloc(textoSeparado, sizeof(char*) * (cont + 1));
		textoSeparado[cont] = malloc(sizeof(char) * strlen(texto) + 1);
    }
    textoSeparado[cont] = texto;
    cont ++;
    texto = strtok(NULL," ");
  }
  *quantidadeTextos = cont;
  return textoSeparado;
}

char* juntar(char **vetor_strings, int tamanho_vetor){
  int tamanho_final = 0, tam;
  char *strings_unidas;
  

  strings_unidas = malloc(sizeof(char));
  for (int i = 0; i < tamanho_vetor; ++i)
  {
  	tam=(int)strlen(vetor_strings[i]);
  	printf("tam%d\n", tam);
	tamanho_final+=tam;
  }
  strings_unidas = realloc(strings_unidas, sizeof(char*)*(tamanho_final));

  strings_unidas[0] = '\0'; //inicializa com uma string vazia
  for(int i=0; i<tamanho_vetor; i++){
    strcat(strings_unidas,vetor_strings[i]);
    strcat(strings_unidas," ");
  }
  return strings_unidas;
}

int todas_apareceram(int m[], int N){
	int cont= 0;
	for (int i = 0; i < N; ++i){
		if(m[i]==1){
			cont += 1;
		}
	}
	/*for (int i = 0; i < N; ++i)
	{
		printf("vetor%d\n", m[i]);
	}
	printf("cont%d\n", cont);*/

	if (cont==N){
		return 1;
	}else{
		return 0;
	}
}


char* embaralha(char T[]){
	//seja T um texto dado como entrada
	//seja E um vetor de palavras inicialmente vazio
	int k=0, tam, cont, espaco=0;
	char** E= NULL;
	char **M;
	char *R;
	int *N;

	N = malloc(sizeof(int));

	tam=(int)strlen(T);
	tam--;

	for (int i = 0; i < tam; ++i){
		if (T[i]==' '){
			espaco+=1;
		}
	}
	//printf("tam%d\n", espaco);

	*N=espaco+1;
	int marcacao[espaco+1];
	for(int i=0;i<espaco+1;i++){
	    marcacao[i]=0;
	}
	
	M = separa(T, N);//separe T gerando o vetor de palavras M de tamanho N
	
	while(todas_apareceram(marcacao, *N)==0){
		int n = rand();//sorteie um número inteiro n, usando a seed S
		printf("%d\n",n );
	  	if (k==0){
	  		E = malloc(sizeof(char*));
	  	}else{
	  		E = realloc(E,sizeof(char*)*(k+1));
	  	}
		E[k] = NULL;

		E[k] =malloc(sizeof(char*)* (strlen(M[n % *N])+1));

		E[k] = M[n % *N];
		marcacao[n % *N]=1;
	  	
	  	k+=1;
	}

	/*for (int i = 0; i < k; ++i)
	{
		printf("%s\n", E[i]);
	}*/
	//junte as palavras de E usando ' ', gerando o texto R
	R = juntar(E,k);
	//retorne R
	return R;

}


int main()
{
	char mensagem[501];

	char* resultado;

	srand(CHAVE);

	scanf(" %[^\n]", mensagem);

	resultado = embaralha(mensagem);

	printf("%s\n", resultado);

	return 0;
}


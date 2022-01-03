#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nome[200];
    int pontos, jogos, vitorias, empates, derrotas, gols_feitos, gols_sofridos, saldo;
}Time;


Time leitura(char *string){
	
	Time aux;
  	char* parte;

  	parte = strtok(string, ";");
	strcpy(aux.nome, parte);

	parte = strtok(NULL, "\n");
	sscanf(parte, "%d %d %d %d %d", &aux.vitorias, &aux.empates, &aux.derrotas, &aux.gols_feitos, &aux.gols_sofridos);

	aux.pontos = (aux.vitorias*3)+aux.empates;
	aux.jogos = aux.vitorias+ aux.empates+ aux.derrotas;
	aux.saldo = aux.gols_feitos-aux.gols_sofridos;

	return aux;
}

void ordenacao(int T, Time* dados){

    Time aux;

    for(int i=0; i<T-1; i++)
        for(int j=i+1; j<T; j++){
            if(dados[i].pontos > dados[j].pontos){
                aux = dados[i];
                dados[i] = dados[j];
                dados[j] = aux;
            }
            else if(dados[i].pontos == dados[j].pontos && dados[i].vitorias > dados[j].vitorias){
                aux = dados[i];
                dados[i] = dados[j];
                dados[j] = aux;
            }
            else if(dados[i].pontos == dados[j].pontos && dados[i].vitorias == dados[j].vitorias &&  dados[i].saldo > dados[j].saldo){
                aux = dados[i];
                dados[i] = dados[j];
                dados[j] = aux;
            }
    }
    
}

void impressao(int T, Time* vet){
    
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
	for(int k=T-1; k>=0; k--){
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n", vet[k].nome, vet[k].pontos, vet[k].jogos, vet[k].vitorias, 
        	vet[k].empates, vet[k].derrotas, vet[k].gols_feitos, vet[k].gols_sofridos, vet[k].saldo);
    }

    printf("\n");

    printf("Times na zona da libertadores: \n");
    for(int m=T-1; m>=(T-6); m--){
        printf("%s\n", vet[m].nome);
    }

    printf("\n");
    printf("Times rebaixados: \n");

    for (int n = 0; n < 4; ++n)
    {
    	printf("%s\n", vet[n].nome);
    }

}

int main()
{
	int T;
	char linha[500];

	scanf("%d", &T);
	Time dados[T];

	for(int l=0; l<T; l++){
		scanf(" %[^\n]",linha);
		dados[l] = leitura(linha);
	}
    
    
    ordenacao(T,dados);
	impressao(T,dados);


	return 0;
}
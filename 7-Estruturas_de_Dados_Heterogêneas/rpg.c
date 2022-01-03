#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Enumeração representando itens do jogo
enum item{
  cura = 1,
  dinheiro,
  vigor
};

//Enumeração representando as armadilhas
enum trap{
  buraco = 1,
  espinhos,
  ladrao
};

//Tipo Personagem, contendo vida e ataque. Usado para definir os inimigos e parte do Jogador
typedef struct person{
  int life;
  int attack;
} Personagem;

//Tipo Jogador. Contém um Personagem com informações de vida e ataque, além de uma posição x,y e informações de dinheiro (loot) e se está equipado com escudo ou não.
typedef struct player{
  Personagem p; 

  int x, y, escudo, loot;
}Jogador;

//Tipo de dado Sala, representa uma casa do mapa. Pode conter um personagem inimigo, um tesouro e/ou uma armadilha
typedef struct room{
  Personagem p;
  int tesouro;
  int armadilha;
} Sala;

void entradas_ITA(Sala** mapa ){
	int IQuant, TQuant, AQuant, l, c, vida, ataque;
	char tes[15], arm[15];

	scanf("%d %d %d\n", &IQuant, &TQuant, &AQuant);

	for (int i = 0; i < IQuant; ++i){

		scanf("(%d %d) - %d %d\n", &l, &c, &vida, &ataque);
        l-=1;
        c-=1;

		mapa[l][c].p.life = vida;
		mapa[l][c].p.attack = ataque;
	}

	
	for (int j=0; j< TQuant;++j){

		scanf("%s %i %i\n", tes, &l, &c);
        l-=1;
        c-=1;
		
		if (strcmp(tes,"cura") == 0){
			mapa[l][c].tesouro = cura;	
		}
		else if (strcmp(tes,"dinheiro") == 0){
			mapa[l][c].tesouro = dinheiro;	
		}
		else if (strcmp(tes,"escudo") == 0){
            mapa[l][c].tesouro = vigor;
		}
    }

	
	for (int k=0; k < AQuant; ++k){

		scanf("%s %i %i\n", arm, &l, &c);
        l-=1;
        c-=1;

		if (strcmp(arm,"buraco") == 0){
			mapa[l][c].armadilha = buraco;		
		}
		else if (strcmp(arm,"espinhos") == 0){
			mapa[l][c].armadilha = espinhos;
		}
		else if (strcmp(arm,"ladrao") == 0){
			mapa[l][c].armadilha = ladrao;		
		}
	}
}

int executa_passo_2(Sala** mapa, Jogador* p, int x, int y){
		if ( (mapa[x][y].p.life) != 0 ){
			printf("Um inimigo!!!\n");
			for(;;){
				printf("Jogador ataca!\n");
				mapa[x][y].p.life -= p->p.attack;
                printf("Dano de %i\n", p->p.attack);
				if ((mapa[x][y].p.life) >= 0)
				{
					printf("Vida do inimigo: %i\n",mapa[x][y].p.life);
				}else{
					printf("Vida do inimigo: 0\n");
				}
				if((mapa[x][y].p.life) <= 0){
					break;
				}


				if((p->escudo) != 0){
					(p->escudo) -= 1;
					printf("Defendeu o golpe!\n");
				}else{
					printf("Inimigo ataca!\n");
					p->p.life -= mapa[x][y].p.attack;
					printf("Dano de %i\n", mapa[x][y].p.attack);
					if ((p->p.life) >= 0){
						printf("Vida do jogador: %i\n",p->p.life);
					}else{
						printf("Vida do jogador: 0\n");
					}

					if((p->p.life) <= 0){
						return -1;
					}
	                    
				}
			}
		}

		if ( (mapa[x][y].tesouro) != 0 ){
			printf("Um tesouro!\n");
	        if((mapa[x][y].tesouro) == cura){
	            printf("Jogador coleta: pocao de cura!\n");
				p->p.life += 10;
	        }else if((mapa[x][y].tesouro) == dinheiro){
	            printf("Jogador coleta: dinheiro!\n");
				p->loot += 10;				
			}else if ((mapa[x][y].tesouro) == vigor){
	            printf("Jogador coleta: um escudo!\n");
				p->escudo += 1;
			}
		}

		if ((mapa[x][y].armadilha) != 0 ){
			if((mapa[x][y].armadilha) == buraco){
				printf("Armadilha: buraco! Jogador se machuca!\n");
				p->p.life -= 10;
                if(p->p.life <= 0){
                	return -1;
                }
			}else if((mapa[x][y].armadilha) == espinhos){
				printf("Armadilha: espinhos! Jogador se machuca!\n");
				p->p.life -= 5;
                if(p->p.life <= 0){
                	return -1;
                }
			}else if((mapa[x][y].armadilha) == ladrao) {
				printf("Armadilha: ladrao! Jogador perde dinheiro!\n");
				if ((p->loot) > 10){
					(p->loot) -= 10;
				}
				else{
					p->loot = 0;
				}
			}
		}
		return 0;
}


Sala** cria_mapa(int lin, int col, Jogador* player){
	Sala **mapa;

	mapa = (Sala **) malloc(sizeof(Sala *) * lin);
  	for(int i=0; i < lin; ++i){
    	mapa[i] = (Sala *) malloc(sizeof(Sala) * col);
  	}
	for(int l=0; l < lin; ++l){
		for(int c=0; c < col; ++c){
	      	mapa[l][c].p.life = 0;
	      	mapa[l][c].p.attack = 0;
	      	mapa[l][c].tesouro = 0;
	      	mapa[l][c].armadilha = 0;
		}
	}
    player->escudo = 0;
 	player->loot = 0;
 
	scanf(" (%i %i) - %i %i\n", &(player->x), &(player->y), &(player->p.life), &(player->p.attack));
    (player->x)-=1;
    (player->y)-=1;

    entradas_ITA(mapa);

	printf("Mapa inicializado!\n");
    printf("Jogador na posicao %i,%i\n", (player->x)+1, (player->y)+1);

  	return mapa;
}




int executa_passo(int N, int M, Sala** mapa, char step, Jogador* p){
	int x, y;
	int retorno;
	switch(step){
		case 'W':
			x = (p->x) - 1;
			y = (p->y);
			break;
		case 'S':
			x = (p->x) + 1;
			y = (p->y);
			break;
		case 'A':
			x = (p->x);
			y = (p->y) - 1;
			break;
		case 'D':
			x = (p->x);
			y = (p->y) + 1;
			break;
		default:
			return 0;
	}

    printf("Avancando para %i, %i...\n", x+1, y+1);


	if ( x < 0 || y < 0 || x >= N || y >= M){
		printf("Movimento Ilegal!\n");
	} else {
		(p->x) = x;
		(p->y) = y;

		retorno = executa_passo_2(mapa, p, x, y);
		if (retorno == -1)
		{
			return retorno;
		}
		

	}

	return 1;
}

void imprime_status_personagem(Jogador p){
	printf("Terminou na posicao (%i, %i)\n", (p.x)+1, (p.y)+1);
	printf("Vida: %i\n", p.p.life);
	printf("Dinheiro: %i\n", p.loot);
}


//Função principal
int main(){
  int n, m, movimentos, res;
  char passo;
  Jogador player;
  Sala** mapa;

  //Leitura do tamanho do mapa
  scanf("%d %d", &n, &m);

  //Função que cria o mapa e inicializa o Jogador de acordo com os dados da entrada
  mapa = cria_mapa(n, m, &player);

  //Leitura dos movimentos da simulação
  scanf("%d", &movimentos);

  //Para cada movimento do jogador...
  for(int i=0; i<movimentos; i++){
    //Lê o movimento
    scanf(" %c", &passo);

    //Executa a simulação do passo. Se o retorno for -1, o jogador morreu e encerra a simulação
    res = executa_passo(n, m, mapa, passo, &player);
    if(res == -1) break;
  }
 
  //Testa pra ver se o jogador terminou vivo
  res < 0 ? printf("You died...\n"): printf("Vitoria!\n");

  //Imprime as informações finais do jogador
  imprime_status_personagem(player);

  return 0;
}
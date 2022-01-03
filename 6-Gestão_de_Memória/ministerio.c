#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int adicionarLinhas(int N, char* linhas[N], char* str){
    static int i = 0;
    if (i<N){
        if (linhas[i] == NULL){ 
            linhas[i] = malloc(sizeof(char)*(strlen(str)));
            strcpy(linhas[i],str);
            return 1;
        }
        
        if(str[strlen(str)-1] == '\n')
        {   
            linhas[i] = realloc(linhas[i], sizeof(char)*(strlen(linhas[i])+strlen(str)+1));
            strcat(linhas[i],str);
            i++;
            return 1; 
        }
        else{
            linhas[i] = realloc(linhas[i], sizeof(char)*(strlen(linhas[i])+10));
            strcat(linhas[i],str);
            return 1; 
        }
        
    }
    
    return 0;
}

void imprimirLinhas(int N, char* linhas[N]){
  for (int j = 0; j < N; j++)
  {
    printf("%s",linhas[j]);
  }
}

void liberarLinhas(int N, char* linhas[N]){
  for(int k=0; k<N; k++){
    free(linhas[k]);
  }  
}

int main(){
  char str[10];
  int N;   
  scanf("%d\n", &N);
  char *linhas[N];
  
  for(int i=0; i<N; i++)
    linhas[i]=NULL;   
  
  do{
    fgets(str,10,stdin);
  }while(adicionarLinhas(N, linhas,str));

  printf("Texto liberado pelo Ministro\n");
  imprimirLinhas(N, linhas);
  
  liberarLinhas(N, linhas);
  return 0;
}
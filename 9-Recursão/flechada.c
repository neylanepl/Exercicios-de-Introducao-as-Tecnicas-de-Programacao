#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	char nome[21];
  int valor, peso;
}elementos;

typedef struct{
	char *pont_itens;
	int quant_itens;
	int valTotal_itens;
	int pesTotal_itens;
}cadaCombinacao;

/*typedef struct{
	int *pont_combi;
	int  combi_total;
}totalCombinacao;*/

void printSubset(elementos arr[], int n, int r, int index, cadaCombinacao data[], int i, int tc){
  static int k = 0;
  int count=0;
  int retorno=0;
  //data->pont_itens = malloc(sizeof(char) * r);
  if (index == r && k < tc){
    for (int j = 0; j < r; j++){
      if(r > 1){
        data[k].valTotal_itens += data[j].valTotal_itens;
        data[k].pesTotal_itens += data[j].pesTotal_itens;
        count ++;
        if(count==r){
          data[k].quant_itens = r;
          printf("KKKKK%d\n", k);
          printf("%d %d\n", data[k].valTotal_itens,  data[k].pesTotal_itens);
          k += 1;
        }
      }else{
        //data.pont_itens[k] = data[j].pont_itens;
        data[k].quant_itens = r;
        k += 1;

        printf("%d %d\n", data[j].valTotal_itens,  data[j].pesTotal_itens);
        
      }
    }
    
    return;
  }
  if(i >= n){
    return;
  }
  //data->pont_itens[index] = arr[i].nome;
  data[index].pesTotal_itens = arr[i].peso;
  data[index].valTotal_itens = arr[i].valor;
  printSubset(arr, n, r, index + 1, data, i + 1, tc);
  printSubset(arr, n, r, index, data, i + 1, tc);
}

int main()
{
	int q, p;
	scanf("%d %d", &q, &p);
	elementos itens[q];
	int cadaCombi[q+2];
	int combi[q+2];
	for (int i = 0; i < q; ++i){
		scanf("%s %d %d", itens[i].nome, &itens[i].valor, &itens[i].peso);
	}

  	for (int i = 0; i < q+2; ++i){
  		cadaCombi[i]=0;
  	}
  	

    printSubset(itens, n, r, 0, data, 0, tc);
    
  
      printf("Inventario final:");
      cadaCombinacao aux;
      for(int m=0; m< tc; m++){
        for(int l=m+1; l< tc; l++){
            if(data[l].valTotal_itens > data[m].valTotal_itens){
                aux = data[m];
                data[m] = data[l];
                data[l] = aux;
            }
        }
      }
      for(int j=0; j< pow(q,2); j++){
        if(data[j].pesTotal_itens == p || (data[j].pesTotal_itens<p)){
          printf("FINAL%d %d\n", data[j].valTotal_itens,  data[j].pesTotal_itens);
          break;
        }
      }
      
    
	return 0;
}
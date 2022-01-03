#include <stdio.h>

/**
 * Cria um histograma H com C categorias a partir de uma sequência de valores lidos da entrada-padrão.
 * A entrada a ser lida contém um valor inteiro N seguido de uma sequência de N valores reais.
 * 
 * Os valores lidos estarão entre na faixa de 0 a 10 (incluindo estes) e serão contabilizados no histograma
 * de acordo com o intervalo a qual pertence, levando em conta que haverá C categorias entre 0 e 10.
 * 
 * Por exemplo, se C for 5, teremos os intervalos [0; 2[, [2; 4[, [4; 6[, [6; 8[ e [8; 10]. Portanto, se o
 * valor 3.0 for lido, a 2ª categoria terá um elemento a mais no histograma. Se C for 3, os intervalos
 * seriam [0; 3.333...[, [3.333...; 6.666...[ e [6.666...;10]. Portanto, a 1ª categoria será atualizada.
 * 
 * @param c Número de categorias do histograma
 * @param h Array do histograma cujos valores serão atualizados a partir de dados lidos da entrada-padrão.
 */
void createHistogram(int c, int h[c]) {
    // faça sua implementação aqui
    int quanSeq;
    double intervalo, anterior=0, para=0; 
    intervalo= 10/c;

    for (int i = 0; i < c; ++i)
    {
       h[i]=0;
    }

    scanf("%d", &quanSeq);
    double notas[quanSeq];

    for (int j = 0; j < quanSeq; ++j)
    {
        scanf(" %lf", &notas[j]);
    }    


    for (int k = 0; k < quanSeq ; ++k)
    {   
        for (int l = 0; l < c; ++l)
        {   
            if (l+1 == c)
            {
                if( intervalo >= notas[k] && notas[k] >=  anterior){
                    h[l]=h[l] + 1;
                }
            }
            else if(l+1 != c)
            {
                if(intervalo > notas[k] && notas[k] >= anterior)
                {
                    h[l]=h[l]+1;
                }

            }
            anterior = intervalo;
            intervalo = intervalo + (10/c); 
          
        }
        anterior = 0;
        intervalo= 10/c;

    }

    

}

/**
 * Junta os valores de dois histogramas em um terceiro histograma.
 * 
 * @param c  Número de categorias do histograma.
 * @param h1 Array com os dados do 1º histograma.
 * @param h2 Array com os dados do 2º histograma.
 * @param joint Array do histograma cujos valores serão atualizados a partir dos dois primeiros.
 */
void joinHistograms(int c, int h1[c], int h2[c], int joint[c]) {
    // faça sua implementação aqui 

    for (int i = 0; i < c; ++i)
    {
      joint[i] = h1[i] + h2[i];
    }
    /*for (int p = 0; p < c; ++p)
    {
        printf("%i\n", joint[p]);
    }*/
}

/**
 * Imprime um histograma em modo textual. A altura do histograma (quantidade de linhas a
 * serem impressas) corresponde ao maior valor de seu array.
 * 
 * @param c Número de categorias do histograma.
 * @param h Array com os dados do histograma a imprimir.
 */
void printHistogram(int c, int h[c]) {
    // faça sua implementação aqui
    int maior=0, quant=0, aux[c], anterior=0, cont=0;
    for(int i=0;i<c;++i){
        if(h[i]>maior){
            maior=h[i];
        }
    }
    for (int i = 0; i < c; ++i)
    {
        aux[i]=0;
    }
    cont = maior;
    for (int j = 0; j < maior; ++j){   
        for (int  l= 0; l < c ; ++l)
        {   
            
           quant =  h[l];
           if (quant!= aux[l] && cont - quant == 0)
           {
               aux[l]=aux[l]+1;
           }
            printf("_");
            if (aux[l] >0)
            {
                printf("##");
            }
            else if(aux[l] == 0)
            {
                printf("__");
            }
                printf("_");
             
        }
        cont-=1;
        printf("\n");

    }
    printf("\n");
}

int main() {
    int numCateg;
    scanf("%i", &numCateg);

    int histA[numCateg];
    int histB[numCateg];
    int histAll[numCateg];

    createHistogram(numCateg, histA);
    createHistogram(numCateg, histB);
    joinHistograms(numCateg, histA, histB, histAll);

    printHistogram(numCateg, histA);
    printHistogram(numCateg, histB);
    printHistogram(numCateg, histAll);

    return 0;
}
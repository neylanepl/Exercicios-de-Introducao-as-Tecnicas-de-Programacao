#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE 305

typedef struct{
    int size;
    int *array;
}IouF;

typedef struct{
    int signal;
    int exp;
    IouF integer;
    IouF fractional;
}BigFloat;

void readline(char linha[MAX_LINE]){
    fgets(linha, MAX_LINE, stdin);
}

void casos_especiais(char *linha){
    char aux[MAX_LINE];
    if(linha[0] == '.'){
        aux[0] = '0';
        for(int j = 0; j < strlen(linha); ++j){
            aux[j+1] = linha[j];
        }
        strcpy(linha, aux);
    }

    if(linha[strlen(linha)-1] == '.'){
        linha[strlen(linha)] = '0';
        linha[strlen(linha)+1] = '\0';
    }
}

void quant_vetores(char *inteiros, char *fracionais, BigFloat *Bfloat){
    if (strlen(inteiros) % 9 == 0){
        Bfloat->integer.size = strlen(inteiros) / 9;
    }else if (strlen(inteiros) % 9 != 0){
        Bfloat->integer.size = strlen(inteiros) / 9 + 1;
    }
    Bfloat->integer.array = malloc(sizeof(int) * Bfloat->integer.size);

    if (strlen(fracionais) % 9 == 0){
        Bfloat->fractional.size = strlen(fracionais) / 9;
    }else if (strlen(fracionais) % 9 != 0){
        Bfloat->fractional.size = strlen(fracionais) / 9 + 1;
    }
    Bfloat->fractional.array = malloc(sizeof(int) * Bfloat->fractional.size);
}

void numero(IouF a ,char *b){
    int l, m, indice;
    char aux[11];
    for (l = 0; l < a.size; ++l){
        if (l == a.size - 1){
            if(strlen(b) % 9 == 0){
                indice = 8;
            }else{
                indice = strlen(b) % 9 - 1;
            }

            for (m = (strlen(b) - ((9 * l) + 1)); m >= 0; --m){
                aux[indice] = b[m];
                indice-=1;
            }

            if(strlen(b) % 9 == 0){
                 aux[9] = '\0';
            }else{
                aux[strlen(b) % 9] = '\0';
            }
        }else{
            aux[9] = '\0';
            indice = 8;
            for (m = (strlen(b) - ((9 * l) + 1)); m > (strlen(b) - ((9 * l) + 10)); --m){
                aux[indice] = b[m];
                indice-=1;
            }
               
        }
        a.array[l] = atoi(aux);
    }
}

void print_num(IouF a){
    int n, sub, aux;
    for (n = a.size - 1; n >= 0; --n){
        sub = 999999999 - a.array[n];
        aux = 8;
        while ((sub >= 9 * pow(10, aux)) && (n != a.size - 1)){
            printf("0");
            sub -= 9 * pow(10, aux);
            aux-=1;
        }
        printf("%d", a.array[n]);
    }
}



BigFloat strToBigFloat(char linha[MAX_LINE]){
    BigFloat Bfloat;

    char inteiros[MAX_LINE], fracionais[MAX_LINE], *parte;


    while(linha[strlen(linha)-1] == '0'){
        linha[strlen(linha)-1] = '\0';
    }

    if (linha[0] != '-'){
        Bfloat.signal = 1;
    }else if (linha[0] == '-'){
        Bfloat.signal = -1;
        for (int i = 1; i <= strlen(linha); ++i){
            linha[i - 1] = linha[i];
        }
    }

    casos_especiais(linha);

    parte = strtok(linha, ".");
    strcpy(inteiros, parte);
    parte = strtok(NULL, "\n");
    strcpy(fracionais, parte);

    Bfloat.exp = 0;
    while ((fracionais[strlen(fracionais)-2]!='.')
        &&(fracionais[strlen(fracionais)-1]!='0')
        &&(fracionais[Bfloat.exp] == '0')){
        Bfloat.exp+=1;
    }

    for (int k = Bfloat.exp; k <= strlen(fracionais); ++k){
        fracionais[k - Bfloat.exp] = fracionais[k];
    }

    quant_vetores(inteiros, fracionais, &Bfloat);

    numero(Bfloat.integer, inteiros);

    numero(Bfloat.fractional, fracionais);

    return Bfloat;
}


void printBigFloat(BigFloat Bfloat){
    
    if(Bfloat.signal == -1){
        printf("-");
    }

    print_num(Bfloat.integer);
    
    printf(".");

    for (int p = 0; p < Bfloat.exp; ++p){
        printf("0");
    }

    print_num(Bfloat.fractional);

    printf("\n");
}


int main() {
    char line[MAX_LINE];
    readline(line);
    BigFloat bf = strToBigFloat(line);
    printBigFloat(bf);
    printf("%i %u %u %u\n",
        bf.signal,
        bf.exp,
        bf.integer.array[bf.integer.size - 1],
        bf.fractional.array[bf.fractional.size - 1]
    );
    return 0;
}
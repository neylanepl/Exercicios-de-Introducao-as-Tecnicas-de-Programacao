#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int main()
{
    int valor, cont100, cont50, cont20, cont10, cont5, cont2, cont1;


    scanf("%i", &valor);
    
    if (valor >= 100) {
        cont100 = valor/100;
        valor = valor - (cont100 * 100);
        printf("%i nota(s) de R$ 100,00\n", cont100);
    } else{
        printf("0 nota(s) de R$ 100,00\n");
    }
    if (valor >= 50 && valor < 100) {
        cont50 = valor/50;
        valor = valor - (cont50 * 50);
        printf("%i nota(s) de R$ 50,00\n", cont50);
    }else{
        printf("0 nota(s) de R$ 50,00\n");
    }
    if (valor >= 20 && valor < 50) {
        cont20 = valor/20;
        valor = valor - (cont20 * 20);
        printf("%i nota(s) de R$ 20,00\n", cont20);
    }else{
        printf("0 nota(s) de R$ 20,00\n");
    }
    if (valor >= 10 && valor < 20) {
        cont10 = valor/10;
        valor = valor - (cont10 * 10);
        printf("%i nota(s) de R$ 10,00\n", cont10);
    }else{
        printf("0 nota(s) de R$ 10,00\n");
    }
    if (valor >= 5 && valor < 10) {
        cont5 = valor/5;
        valor = valor - (cont5 * 5);
        printf("%i nota(s) de R$ 5,00\n", cont5);
    }else{
        printf("0 nota(s) de R$ 5,00\n");
    }
    if (valor >= 2 && valor < 5) {
        cont2 = valor/2;
        valor = valor - (cont2 * 2);
        printf("%i nota(s) de R$ 2,00\n", cont2);
    }else{
        printf("0 nota(s) de R$ 2,00\n");
    }
    if (valor >= 1 && valor < 2) {
        cont1 = valor/1;
        valor = valor - (cont1 * 1);
        printf("%i nota(s) de R$ 1,00\n", cont1);
    }else{
        printf("0 nota(s) de R$ 1,00\n");
    }


    return 0;
    
}

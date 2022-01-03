#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char texto1[41]={0}, texto2[41]={0}, mult[81]={0}, maior[41]={0};
    int max1, max2, cont=0;
    
    fgets(texto1, 40, stdin);
    fgets(texto2, 40, stdin);
    
    max1=(int)strlen(texto1);
    max2=(int)strlen(texto2);
    
    if(max1>=max2){
        strcpy(maior, texto1);
    }else if(max1<max2){
        strcpy(maior, texto2);
    }
    
    for(int i = 0; maior[i+1] != '\0'; i++){
        if (i<max1-1)
        {
            mult[i+i] = texto1[i];
        }else{
            cont+=1;
        }
        
        if (i<max2-1)
        {
            mult[i+i+1] = texto2[i];
        }else{
            cont+=1;
        }
        
    }

    for(int x = 0; x<(max1+max2+cont); x++){
        if(isprint(mult[x])){
            printf("%c", mult[x]);
        }
        
    }

    return 0;
}
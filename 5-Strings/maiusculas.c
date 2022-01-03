#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char texto[60];
	char letra;
    fgets(texto, 60, stdin);

    for(int i = 0; texto[i] != '\0'; i++){
        if(isspace(texto[i])){
        	if (islower(texto[i+1]))
        	{
        		letra = texto[i+1];
        		texto[i+1] = toupper(letra);
        	}  
        }

        if (i!=0 && isspace(texto[i-1])==0)
        	{
        		letra = texto[i];
        		texto[i]=tolower(letra);
        	}
    }

    printf("%s\n",texto );


	return 0;
}
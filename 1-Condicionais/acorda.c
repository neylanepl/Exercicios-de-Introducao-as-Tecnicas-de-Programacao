#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int hora, minuto;

    	scanf("%d:%d", &hora, &minuto);

    	if (hora<12 || (hora==12 && minuto<01)) {
        	printf("Cedo demais!\n");
    	}
	else if (hora>12 || (hora==12 && minuto>=01)) {
        	printf("Hora de acordar...\n");
    	}
    
    	return 0;

}

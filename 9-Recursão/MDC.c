#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long mdc(long m, long n){
    if (n==0){
    	return m;
    }else{
    	return mdc(n, m % n);
    }
    
  }

int main()
{	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("MDC de %d, %d e %d: %ld\n", a, b, c, mdc(mdc(a, b), c));
	
	return 0;
}
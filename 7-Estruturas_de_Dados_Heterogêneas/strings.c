#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
  char *str;
  int capacity;
  int length;
} string;

void set_str(string* str1, char palavra[]){
	int multiplo;

	str1->length=strlen(palavra);
	multiplo = (int)((str1->length)/16)+1;
	multiplo = 16*multiplo;
	str1->capacity = multiplo;
	str1->str = malloc(sizeof(char)* str1->capacity);
	strcpy(str1->str, palavra);
}

void read_str(string* str2){
	char nome[301];
	int multiplo;

	scanf(" %[^\n]", nome);

	str2->length=strlen(nome);
	multiplo = (int)((str2->length)/16)+1;
	multiplo = 16*multiplo;
	str2->capacity=multiplo;
	str2->str = malloc(sizeof(char)* str2->capacity);
	strcpy(str2->str, nome);
}

void concat_str(string* str1, string* str2){
	int multiplo;

	str1->length=str1->length + str2->length;
	multiplo = (int)((str1->length)/16)+1;
	multiplo = 16*multiplo;
	str1->capacity=multiplo;
	str1->str = realloc(str1->str, sizeof(char*) * str1->capacity);
  	strcat(str1->str, str2->str);
}

void clear_str(string* texto){
    free(texto->str);
    texto->length = 0;
    texto->capacity =0;
    texto->str = NULL;
}

int main() {
    string greeting;
    string name;
    set_str(&greeting, "Oi ");
    read_str(&name);
    concat_str(&greeting, &name);
    printf("%s\n", greeting.str);
    printf("%i %i\n", greeting.capacity, greeting.length);
    clear_str(&greeting);
    clear_str(&name);
    return 0;
}
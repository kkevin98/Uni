/* staff about strings */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	char* s1="Sono la prima su\b\b stringa\0 questo è inutile";
	char* s2="Sono la seconda stringa";
	char* s3="Sono la terza stringa";
	
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	printf("%s\n", &(s1[strlen(s1)+1]));
	
	printf("La prima è lunga: %ld\n", strlen(s1));
	
	/*
	strcat(s1, s2);   you should check that s1 have enough space to store the concatenation
	printf("Concat s1 e s2: %s", s1);
	*/
	
	char s4[100];
	strcpy(s4, s1);
	printf("La parte nascosta della stringa 4 è: %s\n", &(s4e[strlen(s1)+1]));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	char *file = "123456.txt";
	
	FILE *ptr =  fopen(file, "r");

	if(ptr==NULL){
		printf("unable\n");

	}

	char line[50];

	
	fgets(line, 49, ptr);
	printf("line : %s\n", line);

	return 0;

}

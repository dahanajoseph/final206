#include <stdio.h>
#include <stdlib.h>


// withdraw : amount withdraw, new balance, current hour date, name,
// transfer : same + to who
// deposite : same
// file : book.txt 
// 1. number of the account
// 1. Type of operation withdraw, deposite, transfer
// 2. date
// 3. amount
// 4. new balance
// linefeed

void add(char *number, char *operation, char *amount, char *balance);

int main(int argc, char *argv[]){


	if(argc==1){
		printf("RBC-history.c : ERROR. No argument provided.");
		return 1;
	}

	else if(argc<5){
		printf("RBC-history.c : ERROR. Too few arguments provided.");
		return 1;
	}

	add(argv[1], argv[2], argv[3], argv[4]);
	return 0;

}

void add(char *number, char *operation, char *amount, char *balance){

	FILE *members = fopen("members.txt", "r");

	if(members==NULL){
		printf("No file with the members of RBC.\n");
		return;
	}


	char line_m[50];

	fgets(line_m, 49, members);

	int exist = 0;
	while(!feof(members)){
		if(strcmp(line_m, "12345\n")==0){
			exist = 1;	
			break;
		}
		else{
			int i = 0;
			while(i<4){
			        fgets(line_m, 49, members);
				i++;
			}
		}
	}

	fclose(members);

	if(exist ==0){
		printf("Account number not found amoung RBC members. \n");
		return;
	}

	char *booklet = malloc(10);
	
	int i = 0;
	while(i<6){
		*(booklet+i) = *(number+i);
		i++;
	}
	
	FILE *book = fopen(booklet, "a");

	fprintf(book,"%s\nAmount:%s\nBalance:%s\n", operation, amount, balance);

	fclose(book);

	return;

}

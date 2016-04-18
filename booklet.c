#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define boolean int
#define FALSE  0
#define TRUE 1

void add(char *id, char *operation, char *amount, char *balance);
void read(char *id, char *operation);
boolean exist(char *id);


void read(char *id, char *operation){

	if(exist(id)==FALSE){
		return;
	}

	FILE *book = fopen(id, "r");

	char data[50];
	char datacpy[50];

	fgets(data, 49, book);
	strcpy(datacpy, data);
	
	char *token = strtok(datacpy, " \n");

	if(strcmp(operation, "all")==0){
		while(!feof(book)){
			printf("%s", data);
			fgets(data, 49, book);
		}
	}

	else if(strcmp(operation, "withdraw")==0 ||strcmp(operation, "transfer")==0 || strcmp(operation, "deposite")==0){

		while(!feof(book)){
			if(strcmp(token, operation)==0){

				//operation
				printf("%s", data);
				//date
		                fgets(data, 49, book);
                                printf("%s", data);
				// amount
				fgets(data, 49, book);
				printf("%s", data);
				//balance
                	        fgets(data, 49, book);
         	                printf("%s\n", data);				

		 	        fgets(data, 49, book);
				strcpy(datacpy,data);
				strtok(datacpy," \n");	
			}

			else {
                        	fgets(data, 49, book);
                        	fgets(data, 49, book);
                                fgets(data, 49, book);
                        	fgets(data, 49, book);
				strcpy(datacpy, data);
                	        strtok(datacpy," \n"); 

			}
		}
	}

	else{

		printf("Not a valid operation.\n");
	}

	return;

}


void add(char *id, char *operation, char *amount, char *balance){

	if (exist(id) == FALSE){
		return;
	}

	
	system("set `date`");
	system("export DATE=`echo $@`");
	char *date = getenv("DATE");
	
	FILE *book = fopen(id, "a");

	fprintf(book,"Operation: %s\nDate: %s\nAmount:%s$\nBalance:%s$\n",operation, date, amount, balance);

	fclose(book);

	return;

}

boolean exist(char *id){

        FILE *members = fopen("../members.txt", "r");

        if(members==NULL){
                printf("No file with the members of RBC.\n");
                return;
        }


        char line_m[6];

        fgets(line_m, 6, members);

        int exist = FALSE;
        while(!feof(members)){
                if(strcmp(line_m, id)==0){
                        exist = TRUE;
                        break;
                }
                else{
                        int i = 0;
                        while(i<4){
                                fgets(line_m, 6, members);
                                i++;
                        }
                }
        }

        fclose(members);

        if(exist == FALSE){
                printf("Account number not found amoung RBC members. \n");
        }

	return exist;

}


/*int main(int argc, char *argv[]){


        if(argc==1){
                printf("RBC-history.c : ERROR. No argument provided.");
                return 1;
        }

        else if(argc==3){

                read(argv[1], argv[2]);
                return 0;

        }

        else if(argc==5){

                add(argv[1], argv[2], argv[3], argv[4]);
                return 0;

        }

        else {
                printf("RBC-history.c : ERROR. Too few or too much arguments provided.");
                return 1;
        }

        return 0;

}*/


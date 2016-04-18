#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUIT 1
#define INVALID 2
#define INSTR 3
#define WELCOME 4
#define FIRSTNAME 5
#define LASTNAME 6
#define WITHDRAW 7
#define DEPOSITE 8
#define TRANSFER 9
#define INVALIDAMOUNT 10

struct ACCOUNT {

	char first[20];
	char last[20];
	
//	char username[20];
//	char password[20];
//	
	float balance;
	
} ;


float deposite(struct ACCOUNT *a, float b, float amount);
float withdraw(struct ACCOUNT *a, float b, float amount);
void transfer(struct ACCOUNT *from, struct ACCOUNT *to, float amount);
void newAccount(struct ACCOUNT *a);
void viewBalance(struct ACCOUNT a);
void message(int mess);





int main(){


// Tools //
	
	float amount = 0;
	char op;
	char garbage;


// An account for transfer //


	struct ACCOUNT dahana;
	strcpy(dahana.first, "Dahana");
	strcpy(dahana.last, "Joseph");
	dahana.balance = 100.00;

	message(WELCOME);

 	scanf(" %c", &op);
	scanf("%c", &garbage);

	if(op == 'q'){

		message(QUIT);
		return 1;
	}


// New account


	while(op!='n'){
		message(INVALID);
		
		scanf(" %c", &op);
		scanf("%c", &garbage);
	}
	
	struct ACCOUNT member;

// First name

	message(FIRSTNAME);

	scanf(" %s",member.first);

	while(strlen(member.first)==0){

		message(FIRSTNAME);
        	scanf(" %s",member.first);
	}


// Last name

        message(LASTNAME);
	
        scanf(" %s",member.last);

        while(strlen(member.last)==0){

                message(FIRSTNAME);
                scanf(" %s",member.last);
        }



	newAccount(&member);
	
	scanf(" %c", &op);
	scanf("%c", &garbage);
	
	while(op!='q'){
		amount = 0;

		if(op!='w' && op!='d' && op!='b' && op!='t'){
			message(INSTR);
		}


		else if(op=='w'){
			
			message(WITHDRAW);

			scanf(" %f", &amount);
		        scanf("%c", &garbage);

			withdraw(&member, member.balance, amount);		
			viewBalance(member);
		}

                else if(op=='d'){
			message(DEPOSITE);                  
                  
			scanf(" %f", &amount);
                        scanf("%c", &garbage);
 
                        deposite(&member, member.balance, amount);
                        viewBalance(member);
                }


                else if(op=='b'){
			viewBalance(member);

                }

                else if(op=='t'){

                        message(TRANSFER);
			scanf(" %f", &amount);
                        scanf("%c", &garbage);

 
                        transfer(&member, &dahana, amount);
                        viewBalance(member);
                }

		else{

			printf("oups\n");
		}


		printf("Please enter your next operation.       ");
		scanf(" %c",&op);
                scanf("%c", &garbage);
		
	}
	message(QUIT);
	
	return 1;	

}




float deposite(struct ACCOUNT *a, float b, float amount){


	if(amount<=0){
		printf("Invalid amount of money for deposite. Please try again. \n");
		return 1.0;
	}
	

	a->balance = b + amount;
	return 0.0;
	
}



float withdraw(struct ACCOUNT *a, float b, float amount){

	if(amount<=0){

		printf("Invalid amount of money for withdraw. Please try again.\n");
		return 1.0;
	}

	else if(b-amount<0){
		printf("Sorry. You do not have enough money to withdraw this amount. (you poor) Please be reasonable or go work.\n");
		return 1.0;
	}

	a->balance = b - amount;
	return a->balance;

}

void newAccount(struct ACCOUNT *a){


	a->balance = 5.0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Welcome at RBC dear %s.~ \n \t We are happy to offer you a deposite of 5$. \n", a->first);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


	message(INSTR);
	return;

}


void transfer(struct ACCOUNT *from, struct ACCOUNT *to, float amount){

	float error = withdraw(from, from->balance, amount);
	if(error==1.0){
		printf("*************************\n");
		printf("* Transfer unsuccessful *\n");
		printf("*************************\n");
		return ;
	}

	error = deposite(to, to->balance, amount);
	
        if(error==1.0){

                printf("*************************\n");
                printf("* Transfer unsuccessful *\n");
                printf("*************************\n");
                return ;
        }
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ The transfer was successful ~\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}

void viewBalance(struct ACCOUNT a){

	printf("\tYour balance is %f .\n", a.balance);
	return;

}




void message(int mess){

        char *quit = "Thank you for using RBC self-service center. Goodbye\n";

        char *invalid = "You entered an invalid operation. Please press \"n\" to make a new account or \"q\" to quit.";
        char *instr = "Instructions : \"d\" for a deposite ; \"w\" for a withdraw ; \"b\" to see your balance or \"t\" to do transfer. \n\n";
        char *welcome = "Welcome on RBC self-service. \n To make a new account, please press \"n\". \n To quit please press \"q\". \n\n";

        char *firstname = "Please enter your first name.\n\n";
        char *lastname = "Please enter your last name.\n\n";

        char *withdraw = "Please enter how much you would like to withdraw. (xxxxx.yy) .\n\n";
        char *deposite = "Please enter how much you would like to depose. (xxxxx.yy) \n\n";
        char *transfer = "Please enter how much you would like to transfer to Dahana. (xxxxx.yy) \n\n";

        char *invalidAmount = "Invalid Amount ";


             if(mess == QUIT){          printf("%s\n", quit);}
        else if(mess == INVALID){       printf("%s\n", invalid ); }
        else if(mess == INSTR){         printf("%s\n", instr); }
        else if(mess == INVALIDAMOUNT){ printf("%s\n", invalidAmount); }
        else if(mess == WELCOME){       printf("%s\n", welcome); }
        else if(mess == FIRSTNAME){     printf("%s\n", firstname); }
        else if(mess == LASTNAME){      printf("%s\n", lastname); }
        else if(mess == WITHDRAW){      printf("%s\n", withdraw) ; }
        else if(mess == DEPOSITE){      printf("%s\n", deposite); }
        else if(mess == TRANSFER){      printf("%s\n", transfer); }

        return;

}





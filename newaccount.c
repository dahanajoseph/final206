


struct ACCOUNT {

        char first[20];
        char last[20];

//      char username[20];
//      char password[20];
//      
        float balance;

} ;

void newAccount(struct ACCOUNT *a);
void message(int mess);


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



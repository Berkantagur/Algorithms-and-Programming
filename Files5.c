#include <stdio.h>
struct clientData{
    int account;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main(void){

    FILE *fPtr = NULL;

    if((fPtr = fopen("credit.dat", "rb")) == NULL){
        puts("File could not be opened.");
    }else{

        printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

        while(!feof(fPtr)){
            struct clientData client = {0, "", "", 0.0};
            fread(&client, sizeof(struct clientData), 1, fPtr);

            if(client.account != 0){
                printf("%-6d%-16s%-11s%10.2f\n", client.account, client.lastName, client.firstName, client.balance);
            }
        }

        fclose(fPtr);
    }
}

// OUTPUT:
// Acct  Last Name       First Name  Balance
// 19    Smith           John         10.12
// 52    Doe             Jane        200.00
// 30    Brown           Sam         -30.41
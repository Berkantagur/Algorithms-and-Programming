#include <stdio.h>

struct clientData{
    int account;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main(void){
    FILE *fPtr = NULL;

    if((fPtr = fopen("credit.dat", "rb+")) == NULL){
        puts("File could not be opened.");
    }else{
        struct clientData client = {0, "", "", 0.0};
        printf("%s", "Enter account number (1 to 100, 0 to end input): ");
        scanf("%d", &client.account);

        while(client.account != 0){
            printf("%s", "Enter lastname, firstname and balance: ");

            fscanf(stdin, "%14s%9s%lf", client.lastName, client.firstName, &client.balance);

            fseek(fPtr, (client.account - 1) * sizeof(struct clientData), SEEK_SET);

            fwrite(&client, sizeof(struct clientData), 1, fPtr);

            printf("%s", "\nEnter account number: ");
            scanf("%d", &client.account);
        }

        fclose(fPtr);
    }
}

// OUTPUT:
// Enter account number (1 to 100, 0 to end input): 19
// Enter lastname, firstname and balance: Smith John 10.12
// Enter account number: 52
// Enter lastname, firstname and balance: Doe Jane 200.0
// Enter account number: 30
// Enter lastname, firstname and balance: Brown Sam -30.41
// Enter account number: 0
//
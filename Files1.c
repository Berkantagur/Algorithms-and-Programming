#include <stdio.h>

int main(void){

    FILE *fPtr = NULL;

    if((fPtr = fopen("client.txt", "w")) == NULL){
        puts("File could not be opened"); // puts() is used to print a string + newline

    }else{
        //File opened successfully
        puts("Enter the account, name and balance.");
        puts("Enter EOF to end input.");
        printf("%s", "? ");

        int account = 0;
        char name[30] = "";
        double balance = 0.0;
        scanf("%d%29s%lf", &account, name, &balance);

        while(!feof(stdin)){
            fprintf(fPtr, "%d %s %.2f\n", account, name, balance);
            printf("%s", "? ");
            scanf("%d%29s%lf", &account, name, &balance);
        }

        fclose(fPtr);
    }
}
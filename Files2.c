// Read a “record” from the file.
// Function fscanf is equivalent to scanf , except fscanf receives a file pointer for the file being read.
// After this statement executes the first time, account will have the value 100, name will have the value "Jones" and balance will have the value 24.98.

// Each time the second fscanf statement executes, the program reads another record from the file and account, name and balance take on new values.
// When the program reaches the end of the file, the file is closed and the program terminates.
// Function feof returns true only after the program attempts to read the nonexistent data following the last line.

#include <stdio.h>

int main(void){
    
    FILE *fPtr = NULL;
    if((fPtr = fopen("client.txt", "r")) == NULL){
        puts("File could not be opened!");
    }else{
        // Successfully opened.
        int account = 0;
        char name[30] = "";
        double balance = 0.0;

        printf("%-10s%-10s%s\n", "Account", "Name", "Balance");
        fscanf(fPtr, "%d%29s%lf", &account, name, &balance);

        while(!feof(fPtr)){ // "w" olsaydı stdin olurdu
            printf("%-10d%-10s%7.2lf\n", account, name, balance);
            fscanf(fPtr, "%d%29s%lf", &account, name, &balance);
        }

        fclose(fPtr);
    }
}
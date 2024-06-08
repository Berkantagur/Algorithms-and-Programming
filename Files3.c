// The program shows how to open a random access file, define a record format using a struct, write data to the disk and close the file.
// This program initializes all 100 records of the file "credit.dat" with empty structs using the function fwrite .
// Each empty struct contains 0 for the account number, " "(the empty string) for the last name, """ for the first name and 0.0 for the balance.
// The file is initialized in this manner to create space on the disk in which the file will be stored and to make it possible to determine whether a record contains data.

#include <stdio.h>

// clientData structure definition
struct clientData{
    int account;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main(void){

    FILE *fPtr = NULL; // credit.dat file pointer

    if ((fPtr = fopen("credit.dat", "wb")) == NULL){
        puts("File could not be opened.");
    }else{
        // create clientData with default information
        struct clientData bankClient = {0, "", "", 0.0};

        // output 100 blank records to file
        for (int i = 1; i <= 100; i++){
            fwrite(&bankClient, sizeof(struct clientData), 1, fPtr);
        }

        fclose(fPtr);
    }
}
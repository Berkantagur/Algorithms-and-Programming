// The file1.txt file is in sequential structure and contains book records consisting of an integer, a string and a floating point number representing
// the barcode number, the title and price. These records are fetched from the file1.txt file and written to the file2.dat file in binary form.

#include <stdio.h>

typedef struct{
    int barcode;
    char title[50];
    float price;
}BOOK;

int main(void){

    BOOK b;
    FILE *fPtr1 = NULL;
    FILE *fPtr2 = NULL;

    if ((fPtr1 = fopen("client.txt", "r")) == NULL){
        puts("File could not be opened.");
    }

    if ((fPtr2 = fopen("file2.dat", "wb")) == NULL){
        puts("File could not be opened.");
    }

    fscanf(fPtr1, "%d %s %f", &b.barcode, b.title, &b.price);

    while (!feof(fPtr1)){
        fwrite(&b, sizeof(BOOK), 1, fPtr2);
        fscanf(fPtr1, "%d %s %f", &b.barcode, b.title, &b.price);
    }
    
    // Display the contents of the file2.dat file
    /*while (fread(&b, sizeof(BOOK), 1, fPtr2)) {
        printf("Barcode: %d, Title: %s, Price: %.2f\n", b.barcode, b.title, b.price);
    }*/

    fclose(fPtr1);
    fclose(fPtr2);
    
}
// This programme receives the source file name and the destination file name from the user,
// reads the source file and copies it to the destination file.

#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *sPtr = NULL; // sPtr = source file pointer
    FILE *dPtr = NULL; // dPtr = destination file pointer

    char source[50] = ""; // Source file name
    char destination[50] = ""; // Destination file name
    char ch = '\0'; // Character to be read from the source file

    printf("Enter the source file name: ");
    scanf("%s", source);

    printf("Enter the destination file name: ");
    scanf("%s", destination);

    if ((sPtr = fopen(source, "r")) == NULL){
        printf("Error: Unable to open the source file.\n");
        exit(1);
    }

    if ((dPtr = fopen(destination, "w")) == NULL){
        printf("Error: Unable to open the destination file.\n");
        fclose(sPtr);
        exit(1); // return 1;
    }

    while ((ch = fgetc(sPtr)) != EOF){
        fputc(ch, dPtr);
    }

    fclose(sPtr);
    fclose(dPtr);

    printf("File copied successfully.\n");

    /*// Remove the source file
    if (remove(source) == 0){
        printf("Source file removed successfully.\n");
    } else {
        printf("Error: Unable to remove the source file.\n");
    }*/
   
    return 0;
}
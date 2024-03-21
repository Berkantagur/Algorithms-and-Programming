#include <stdio.h>
#define SIZE 100

int main(void) {
    //GETCHAR
    int c, i = 0;
    char sentence[SIZE] = ""; // variable to hold input by user
    puts("Enter a line of text:");

    // use getchar to read each character
    while (i < SIZE - 1 && (c = getchar()) != '\n' && c != '\n') {
        sentence[i++] = c;
    }

    sentence[i] = '\0'; // terminate string
    puts("\nThe line entered was:");
    puts(sentence); // display sentence
    puts(""); // \n newline


    //SPRINTF
    int x = 0;
    double y = 0.0;

    puts("Enter an integer and a double:");
    scanf("%d%lf", &x, &y);

    char s[SIZE] = ""; // create char array
    sprintf(s, "integer:%6d\ndouble:%8.2f", x, y); // create string

    printf("\nThe formatted output stored in array s is:\n%s\n", s);
    return 0;
}
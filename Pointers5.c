// Using subscripting and pointer notations with arrays.
#include <stdio.h>
#define ARRAY_SIZE 4

int main(void)
{

    int b[] = {10, 20, 30, 40}; // create and initialize array b
    int *bPtr = b;              // create bPtr and point it to array b

    // output array b using array subscript notation.
    puts("Array b printed with:\nArray subscript notation");

    // loop through array b
    for (int i = 0; i < ARRAY_SIZE; ++i){
        printf("b[%d] = %d\n", i, b[i]);
    }

    // output array b using array name and pointer/offset notation
    puts("\nPointer /offset notation where the pointer is the array name");

    // loop through array b
    for (int offset = 0; offset < ARRAY_SIZE; ++offset) {
        printf("*(b + %d ) = %d\n", offset, *(b + offset));
    }

    // output array b using bPtr and array subscript notation
    puts("\nPointer subscript notation");

    // loop through array b
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("bPtr[%d] = %d\n", i, bPtr[i]);
    }

    // output array b using bPtr and pointer/offset notation
    puts("\nPointer/offset notation");

    // loop through array b
    for (int offset = 0; offset < ARRAY_SIZE; ++offset) {
        printf("*(bPtr + %d) = %d\n", offset, *(bPtr + offset));
    }

    return 0;
}
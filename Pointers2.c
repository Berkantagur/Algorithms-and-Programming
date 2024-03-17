// Pointer - Array Relationship
// 1. The array name is a pointer to the first element of the array.
// 2. The pointer is used to access the array elements.(using the subscript operator) -> POINTER ARITHMETIC
// 3. The pointer is incremented to access the next element of the array.
// 4. The pointer is decremented to access the previous element of the array.
// 5. The pointer is used to dynamically allocate memory for the array. But array is not used to dynamically allocate memory for the pointer.
// 6. Dynamic memory allocation is done with the malloc() function.

#include <stdio.h>
#include <conio.h>

int main(){

    int arr[4] = {1, 2, 3, 4};
    int *ptr;
    ptr = arr;

    printf("%d\n", *ptr); // 1
    printf("%d\n", *(ptr + 1)); // 2
    printf("%d\n", *(ptr + 2)); // 3
    printf("%d\n", *(ptr + 3)); // 4
    printf("\n");

    ptr = &arr[3]; // ptr = arr[3] is not valid.

    printf("%d\n", *ptr); // 4
    printf("%d\n", *(ptr - 1)); // 3
    printf("%d\n", *(ptr - 2)); // 2
    printf("%d\n", *(ptr - 3)); // 1
    printf("\n");

    ptr = arr + 1;

    printf("%d\n", *ptr); // 2
    printf("%d\n", *(ptr + 1)); // 3
    printf("%d\n", *(ptr + 2)); // 4

    printf("\n");

    printf("%p\n", ptr); // 6422296
    printf("%p\n", ptr + 1); // 6422300
    printf("%p\n", ptr + 2); // 6422304
    printf("%p\n", ptr + 3); // 6422308

    printf("%p\n", &ptr); // 6422292

    getch();
    return 0;
}
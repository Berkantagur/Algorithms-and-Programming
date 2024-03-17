// Pointers - Call By Reference - Call By Value
// Value of a variable is passed to a function in Call By Value (copy of the variable is passed)
// Address of a variable is passed to a function in Call By Reference (original variable is passed)

#include <stdio.h>

// Call by value
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// Call by reference
void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 50, y = 60;

    printf("Before swapping:\n");
    printf("x = %d, y = %d\n", x, y);

    // Call by value
    swapByValue(x, y);
    printf("After swapping by value:\n");
    printf("x = %d, y = %d\n", x, y); // Değerler değişmez, çağırılan fonksiyon kendi kopyaları üzerinde çalışır.

    // Call by reference
    swapByReference(&x, &y);
    printf("After swapping by reference:\n");
    printf("x = %d, y = %d\n", x, y); // Değerler değişir, çağırılan fonksiyon asıl değişkenlerin bellek adreslerini alır ve bu adresler üzerinde işlem yapar.

    return 0;
}

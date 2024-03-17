// POINTERS
// 1. A pointer is a variable that stores the address of another variable.
// 2. The pointer is declared with the * operator.
// 3. The pointer is initialized with the address of the variable.

/*
    Pointer Declaration:           Adress of Operator    Content     Logical Operator
    int *ptr;                      ------------------    -------     ----------------
    int x = 10;                           A101              10             x
    ptr = &x;                             A102            
                                          A103
    printf("%d", *ptr); -> 10             A104
    printf("%d", ptr); -> A101            A105
    printf("%d", &ptr); -> A106           A106             A101           ptr
                                          A107
                                          A108
                                          A109
                                          A110
*/                                        

//Pointers içerisinde değer tutmaz, başka bir değişkenin adresi durur.
//  printf("%d", *ptr); -> 10 (ptr'nin gösterdiği adresteki değeri yazdırır.)
//  printf("%d", ptr); -> A101 (ptr'nin gösterdiği adresi yazdırır.)
//  printf("%d", &ptr); -> A106 (ptr'nin adresini yazdırır.)

#include <stdio.h>
#include <conio.h>

int main(){

    int a = 5;
    int *ptr, **countPtr;
    ptr = &a;
    countPtr = &ptr;

    printf("%d\n", a); // a'nın değeri (5)
    printf("%d\n", &a); // a'nın adresi (Örn: 6422300) // Adres için %p kullanılır.
    printf("%d\n", *ptr); // ptr'nin gösterdiği adresteki değer (5)
    printf("%d\n", ptr); // ptr'nin gösterdiği adres (Örn: 6422300)
    printf("%d\n", &ptr); // ptr'nin adresi (Örn: 6422296)
    printf("%d\n", **countPtr); // countPtr'nin gösterdiği adresteki değer (6422300)
    printf("%d\n", *countPtr); // countPtr'nin gÖsterdiği adres (Örn: 6422296)
    printf("%d\n", &countPtr); // countPtr'nin adresi (Örn: 6422292)

    getch();
    return 0;
}
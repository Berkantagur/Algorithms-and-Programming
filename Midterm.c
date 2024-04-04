#include <stdio.h>
#include <string.h>
/*
int main (void){

    int i, j, k,m;
    i = -3;
    j = 0;
    k = 0;
    m = 1;
    m = ++i && ++j && ++k;
    printf("%d  %d  %d  %d ", i, j, k, m);
    return 0;
}
//OUTPUT: -2  1  1  1
*/
/*
void fun(int (*p)[4]){
    printf("\n%d %d %d %d", (*p)[0], (*p)[1], (*p)[2], (*p)[3]);
}

int main(void){
    int x[3][4] = {{4, 5, 2, 8},{7, 6, 9, 0},{1, 3, 2, 6}};
    fun(x);
    fun(x+2);
    fun(x+1);
    return 0;
//OUTPUT:
//4 5 2 8
//1 3 2 6
//7 6 9 0
}
*/
/*
int main(void)
{

    int i, j = 0, k = 0, x, len;
    char str1[10][20], temp;
    char *str = "Hello World"; // 2 satır 5'er sütun

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == ' '){
            str1[k][j] = '\0';
            k++;
            j = 0;
        }else{
            str1[k][j] = str[i];
            j++;
        }
    }

    str1[k][j] = '\0';

    for (i = 0; i <= k; i++){
        len = strlen(str1[i]); // Hello = 5 str1[0], World! = 6 str1[1]
        for (j = 0, x = len - 1; j < x; j++, x--){
            temp = str1[i][j];
            str1[i][j] = str1[i][x];
            str1[i][x] = temp;
        }
    }
    for (i = 0; i <= k; i++){
        printf("%s ", str1[i]);
    }
    return 0;
//OUTPUT: olleH !dlroW
}
*/
/*
int main(void){
    char array[27] = "Algorithms and Programming";
    char *temp;
    temp = array;

    while (*temp != '\0'){
        temp++;
        printf("%c", *temp);
        temp++;
    }
    return 0;
//OUTPUT: loihsadPormig
}
*/

typedef struct{
    float real, imag;
}COMPLEX_T;

COMPLEX_T add(COMPLEX_T *c1, COMPLEX_T *c2){
    COMPLEX_T sum;
    sum.real = c1->real + c2->real;
    sum.imag = c1->imag + c2->imag;
    return sum;
}

int main(void){
    COMPLEX_T c1, c2, c3;
    c1.real = 1.0;
    c1.imag = 2.0;
    c2.real = 3.0;
    c2.imag = 4.0;
    c3 = add(&c1, &c2);
    printf("%f %f", c3.real, c3.imag);
    return 0;
}
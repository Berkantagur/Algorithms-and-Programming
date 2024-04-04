#include <stdio.h>
#include <string.h>

void sreverse(char *str){
    int i, len;
    len = slen(str);
    for (i = len - 1; i >= 0; i--){
        printf("%c", str[i]);
    }
}

int slen (char *str){
    int i = 0;
    while (str[i] != '\0'){
        str++;
        i++;
    }
    return i;
}

int main(void){

    int i, k = 0;
    char sentence[100], word[20];
    printf("Enter a sentence: ");
    gets(sentence); // fgets(sentence, 100, stdin);

    for (i = 0; sentence[i] != '\0'; i++){
        if(sentence[i] != ' '){
            word[k] = sentence[i];
            k++;
        }
        else{
            word[k] = '\0';
            sreverse(word);
            k = 0;
        }
    }
    word[k] = '\0';
    sreverse(word);
    return 0;
}
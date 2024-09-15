#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lowerstr(char *str);
int reversible(char str1[], char str2[]);

int main (){

    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf(" %[^\n]s", str1);

    printf("Enter second string: ");
    scanf(" %[^\n]s", str2);

    lowerstr(str1);
    lowerstr(str2);
    
    if(reversible(str1, str2)){
        printf("Output: True");
    } else {
        printf("Output: False");
    }

    return 0;
}

void lowerstr(char str[]){
    for(int i = 0; i < *str; i++){
        str[i] = tolower(str[i]);
    }
}

int reversible(char str1[], char str2[]){
    if(strlen(str1) != strlen(str2)){
        return 0;
    }

    char reversedStr[100];
    strcpy(reversedStr, str1);
    strrev(reversedStr);

    return strcmp(reversedStr, str2) == 0;
}
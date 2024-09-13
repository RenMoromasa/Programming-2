#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 2 Strings Comparison Activity - compare 2 strings and see if its reversible or not*/

void lowerstr(char str[]);
void reversible(char str1[], char str2[]);
void display(char str1[], char str2[]);

int main() {
    
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    scanf(" %[^\n]s", &str1);
    printf("Enter second string: ");
    scanf(" %[^\n]s", &str2);;
    
    lowerstr(str1);
    lowerstr(str2);
    reversible(str1, str2);
    display(str1, str2);
    
    return 0;
}

void lowerstr(char str[]){
    for(int i = 0; i < *str; i++){
        str[i] = tolower(str[i]);
    }
}

void reversible(char str1[], char str2[]){
    int len1, len2, i, reversible = 1; 
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    if(len1 != len2){
        reversible = 0;
    } else {
        for(i = 0; i < len1; i++){
            if(str1[i] != tolower(str2[len2 - i -1])){
                reversible = 0;
                break;
            }
        }
    }
}

void display(char str1[], char str2[]){
        
    if(reversible){
        printf("Output = True");
    } else {
        printf("Output = False");
    }
    
}


#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* 2 Strings Comparison Activity*/

void lowerstr1(char str1[]);
void lowerstr2(char str2[]);
void reversible(char str1[], char str2[]);
void display(char str1[], char str2[]);

int main() {
    
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    scanf("%s", &str1);
    printf("Enter second string: ");
    scanf("%s", &str2);;
    
    lowerstr1(str1);
    lowerstr2(str2);
    reversible(str1, str2);
    display(str1, str2);
    
    return 0;
}

void lowerstr1(char str1[]){
    for(int i = 0; i < *str1; i++){
        str1[i] = tolower(str1[i]);
    }
}
void lowerstr2(char str2[]){
    for(int i = 0; i < *str2; i++){
        str2[i] = tolower(str2[i]);
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


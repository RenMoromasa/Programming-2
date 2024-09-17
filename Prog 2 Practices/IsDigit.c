/*
2024-09-17-20-55-00.png
*/
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf(" %[^\n]s", &str);
    
    if(isDigitOnly(str)){
        printf("The string contains only digits.");
    } else {
        printf("The string contains non-digit characters.");
    }
}

int isDigitOnly(char str[]){
    
    for(int i = 0; str[i] != '\0'; i++){
        if(!isdigit(str[i])){
            return 0;
        }
    }
    return 1;
}
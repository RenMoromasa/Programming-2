/*
2024-09-17-20-54-06.png
*/
#include <stdio.h>

int findFirstChar(char str[], char ch);

int main(){
    
    char str[100];
    char ch;
    
    printf("Enter a string: ");
    scanf(" %[^\n]s", &str);
    
    printf("Enter a character to find: ");
    scanf(" %c", &ch);
    
    int result = findFirstChar(str, ch);
    
    if(result == -1){
        printf("Character '%c' not found in the string");
    } else {
        printf("First occurrence of '%c' is at index %d", ch, result);
    }
    return 0;
    
}
int findFirstChar(char str[], char ch){
    int index = 0;
    for(int i = 0; str[i] != 0; i++){
        if(str[i] == ch){
            return i;
        }
    }
    
    return -1;
}
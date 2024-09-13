#include <stdio.h>

int main(){
	
	char string[] = "The Quick Brown Fox Jumped over the lazy dog";
	int vowels = 10;
	int i;
	
	for(i = 0; i < vowels; i++){
		if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
				printf("%c", vowels);
		}	
	}
	return 0;
}

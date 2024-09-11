# include <stdio.h>
# include <stdlib.h>


int* getEven(int* arr, int size, int evencount){
    
    int i, *num, count = 0;
    
    num = (int*) malloc(sizeof(int) * evencount);
    
    for(i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
        num[count] = arr[i];
        ++count;
        }
    }
    
    return num;
}

int main(){
    
    int size, i, evencount = 0;
    int arr[100], *evens;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter values: ");

    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);
        
        if(arr[i] % 2 == 0){
            ++evencount;
        }
    }
        
    evens = getEven(arr, size, evencount);
    
    printf("Even numbers in the array are: ");
    
     for(i = 0; i < evencount; ++i){
        printf("%d ", evens[i]);
    }
    
    free(evens);
    
    return 0;
    
}

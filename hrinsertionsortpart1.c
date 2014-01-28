#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/* Head ends here */
void insertionSort(int size, int *  arr);

/* Tail starts here */
int main(void) {
    int size;
    scanf("%d", &size);
    int arr[size],i;
    for(i = 0;i < size;i++) { 
        scanf("%d", &arr[i]); 
    }

    insertionSort(size,arr);
   
    return 0;
}

void insertionSort(int size, int * arr) {
    int i = size-2;
    int t;
    int temp = arr[size-1];
    printf("temp = %d\n",temp);
    while(temp<arr[i]){
        arr[i+1] = arr[i];
        //printing array each time //
        for(t = 0;t<size;t++){
            printf("%d ",arr[t]);
        }
        printf("\n");
        --i;
    }
    arr[i+1] = temp;
    for(t = 0;t<size;t++){
            printf("%d ",arr[t]);
    }
}


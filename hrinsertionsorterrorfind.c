#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/* Head ends here */
#include <stddef.h>


int* insertionSort(int n, int *  arr) {    
    int i,k;
    for(i=1;i<n;i++){
        if(arr[i]>=arr[i-1]) continue;
        else{
            int temp = arr[i];
            int j=i-1;
            while(arr[j]>temp && j>0){
                j--;
            }
            if(j==0 && arr[j]>temp){
				for(k = i-1;k>=j;k--){
               		arr[k+1] = arr[k];
            	}	
            	arr[j] = temp;
            }
			else{
				++j;
				for(k = i-1;k>=j;k--){
               		arr[k+1] = arr[k];
            	}	
            	arr[j] = temp;
			}
        }
    }
    return arr;
}
/* Tail starts here */
int main(void) {   
   int _ar_size,i;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   		scanf("%d", &_ar[_ar_i]); 
	}
	int *arr = insertionSort(_ar_size, _ar);
   	for(i=0;i<_ar_size;i++){
		printf("%d ",arr[i]);
   	}
	return 0;
}

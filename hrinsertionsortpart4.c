// Program to count the number of shifts in an insertion sort for given testcases //

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int countmoves(int*,int);

int main() {

    int *arr,n,i,t=0,testcases;
    scanf("%d",&testcases);
    while(t<testcases){
        scanf("%d",&n);
        arr = (int*)malloc(sizeof(int)*n);
        for(i = 0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        int result = countmoves(arr,n);
        printf("%d",result);
        printf("\n");
        t++;
    }
    return 0;
}

int countmoves(int* arr,int n){
    int i;int count=0,k;
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
               		++count;
            	}	
            	arr[j] = temp;
            }
			else{
				++j;
				for(k = i-1;k>=j;k--){
               		arr[k+1] = arr[k];
               		++count;
            	}	
            	arr[j] = temp;
			}
        }
    }
    return count;
}

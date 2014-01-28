#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


void insertionSort(int n, int *arr);
void printarray(int*,int);



int main(void) {
    int n,i=0;
    int*arr;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    for(i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(n,arr);
    return 0;
}

void insertionSort(int n, int *arr) {
    int i;
    for(i=1;i<n;i++){
        if(arr[i]>=arr[i-1]) printarray(arr,n);
        else{
            int temp = arr[i];
            int j=i-1;
            while(arr[j]>temp){
                j--;
            }
            int k;
            for(k = i-1;k>j;k--){
                arr[k+1] = arr[k];
            }
            k++;
            arr[k] = temp;
            printarray(arr,n);
        }
    }
}

void printarray(int* arr,int n){
    int i=0;
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

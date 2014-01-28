// complete quicksort problem //

#include<stdio.h>
#include<stdlib.h>

void quicksort(int*,int,int);
void swap(int*,int*);

int main()
{
	int n,i,*arr;
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	for(i = 0;i < n;i++){
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	for(i = 0;i < n;i++){
		printf("%d ",arr[i]);
	}
	return 0;	
}

void quicksort(int*arr,int low,int high){
	int pivot = arr[low];
	int thi = low+1;
	int tsi = high;
	while(tsi > thi){
		while(arr[thi] <= arr[pivot])
			++thi;
		while(arr[tsi] > arr[pivot])
			--tsi;
		if(tsi > thi){
			swap(&arr[thi],&arr[tsi]);
		}
	}
	swap(&arr[pivot],&arr[tsi]);
	quicksort(arr,low,tsi-1);
	quicksort(arr,tsi+1,high);
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;	
}

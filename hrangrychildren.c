#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void quickSort( int a[], int l, int r);
int partition( int a[], int l, int r);

int main() {

    int *arr,n,k,i,j,min =  2147483647;
    scanf("%d",&n);
    scanf("%d",&k);
    printf("\n n and k are %d %d\n",n,k);
    arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //now sorting the array
    quickSort(arr,0,n-1);
    printf("Array after sorting\n");
	for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    //now taking the window of k elements and finding the combinations //
    for(i=0;i+(k-1)<n;i++){
        if(arr[i+(k-1)]-arr[i] < min){
            min = arr[i+(k-1)]-arr[i];
        }
    }
    printf("%d",min);
    return 0;
}

void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
	
}



int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

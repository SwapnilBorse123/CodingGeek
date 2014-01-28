// two arrays problem, to check if the given array satisfies the given property //
// basically its all about implementing the Fisher Yates algorithm

#include<stdio.h>
#include<stdlib.h>

void swap(int*,int*);
void shuffle(int*,int);
int factorial(int);


int main()
{
	int n,fact,i = 0;
	scanf("%d",&n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	// printing all the possible permutations in an array //
	fact = factorial(n);
	printf("The shuffled array is:\n");
	printf("\n");*/
	while(fact>0){
		shuffle(arr,n);
		for(i=0;i<n;++i){
			printf("%d ",arr[i]);
		}
		printf("\n");
		--fact;
	}
	return 0;	
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shuffle(int *arr,int n){
	int num,i,j;
	for(i = n-1,j = 0;i>0;--i,++j){
		num = rand() % (n-j);
		swap(&arr[i],&arr[num]);	
	}	
}

int factorial(int num){
	int prod = 1;
	while(num>0){
		prod = prod*num--;	
	}
	return prod;
}

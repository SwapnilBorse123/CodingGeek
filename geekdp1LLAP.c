// to find the length of the longest arithmetic progression //

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int LongestAP(int*,int);
int maximum(int,int);

int main()
{
	int n,*arr,i,j,k,max = 0,count = 0;
	printf("How many elements do you want? ");
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	printf("Enter the elements you want\n");
	for(i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	max = LongestAP(arr,n);
	printf("The length of the longest arithmetic progression is: %d",max);
	return 0;
}

int LongestAP(int *set,int n){
	//first base condition // two elements are in AP
	if(n == 2)return n;
	int maxl = 0,i,j,k;
	int Grid[n][n];
	// lets set all places as two cuz every two numbers are in AP
	for(i = 0;i<n;i++){
		for(j = 0;j<n;j++){
			Grid[i][j] = 2;
		}
	}
	// scanning j from i =2 to i =n-2 with i preceding and k following it
	
	for(j = n-2;j>0;j--){
		i = j-1;k = j+1;
		while(i>=0 && k<=n-1){
			if(set[i]+set[k] < 2*set[j]){
				k++;	
			}
			else if(set[i]+set[k] > 2*set[j]){
				Grid[i][j] = 2;i--;
			}
			else{
				Grid[i][j] = Grid[j][k]+1;
				maxl = maximum(maxl,Grid[i][j]);
				i--;k++;
			}
		}
		//while(i>=0)
	}
	return maxl;
}

int maximum(int a,int b){
	return (a>b?a:b);
}

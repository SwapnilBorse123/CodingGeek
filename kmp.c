//  implementing KMP algorithm for pattern matching in a string //

/*KMP (Knuth-Morris-Prat) algorithm matches the longest matching pattern with the pattern from the beginning */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[50];
	int len,i=0,j=1,max = 0,index;
	printf("Enter your string: \n\n");
	scanf("%s",str);
	len = strlen(str);
	int *arr = (int*)malloc(sizeof(int)*len);
// Creating the KMP table //
	arr[0] = 0;
	for(i = 0;i<len;i++){
		while(j<len){
			if(str[j] == str[i]){
				arr[j] = arr[j-1]+1;
				i++;j++;	
			}
			else{
				arr[j] = 0;
				i = 0;
				j++;	
			}
		}
	}
// Finding the maximum number of match //
	for(i = 0;i<len;i++){
		if(arr[i]>max){
			max = arr[i];
			index = i;
		}
	}

// Printing the longest common matching pattern //
	printf("\n\nThe longest matching pattern is:\n");

	for(i = (index-max)+1;i<=index;i++){
		printf("%c ",str[i]);
	}
	return 0;		
}

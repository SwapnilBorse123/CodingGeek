//Program to calculate the number of ways to reach a step if you can take a hop of one step or a hop of two steps//
/*Small example of dynamic programming paradigm */

#include<stdio.h>
#include<stdlib.h>

int return_step(int);

int main(){
	int num,temp;
	printf("Enter the number of step:\n");
	scanf("%d",&num);
	if(num == 2) temp = 2;
	else if(num == 1) temp = 1;
	else{
		
		temp = return_step(num-1) + return_step(num-2);	
	}
	printf("Possible ways to reach step %d are %d ",num,temp);
	return 0;
}

int return_step(int n){
	if(n == 1)
		return 1;
	if(n == 2) return 2;
	return(return_step(n-1)+return_step(n-2));

}

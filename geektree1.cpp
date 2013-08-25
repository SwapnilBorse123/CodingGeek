#include<stdio.h>
#include<conio.h>

int search(int arr[],int x,int n);
void printpostorder(int in[],int pre[],int root);


main()
{
	int n;
	int in[10];
	int pre[10];
	printf("How many elements you want?\n");
	scanf("%d",&n);
	printf("\nEnter the inorder elements\n");
	for(int i = 0;i<n;i++){
		scanf("%d",&in[i]);
	}
	printf("\nEnter the pre order elements\n");
	for(int i = 0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	printf("\nPostorder traversal is:\n");
	printpostorder(in,pre,n);
}


int search(int a[],int num,int n){
	for(int i = 0;i<n;i++){
		if(a[i] == num)
			return i;
	}
	return -1;
}

void printpostorder(int in[],int pre[],int n){
	int root = search(in,pre[0],n);
	
	if(root != 0){  //left subtree has elements
		printpostorder(in,pre+1,root);
	}
	if(root != n-1){  //right subtree has elements
		printpostorder(in+root+1,pre+root+1,n-1-root);
	}
	printf("%d ",pre[0]);
}

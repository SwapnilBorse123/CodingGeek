// to check if the string is palindrome using recursion //

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool isPalindrome(char*);
char* substring(char* str,int pos,int len);

int main()
{
	char str[30];
	bool flag = false;
	printf("Please enter your string:\n");
	scanf("%s",str);
	flag = isPalindrome(str);
	if(flag){
		printf("Your string is a palindrome!!");
	}else printf("Your string is a not a palindrome!!");
	return 0;
}

bool isPalindrome(char* str){
	int len = strlen(str);
	if(len<=1) return true;
	else{
		return(str[0] == str[len-1] && isPalindrome(substring(str,1,len-2)));/*Substring library funtion is not available in C so had
		to write my own funtion and it was fun :D :) */
	}
}

char* substring(char* str,int pos,int len){
	char* temp = (char*)malloc(sizeof(char)*len);
	while(pos <= len){
		*temp++ = str[pos++];
	}
	return temp;
}

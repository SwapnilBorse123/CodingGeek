#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;

void strreverse(char* s1);

int main(){
	string s;
	cout<<"enter a string\n";
	getline(cin,s);
	cout<<"The complete reverse string is\n";
	/*for(int i=0;i<=s.length()/2;i++){
	int l=s.length();
	char temp;
	temp=s.at((l-1)-i);
	s.at((l-1)-i)=s.at(i);
	s.at(i)=temp;
	}*/
	strreverse(s);

	cout<<s;
	//char *p=strtok(s,' ');

	getch();
	return 0;
}
void strreverse(char* s1){
	for(int i=0;i<=s1.length()/2;i++){
	int l=s1.length();
	char temp;
	temp=s1.at((		l-1)-i);
	s1.at((l-1)-i)=s1.at(i);
	s1.at(i)=temp;
	}
	//return s1;
}



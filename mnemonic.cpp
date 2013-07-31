// Making a mnemonic table and reading it in a structure

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

char* convert (string);


struct Table{
	int opcode;
	string mnemo;
};

char Filename[2];


int main()
{
	int num;
	char buffer[5];
	std::vector<Table*> table;
	FILE *fp;
	
	fp = fopen("mnemonic.txt","r");
	if(fp == NULL)
		cout<<"Failed to open the file";
	string s = "",temp = "";
	char ch;
	while(1){
		ch = fgetc(fp);
		if(ch == EOF)
			break;
		else if(ch>=48 && ch<=57){
			temp = temp + ch;
		}
		else if(ch == 32){
			char* cptr = convert(temp);
			num = atoi(cptr);
			temp = "";
		}
		else if(ch>=65 && ch<=90 || ch>=97 && ch<=122){
			temp = temp + ch;
		}
		else{
			Table* t = new Table;
			t->opcode = num;
			t->mnemo = temp;
			temp = "";
			table.push_back(t);
		}
	}
		Table* t = new Table;
		t->opcode = num;
		t->mnemo = temp;
		temp = "";
		table.push_back(t);
	for(std::vector<Table*>::iterator it = table.begin();it != table.end();++it){
		Table* tptr = *it;
		cout<<"opcode "<<tptr->opcode<<" "<<"mnemo "<<tptr->mnemo<<endl;	
	}
	fclose(fp);
	return 0;
}

char* convert (string str){
	string FileMeasure = str;
	int TempNumOne=FileMeasure.size();
	for (int a=0;a<=TempNumOne;a++)
        {
            Filename[a]=FileMeasure[a];
        }	
    return(Filename);
}

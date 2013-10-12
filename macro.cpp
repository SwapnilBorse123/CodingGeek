#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<string.h>
#include<fstream>


using namespace std;

char* stringtoarr(string s);
string tostring(int num);


struct MNT{
	string name;
	int PP;
	int KP;
	int EV;
	int MDTP;
	int KPDTP;
	int SSTP;
};
struct KPDTAB{
	string par1;
	string par2;
};


int main()
{
	char* alstr;
	string PNTAB[5];
	string EVNTAB[4];
	string SSNTAB[4];
	KPDTAB kpdtab[1];
	MNT mnt[1];
	
	// Reading input from the file //
	
	FILE* fp;
	fp = fopen("macrowidoutlab.txt","r");
	string all = "";
	if(fp == NULL){
		printf("Couldn't open your file, sorry!!");
	}
	else{
		while(1){
			char ch = fgetc(fp);
			if(ch == EOF) break;
			all = all + ch;
		}
	}

	alstr = stringtoarr(all);
	//cout<<alstr;

	//Scanning for parameters//
	int i = 0,nenter = 0,pn_ind = 0;
	char ch;
	string temppar = "";

	while(all[i] != '\0'){
		if(all[i] == '\n')nenter++;
			if(nenter<2){
				if(all[i] == '&'){
					i++;
					while(all[i]>='A' && all[i]<='Z'){
						temppar = temppar + all[i];
						i++;
					}
					PNTAB[pn_ind++] = temppar;
					temppar = "";
				}
			}
		i++;	
	}
	
	//Scanning for the expansion time variables
	
	i = 0;string tempwrd = "",evar = "";
	
	while(all[i]!='\0'){
		if(all[i]!='\t' && all[i]!='\n')
		tempwrd = tempwrd + all[i];
		else{
			if(tempwrd == "LCL" || tempwrd == "GBL"){
				i += 2;
				while(all[i] >= 'A' && all[i] <= 'Z'){
					evar = evar + all[i];	
					i++;
				}
				EVNTAB[0] = evar;
			}
			tempwrd = "";		
		}
		i++;	
	}
	
	//Scanning for the sequencing symbol
	
	string all1 = "",ssym = "";
	FILE* fp1;
	fp1 = fopen("macrodef.txt","r");
	
	if(fp1 == NULL){
		printf("Couldn't open your file, sorry!!");
	}
	else{
		while(1){
			char ch = fgetc(fp1);
			if(ch == EOF) break;
			all1 = all1 + ch;
		}
	}
	
	i = 0;
	while(all1[i]!='\0'){
		if(all1[i] == '\n' && all1[i+1] == '.'){
			i+=2;
			while(all1[i] >= 'A' && all1[i] <= 'Z'){
				ssym = ssym + all1[i];
				i++;
			}
			SSNTAB[0] = ssym;
		}
		i++;	
	}
	
	//Creating MNT
	
	i = 0;string macname = "";tempwrd = "";
	while(all[i]!='\0'){
		if(all[i]!='\t' && all[i]!='\n')
		tempwrd = tempwrd + all[i];
		else{
			if(tempwrd == "MACRO"){
				i +=1;
				while(all[i] >= 'A' && all[i] <= 'Z'){
					macname = macname + all[i];	
					i++;
				}
				mnt[0].name = macname;
				break;				
			}
			tempwrd = "";		
		}
		i++;	
	}
	mnt[0].PP = 2;
	mnt[0].KP = 1;
	mnt[0].EV = 1;
	
	string kpara = "",kpara1 = "";
	while(all[i]!='\0'){
		if(all[i] == '='){
			int j = i;
			while(all[j]!='&'){
				j--;	
			}
			j++;
			while(all[j] >= 'A' && all[j] <= 'Z'){
				kpara = kpara + all[j];	
				j++;			
			}
			i++;
			while(all[i] >= 'A' && all[i] <= 'Z'){
				kpara1 = kpara1 + all[i];
				i++;
			}
			kpdtab[0].par1 = kpara;
			kpdtab[0].par2 = kpara1;
			break;
		}
		i++;
	}
	
	// Creating MDT //
	int count = 0;i = 0;string onlywrd = "",fwrd = "";
	while(count<2){
		if(all1[i] == '\n'){
			count++;	
		}
		i++;	
	}
	i++;

		ofstream myfile;
			myfile.open("intermcode.txt");
	
	while(all1[i]!='\0'){
		if(all1[i] != '\t' && all1[i] != '\n' && all1[i]!=' ' && all1[i]!='+'){
			onlywrd = onlywrd + all1[i];	
		}
		else{
			char spchar;
			if(all1[i] == '\n'){
				spchar = '\n';
			}
			if(all1[i] == '\t'){
				spchar = '\t';		
			}
			int len = onlywrd.length();
			for(int k=0;k<len;k++){
				if(onlywrd[k]>='A'&& onlywrd[k]<='Z' || onlywrd[k]>='0'&& onlywrd[k]<='9' || onlywrd[k] == '\'' || onlywrd[k] == '=' || onlywrd[k] == '+'){
					fwrd = fwrd + onlywrd[k];
				}
			}
			
			//complete compare algo;
			//writing IC to a file
		
			string ic = "";
			int counter = 0;
			for(int k=0;k<3;k++){
				if(fwrd == PNTAB[k]){
					/*if(spchar == '\n'){
						cout<<"(P,"<<k+1<<")"<<endl;
						spchar = ' ';					
					}
					else if(spchar == '\t'){
						cout<<"(P,"<<k+1<<")"<<"\t";
						spchar = ' ';
					}
					else*/ myfile<<"(P,"<<k+1<<")"<<" ";
					counter++;
					break;
				}
			}	
			for(int k=0;k<1;k++){
				if(fwrd == EVNTAB[k]){
					/*if(spchar == '\n'){
						cout<<"(E,"<<k+1<<")"<<endl;
						spchar = ' ';					
					}
					else if(spchar == '\t'){
						cout<<"(E,"<<k+1<<")"<<"\t";
						spchar = ' ';
					}else*/ myfile<<"(E,"<<k+1<<")"<<" ";
					counter++;
					break;
				}
			}
			for(int k=0;k<1;k++){
				if(fwrd == SSNTAB[k]){
					/*if(spchar == '\n'){
						cout<<"(S,"<<k+1<<")"<<endl;
						spchar = ' ';					
					}
					else if(spchar == '\t'){
						cout<<"(S,"<<k+1<<")"<<"\t";
						spchar = ' ';
					}
					else*/ myfile<<"(S,"<<k+1<<")"<<" ";
					counter++;
					break;
				}
			}
			if(counter == 0){
				myfile<<fwrd<<" ";
				counter = 0;	
			}
			fwrd = "";			
			onlywrd = "";
		}
		i++;	
	}
	myfile<<"MEND";
	myfile.close();
	
	//Printing all the tables //
	
	cout<<endl<<endl<<"PNTAB"<<endl;
	for(int k=0;k<3;k++){
		cout<<PNTAB[k]<<endl;
	}
	cout<<endl<<"EVNTAB"<<endl;
	for(int k=0;k<1;k++){
		cout<<EVNTAB[k]<<endl;
	}
	cout<<endl<<"SSNTAB"<<endl;
	for(int k=0;k<1;k++){
		cout<<SSNTAB[k]<<endl;
	}
	
	// taking the input
	
	struct APTAB{
		int num;
		string str;	
	};
	
	APTAB aptab[3];
	int EVTAB[1];
	
	string input="",param="",actualpar="";char cha;int j = 0;
	
	FILE *Fpnt = fopen("macroinput.txt","r");
	if(Fpnt == NULL){
		cout<<"Sorry cannot open your file\n";
	}
	else{
		while(1){
			cha = fgetc(Fpnt);
			if(cha == EOF)break;
			else input = input + cha;
		}
	}
	i = 0;
	while(input[i]!='\0'){
		if(input[i] != ' ' && input[i] != '\n')
			param = param + input[i];
		else{
			if(param == mnt[0].name){
				i++;
				aptab[0].str = "AREA";
				aptab[1].num = 5;
				aptab[2].str = "AREG";
				EVTAB[0] = 0;
				/*while(input[i]!='\n'){
					if(input[i]>='A' && input[i]<='Z' || input[i]>='0' && input[i]<='9'){
						actualpar = actualpar + input[i];
					}
					else{
						cout<<actualpar<<" ";
						//aptab[j++] = actualpar;
						actualpar = "";
					}
					i++;		
				}
				actualpar = "";*/
			}
		}
		i++;	
	}
	
	// Reading the intermediate code//
	FILE* icode;string intcode="";
	icode = fopen("intermcode.txt","r");
	if(icode == NULL){
		cout<<"Sorry cannot open your file\n";	
	}
	else{
		while(1){
			char c = fgetc(icode);
			if(c == NULL)break;
			intcode = intcode + c;		
		}
	}
	cout<<intcode<<" ";
	return 0;
}

//Function to convert strings to character arrays //

char* stringtoarr(string s){
	int l = s.length();
	char* arr = (char*)malloc(sizeof(char)*l+1);
	int i = 0;
	while(i<l){
		arr[i] = s[i];
		i++;
	}
	return arr;
}

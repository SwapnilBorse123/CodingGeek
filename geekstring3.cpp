// Longest subsequence problem //

#include<iostream>
#include<algorithm>
#include<cstring>


using namespace std;

int main()
{
	// Initialising the variables
	
	
	string s1,s2,output = "empty",temp = "";
	cout<<"Enter the strings:\n\n";
	getline(cin,s1);
	getline(cin,s2);
	int t,max = 0,cnt = 0;   
	if(s1.compare(s2) == 0)													 //If both are equal anyone is largest subsequence
		cout<<"Largest common subsequence is:"<<endl<<s1;
		
	//If not same then do the following
		
	else{
		try{
			int i=0,j=0;
			while(s1[i] != '\0'){
				t = i; j = 0;
				while(s2[j] != '\0'){
					A:					
					
					if(s1[t] == s2[j]){
						temp = temp + s1[t];
						cnt++;
				
						t++;j++;
						
						goto A;
					}
					else{
						if(cnt > max){
							max = cnt;
							output = temp;
							cnt  = 0;
							temp = "";	
						}
						else temp = "";
						cnt = 0;
					}
					j++;
				}
				i++;
			}
		}catch(...){
			cout<<"Exception caught ;)";	
		}
		
		cout<<endl<<"Largest common subsequence is:"<<output<<endl;
	}
	return 0;
}

// program to output the subsequence in ascending order having the largest product in the subset of three

#include<iostream>

using namespace std;

int main()
{
	int a[15],lsl[15],lgr[15],prod[15],n,i,j,k,max = 1,max1 = 1;
	cout<<"Enter how many elements do you want? max 15 ";
	cin>>n;
	cout<<"Enter elements:\n";
	for(int t = 0;t<n;t++){
		cin>>a[t];
	}
	//cout<<"largest subsequence is: ";
	
	for(i = 1;i<n-1;i++){
		for(j = 0;j<i;j++){
			max = 0;
			if(a[j]<a[i]){
				if(a[j] >= max)
					max = a[j];
			}
		}
		lsl[i] = max;
		
		for(k = 1+i;k<n;k++){
			max = 0;
			if(a[k]>a[i] && max1 <= a[k]){
				max1 = a[k];
			}
		}
		lgr[i] = max1;
		
		prod[i] = lsl[i]*a[i]*lgr[i];
		cout<<"values for index "<<i<<" lsl "<<lsl[i]<<" lgr "<<lgr[i]<<endl;
		
	}
	int temp;
	for(i = 1;i<n-1;i++){
		int max = 0;
		if(prod[i] > max){
			max = prod[i];
			temp = i;
		}
	}
	for(int i = 1;i<n-1;i++){
		cout<<"Product for index"<<i<<" is "<<prod[i]<<endl;	
	}
	cout<<lsl[temp]<<" "<<a[temp]<<" "<<lgr[temp];
	return 0;
}

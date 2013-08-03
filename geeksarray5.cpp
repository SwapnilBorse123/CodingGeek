// sorting the array according to the frequency of the elements

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,arr[20],num[20],times[20],cnt = 1;
	int n_times = 0,j = 0,k = 0;
	cout<<"How many elements?(max20) ";
	cin>>n;
	cout<<"Enter them\n";
	for(int i=0;i < n;i++){
		cin>>arr[i];
	}
	
	cout<<endl;
	// sorting the array
	
	for(int i=0;i < n;i++){
		for(int j=0;j < n;j++){
			if(arr[i]<arr[j])
			swap(arr[i],arr[j]);
		}
	}
	

	for(int i=0;i < n;i++){
		if(arr[i] == arr[i+1])
			cnt++;
		else{
			times[j++] = cnt;
			n_times++;
			num[k++] = arr[i];
			cnt = 1;
		}
	}
	
	// sorting the times and number arrays simultaneously so that they match
	
	for(int i = 0;i<n_times;i++){
		for(int j = 0;j<n_times;j++){
			if(times[i]>times[j]){
				swap(times[i],times[j]);
				swap(num[i],num[j]);
			}
		}
	}
	
	cout<<"The array sorted frequency wise is: "<<endl;
	
	for(int i = 0;i<n_times;i++){
		int term = times[i];
 		for(int j = 0;j<times[i];j++)
		 	cout<<num[i]<<" ";
		 	cout<<"  ";
	}
	return 0;
}

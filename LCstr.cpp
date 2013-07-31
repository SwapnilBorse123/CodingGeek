#include<iostream>
using namespace std;

int main(){
    int dp[100][100],MAX=-1,MAXINDEX;
    string a,b;
    cout<<"Enter two strings\n";
    getline(cin,a);
    getline(cin,b);
    int n = a.length();
    int m = b.length();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0){dp[i][j]=0;continue;}
            if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
            if(MAX < dp[i][j]){
                MAX = dp[i][j];
                MAXINDEX=i;
            }
        }
   // cout<<MAXINDEX<<" "<<MAX;
    cout<<"Longest Common Substring is \""<<a.substr(MAXINDEX-MAX,MAX)<<"\"\n";
}


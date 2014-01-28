#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findChocs(long int,int,int);

int main()
{
    int t,c,m,cnt = 0;
    long int n;
    printf("Enter the value of T: ");
    scanf("%d",&t);
    while(cnt < t){
		printf("Enter the value of n,c,m:\n");
        scanf("%ld %d %d",&n,&c,&m);
        int result = findChocs(n,c,m);
        printf("%d\n",result);
        cnt++;
    }
    return 0;
}
int findChocs(long int n,int c,int m){
    int Chocs = n/c;
    int wrappers = Chocs;
    int free = wrappers/m;
    int totalChocs = Chocs +  free;
    wrappers = (wrappers - (free * m))+free;
    if(wrappers < m){
		return totalChocs;
    }
    while(wrappers>=m){
		int temp = wrappers/m;
		totalChocs = totalChocs + temp;
		wrappers = (wrappers - (temp * m))+temp;
    }
    return totalChocs;
}

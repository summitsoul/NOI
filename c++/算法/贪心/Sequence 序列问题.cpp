#include<iostream>
#include<algorithm>
using namespace std;
    
int main(){
	int n;	scanf("%d",&n);
	long long ans=0;
	long long a[1000010];
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=2;i<=n;i++)
		ans+=max(a[i-1],a[i]);
	return 0;
}

#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	long long n;
	long long maxn=99999999999999;
	long long a[100010],b[100010];
	cin>>n;
	for(long long i=1;i<=n;i++)	cin>>a[i];
	for(long long i=1;i<=n;i++)	cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	cout<<a[1]+b[1]<<" ";
	cout<<min(a[1]+b[2],a[2]+b[1])<<" ";
	cout<<max(a[1]+b[2],a[2]+b[1])<<" ";
	return 0;
}

#include<iostream>
#define N 500010
#define M 1000000007
using namespace std;
long long a[N],b[N];
long long prea[N],preb[N];
long long ans;

int main(){
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) prea[i]=prea[i-1]+a[i];
	for(int i=1;i<=n;i++) preb[i]=preb[i-1]+b[i];
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
			ans+=(((prea[r]-prea[l-1])%M)*((preb[r]-preb[l-1])%M))%M;
	cout<<ans%M<<endl;
	return 0;
}

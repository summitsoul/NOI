#include<cmath>
#include<iostream>
using namespace std;
int n,m,a[10010];
long long ans;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y; cin>>x>>y;
		ans+=min(a[x],a[y]);
	}
	cout<<ans<<endl;
	return 0;
}

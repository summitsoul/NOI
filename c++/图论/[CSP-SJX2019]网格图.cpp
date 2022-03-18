#include<iostream>
#include<algorithm>
#define N 300010
using namespace std;
int n,m,a[N],b[N];
long long ans;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	ans=(long long)a[1]*(m-1)+(long long)b[1]*(n-1);
	int x=2,y=2,line=1,row=1;
	while(x<=n&&y<=m){
		if(a[x]<=b[y]) ans+=(long long)a[x++]*(m-row),line++;
		else ans+=(long long)b[y++]*(n-line),row++;
	}
	cout<<ans<<endl;
	return 0;
}

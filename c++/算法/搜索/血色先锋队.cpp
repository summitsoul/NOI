#include<bits/stdc++.h>
#define N 250001
using namespace std;
int n,m,a,b;
int x[N],y[N],x1[N],Y1[N],maxn[N];

int main(){
	memset(maxn,0x3f,sizeof(maxn));
	cin>>n>>m>>a>>b;
	for(int i=1;i<=a;i++)	cin>>x[i]>>y[i];
	for(int i=1;i<=b;i++)	cin>>x1[i]>>Y1[i];
	for(int i=1;i<=b;i++)
		for(int j=1;j<=a;j++)
			maxn[i]=min(maxn[i],abs(x[j]-x1[i])+abs(y[j]-Y1[i]));
	for(int i=1;i<=b;i++)	cout<<maxn[i]<<endl;
	return 0;
}

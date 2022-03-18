#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,C,v;
struct di{
	int a,b,p;
}d[100010];
struct ci{
	int a,b;
}c[100010];

bool cmp1(ci x,ci y){return x.b<y.b;}
bool cmp2(di x,di y){return x.b>y.b;}

int main(){
	cin>>n>>m>>C>>v;
	for(long long i=1;i<=n;i++)	cin>>d[i].a>>d[i].b,d[i].p=i;
	for(long long i=1;i<=m;i++)	cin>>c[i].a>>c[i].b;
	sort(d+1,d+n+1,cmp1);
	sort(c+1,c+m+1,cmp2);
	
}

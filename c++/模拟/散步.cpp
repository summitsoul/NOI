#include<cmath>
#include<cstdio>
#include<iostream>
const int N=100010;
using namespace std;
int n,q,p[N];
long long a[N][2],t,loc[N];

int main(){
	scanf("%d %lld %d",&n,&t,&q);
	for(int i=1;i<=n;i++)	scanf("%lld %lld",&a[i][0],&a[i][1]);
	for(int i=1;i<=q;i++)	scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		if(a[i][1]==2){
			if(i==1) loc[i]=a[i][0]-t;
			else if(a[i-1][1]==2) loc[i]=max(loc[i-1],a[i][0]-t);
			else loc[i]=max(a[i][0]/2+a[i-1][0]/2,a[i][0]-t);
		}
	for(int i=n;i>=1;i--)
		if(a[i][1]==1){
			if(i==n) loc[i]=a[i][0]+t;
			else if(a[i+1][1]==1) loc[i]=min(loc[i+1],a[i][0]+t);
			else loc[i]=min(a[i][0]/2+a[i+1][0]/2,a[i][0]+t);
		}
	for(int i=1;i<=q;i++)	printf("%lld\n",loc[p[i]]);
	return 0;
}

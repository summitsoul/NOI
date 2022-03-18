#include<cmath>
#include<cstdio>
#include<iostream>
#define N 1000010
using namespace std;
int n,h=1,t=0,L=0,ans;
int l[N],r[N],Q[N],num[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d %d",&l[i],&r[i]);
	for(int i=1;i<=n;i++){
		while(h<=t&&l[Q[h]]>r[i]) h++;
		if(h>t) ans=1;
		else ans=i-Q[h-1];
		L=max(L,ans);
		while(h<=t&&l[Q[t]]<l[i]) t--;
		Q[++t]=i;
	}
	printf("%d\n",L);
	return 0;
}

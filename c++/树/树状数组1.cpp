#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int tree[2000010];

int lowbit(int k){return k&-k;}

void add(int x,int k){
	while(x<=n){
		tree[x]+=k;
		x+=lowbit(x);
	}
}

int sum(int x){
	int ans=0;
	while(x!=0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int a;	scanf("%d",&a);
		add(i,a);
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1) add(b,c);
		else printf("%d\n",sum(c)-sum(b-1));
	}
	return 0;
}

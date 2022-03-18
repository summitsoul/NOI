#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int tree[500010];

int lowbit(int k){return k&-k;}

void add(int x,int k){
	while(x<=n){
		tree[x]+=k;
		x+=lowbit(x);
	}
}

int sum(int x){
	int ans=0;
	while(x){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}

int main(){
	scanf("%d %d",&n,&m);
	int last=0,now;
	for(int i=1;i<=n;i++){
		scanf("%d",&now);
		add(i,now-last); last=now;
	}
	for(int i=1;i<=m;i++){
		int a; scanf("%d",&a);
		if(a==1){
			int x,y,k;	scanf("%d %d %d",&x,&y,&k);
			add(x,k);	add(y+1,-k);
		}
		else{
			int x;	scanf("%d",&x);
			printf("%d\n",sum(x)); 
		}
	}
	return 0;
}

#include<cstdio>
#include<algorithm>
#define N 200010
using namespace std;
int n,minn=0x3f3f3f;
int f[N],dis[N];

int fa(int x){
	if(f[x]!=x){
		int last=f[x];
		f[x]=fa(f[x]);
		dis[x]+=dis[last];
	}
	return f[x];
}

void check(int v,int u){
	int x=fa(v),y=fa(u);
	if(x!=y){f[x]=y; dis[v]=dis[u]+1;}
	else minn=min(minn,dis[v]+dis[u]+1);
	return ;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		int t; scanf("%d",&t);
		check(i,t);
	}
	printf("%d\n",minn);
	return 0;
}

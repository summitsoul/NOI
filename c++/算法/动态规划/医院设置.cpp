#include<cmath>
#include<iostream>
#define INF 0x3f3f3f
using namespace std;
const int MAXN=10010;
struct Edge{
	int next,to;
}e[MAXN<<1];
int head[MAXN],cnt,w[MAXN],n,size[MAXN];
long long ans=INF,f[MAXN];

inline void add(int from,int to){
	e[++cnt].to=to;
	e[cnt].next=head[from];
	head[from]=cnt;
}

void dfs(int x,int fa,int d){
	size[x]=w[x];
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
			dfs(e[i].to,x,d+1),size[x]+=size[e[i].to];
	f[1]+=w[x]*d;
}

void dp(int v,int fa){
	for(int i=head[v];i;i=e[i].next)
		if(e[i].to!=fa)
			f[e[i].to]=f[v]+size[1]-size[e[i].to]*2,dp(e[i].to,v);
	ans=min(ans,f[v]);
}

int main(){
	ans*=ans;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b; cin>>w[i]>>a>>b;
		if(a) add(i,a); add(a,i);
		if(b) add(i,b); add(b,i);
	}
	dfs(1,0,0);
	dp(1,0);
	cout<<ans<<endl;
	return 0;
}

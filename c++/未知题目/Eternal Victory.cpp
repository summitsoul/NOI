#include<cmath>
#include<iostream>
#define ll long long 
using namespace std;
int cnt,head[100010];
ll ans=0,len=-1,n;
struct edge{
	int to,next,dis;
}edge[100010<<1];

void add(int x,int y,int t){
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	edge[cnt].dis=t;
	head[x]=cnt;
}

void dfs(int x,int y,ll now){
	len=max(len,now);
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to,d=edge[i].dis;
		if(v==y) continue;
		dfs(v,x,now+d);
	}
	return ;
}

int main(){
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int x,y,w; cin>>x>>y>>w;
		add(x,y,w); add(y,x,w);
		ans+=w;
	}
	ans*=2;
	dfs(1,0,0);
	cout<<ans-len<<endl;
	return 0;
}

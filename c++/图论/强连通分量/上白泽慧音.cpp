#include<bits/stdc++.h>
#define MAXN 5010
using namespace std;
int n,m,cnt,tot,ans;
int tmmk=0;
bool v[MAXN];
struct road{
	int a,b;
}r[MAXN];
stack<int>s;
int all[MAXN],dfn[MAXN],low[MAXN],head[MAXN],sd[MAXN];

void adde(int x,int y){
	cnt++;
	r[cnt].a=head[x];
	r[cnt].b=y;
	head[x]=cnt;
}

void tarjin(int x){
	dfn[x]=low[x]=++tmmk;
	s.push(x);
	v[x]=true;
	for(int i=head[x];i;i=r[i].a){
		int y=r[i].b;
		if(!dfn[y]){
			tarjin(y);
			low[x]=min(low[x],low[y]);
		}
		else if(v[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]){
		tot++;
		while(1){
			int y=s.top();
			s.pop();
			sd[y]=tot;
			all[tot]++;
			v[y]=false;
			if(x==y)	break;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adde(a,b);
		if(c==2) adde(b,a);
	}
	for(int i=1;i<=n;i++) if(!dfn[i])	tarjin(i);
	for(int i=1;i<=tot;i++)	ans=max(ans,all[i]);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if(all[sd[i]]==ans)	cout<<i<<' ';
	return 0;
}

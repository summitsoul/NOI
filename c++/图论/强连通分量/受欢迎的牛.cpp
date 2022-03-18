#include<bits/stdc++.h>
#define MAXN 5010
using namespace std;
int n,m,cnt,tot,ans,gg;
int tmmk=0;
bool v[MAXN];
struct road{
	int a,b;
}r[MAXN];
stack<int>s;
int all[MAXN],dfn[MAXN],low[MAXN],head[MAXN],sd[MAXN],du[MAXN];

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
		gg++;
		while(1){
			int y=s.top();	s.pop();
			sd[y]=gg;
			all[gg]++;
			v[y]=false;
			if(x==y)	break;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		adde(x,y);
	}
	for(int i=1;i<=n;i++) if(!dfn[i])	tarjin(i);
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=r[j].a){
			int u=r[i].b;
			if(sd[i]!=sd[u]) du[sd[i]]++;
		}
	int tt=0;
	for(int i=1;i<=gg;i++){
		if(!du[i]){
			if(tt)	cout<<0<<endl; return 0;
			tt=i;
		}
	}
	cout<<all[tt]<<endl;
	return 0;
}

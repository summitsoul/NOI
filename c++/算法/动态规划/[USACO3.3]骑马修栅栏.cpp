#include<bits/stdc++.h>
using namespace std;
int jl,maxn,n,ru[1100],chu[1100];
int g[1100][1100];

void find(int x){
	for(int i=1;i<=maxn;i++)
		if(g[x][i]>0){
			g[x][i]--;	g[i][x]--;
			find(i);
		}
	chu[++jl]=x;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int u,v;	cin>>u>>v;
		g[u][v]++;	g[v][u]++;
		ru[u]++;	ru[v]++;
		maxn=max(maxn,max(u,v));
	}
	int start=1;
	for(int i=1;i<=maxn;i++)
		if(ru[i]%2){
			start=i;
			break;
		}
	find(start);
	for(int i=jl;i>0;i--)cout<<chu[i]<<endl;
	return 0;
}

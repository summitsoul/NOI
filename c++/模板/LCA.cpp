#include<cstdio>
#include<iostream>
using namespace std;
int n, m, s, tot = 0;
int head[500010],lg[500010];
int depth[500010], fa[500010][22];
struct edge{
	int to, next;
}e[500010 << 1];

inline int read(){
	int s= 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
	return s; 
}

void add(int u, int v){
	e[++tot].to = v;
	e[tot].next = head[u];
	head[u] = tot;
}

void dfs(int now, int fath){
	fa[now][0] = fath; depth[now] = depth[fath] + 1;
	for(int i = 1; i <= lg[depth[now]]; i++)
		fa[now][i] = fa[fa[now][i - 1]][i - 1];
	for(int i = head[now]; i; i = e[i].next)
		if(e[i].to != fath) dfs(e[i].to, now);
}

int LCA(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	while(depth[u] > depth[v])
		u = fa[u][lg[depth[u] - depth[v]] - 1];
	if(u == v) return u;
	for(int i = lg[depth[u]] - 1; i >= 0; i--)
		if(fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
} 

int main(){
	n = read(); m = read(); s = read();
	for(int i = 1; i < n; i++){
		int u, v; u = read(); v = read();
		add(u, v); add(v, u);
	}
	for(int i = 1; i <= n; i++)
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	dfs(s, 0);
	for(int i = 1; i <= m; i++){
		int u, v; u = read(); v = read();
		printf("%d\n", LCA(u, v));
	}
	return 0;
}

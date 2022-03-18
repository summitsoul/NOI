#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f
using namespace std;
int n, m, q, cnt = 0;
bool vis[50010];
int fu[50010][22], w[50010][22];
int fa[10010], head[10010], depth[10010];
struct edge1{
	int u, v, w;
}e1[50010];
struct edge2{
	int w, to, next;
}e2[50010 << 1];

inline int read(){
	int s = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
	return s;
}

bool cmp(edge1 a, edge1 b){return a.w > b.w;}

int find(int x){
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}

void add(int u, int v, int w){
	e2[++cnt].next = head[u];
	e2[cnt].to = v;
	e2[cnt].w = w;
	head[u] = cnt;
}

void kruskal(){
	sort(e1 + 1, e1 + m + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
		if(find(e1[i].u) != find(e1[i].v)){
			fa[find(e1[i].u)] = find(e1[i].v);
			add(e1[i].u, e1[i].v, e1[i].w);
			add(e1[i].v, e1[i].u, e1[i].w);
		}
}

void dfs(int now){
	vis[now] = true;
	for(int i = head[now]; i; i = e2[i].next){
		int to = e2[i].to;
		if(vis[to]) continue;
		depth[to] = depth[now] + 1;
		w[to][0]  = e2[i].w;
		fu[to][0] = now;
		dfs(to);
	}
}

int LCA(int u, int v){
	if(find(u) != find(v)) return -1;
	int ans = INF;
	if(depth[u] > depth[v]) swap(u, v);
	for(int i = 20; i >= 0; i--)
		if(depth[fu[v][i]] >= depth[u]){
			ans = min(ans, w[v][i]);
			v = fu[v][i];
		}
	if(u == v) return ans;
	for(int i = 20; i >= 0; i--)
		if(fu[u][i] != fu[v][i]){
			ans = min(ans, min(w[u][i], w[v][i]));
			u = fu[u][i];
			v = fu[v][i];
		}
	ans = min(ans, min(w[u][0], w[v][0]));
	return ans;
}

int main(){
	n = read(); m = read();
	for(int i = 1; i <= m; i++){
		int x, y, z; 
		x = read(); y = read(); z = read();
		e1[i].u = x; e1[i].v = y; e1[i].w = z;
	}
	kruskal();
	for(int i = 1; i <= n; i++)
		if(!vis[i]){
			depth[i] = 1;
			dfs(i);
			fu[i][0] = i;
			w[i][0] = INF;
		}
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= n; j++){
			fu[j][i] = fu[fu[j][i - 1]][i - 1];
			w[j][i] = min(w[j][i - 1], w[fu[j][i - 1]][i - 1]);
		}
	q = read();
	for(int i = 1; i <= q; i++){
		int u, v; u = read(); v = read();
		printf("%d\n", LCA(u, v));
	}
	return 0;
}

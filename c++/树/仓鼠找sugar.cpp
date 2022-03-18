#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 200010
using namespace std;
int n, q, cnt = 0;
int lg[N], head[N], depth[N];
int fa[N][20];

struct edge{
    int to, next;
}e[N];

void add(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
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
    int u, v;
    scanf("%d %d", &n, &q);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &u, &v);
        add(u, v); add(v, u);
    }
	for(int i = 1; i <= n; i++)
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    dfs(1, 0);
    for(int i = 1; i <= q; i++){
	    int x1, y1, x2, y2;
	    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	    int lac1 = LCA(x1, y1), lac2 = LCA(x2, y2);
	    int st = max(depth[LCA(x1, x2)], depth[LCA(x1, y2)]);
	    st = max(st, depth[LCA(y1, x2)]);
	    st = max(st, depth[LCA(y1, y2)]);
	    if(st >= depth[lac1] && st >= depth[lac2]) printf("Y\n");
	    else printf("N\n");
    } 
    return 0;
}
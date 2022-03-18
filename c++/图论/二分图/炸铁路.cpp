#include<cstdio>
#include<algorithm>
#define N 5010
using namespace std;
int n, m, cnt = 0, tot = 0, num = 0;
int head[N >> 1];
int dfn[N], low[N], vis[N], stack[N], color[N];
struct edge{
    int to, next;
}e[N >> 1];
struct bridge{
    int u, v;
}b[N >> 1];

bool cmp(bridge x, bridge y){
    if(x.u == y.u) return x.u < y.u;
    return x.u < y.u;
}

void add(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void tarjin(int u, int in_edge){
    dfn[u] = low[u] = ++tot;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(!vis[v]){
            tarjin(v, i);
            low[u] = min(low[u], low[v]);
            if(low[u] < low[v]){
            	int tx, ty;
            	if(u > v) tx = v, ty = u;
            	else tx = u, ty = v;
            	b[++num].u = tx; b[num].v = ty;
			} 
        }
        else if(i != (in_edge ^ 1)) low[u] = min(low[u], dfn[v]);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d %d", &u, &v);
        add(u, v); add(v, u);
    }
    for(int i = 1; i <= n; i++) if(!dfn[i]) tarjin(i, 0);
    sort(b + 1, b + num + 1, cmp);
    for(int i = 1; i <= num; i++)
        printf("%d %d\n", b[i].u, b[i].v);
    return 0;
}

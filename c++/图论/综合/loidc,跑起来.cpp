#include<cstdio>
#include<algorithm>
#define N 30010
using namespace std;
int n, m, a, b, sum = 0, tot = 0, cnt = 0, top = 0;
int head[N], dis_l[N], dis_c[N];
int dfn[N], low[N], siz[N], color[N];
int vis[N], stack[N], belong[N];
struct edge{
    int next, to;
}e[N];

void add(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void tarjin(int u){
    dfn[u] = low[u] = ++tot;
    stack[++top] = u;
    vis[u] = true;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(!dfn[v]){
            tarjin(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        int x = -1; sum++;
        while(x != u){
            x = stack[top--];
            belong[x] = sum;
            vis[x] = false;
        }
    }
}

int main(){
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d %d", &u, &v);
        add(u, v); add(v, u);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjin(i);
}
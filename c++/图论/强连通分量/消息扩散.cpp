#include<cstdio>
#include<algorithm>
#define N 500010
using namespace std;
int n, m, ans = 0, top = 0, sum = 0, tot = 0, cnt = 0; 
int ru[N], low[N], dfn[N], head[N], stack[N], belong[N];
bool vis[N];
struct edge{
    int to, next;
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
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d %d", &u, &v);
        if(u != v)add(u, v);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjin(i);
    for(int i = 1; i <= n; i++)
        for(int j = head[i]; j; j = e[j].next)
            if(belong[i] != belong[e[j].to])
                ru[belong[e[j].to]]++;
    for(int i = 1; i <= sum; i++)
        if(!ru[i]) ans++;
    printf("%d\n", ans);
    return 0;
}
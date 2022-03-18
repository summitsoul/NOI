#include<queue>
#include<cstdio>
#include<iostream>
#define N 200010
using namespace std;
int n, k, ans = 0, cnt = 0;
int head[N], depth[N], power[N];
int fa[N][30];
queue<int> q;

struct edge{
    int to, next;
}e[N];

void add(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

/*void dfs(int u, int fath){
    depth[u] = depth[fath] + 1; fa[u][0] = fath;
    for(int i = 0; fa[u][i]; i++) fa[u][i + 1] = fa[fa[u][i]][i];
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v != fath) dfs(v, u);
    }
}*/

int LCA(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    for(int i = 20; i >= 0; i--)
        if(depth[u] <= depth[v] - (1 << i))
            v = fa[v][i];
    if(u == v) return u;
    for(int i = 20; i >= 0; i--)
        if(fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

void get(int u, int fath){
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == fath) continue;
        get(v, u);
        power[u] += power[v];
    }
    ans = ans > power[u] ? ans : power[u];
}

int main(){
    int u, v;
    scanf("%d %d", &n, &k);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &u, &v);
        add(u, v); add(v, u);
    }
    q.push(1);
    depth[1] = 1;
    while(q.size()){
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = e[i].next){
            int y = e[i].to;
            if(depth[y]) continue;
            depth[y] = depth[x] + 1;
            
        }
    }
    //dfs(1, 0);
    for(int i = 1; i <= k; i++){
        scanf("%d %d", &u, &v);
        int lca = LCA(u, v);
        power[u]++; power[v]++;
        power[lca]--; power[fa[lca][0]]--;
    }
    get(1, 0);
    printf("%d\n", ans);
    return 0;
}
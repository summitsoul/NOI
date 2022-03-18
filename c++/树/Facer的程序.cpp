#include<cstdio>
#define p 1000000007
#define ll long long
using namespace std;
int n, ans, cnt = 0;
int f[100010], head[100010];
struct edge{
    int next, to;
}e[2000010];

void add(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void dfs(int x, int fa){
    f[x] = 1;
    for(int i = head[x]; i; i = e[i].next)
        if(e[i].to != fa)
            dfs(e[i].to, x), f[x] = (ll)((ll)f[x] * f[e[i].to] + f[x]) % p;
    ans += f[x]; ans %= p;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}
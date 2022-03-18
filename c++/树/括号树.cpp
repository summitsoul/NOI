#include<string>
#include<cstdio>
#define N 500010
#define int long long
using namespace std;
int n, x, ans = 0, cnt = 0;
int h[N], w[N], fa[N], head[N];
char s[N];
struct edge{
    int to, next;
}e[N];

void add(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void dfs(int x){
    w[x] = w[fa[x]];
    if(s[x] == '(') w[x] = x;
    else if(w[x]) h[x] = 1 + h[fa[w[x]]], w[x] = w[fa[w[x]]];
    for(int i = head[x]; i; i = e[i].next) dfs(e[i].to);
}

signed main(){
    scanf("%lld %s", &n, s + 1);
    for(int i = 2; i <= n; i++){
        scanf("%lld", &x); fa[i] = x;
        add(x, i);
    }
    dfs(1);
    ans = h[1];
    for(int i = 2; i <= n; i++)
        h[i] += h[fa[i]], ans ^= (i * h[i]);
    printf("%lld\n", ans);
    return 0;
}
#include<cstdio>
#define int long long
#define N 300010
using namespace std;
int V, E, K, cnt = 0;
int head[N];
struct edge{
    int next, to, w;
}e[N];

void add(int u, int v, int w){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].w = w;
    head[u] = cnt;
}

signed main(){
    scanf("%lld %lld %lld", &V, &E, &K);
    for(int i = 1; i <= E; i++){
        int p, q, f; scanf("%d %d %d", &p, &q, &f);
        add(p, q, f);
    }
    
}
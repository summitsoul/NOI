#include<queue>
#include<cstdio>
#define N 100010
#define INF 0x7f7f7f7f7f
using namespace std;
int n, m, s, cnt = 0;
int head[N], pre[N];
bool vis[N];
long long dis[N];
long long ans = 0;
struct edge{
    int next, to, w;
}e[N << 1];

void add(int u, int v, int w){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
    e[cnt].w = w;
}

void SPFA(int s){
    queue<int> q;
    for(int i = 1; i <= n; i++) dis[i] = INF;
    q.push(s); dis[s] = 0; vis[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i; i = e[i].next){
            int v = e[i].to, w = e[i].w;
            if(dis[v] >= dis[u] + w){
                if(dis[v] > dis[u] + w){
                    ans += w;
                    if(dis[v] != INF) ans -= pre[v];
                    pre[v] = w;
                }
                else
                    if(pre[v] > w){
                        ans += w - pre[v];
                        pre[v] = w;
                    }
                dis[v] = dis[u] + w;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    scanf("%d", &s);
    SPFA(s);
    printf("%lld\n", ans);
    return 0;
}

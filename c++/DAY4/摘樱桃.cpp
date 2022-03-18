#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
#define int long long
using namespace std;
int n, t, cnt = 0, ans = 0;
int v[N], sum[N], dis[N], head[N << 1];
bool vis[N];
struct edge{
    int next, to, w;
}e[N << 1];

void add(int u, int v, int w){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].w = w;
    head[u] = cnt;
}
 
void SPFA(){
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    q.push(0);
    dis[0] = 0; vis[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u]; i; i = e[i].next){
            int v = e[i].to;
            if(dis[v] > dis[u] + e[i].w){
                dis[v] = dis[u] + e[i].w;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

signed main(){
    scanf("%lld %lld", &n, &t);
    for(register int i = 1; i <= n; i++) scanf("%lld", &v[i]), sum[i] = sum[i - 1] + v[i];
    for(register int i = 0; i < n; i++){
        for(register int j = i + 1; j <= n; j++){
            int w = (sum[j] - sum[i] - t) * (sum[j] - sum[i] - t);
            add(i, j, w);
        }
    }
    SPFA();
    printf("%lld\n", dis[n]);
    return 0;
}
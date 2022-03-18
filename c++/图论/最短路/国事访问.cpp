#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 2010
using namespace std;
int n, m, ans = 0, cnt = 0;
int head[N], dis[N], val[N];
bool vis[N];
struct edge{
    int to, next, w;
}e[N];

void add(int u, int v, int w){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    if(w == 1) e[cnt].w = -1;
    if(w == 0) e[cnt].w = 1;
    head[u] = cnt;
}

void spfa(int s){
    memset(dis, 0x3f, sizeof(dis));
    memset(val, 0x3f, sizeof(val));
    queue<int> q;
    q.push(s);
    vis[s] = true; dis[s] = 0; val[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = head[u]; i; i = e[i].next){
            int v = e[i].to;
            if(dis[u] + 1 <= dis[v]){
                if(dis[u] + 1 == dis[v])
                    val[v] = min(val[v], val[u] + e[i].w);
                else{
                    dis[v] = dis[u] + 1;
                    val[v] = val[u] + e[i].w;
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    int u, v, w;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
        ans += w;
    }
    spfa(1);
    printf("%d\n", val[n] + ans);
    return 0;
}
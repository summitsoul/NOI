#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int n, k;
int dis[110][110];

int main(){
    scanf("%d %d", &n, &k);
    memset(dis, INF, sizeof(dis));
    for(int i = 1; i <= n; i++){
        int u = i, v = i % n + 1;
        int w; scanf("%d", &w);
        if(dis[u][v] == INF) dis[u][v] = dis[v][u] = w;
        else dis[u][v] =dis[v][u] = max(dis[u][v], w);
    }
    for(int i = 1; i <= k; i++){
        char u, v; int w; cin >>u >> v >> w;
        if(dis[u - 'A' + 1][v - 'A' + 1] == INF) dis[u - 'A' + 1][v - 'A' + 1] = dis[v - 'A' + 1][u - 'A' + 1] = w;
        else dis[u - 'A' + 1][v - 'A' + 1] = dis[v - 'A' + 1][u - 'A' + 1] = max(dis[u - 'A' + 1][v - 'A' + 1], w);
    }
    for(int t = 1; t <= n; t++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);
    char a, b; cin >> a >> b;
    printf("%d\n", dis[a - 'A' + 1][b - 'A' + 1]);
    return 0;
}
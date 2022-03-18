#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1010
#define INF 0x3f3f3f3f
using namespace std;
int n, m, t, cnt = 0;
int dis[N][N];

int main(){
    memset(dis, INF, sizeof(dis));
    scanf("%d %d %d", &n, &m ,&t);
    int u, v, w;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        dis[u][v] = w;
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(max(dis[i][k], dis[k][j]), dis[i][j]);
    for(int i = 1; i <= t; i++){
        scanf("%d %d", &u, &v);
        if(dis[u][v] != INF)
            printf("%d\n", dis[u][v]);
        else printf("-1\n");
    }
    return 0;
}
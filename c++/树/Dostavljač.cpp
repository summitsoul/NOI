#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, cnt = 0;
int a[5010], dp[10010][10010][2], head[5010];
struct edge{
    int next, to;
}e[10010];

void add(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void dfs(int u, int fa){
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, u);
        for(int j = m; j >= 0; j--)
            for(int k = m; k >= 0; k--){
                if(k + j + 2 <= m){
                    dp[u][j + k + 2][0] = max(dp[u][j + k + 2][0], dp[u][j][0] + dp[v][k][1]);
                    dp[u][j + k + 2][1] = max(dp[u][j + k + 2][1], dp[u][j][1] + dp[v][k][1]);
                    }
                if(k + j + 1 <= m)
                    dp[u][j + k + 1][0] = max(dp[u][j + k + 1][0], dp[u][j][1] + dp[v][k][0]);
            }
    }
    for(int i = m; i >= 1; i--){
        dp[u][i][1] = max(dp[u][i][1], dp[u][i - 1][1] + a[u]);
        dp[u][i][0] = max(dp[u][i][0], dp[u][i - 1][0] + a[u]);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(1, 0);
    printf("%d\n", dp[1][m][0]);
    return 0;
}


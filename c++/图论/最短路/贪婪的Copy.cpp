#include<cstdio>
#include<algorithm>
#define N 110
using namespace std;
int n, p, cnt = 0;
int pan[N], w[N][N];
long long ans = 0x7f7f7f7f7f7f7f7f;
bool f[N];

void dfs(int now, int m, long long sum){
    if(m == p) ans = min(ans, sum + w[now][n]);
    else{
        for(int i = 1; i <= p; i++){
            if(!f[i]){
                f[i] = 1;
                dfs(pan[i], m + 1, sum + w[now][pan[i]]);
                f[i] = 0;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &w[i][j]);
    scanf("%d", &p);
    for(int i = 1; i <= p; i++) scanf("%d", &pan[i]);
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
    sort(pan + 1, pan + p + 1);
    dfs(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}

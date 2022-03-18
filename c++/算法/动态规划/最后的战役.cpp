#include<cstdio>
#include<algorithm>
#define N 500010
using namespace std;
int n, m, maxn, cnt = 0;
int k[N], p[N], x[N], mp[N << 1], dp[N][510], sum[N];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &k[i], &p[i]);
        mp[++cnt] = k[i];
    }
    for(int i = 1; i <= n; i++)
        scanf("%d", &x[i]), mp[++cnt] = x[i];
    sort(mp, mp + cnt + 1);
    cnt = unique(mp + 1, mp + cnt + 1) - mp - 1;
    for(int i = 1; i <= n; i++){
        k[i] = lower_bound(mp + 1, mp + cnt + 1, k[i]) - mp;
        x[i] = lower_bound(mp + 1, mp + cnt + 1, x[i]) - mp;
    }
    for(int i = 1; i <= n; i++){
        maxn = max(maxn, p[i]);
        sum[k[i]] += p[i];
        int tmp = max(maxn, sum[x[i]]);
        for(int j = 0; j <= min(i, m); j++){
            if(i > 1 && j)
                dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + 2 * tmp);
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + tmp);
        }
    }
    int ans = 0;
    for(int i = 0; i <= m; i++)
        ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}
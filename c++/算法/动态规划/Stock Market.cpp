#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s, d, m;
int dp[500010], p[55][20];

int main(){
    scanf("%d %d %d", &s, &d, &m);
    for(int i = 1; i <= s; i++)
        for(int j = 1; j <= d; j++)
            scanf("%d", &p[i][j]);
    for(int i = 2; i <= d; i++){
        int maxn = -1; 
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j <= s; j++)
            for(int k = p[j][i - 1]; k <= m; k++){
                dp[k] = max(dp[k], dp[k - p[j][i - 1]] + p[j][i] - p[j][i - 1]);
                maxn = max(maxn, dp[k]);
            }
        m += maxn;
    }
    printf("%d\n", m);
    return 0;
}
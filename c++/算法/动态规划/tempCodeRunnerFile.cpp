#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int n, type;
int a[500010], dp[500010], sum[500010], last[500010];

signed main(){
    memset(dp, 0x7f, sizeof(dp));
    scanf("%lld %lld", &n, &type);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; i++) printf("%lld ", sum[i]);
    dp[1] = a[1] * a[1];
    for(int i = 2; i <= n; i++)
        for(int j = 1; j < i; j++)
            if(sum[i] - sum[j] >= last[j] && dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]) < dp[i]){
                dp[i] = dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]);
                last[i] = sum[i] - sum[j];
            }
    printf("%lld\n", dp[n]);
    return 0;
}
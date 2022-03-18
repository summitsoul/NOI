#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n;
int a[11], f[100010], dp[100010];
int b[11] = {0, 1, 3, 5, 7, 9, 10, 11, 14, 15, 17};

signed main(){
    scanf("%lld", &n);
    for(int i = 1; i <= 10; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= i; j++)
            f[i] = max(f[i], f[i - j] + a[j]);
    for(int i = 1; i <= 10; i++) f[i] -= b[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= min(i, 10ll); j++)
            dp[i] = max(dp[i], dp[i - j] + f[j]);
    printf("%lld\n", dp[n]);
    return 0;
}
#include<cstdio>
#include<algorithm>
#define N 200010
using namespace std;
int n;
int l[N], r[N], dp[N][2];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &l[i], &r[i]);
    dp[1][0] = r[1] + r[1] - l[1] - 1;
    dp[1][1] = r[1] - 1;
    for(int i = 2; i <= n; i++){
        dp[i][0] = min(dp[i - 1][1] + abs(r[i] - r[i - 1]) + r[i] - l[i], dp[i - 1][0] + abs(r[i] - l[i - 1]) + r[i] - l[i]) + 1;
        dp[i][1] = min(dp[i - 1][1] + abs(l[i] - r[i - 1]) + r[i] - l[i], dp[i - 1][0] + abs(l[i] - l[i - 1]) + r[i] - l[i]) + 1;
    }
    int ans = min(dp[n][0] + n - l[n], dp[n][1] + n - r[n]);
    printf("%d\n", ans);
    return 0;
}
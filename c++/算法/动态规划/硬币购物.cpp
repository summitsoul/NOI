#include<cstdio>
using namespace std;
int n;
int c[5], d[5];
long long dp[100010];

int main(){
    for(int i = 1; i <= 4; i++) scanf("%d", &c[i]);
    scanf("%d", &n);
    dp[0] = 1;
    for(int i = 1; i <= 4; i++)
        for(int j = c[i]; j <= 100010; j++)
            dp[j] += dp[j - c[i]];
    while(n--){
        int sum; long long res = 0;
        for(int i = 1; i <= 4; i++) scanf("%d", &d[i]);
        scanf("%d", &sum);
        for(int i = 0; i <= 15; i++){
            long long t = sum;
            int cnt = 0;
            for(int j = 1; j <= 4; j++)
                if((i >> (j - 1)) & 1) t -= c[j] * (d[j] + 1), cnt ^= 1;
                if(t < 0) continue;
                if(!cnt) res += dp[t];
                else res -= dp[t];
        }
        printf("%lld\n", res);
    }
    return 0;
}
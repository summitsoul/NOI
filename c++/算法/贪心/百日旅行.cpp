#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n, p, q, ans = 0x3f3f3f3f;

signed main(){
    scanf("%lld %lld %lld", &n, &p, &q);
    for(int i = 0; i <= n; i++){
        int d = n - 1, t = i + 1;
        ans = min(ans, i * q + p * (t - d % t) * (d / t) * (d / t) + p * (d % t) * (d / t + 1) * (d / t + 1));
    }
    printf("%lld\n", ans);
    return 0;
}
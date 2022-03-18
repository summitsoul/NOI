#include<cmath>
#include<cstdio>
#define int long long
using namespace std;
int k, n, ans = 0, cnt = 0;
int s[100010];

signed main(){
    scanf("%lld %lld", &k, &n);
    while(n){
        s[++cnt] = n & 1;
        n >>= 1;
    }
    while(cnt != 0){
        ans += s[cnt] * pow(k, cnt - 1);
        cnt--;
    }
    printf("%lld\n", ans);
    return 0;
}
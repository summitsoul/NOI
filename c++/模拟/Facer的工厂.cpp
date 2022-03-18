#include<cstdio>
using namespace std;
int n, m, k, p;
long long ans = 0;

signed main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        int a; scanf("%d", &a);
        if(p + a > m){
            ans++;
            p = a;
        }
        else p += a;
        ans += p / k;
        p %= k;
    }
    if(p != 0) ans++;
    printf("%lld\n", ans);
    return 0;
}
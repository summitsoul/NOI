#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n, m, k, ans = 0;
int a[30010];

signed main(){
    scanf("%d %d %d", &n, &m, &k);
    if(n > m) swap(n, m);
    for(int i = 2; i < 400; i++) a[i] = a[i - 1] + i - 1;
    for(int i = min(n, k), b; i && (k + i - 1) / i <= m; i--){
        b = k / i;
        ans = max(ans, a[b] * a[i] + a[k % i] * b);
    }
    printf("%lld\n", ans);
    return 0;
}
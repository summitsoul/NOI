#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N  = 1e6 + 10; 
int a, n, m, p, cur, maxn, maxx, flag;
int b[N];

signed main(){
    scanf("%lld %lld %lld", &n, &p, &a);
    maxn = b[1] = cur = a;
    if(a > 0) flag = 1;
    if(cur < 0) cur = 0;
    for(int i = 2; i <= n; i++){
        scanf("%lld", &a); cur += a;
        b[i] = maxn = max(maxn, cur);
        if(cur < 0) cur = 0;
        if(i == 2) m = 2 * b[1];
        else if(b[i - 1] > 0){
            m = (m + b[i - 1]) % p;
            if(!flag && (maxx += b[i - 1]) >= -b[1]) flag = 1;
        }
    }
    if(flag) printf("%lld\n", m);
    else printf("%lld\n", b[1] % p);
    return 0;
}
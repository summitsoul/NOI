#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int n, k, sum = 0;
int a[100010], pan[100010], gro[100010];

signed main(){
    scanf("%lld %lld", &n, &k);
    for(register int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum += a[i];
    memset(pan, 0x7f7f7f7f, sizeof(pan));
    for(register int i = 1; i <= n; i++){
        gro[i % k]++;
        if(a[i] < pan[i % k] && gro[i % k] % 2 == 1) pan[i % k] = a[i];
    }
    for(register int i = 0; i < k; i++)
        if(gro[i] % 2) sum -= pan[i];
    printf("%lld\n", sum);
    return 0;
}
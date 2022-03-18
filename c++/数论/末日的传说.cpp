#include<cstdio>
#define int long long
using namespace std;
int n, m;
int a[50010];

signed main(){
    scanf("%lld %lld", &n, &m);
    int l = 1, r = n;
    for(int i = 1; i <= n; i++){
        int t = (n - i) * (n - i - 1) / 2;
        if(t >= m) a[l++] = i;
        else a[r--] = i, m -= (r - l + 1);
    }
    for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
    return 0;
}
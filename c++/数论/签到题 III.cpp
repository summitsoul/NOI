#include<cmath>
#include<cstdio>
#define int long long
using namespace std;
int n, x, y;

signed main(){
    scanf("%lld", &n);
    x  =  floor(log2(n)) / 2;
    y = n / ((1ll << x + 1) + 1);
    int z = (1ll << x) - 1, ans = 0;
} 
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[51];
long long ans = 1;
    
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) ans *= (a[i] - i + 1), ans %= 1000000007;
    printf("%lld\n", ans);
    return 0;
}
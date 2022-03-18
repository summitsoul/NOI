#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
long long ans = 0;
long long a[100010], b[100010];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int k = 1;
    for(int i = 1; i <= m; i++){
        long long t = abs(b[i] - a[k]);
        while(abs(b[i] - a[k + 1]) <= t){
            k++;
            t = abs(b[i] - a[k]);
        }
        ans += t;
    }
    printf("%lld\n", ans);
    return 0;
}
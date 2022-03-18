#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 50010
#define x 10086001
using namespace std;
int n, k, ans = 0, sum = 0;
long long s[N], f[N];

int main(){
    scanf("%d %d", &n, &k);
    s[0] = f[0] = 1;
    for(int i = 1; i <= k; i++){
        int t; scanf("%d", &t);
        for(int j = 1; j <= n; j++) s[j] = s[j - 1] + f[j];
        for(int p = n; p >= 0; p--)
            f[p] = (f[p] + s[p - 1] - s[p - min(t, p) - 1]) % x;
        sum += t;
        ans = (ans + f[n]) % x;
    }
    if(sum < n) printf("impossible\n");
    else printf("%d\n", ans);
    return 0;
}

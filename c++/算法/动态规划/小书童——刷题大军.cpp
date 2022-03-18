#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, k, r, ans = 0;
int t[11], f[1010],  w_t[55], w_g[160];

int main(){
    scanf("%d %d %d %d", &n, &m, &k, &r);
    for(int i = 1; i <= n; i++) scanf("%d", &t[i]);
    sort(t + 1, t + n + 1);
    for(int i = 1; i <= m; i++) scanf("%d", &w_t[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &w_g[i]);
    for(int i = 1; i <= n; i++)
        for(int j = r; j >= w_t[i]; j--)
            f[j] = max(f[j], f[j - w_t[i]] + w_g[i]);
    for(int i = 1; i <= r; i++)
        if(f[i] >= k){
            r -= i; break;
        }
    for(int i = 1; i <= n; i++){
        r -= t[i];
        if(r <= 0) break;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
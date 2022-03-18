#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n, m, k, a[405][405];
long long f[405][405],ans,cnt[1000005],b[1000005];

int main(){
    scanf("%d %d %d",&n, &m, &k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){ 
            scanf("%d", &a[i][j]);
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j <= n; j++){
            cnt[0] = 1;
            for(int o = 1; o <= m; o++){
                b[o] = (f[j][o] - f[i][o] + k) % k;
                ans += cnt[b[o]];
                cnt[b[o]]++;
            }
            for(int o = 1; o <= m; o++) cnt[b[o]] = 0;
    }
    printf("%lld\n", ans);
    return 0;
}
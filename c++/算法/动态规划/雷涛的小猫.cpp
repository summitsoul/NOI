#include<cstdio>
#include<algorithm>
using namespace std;
int n, h, d, maxn = 0;
int pre[5010], t[5010][2010], f[5010][2010];

int main(){
    scanf("%d %d %d", &n, &h, &d);
    for(int i = 1; i <= n; i++){
        int k; scanf("%d", &k);
        for(int j = 1; j <= k; j++){
            int x; scanf("%d", &x);
            t[i][x]++;
        }
    }
    for(int j = h; j >= 0; j--)
        for(int i = 1; i <= n; i++){
            f[i][j] = t[i][j] + f[i][j + 1];
            f[i][j] = max(f[i][j], pre[j + d] + t[i][j]);
            pre[j] = max(pre[j], f[i][j]);
            maxn = max(maxn, f[i][j]);
        }
    printf("%d\n", maxn);
    return 0;
}
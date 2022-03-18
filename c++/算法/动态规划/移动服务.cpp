#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int l, n;
int q[1010];
int c[500][500];
int f[1010][500][500];

int main(){
    scanf("%d %d", &l, &n);
    for(int i = 1; i <= l; i++)
        for(int j = 1; j <= l; j++)
            scanf("%d", &c[i][j]);
    for(int i = 1; i <= n; i++) scanf("%d", &q[i]);
    memset(f, INF, sizeof(f));
    q[0] = 3;
    f[0][1][2] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= l; j++)
            for(int k = 1; k <= l; k++){
                int z = q[i], v = f[i][j][k];
                if(j == k || j == z || k == z) continue;
                int u = q[i + 1];
                f[i + 1][j][k] = min(f[i + 1][j][k], v + c[z][u]);
                f[i + 1][z][k] = min(f[i + 1][z][k], v + c[j][u]);
                f[i + 1][j][z] = min(f[i + 1][j][z], v + c[k][u]);
            }
    int ans = INF;
    for(int i = 1; i <= l; i++)
        for(int j = 1; j <= l; j++){
            int k = q[n];
            if(i == j || i == k || j == k) continue;
            ans = min(ans, f[n][i][j]);
        }
    printf("%d\n", ans);
    return 0;
}
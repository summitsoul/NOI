#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f
using namespace std;
int n, m;
int a[110];
int b[110][110][11], s[110][110][11];

int mod(int x){return ((x % 10) + 10) % 10;}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        int x; scanf("%d", &x);
        a[i] = a[i + n] = x;
    }
    for(int i = 1; i <= n * 2; i++) a[i] += a[i - 1];
    for(int l = 1; l <= n * 2; l++)
        for(int r = l; r <= n * 2; r++)
            b[l][r][1] = s[l][r][1] = mod(a[r] - a[l - 1]);
    for(int i = 2; i <= m; i++)
        for(int l = 1; l <= n * 2; l++)
            for(int r = l + i - 1; r <= n * 2; r++)
                s[l][r][i] = INF;
    for(int i = 2; i <= m; i++)
        for(int l = 1; l <= n * 2; l++)
            for(int r = l + i - 1; r <= n * 2; r++)
                for(int k = l + i - 2; k < r; k++){
                    s[l][r][i] = min(s[l][r][i], s[l][k][i - 1] * mod(a[r]- a[k]));
                    b[l][r][i] = max(b[l][r][i], b[l][k][i - 1] * mod(a[r]- a[k]));
                }
    int maxx = 0, minn = INF;
    for(int i = 1; i <= n; i++){
        maxx = max(maxx, b[i][i + n - 1][m]);
        minn = min(minn, s[i][i + n - 1][m]);
    }
    printf("%d\n%d\n", minn, maxx);
    return 0;
}
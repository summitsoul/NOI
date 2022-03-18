#include<cstdio>
#define re register
#define N 100010
using namespace std;
int n, m, c;
int q[N], f[N], dp[N];

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}

int main(){
    n = read(); m = read(); c = read();
    for(re int i = 1; i <= n; i++)
        for(re int v = read(), w = read(), d = read(), j = 1; j <= v; j++)
            for(re int h = 0, t = 0, k = 0; k * v + j <= c; k++){
                int x = dp[k * v + j] - k * w;
                while(h != t && x >= f[i - 1]) t--;
                q[t] = k; f[t++] = x;
                if(q[h] + d < k) h++;
                dp[k * v + j] = f[h] + k * w;
            }
    for(re int i = 1; i <= m; i++)
        for(re int v = read(), w = read(), d = read(), j = c; j >= 1; j--)
            for(re int k = 1; k <= j; k++)
                if(dp[j - k] + (v * k + w) * k + d > dp[j])
                    dp[j] = dp[j - k] + (v * k + w) * k + d;
    printf("%d\n", dp[c]);
    return 0;
}
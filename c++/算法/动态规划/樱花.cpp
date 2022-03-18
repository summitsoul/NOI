#include<cstdio>
#include<algorithm>
#define re register
using namespace std;
int n, h1, h2, m1, m2, ti, cnt = 0;
int t[10010], c[10010], p[10010], dp[1000010];
int co[1000010], v[1000010];

inline void pre(){
    for(re int i = 1; i <= n; i++){
        int k = 1;
        while(p[i]){
            co[++cnt] = k * t[i];
            v[cnt] = k * c[i];
            p[i] -= k; k <<= 1;
            if(p[i] < k){
                co[++cnt] = t[i] * p[i];
                v[cnt] = c[i] * p[i];
                break;
            }
        }
    }
}

int main(){
    scanf("%d:%d%d:%d%d", &h1, &m1, &h2, &m2, &n);
    for(re int i = 1; i <= n; i++){
        scanf("%d %d %d", &t[i], &c[i], &p[i]);
        if(!p[i]) p[i] = 999999;
    }
    ti = (h2 - h1) * 60 + m2 - m1;
    pre();
    for(re int i = 1; i <= cnt; i++)
        for(re int j = ti; j >= co[i]; j--)
            dp[j] = max(dp[j], dp[j - co[i]] + v[i]);
    printf("%d\n", dp[ti]);
    return 0;
}
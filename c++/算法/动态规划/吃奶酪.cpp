#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
double x[16], y[16];
double dp[16][1 << 16];

double dis(int a, int b){return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lf %lf", &x[i], &y[i]);
    memset(dp, 127 ,sizeof(dp));
    for(int s = 1; s <= (1 << n) - 1; s++)
        for(int i = 1; i <= n; i++){
            if((s & (1 << (i - 1))) == 0) continue;
            if(s == (1 << (i - 1))){dp[i][s] = 0; continue;}
            for(int j = 1; j <= n; j++){
                if(s & (1 << (j - 1)) == 0 || i == j) continue;
                dp[i][s] = min(dp[i][s], dp[j][s - (1 << (i - 1))] + dis(i, j));
            }
        }
    double ans = -1;
    for(int i = 1; i <= n; i++){
        double s = dp[i][(1 << n) - 1] + dis(i, 0);
        if(ans == -1 || ans > s) ans = s;
    }
    printf("%.2lf\n", ans);
    return 0;
}
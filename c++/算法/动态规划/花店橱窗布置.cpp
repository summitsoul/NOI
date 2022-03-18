#include<cstdio>
using namespace std;
int f, v;
int a[110][110], dp[110][110], pre[110][110];

void print(int x, int y){
    if(pre[x][y] == y){printf("%d ", y); return ;}
    print(x - 1, pre[x][y]);
    printf("%d ", y);
}

int main(){
    scanf("%d %d", &f, &v);
    for(int i = 1; i <= f; i++)
        for(int j = 1; j <= v; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= v - f; i++)
        dp[1][i] = a[1][i], pre[1][i] = i;
    for(int i = 2; i <= f; i++)
        for(int j = i; j <= v - f + i; j++)
            for(int k = 1; k < j; k++){
                if(dp[i - 1][k] + a[i][j] > dp[i][j]){
                    dp[i][j] = dp[i - 1][k] + a[i][j];
                    pre[i][j] = k;
                }
            }
    int tx = f, ty, ans = 0;
    for(int i = f; i <= v; i++)
        if(dp[f][i] > ans){ans = dp[f][i]; ty = i;}
    printf("%d\n", ans);
    print(tx, ty);
    return 0;
}
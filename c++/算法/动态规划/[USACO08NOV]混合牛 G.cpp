#include<cmath>
#include<cstdio>
long long f[18][70000];
int num[18];

int main(){
    int n,K;
    scanf("%d %d", &n, &K);
    for(int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for(int i = 1; i <= n;i++)
        f[i][1 << (i - 1)] = 1;
    for(int i = 1; i < (1 << n); i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                if(abs(num[j] - num[k]) > K && ((1 << (j - 1)) & i)&&(((1 << (k - 1)) & i) == 0))
                    f[k][((1 << (k - 1)) | i)] += f[j][i];
    long long sum = 0;
    for(int i = 1;i <= n; i++)
        sum += f[i][(1 << n) - 1];
    printf("%lld\n", sum);
    return 0;
}

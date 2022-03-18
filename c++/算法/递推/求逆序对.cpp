#include<cstdio>
#include<algorithm>
using namespace std;
int n, k;
int f[5010][5010];

int main(){
    scanf("%d %d", &n, &k);
    f[0][0] = 0; f[1][0] = 1; f[2][1] = 1; f[2][0] = 1;
    for(int i = 3; i <= n; i++)
        for(int j = 0; j <= k; j++)
            for(int l = 0; l <= min(i - 1, j); l++)
                f[i][j] = (f[i - 1][j - l] + f[i][j]) % 10000;
    printf("%d\n", f[n][k]);
    return 0;
}
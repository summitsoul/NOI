#include<cstdio>
using namespace std;
int n, m, x1, x2, yy, y2;
int sum[1010][1010];

int main(){
    scanf("%d %d", &n, &m);
    for(int k = 1; k <= m; k++){
        scanf("%d %d %d %d", &x1, &yy, &x2, &y2);
        for(int i = x1; i <= x2; i++)
            for(int j = yy; j <= y2; j++)
                sum[i][j]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
    return 0;
}
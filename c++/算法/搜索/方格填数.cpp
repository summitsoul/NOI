#include<cstdio>
#include<algorithm>
using namespace std;
int n, sum = 0;
int a[20], b[6][6], vis[20];

void dfs(int x, int y, int z){
    if(y > n){
        if(z != sum) return ;
        x++, y = 1, z = 0;
    }
    if(x > n){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < n; j++)
                printf("%d ", b[i][j]);
            printf("%d\n", b[i][n]);
        }
        exit(0);
    }
    for(int i = 1; i <= n * n; i++)
        if(!vis[i]){
            if(y == n && z + a[i] != sum) continue;
            if(x == n){
                int s = 0;
                for(int j = 1; j < n; j++) s += b[j][y];
                if(s + a[i] != sum) continue;
            }
            if(x == n && y == 1){
                int s = 0;
                for(int j = 1; j < n; j++) s += b[j][n - j + 1];
                if(s + a[i] != sum) continue;
            }
            if(x == n && y == n){
                int s = 0;
                for(int j = 1; j < n; j++) s += b[j][j];
                if(s + a[i] != sum) continue;
            }
            b[x][y] = a[i];
            vis[i] = 1;
            dfs(x, y + 1, z + a[i]);
            b[x][y] = 0;
            vis[i] = 0;
        }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n * n; i++)
        scanf("%d", &a[i]), sum += a[i];
    sum /= n;
    printf("%d\n", sum);
    sort(a + 1, a + n * n + 1);
    dfs(1, 1, 0);
    return 0;
}
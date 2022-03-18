#include<cstdio>
#include<algorithm>
using namespace std;
int n, x, y, ans = 0;
int a[110][110], f[110][110];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int step){
    ans = max(ans, step);
    for(int i = 0; i < 4; i++){
        int xx = x, yy = y, s = 0;
        while(xx + dx[i] > 0 && xx + dx[i] <= n && yy + dy[i] > 0 && yy + dy[i] <= n){
            xx += dx[i]; yy += dy[i]; s += 1;
            if(a[xx][yy] == 0) break;
        }
        if(xx >0 && xx <= n && yy > 0 && yy <= n && a[xx][yy] == 0 && f[xx][yy] == 0 && s != 1){
            f[xx][yy] = 1;
            dfs(xx, yy, step + s);
            f[xx][yy] = 0;
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &x, &y);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    f[x][y] = 1;
    dfs(x, y, 0);
    printf("%d\n", ans);
    return 0;
}

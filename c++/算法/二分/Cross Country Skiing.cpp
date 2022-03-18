#include<cmath>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int n, m, sx, sy, ans;
int a[510][510];
bool imp[510][510];
bool jud[510][510];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int mid){
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx > 0 && xx <= n &&  yy > 0 && yy <= n){
            if(abs(a[xx][yy] - a[x][y]) <= mid){
                jud[xx][yy] = true;
                dfs(xx, yy, mid);
            }
        }
    }
}

bool check(int mid){
    memset(jud, false , sizeof(jud));
    jud[sx][sy] = true;
    dfs(sx, sy, mid);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(imp[i][j])
                if(!jud[i][j]) return false;
    return true;
}

signed main(){
    scanf("%lld %lld", &n, &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int x; scanf("%lld", &x);
            if(x){
                imp[i][j] = true;
                sx = i; sy = j;
            }
        }
    int l = 0, r = 2100000000;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){r = mid - 1, ans = mid;}
        else l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
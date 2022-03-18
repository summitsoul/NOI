#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
#define INF 0x3f3f3f3f
using namespace std;
int n, m;
int a[N], f[N], mi[N];
vector<int> g[N];

void dfs(int x, int minn, int pre){
    bool flag = 1;
    minn = min(a[x], minn);
    if(mi[x] > minn) mi[x] = minn, flag = 0;
    int maxn = max(f[pre], a[x] - minn);
    if(f[x] < maxn) f[x] = maxn, flag = 0;
    if(flag) return ;
    for(int i = 0; i < g[x].size(); i++) dfs(g[x][i], minn, x);
}

int main(){
    scanf("%d %d", &n, &m);
    memset(mi, INF, sizeof(mi));
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++){
        int x, y, z; scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(y);
        if(z == 2) g[y].push_back(x);
    }
    dfs(1, INF, 0);
    printf("%d\n", f[n]);
    return 0;
}
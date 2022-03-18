#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
int n, ans = 0;
struct tree{
    int l, r;
}t[N];

void dfs(int x, int depth){
    if(x == 0) return ;
    ans = max(ans, depth);
    dfs(t[x].l, depth + 1);
    dfs(t[x].r, depth + 1);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &t[i].l, &t[i].r);
    dfs(1, 1);
    printf("%d\n", ans);
    return 0;
}

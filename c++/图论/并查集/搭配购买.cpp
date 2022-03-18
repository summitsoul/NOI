#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m, w;
int c[N], d[N], f[N], fa[N];

int find(int x){
    if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}

int main(){
    scanf("%d %d %d", &n, &m, &w);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= n; i++) scanf("%d %d", &c[i], &d[i]);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d %d", &u, &v);
        int x = find(u), y = find(v);
        if(x != y) fa[x] = y;
    }
    for(int i = 1; i <= n; i++){
        if(fa[i] != i){
            d[find(i)] += d[i];
            d[i] = 0;
            c[find(i)] += c[i];
            c[i] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = w; j >= c[i]; j--)
            f[j] = max(f[j], f[j - c[i]] + d[i]);
    printf("%d\n", f[w]);
    return 0;
}
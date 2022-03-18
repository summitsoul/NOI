#include<cstdio>
#include<algorithm>
#define N 10000010
#define ll long long
using namespace std;
ll ans = 0;
int n, cnt = 0;
ll head[N], fa[N], d[N], size[N], f[N];
struct edge{
	int to, next;
}e[N];

void add(int u, int v){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void dfs1(int u, int fa){
	size[u] = 1; d[u] = d[fa] + 1;
	for(int i = head[u]; i; i = e[i].next){
		int v = e[i].to;
		if(v == fa) continue;
		dfs1(v, u);
		size[u] += size[v];
	}
}

void dfs2(int u, int fa){
	for(int i = head[u]; i; i = e[i].next){
		int v = e[i].to;
		if(v == fa) continue;
		f[v] = f[u] + n - 2 * size[v];
		dfs2(v, u);
	}
}

int main(){
	scanf("%lld", &n);
	for(int i = 1; i < n; i++){
		int u, v; scanf("%d %d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs1(1, 0);
	for(int i = 1; i <= n; i++) f[1] += d[i];
	dfs2(1, 0);
	int k = 0;
	for(int i = 1; i <= n; i++)
		if(ans < f[i]){
			ans = f[i]; k = i;
		}
	printf("%d\n", k);
	return 0;
} 

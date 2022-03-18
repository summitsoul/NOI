#include<cstdio>
#include<algorithm>
using namespace std;
int n, cnt = 0, ans = -1000010;
int b[100010], head[100010], f[100010];
struct edge{
	int to, next;
}e[100010]; 

void add(int u, int v){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void dfs(int u, int fa){
	f[u] = b[u];
	for(int i = head[u]; i; i = e[i].next){
		int v = e[i].to;
		if(v != fa){
			dfs(v, u);
			f[u] += max(0, f[v]);
		}
	}
	ans = max(ans, f[u]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i < n; i++){
		int u, v; scanf("%d %d", &u, &v);
		add(u, v); add(v, u); 
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}

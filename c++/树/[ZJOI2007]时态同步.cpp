#include<cstdio>
#include<algorithm>
#define N 500010
using namespace std;
int n, s, cnt = 0;
int head[N], maxn[N], dis[N];
long long ans;
struct edge{
	int to, next, w;
}e[N];

void add(int u, int v, int w){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	head[u] = cnt;
}

void dfs(int u, int fa){
	for(int i = head[u]; i; i = e[i].next){
		int to = e[i].to;
		if(to == fa) continue;
		dfs(to, u);
		dis[u] = max(dis[u], dis[to] + e[i].w);
	}
	for(int i = head[u]; i; i = e[i].next){
		int to = e[i].to;
		if(to == fa) continue;
		ans += dis[u] - (dis[to] + e[i].w);
	}
}

int main(){
	scanf("%d %d", &n, &s);
	for(int i = 1; i < n; i++){
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	dfs(s, 0);
	printf("%lld\n", ans);
	return 0;
}

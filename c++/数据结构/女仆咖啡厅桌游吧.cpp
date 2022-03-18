#include<cstdio>
#include<algorithm>
#define N 500010
using namespace std;
int n, cnt = 0;
int head[N], ans[N], dis[N], in[N];
struct edge{
	int to, next;
}e[N];

void add(int u, int v){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void dfs(int u, int fa){
	int sum = 1;
	for(int i = head[u]; i; i = e[i].next){
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v, u);
		if(in[v] == 1) sum++;
		else ans[u] += ans[v];
	}
	ans[u] += sum / 2;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u, v; scanf("%d %d", &u, &v);
		add(u, v); add(v, u);
		in[u]++; in[v]++;
	}
	dfs(1, 0);
	printf("%d\n", ans[1]);
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
int n, cnt = 0;
int f[6010][2], head[6010], vis[6010], is[6010];

struct edge{
	int next,to;
}e[6010];

void add(int u,int v){
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void dfs(int x){
	vis[x] = 1;
	for(int i = head[x]; i; i = e[i].next){
		if(vis[e[i].to]) continue;
		dfs(e[i].to);
		f[x][1] += f[e[i].to][0];
		f[x][0] += max(f[e[i].to][0], f[e[i].to][1]);
	}
	return ;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &f[i][1]);
	for(int i = 1; i < n; i++){
		int l, k; scanf("%d %d", &l, &k);
		is[l] = 1; add(k, l);
	}
	for(int i = 1; i <= n; i++)
		if(!is[i]){
			dfs(i);
			printf("%d\n",max(f[i][1], f[i][0])); 
			return 0;
		}
}

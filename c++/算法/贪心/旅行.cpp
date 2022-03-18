#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, cnt = 0;
int vis[5010], ans[5010];
vector<int> a[5010];

void dfs(int u, int fa){
	if(vis[u]) return ;
	vis[u] = 1;
	ans[++cnt] = u;
	for(int i = 0; i < a[u].size(); i++){
		int v = a[u][i];
		if(v == fa) continue;
		dfs(v, u);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v; scanf("%d %d", &u, &v);
		a[u].push_back(v); a[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());
	dfs(1, 0);
	for(int i = 1; i <= cnt; i++)
		printf("%d ", ans[i]);
	return 0;
}

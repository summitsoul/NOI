#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,cnt = 0;
int head[100010],dep[100010],Fa[100010][25],size[100010];
struct edge{
	int next, to;
}e[200010];
void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to = v;
	head[u] = cnt;
}
void dfs(int x, int fa){
	dep[x] = dep[fa] + 1;
	size[x] = 1;  Fa[x][0] = fa;
	for(int i = 1;i <= 20; i++) Fa[x][i] = Fa[Fa[x][i - 1]][i - 1];
	for(int i = head[x];i;i=e[i].next) if(e[i].to ^ fa) dfs(e[i].to, x), size[x] += size[e[i].to];
}
int lca(int x, int y){
	for(int i = 20; ~i; i--) if(dep[Fa[x][i]] >= dep[y]) x = Fa[x][i];
	for(int i = 20; ~i; i--) if(Fa[x][i] ^ Fa[y][i]) x = Fa[x][i], y = Fa[y][i];
	if(x ^ y) return Fa[x][0];
	else return y;
}
int find(int x, int y){
	for(int i = 20; ~i; i--) if(y>>i&1) x=Fa[x][i];
	return x;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u, v; scanf("%d %d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs(1,0);
	scanf("%d", &m);
	for(int i=1;i<=m;i++){
		int x, y, len, LCA;scanf("%d %d", &x, &y);
		if(dep[x]<dep[y]) swap(x,y);
		LCA = lca(x, y);
		len = dep[x] + dep[y] - 2 * dep[LCA];
		if(len & 1) printf("0");
		else{
			len >>= 1;
			int mid = find(x, len);
			if(mid == x) printf("%d", n);
			else if(mid == LCA) printf("%d",size[1] - size[find(x, len - 1)] - size[find(y, len - 1)]);
			else printf("%d",size[mid] - size[find(x, len - 1)]);
		}
		printf("\n");
	}
	return 0;
}

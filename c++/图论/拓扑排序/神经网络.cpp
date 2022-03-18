#include<queue>
#include<cstdio>
#define N 110
using namespace std;
int n, m, cnt = 0;
int head[N], c[N], vis[N];
bool out[N];
struct edge{
	int to, next, w;
}e[N];
queue<int> q;

void add(int u, int v, int w){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	head[u] = cnt;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		out[i] = false; int x;
		scanf("%d %d", &c[i], &x);
		if(c[i]){q.push(i); vis[i] = true;}
		else c[i] -= x;
	}
	for(int i = 1; i <= m; i++){
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		add(u, v, w); out[u] = true;
	}
	while(!q.empty()){
		int h = q.front(); q.pop();
		if(c[h] <= 0) continue;
		for(int i = head[h]; i; i = e[i].next){
			int to = e[i].to;
			c[to] += e[i].w * c[h];
			if(!vis[to]){
				q.push(to);
				vis[to] = true;
			}
		}
	}
	bool flag = false;
	for(int i = 1; i <= n; i++)
		if(!out[i] && c[i] > 0){
			printf("%d %d\n", i, c[i]); flag = 1;
		}
	if(!flag) printf("NULL\n");
	return 0;
}

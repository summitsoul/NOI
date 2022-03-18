#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 1005; 
const int maxm = 100005; 
int n, m, s, ans[maxn], sum;
int dis[maxn], vis[maxn];
int head[maxn], cnt = 0;
struct Edge{
	int nxt, to, w;
}e[maxm];
void add(int u, int v, int w){
	e[++cnt].nxt = head[u];
	e[cnt].w = w;
	e[cnt].to = v;
	head[u] = cnt; 
}

void dijkstra(int s) {
	for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f;  
	priority_queue< pair<int, int> > q;
	q.push(make_pair(0, s));
	dis[s] = 0;
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				q.push(make_pair(-dis[v], v));
			}
		}
	}
}

int main() {
	int u[maxm], v[maxm], w[maxm];
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i]; 
		add(u[i], v[i], w[i]); 
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++) ans[i] = dis[i]; 
	cnt = 0;
	memset(dis, 0, sizeof(dis));
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= m; i++) add(v[i], u[i], w[i]); 
	dijkstra(s);
	for (int i = 1; i <= n; i++) {
		ans[i] += dis[i]; 
		sum = max(sum, ans[i]); 
	}
	cout << sum << endl;
	return 0;
}

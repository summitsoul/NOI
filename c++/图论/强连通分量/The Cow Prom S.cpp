#include<stack>
#include<vector>
#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
int n, m, ans = 0, cnt = 0, colornum = 0;
int vis[N], dfn[N], low[N], num[N], belong[N], used[N];
stack<int> s;
vector<int> G[N];

void paint(int x){
	s.pop();
	belong[x] = colornum;
	num[colornum]++;
	vis[x] = false;
}

void tarjin(int x){
	dfn[x] = low[x] = ++cnt;
	s.push(x);
	vis[x] = used[x] = true;
	for(int i = 0; i < G[x].size(); i++){
		int q = G[x][i];
		if(!dfn[q]){
			tarjin(q);
			low[x] = min(low[x], low[q]);
		}
		else if(vis[q]) low[x] = min(low[x], dfn[q]);
	}
	if(low[x] == dfn[x]){
		colornum++;
		while(s.top() != x){
			int t = s.top();
			paint(t);
		}
		paint(x);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v; scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}
	for(int i = 1; i <= n; i++)
		if(!used[i]) tarjin(i);
	for(int i = 1; i <= colornum; i++)
		if(num[i] > 1) ans++;
	printf("%d\n", ans);
	return 0;
}

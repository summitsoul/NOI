#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
using namespace std;
int n, m, p, q, cnt = 0;
int head[N], d[N], c[N];
struct edge{
	int to, next, w, broke;
}e[N << 1];
struct node{
	int c, id, fa, d;
	node(int x, int y, int z, int t){c = x; id = y; fa = z; d = t;}
};

void add(int u, int v, int w, int k){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	e[cnt].broke = k;
	head[u] = cnt;
}

void SPFA(int s){
	node st(0, s, 0, 0);
	queue<node> q;
	q.push(st);
	memset(d, 0x7f, sizeof(d));
	d[s] = 0; c[s] = 0;
	while(q.size()){
		node u = q.front(); q.pop();
		for(int i = head[u.id]; i; i = e[i].next){
			int v = e[i].to, z = e[i].w, k = e[i].broke;
			if(u.c >= k || v == u.fa) continue;
			if(d[v] > u.d + z || c[v] > u.c + 1){
				if(d[v] > u.d + z){
					d[v] = u.d + z;
					c[v] = u.c + 1;
				}
				q.push(node(u.c + 1, v, u.id, u.d + z));
			}
		}
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &p, &q);
	for(int i = 1; i <= m; i++){
		int x, y, t, k; scanf("%d %d %d %d", &x, &y, &t, &k);
		add(x, y, t, k); add(y, x, t, k);
	}
	SPFA(p);
	if(d[q] == 0x7f7f7f7f) printf("ban 0\n");
	else printf("%d\n", d[q]);
	return 0;
}

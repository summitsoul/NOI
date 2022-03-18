#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 500
using namespace std;
int d, p, c, f, cnt = 0, ans = 0;
int head[N << 1], dis[N];
int in[N], vis[N];
struct edge{
    int to, next, w;
}e[N << 1];

void add(int u, int v, int w){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
    e[cnt].w = w;
}

bool SPFA(int x){
	memset(in, 0, sizeof(in));
	memset(vis, 0, sizeof(vis));
	memset(dis, -1e9, sizeof(dis));
	queue<int> q;
	q.push(x);
	dis[x] = d; vis[x] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
        vis[u] = 0;	in[u]++;
		if(in[u] > c) return 1;
		for(int i = head[u]; i; i = e[i].next){
			int v = e[i].to;
			if(dis[v] < dis[u] - e[i].w + d){
				dis[v] = dis[u]-e[i].w + d;
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return 0;
}

int main(){
    scanf("%d %d %d %d", &d, &p, &c, &f);
    for(int i = 1; i <= p; i++){
        int u, v; scanf("%d %d", &u, &v);
        add(u, v, 0);
    }
    for(int i = 1; i <= f; i++){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    for(int i = 1; i <= c; i++){
        if(SPFA(i)) {printf("orz\n"); return 0;}
        for(int j = 1; j <= c; j++) ans = max(ans, dis[j]);
    }
    printf("%d\n", ans);
    return 0;
}

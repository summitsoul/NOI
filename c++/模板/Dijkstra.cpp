#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f
using namespace std;
const int maxn = 1e4 + 10; 
int n, m, s, t, cnt = 0;
int head[maxn], dis[maxn], vis[maxn]; 
struct edge{
	int to, w, next;
}e[maxn];

void add(int u, int v, int w){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	head[u] = cnt;
}

void Dijkstra(){
	for(int i = 1; i <= n - 1; i++){ //n - 1��ѭ�� 
		int minn = INF, now;
		for(int j = 1; j <= n; j++) //�������һ���� 
			if(!vis[i] && dis[j] < minn){
				minn = dis[j];
				now = j;
			} 
		vis[now] = 1;
		for(int i = head[now]; i; i = e[i].next){ //����������nowΪ���ı� 
			int v = e[i].to; 
			dis[v] = min(dis[v], dis[now] + e[i].w); 
		}
	}
}

int main(){
	memset(vis, 0, sizeof(vis));
	memset(dis, INF, sizeof(dis));
	memset(head, -1, sizeof(head));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	s = 1, t = n; //sΪ���,tΪ�յ�
	dis[s] = 0;
	Dijkstra(); 
	printf("%d\n", dis[t]);
	return 0;
}
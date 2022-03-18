#include<queue> 
#include<cstdio>
#include<cstring>
#define INF 2147483647
using namespace std;
const int N = 500010;
int n, m, s, cnt = 0;
int head[N], dis[10010];	//dis��¼�����ĳ���	
bool vis[N];	//vis��¼�Ƿ��ڶ�
struct edge{
	int to, next, w;
}e[N];
void spfa(int s);

void add(int u, int v, int w){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	head[u] = cnt;
}

void SPFA(){
	for(int i = 1; i <= n; i++){
		dis[i] = INF;
		vis[i] = false;
	}
	dis[s] = 0;	//��㵽�����ľ���Ϊ0
	queue<int> q;
	q.push(s);	//������ 
	vis[s] = true;
	while(!q.empty()){	//������в�Ϊ�� 
		int u = q.front();	//ȡ������ 
		q.pop();	//���䵯�� 
		vis[u] = false;	
		for(int i = head[u]; i; i = e[i].next){	//��ʽǰ���Ǳ��� 
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].w){	//�ɳ� 
				dis[v] = dis[u] + e[i].w;
				if(!vis[v]){	//���û����� 
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &s);
	for(int i = 1; i <= m; i++){
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		add(u, v, w); //����ͼ, ����� add(v, u, w);
	}
	SPFA();
	for(int i = 1; i <= n; i++)
		if(s == i) printf("%d�����ľ���Ϊ 0\n", s);
		else printf("%d�����ľ���Ϊ %d \n", i, dis[i]);
	return 0;
} 
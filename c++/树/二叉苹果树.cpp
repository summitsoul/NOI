#include<cstdio>
using namespace std;
int n,q;
int head[30010], cnt = 0;
struct edge{
	int w,to,next;
}e[30010];

void add(int u, int v, int cost){
	e[++cnt].w = cost;
	e[cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++){
		int a,b,c; scanf("%d %d %d", &a, &b, &c);
		add(a, b, c); add(b, a, c);
	}
	
}

#include<cstdio>
#include<algorithm>
#define N 1010
using namespace std;
int n, m, cnt = 0;
int head[N];
int f[N][N];
struct edge{
	int to, next;
}e[N];

void add(int u, int v){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void dp(int now){
	for(int i = head[now]; i; i = e[i].next){
		int v = e[i].to;
		dp(v);
		for(int j = m + 1; j >= 1; j--)
			for(int k = 0; k < j; k++)
				f[now][j] = max(f[now][j], f[v][k] + f[now][j - k]);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		int fa; scanf("%d", &fa);
		scanf("%d", &f[i][1]);
		add(fa, i);
	}
	dp(0);
	printf("%d\n", f[0][m + 1]);
	return 0; 
}

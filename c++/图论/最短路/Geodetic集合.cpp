#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, t; 
int f[50][50];

int main(){
	memset(f, 10, sizeof(f));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v; scanf("%d %d", &u, &v);
		f[u][v] = f[v][u] = 1;
	}
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		for(int j = 1; j <= n; j++)
			if(f[v][j] + f[j][u] == f[v][u]) printf("%d ", j);
			printf("\n");
	}
	return 0;
}

#include<cstdio>
using namespace std;
int n, b, m;
int c[55], f[55][1010];

int main(){
	scanf("%d %d %d", &n, &b, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	f[0][b] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++){
			if(f[i - 1][j] && j + c[i] <= m) f[i][j + c[i]] = 1;
			if(f[i - 1][j] && j - c[i] >= 0) f[i][j - c[i]] = 1;
		}
	for(int i = m; i >= 0; i--)
		if(f[n][i]){printf("%d\n", i); return 0;}
	printf("-1\n");
	return 0;
} 

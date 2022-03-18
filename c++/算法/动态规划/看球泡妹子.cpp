#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, k, c, maxn = 0, ans = -1;
int a[110], b[110], p[110], q[110];
int f[110][110][2020];

int main(){
	memset(f, 128, sizeof(f));
	scanf("%d %d %d %d", &n, &m, &k, &c);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= m; i++) scanf("%d %d", &p[i], &q[i]), maxn += b[p[i]] + b[q[i]];
	for(int i = 0; i <= m; i++) f[i][0][0] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= i; j++)
			for(int l = 0; l <= maxn; l++){
				f[i][j][l] = max(f[i][j][l], f[i - 1][j][l]);
				if(l >= b[p[i]] + b[q[i]]) f[i][j][l] = max(f[i - 1][j][l], f[i - 1][j - 1][l - b[p[i]] - b[q[i]]] + a[p[i]] * a[q[i]]);
			}
	for(int i = c; i <= maxn; i++)
		ans = max(ans, f[m][k][i]);
	printf("%d\n", ans);
	return 0;
}

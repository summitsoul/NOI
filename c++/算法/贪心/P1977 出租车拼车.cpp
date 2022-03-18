#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,d,s;
int t[110],z[110],f[110][110];

int main(){
	scanf("%d %d %d %d", &n, &k, &d, &s);
	for(int i = 1; i <= k; i++) scanf("%d %d", &t[i], &z[i]);
	memset(f, 10, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= k; i++)
		for(int j = 0; j <= n; j++){
			f[i][j] = f[i - 1][j];
			for(int k = 0; k <= min(j,z[i]); k++)
				f[i][j] = min(f[i - 1][j - k] + k * t[i] + d, f[i][j]);
		}
	if(f[k][n] >= 10000) printf("impossible");
	else printf("%d", f[k][n]);
	return 0;
}

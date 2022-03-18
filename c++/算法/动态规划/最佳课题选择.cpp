#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
long long f[25][210], a[210], b[210];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++)
		scanf("%lld %lld", &a[i], &b[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; i++)
			for(int k = 0; k <= j; k++){
				long long p = a[i] * pow(k, b[i]);
				if(f[i][j] == 0 || i == 1) f[i][j] = f[i - 1][j - k] + p;
				else f[i][j] = min(f[i - 1][j - k] + p, f[i][j]); 
			}
	printf("%lld\n", f[n][m]);
	return 0;
}

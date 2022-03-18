#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans = 0;
int v[2010],f[2010][2010];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++){
			int l = i - j;
			f[i][j] = max(f[i - 1][j] + v[n - l + 1] * i, f[i - 1][j - 1] + v[j] * i);
		}
	for(int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
	printf("%d\n", ans);
	return 0;
}

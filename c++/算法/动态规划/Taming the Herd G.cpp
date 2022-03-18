#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[110], f[110][110], dp[110][110];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			f[i][j] = f[i][j - 1] + (a[j] != (j - i));
	memset(dp, INF, sizeof(dp));
	dp[1][1] = (a[1] != 0);
	for(int i = 1; i <= n; i++) dp[0][i] = 0;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= i; j++)
			for(int k = j; k <= i; k++)
				dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + f[k][i]);
	for(int i = 1; i <= n; i++)
		printf("%d\n", dp[n][i]);
	return 0;
}

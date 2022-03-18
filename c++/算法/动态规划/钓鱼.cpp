#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, h;
int f[30], d[30], t[30], dp[30][10010], ans = 0;

int main(){
	scanf("%d %d", &n, &h); h *= 12;
	for(int i = 1; i <= n; i++) scanf("%d", &f[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
	for(int i = 1; i < n; i++) scanf("%d", &t[i]);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= h; j++)
			for(int k = 0; k <= j - t[i - 1]; k++){
				if((k - 1) * d[i] < f[i] && dp[i - 1][j - t[i - 1] - k] != -1){
					dp[i][j] = max(dp[i][j], 
					dp[i - 1][j - t[i - 1]- k] + k * f[i] - k * (k - 1) / 2 * d[i]);
					ans = max(ans, dp[i][j]);
				}
			}
	printf("%d\n", ans);
	return 0;
				
}
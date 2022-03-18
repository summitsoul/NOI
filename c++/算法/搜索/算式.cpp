#include<cstdio>
#include<algorithm>
using namespace std;
int n, k;
int a[16], sum[16], dp[16][16];

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		dp[i][0] = sum[i] = sum[i - 1] + a[i];
		dp[1][i] = a[i];
	}
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= min(k, i - 1); j++)
			for(int l = j; l <= i - 1; l++)
				dp[i][j] = max(dp[i][j], dp[l][j - 1] * (sum[i] - sum[l]));
	printf("%d\n", dp[n][k]);
	return 0;
} 

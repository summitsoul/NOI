#include<cstdio>
using namespace std;
int n;
double dp[1260][1260];

int main(){
	scanf("%d", &n);
	n >>= 1;
	for(int i = 2; i <= n; i++)
		dp[i][0] = dp[0][i] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * 0.5;
	printf("%.4f\n", dp[n][n]);
	return 0;
}

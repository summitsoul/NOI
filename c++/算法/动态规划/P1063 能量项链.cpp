#include<cstdio>
#include<algorithm>
using namespace std;
int n, maxn = 0;
int dp[220][220];
int zhu[220];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int a; scanf("%d", &a);
		zhu[i] = zhu[i + n] = a;
	}
	for(int i = 2; i <= 2 * n; i++)
		for(int j = i; (i - j) < n && j >= 1; j--){
			for(int k = j; k < i; k++)
				dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + zhu[j] * zhu[k + 1] * zhu[i + 1]);
			maxn = max(maxn, dp[j][i]);
			}
	printf("%d\n", maxn);
	return 0;
}

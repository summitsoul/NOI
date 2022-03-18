#include<cstdio>
#include<iostream>
using namespace std;
int n, m, t, p;
int mp[1010][1010], dp[1010][1010];

int main(){
	scanf("%d %d %d %d", &n, &m, &t, &p);
	for(int i = 1; i <= t; i++){
		int a, b; scanf("%d %d", &a, &b);
		mp[b][a] = 1;
	}
	if(n <= 1000 && m <= 1000){
		for(int i = 0; i <= n; i++) if(mp[0][i] == 0) dp[0][i] = 1;
		for(int i = 0; i <= m; i++) if(mp[i][0] == 0) dp[i][0] = 1;
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n; j++){
				if(mp[i][j] == 0){
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else dp[i][j] = 0;
			}
		printf("%d\n", dp[m][n] % p);
		return 0;
	}
}

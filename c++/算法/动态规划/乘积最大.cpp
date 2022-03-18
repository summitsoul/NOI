#include<cmath>
#include<string>
#include<iostream>
#define ll long long
using namespace std;
int n,k;
int a[45];
char s[45];
ll dp[45][45];
ll cs(int ks,int js){
	ll sum = 0,t = 1;
	for(int i = js; i >= ks; i--) sum += (s[i] - '0')*t,t*=10;
	return sum;
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) dp[1][i] = cs(1, i);
	for(int i = 1; i <= n; i++) cout << dp[1][i] << endl;
	for(int j = 1; j <= k; j++)
		for(int i = j + 1; i <= n; i++)
			for(int l = j; l <= i; l++)
				dp[i][j] = max(dp[i][j], dp[l][j-1] * cs(l + 1, i));
	cout << dp[n][k] << endl;
	return 0;
}

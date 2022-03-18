#include<bits/stdc++.h>
using namespace std;
	int dp[10010][10010],p1[100100],p2[100100];
	int n;
int main(){

	cin>>n;
	for(int i=1;i<=n;i++) cin>>p1[i];
	for(int i=1;i<=n;i++) cin>>p2[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(p1[i]==p2[j])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
		}
	cout<<dp[n][n]<<endl;
	return 0;
}

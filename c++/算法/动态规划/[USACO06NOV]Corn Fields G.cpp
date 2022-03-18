#include<iostream>
#define N 100000000
using namespace std;
int n,m,ans=0;
int f[15];
int farm[15][15];
int dp[15][1<<12+10];
bool g[1<<12+10];

int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			cin>>farm[i][j];
			f[i]=(f[i]<<1)+farm[i][j];
		}
	for(int i=0;i<(1<<n);i++)
		g[i]=(!(i&(i<<1)))&&(!(i&(i>>1)));
	dp[0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<(1<<n);j++)
			if(g[j]&&((j&f[i])==j))
				for(int k=0;k<(1<<n);k++)
					if((k&j)==0)
						dp[i][j]=(dp[i][j]+dp[i-1][k])%N;
	for(int i=0;i<(1<<n);i++)	ans=(ans+dp[m][i])%N;
	printf("%d\n",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int stone[110][110],dp1[110][110],dp2[110][110];	//石头个数、最小、最大 
int main(){
	int n,Min,Max;	//石头个数
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>stone[1][i];
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n-i+1;j++){ 
			stone[i][j]=stone[i-1][j]+stone[1][j+i-1];
			Min=dp1[i-1][j];
			for(int k=i-1;k>=1;k--)
				if(Min>(dp1[k][j]+dp1[i-k][j-k]))
					Min=dp1[k][j]+dp1[i-k][j-k];
				dp1[i][j]=stone[i][j]+Min;
		}
		cout<<stone[n][1]<<endl;
		return 0;
} 

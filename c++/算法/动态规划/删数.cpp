#include<cmath>
#include<iostream>
using namespace std;
int n;
int a[110],dp[110];

int val(int x,int y){return x==y?a[x]:abs(a[y]-a[x])*(y-x+1);}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=val(1,i);   
		for(int j=1;j<=i-1;j++)	
			dp[i]=max(dp[i],dp[j]+val(j+1,i));
	}
	cout<<dp[n]<<endl;
	return 0;
}

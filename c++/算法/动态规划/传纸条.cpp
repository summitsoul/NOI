#include<bits/stdc++.h>
using namespace std;
int a[55][55],f[110][55][55];
int max_ele(int a,int b,int c,int d){
    if (b>a)
        a=b;
    if (c>a)
        a=c;
    if (d>a)
        a=d;
    return a;
}
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=m+n-1;i++)
		for(int j=1;j<=m;i++)
			for(int k=1;k<=m;k++){
				if(i-j+1<1||i-k+1<1) continue;
				f[i][j][k]=max_ele(f[i-1][j][k],f[i-1][j-1][k],f[i-1][j][k-1],f[i-1][j-1][k-1])+a[j][i-j+1]+a[k][i-k+1];
				if(j==k) f[i][j][k]-=a[j][i-j+1];
			}	
	cout<<f[n+m-1][m][m]<<endl;
	return 0;
}

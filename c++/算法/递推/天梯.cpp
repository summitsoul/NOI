#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	int f[2000010];
	cin>>n>>k;
	f[k]=1;
	for(int i=1+k;i<=n+k;i++)
		for(int j=i-k;j<i;j++){
			if(j>=k)f[i]+=f[j];
			else f[i]=f[i];
		}
	cout<<f[n+k]%3832438324<<endl;
	return 0;
}

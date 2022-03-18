#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 2000010
using namespace std;
int n,k,ans=0;
int a[55];
int f[M];

int main(){
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	cin>>k>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=a[i];j<=a[i]*k;j++)
			if(f[j-a[i]]<min(k,f[j]-1))
				f[j]=f[j-a[i]]+1;
	for(int i=1;i<=M;i++){
		if(f[i]!=0x3f) ans++;
		else break;
	}
	cout<<ans<<endl;
	return 0;
}      

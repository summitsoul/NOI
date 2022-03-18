#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int pri[1010],f[1010][1010];
int p,q;

int main(){
	ios::sync_with_stdio(false);
	cin>>p>>q;
	for(int i=1;i<=q;i++)	cin>>pri[i];
	sort(pri+1,pri+q+1);
	pri[0]=0;	pri[q+1]=p+1;
	for(int i=1;i<=q;i++){
		for(int j=1;j+i<=q+1;j++){
			int k=i+j-1;
			f[j][k]=0x3f3f3f;
			for(int l=j;l<=k;l++){
				f[j][k]=min(f[j][k],f[j][l-1]+f[l+1][k]+pri[k+1]-pri[j-1]-2);
			}
		}
	}
	cout<<f[1][q]<<endl;
	return 0;
}

#include<cmath>
#include<iostream>
using namespace std;
int a[500010],b[500010],x[500010];
int sum1,sum2;

int main(){
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) cin>>b[i];
	if(n==1){cout<<'-'<<sqrt(m/a[1])<<' '<<sqrt(m/a[1])<<endl; return 0;} 
	if(n==2){cout<<'-'<<sqrt(m/(a[1]+a[2]-b[1]))<<' '<<sqrt(m/(a[1]+a[2]-b[1]))<<endl; return 0;}
	else{
		for(int i=1;i;i++){
			x[1]=i;
			for(int j=2;j<=n;j++) x[j]=-1*x[j-1];
			sum1=sum2=0;
			for(int j=1;j<=n;j++) sum1+=a[j]*x[j]*x[j];
			for(int j=1;j<n;j++) sum2+=b[j]*x[j]*x[j+1];
			if((sum2+sum1)==m){cout<<'-'<<x[1]<<' '<<x[1]; return 0;}
		}
	}
}

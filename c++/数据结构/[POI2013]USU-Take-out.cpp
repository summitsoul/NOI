#include<cstdio>
#include<iostream>
const int N=1000010;
using namespace std;
int n,k,top,cnt;
int s[N],num[N],ans[N];
bool b[N];

void hhh(int x,int y){for(int i=x;i<=y;i++) b[i]=b[i+1];}

int main(){
	scanf("%d %d", & n, & k);
	for(int i=1;i<=n;i++){
		char c;	cin>>c;
		if(c=='b') b[i]=true;
	}
	int c=n;
	for(int l=1;l<=c/(k+1);l++){
		for(int i=1;i<=n;i++){
			s[++top]=i;
			if(!b[i]) num[top]=num[top-1]+1;
			if(top>=k+1&&num[top]-num[top-k-1]==1){
				for(int j=top;j>=top-k;j--) ans[++cnt]=s[j];
				for(int j=top;j>=top-k;j--){
					hhh(s[j],n);
					n--;
				}
				top-=k+1;
				break;	
			}
		}
	}
	for(int i=n;i>=1;i--){
		printf("%d ",ans[i]);
		if(i%(k+1)==1) cout<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define N 25
using namespace std;
int n,minn=0x3f3f3f;
int a[N][N];	//边权 
int lx[N],ly[N];	//顶标 
int visx[N],visy[N];	//标记 
int pi[N];	//记录匹配对象 

void dfs(int x){
	visx[x]=1;
	for(int i=1;i<=n;i++){
		if(!visy[i]){
			int t=lx[x]
		}
	}
}

void km(){
	for(int i=1;i<=n;i++){
		memset(visx,0,sizeof(visx));
		memset(visy,0,sizeof(visy));
		if(dfs(i))	break;
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;i<=n;j++){
			int r;	cin>>r;
			a[j][i]*=r;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		lx[i]=max(lx[i],a[i][j]);
	km();
}












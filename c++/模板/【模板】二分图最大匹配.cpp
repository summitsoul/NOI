#include<bits/stdc++.h>
using namespace std;
int n,m,e,sum=0;
int a[510][510],used[510],girl[510],boy[510];

bool km(int x){
	for(int j=1;j<=m;j++){
		if(a[x][j]==1 && used[j]==0){
			used[j]=1;
			if(girl[j]==0 || km(girl[j])){
				girl[j]=x;
				boy[x]=j;
				return true;
			}
		}
	}
	return false;
}

int main(){
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++){
		int u,v;	cin>>u>>v;
		a[u][v]=1;
	}
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		if(km(i)) sum++;
	}
	cout<<sum<<endl;
}

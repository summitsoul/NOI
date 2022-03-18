#include<bits/stdc++.h>
#define MAXN 0x3f3f3f
using namespace std;
int n,m,q,num=0;	//村庄的数目,公路的数量,q个询问
int mp[210][210],t[210];

void floyd(int k){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mp[i][j]=mp[j][i]=min(mp[i][j],mp[i][k]+mp[k][j]);
	return ;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)	cin>>t[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)	mp[i][j]=MAXN; 
	for(int i=0;i<m;i++){
		mp[i][i]=0;
		int a,b,w;
		cin>>a>>b>>w;
		mp[a][b]=mp[b][a]=w;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int x,y,z;
		cin>>x>>y>>z;
		while(t[num]<=z&&num<n){
			floyd(num); num++;
		}
		if(t[x]>z||t[y]>z)cout<<-1<<endl;	
		else{
			if(mp[x][y]==MAXN)cout<<-1<<endl;
			else cout<<mp[x][y]<<endl;
		}
	}
	return 0;
}

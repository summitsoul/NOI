#include<iostream>
using namespace std;
int n,m,ans=0;
int mp[510][510];
int dx[]={0,0,0,1,-1},dy[]={0,1,-1,0,0};

void dfs(int x,int y){
	if(x<0||x>n+1||y<0||y>m+1||mp[x][y]) return ;
	mp[x][y]=2;
	for(int i=1;i<=4;i++) dfs(x+dx[i],y+dy[i]);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char c; cin>>c;
			if(c=='0') mp[i][j]=0;
			else mp[i][j]=1;
		}
	dfs(0,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) if(!mp[i][j]) ans++;
	cout<<ans<<endl;
	return 0;
}

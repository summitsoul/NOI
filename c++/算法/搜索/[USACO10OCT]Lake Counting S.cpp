#include<iostream>
using namespace std;
int n,m,ans=0;
char f[110][110];
int dx[]={0,0,0,1,-1,1,1,-1,-1},dy[]={0,1,-1,0,0,1,-1,1,-1};

void dfs(int x,int y){
	f[x][y]='.';
	for(int i=1;i<=8;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>m||f[xx][yy]=='.')	continue;
			f[xx][yy]='.';
			dfs(xx,yy);
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)	cin>>f[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(f[i][j]=='W') dfs(i,j),ans++;
	cout<<ans<<endl;
	return 0;
}

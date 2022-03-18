#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,ans=0;
bool vis[15][15];
int dx[]={0,0,0,1,-1},dy[]={0,1,-1,0,0};

void dfs(int x,int y){
	if(x<1||x>=a||y<1||y>=b) ans++;
	else{
		for(int i=1;i<=4;i++){
			vis[x][y]=1;
			int xx=x+dx[i],yy=y+dy[i];
			if(!vis[xx][yy]) dfs(xx,yy);
		}
	}
	vis[x][y]=0;
}

int main(){
	scanf("%d %d", & a, & b);
	for(int i=1;i<a;i++){
		memset(vis,0,sizeof(vis));
		vis[i][0]=1;
		dfs(i,1);
	}
	for(int i=1;i<b;i++){
		memset(vis,0,sizeof(vis));
		vis[0][i]=1;
		dfs(1,i);
	}
	printf("%d\n",ans);
	return 0;
}

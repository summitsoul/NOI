#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x7fffffff
int m,n,ans=INF;
int f[110][110];
int mp[110][110];
int dx[]={0,0,0,1,-1},dy[]={0,1,-1,0,0};

void dfs(int x,int y,int sum,bool frog){
	if(x<1||x>m||y<1||y>m) return ;
	if(sum>=f[x][y]) return ;
	f[x][y]=sum;
	if(x==m&&y==m){
		if(sum<ans) ans=sum;
		return ;
	}	
	for(int i=1;i<=4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(mp[xx][yy]){
			if(mp[xx][yy]==mp[x][y])
				dfs(xx,yy,sum,false);
			else dfs(xx,yy,sum+1,false);
		}
		else
			if(!frog){
				mp[xx][yy]=mp[x][y];
				dfs(xx,yy,sum+2,true);
				mp[xx][yy]=0;
			}
	}
}

int main(){
	memset(f,0x3f3f3f,sizeof(f));
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		mp[a][b]=c+1;
	}
	dfs(1,1,0,false);
	printf("%d\n",ans==INF?-1:ans);
	return 0;	
}

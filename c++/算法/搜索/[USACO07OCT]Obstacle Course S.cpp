#include<cstdio>
using namespace std;
int n,ans=0x3f3f3f;
int sx,sy,ex,ey;
char mp[110][110];
int dx[]={0,0,0,-1,1},dy[]={0,1,-1,0,0};

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%c",&mp[i][j]);
			if(mp[i][j]=='A') ex=i,ey=j;
			if(mp[i][j]=='B') sx=i,sy=j; 
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%c ",mp[i][j]);
		putchar('\n');
	}
	return 0;
}

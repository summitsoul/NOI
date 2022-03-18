#include<cstdio>
#include<cstring>
using namespace std;
int m;
int a[310][310];
int dx[] = {0, 0, 0, 1, -1}, dy[] = {0, 1, -1, 0, 0};
bool vis[310][310], che[310][310];

void bfs(int x, int y, int sum){
    
}

int main(){
    scanf("%d", &m);
    memset(a, -1, sizeof(a));
    for(int i = 1; i <= m; i++){
        int x, y, z; scanf("%d %d %d", &x, &y, &z);
        a[x][y] = z;
    }
    bfs(0, 0, 0);
}



#include<bits/stdc++.h> //美丽的万能头文件
using namespace std;
int n,ma[305][305],v[305][305],sx,sy,st,ans[305][305];
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int ch(int a){
	if (a==-1) return 99999;
	else return a;
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<305;i++)
    	for (int j=0;j<305;j++)
    		ma[i][j]=-1;
    for (int i=1;i<=n;i++){
    	scanf("%d%d%d",&sx,&sy,&st);
		for (int j=0;j<5;j++){
			if (sx+dx[j]>=0&&sy+dy[j]>=0&&(ma[sx+dx[j]][sy+dy[j]]==-1||ma[sx+dx[j]][sy+dy[j]]>st))
				ma[sx+dx[j]][sy+dy[j]]=st;
		} 
	}
	queue<int> q[2];
	v[0][0]=1;
	q[0].push(0);q[1].push(0);
	while (!q[0].empty()){
		int x=q[0].front(),y=q[1].front();
		q[0].pop();q[1].pop();
		int s=ans[x][y]+1;
		if (ma[x][y]==-1){ 
			printf("%d\n",s-1);
			return 0;
		}
		for (int i=1;i<=4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if (xx>=0&&yy>=0&&s<ch(ma[xx][yy])&&v[xx][yy]==0){
				q[0].push(xx);q[1].push(yy);
				v[xx][yy]=1;
				ans[xx][yy]=s;
			}
		}
	}
	printf("-1\n");
	return 0;
}
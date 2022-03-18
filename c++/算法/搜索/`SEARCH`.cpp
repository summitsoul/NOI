/*#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, w, pd;
char mp[55][55];
bool vis[55][55];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
string d;
queue<int> q;
queue<int> t;

void dfs(int x, int y, int p){
	int tx = x + dx[p], ty = y + dy[p];
	if(mp[tx][ty] == 'X' || tx > n || tx <= 0 || ty > m || ty <= 0) return ;
	if(vis[tx][ty]) return ;
	vis[tx][ty] = true;
	t.push(tx); t.push(ty);
	dfs(tx, ty, p);
}

void bfs(string str){
	while(!q.empty()){
		int tx = q.front();
		q.pop();
		int ty = q.front();
		q.pop();
		if(str[0] == 'W') pd = 0;
		else if(str[0] == 'E') pd = 1;
		else if(str[0] == 'N') pd = 2;
		else if(str[0] == 'S') pd = 3;
		dfs(tx, ty, pd);
	}
	memset(vis, false, sizeof(vis));
	while(!t.empty()){
		q.push(t.front());
		t.pop();
		q.push(t.front());
		t.pop();
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			cin >> mp[i][j];
			if(mp[i][j] == '*'){
				q.push(i);
				q.push(j);
				mp[i][j] = '.';
			}
		}
	scanf("%d", &w);
	for(int i = 1; i <= w; i++){
		cin >> d;
		bfs(d);
	}
	while(!q.empty()){
		int tx = q.front();
		q.pop();
		int ty = q.front();
		q.pop();
		mp[tx][ty] = '*';
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			cout << mp[i][j];
		cout << endl;
	}
	return 0;
}*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int r,c,n,mp[60][60],ans[60][60];
char st[60][60],str[1000];
bool vis[60][60];
int dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1}; 
void search(int direct)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
        if(ans[i][j] && !vis[i][j])
        {
            int ddx=i+dx[direct],ddy=j+dy[direct];
            ans[i][j]=0;
            while(mp[ddx][ddy]) 
            {
                ans[ddx][ddy]=1;
                vis[ddx][ddy]=true;
                ddx=ddx+dx[direct];ddy=ddy+dy[direct];
            }
        }
    }
}
int main()
{
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
    {
        scanf("%s",st[i]+1);
        for(int j=1;j<=c;j++)
        {
            if(st[i][j]=='*') mp[i][j]=1,ans[i][j]=1; 
            else if(st[i][j]=='.') mp[i][j]=1;
            else mp[i][j]=0;
        }
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        if(str[0]=='N') search(1); 
        if(str[0]=='E') search(2); 
        if(str[0]=='S') search(3); 
        if(str[0]=='W') search(4);
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(ans[i][j]) printf("*");
            else 
            {
                if(st[i][j]=='*') printf(".");
                else printf("%c",st[i][j]);
            }
        }
        printf("\n");
    }
}

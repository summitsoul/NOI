#include<bits/stdc++.h>
using namespace std;
int n,m;	//n�ǿ�ѡ��ѧ��������,m����֪�������ѧ���Ķ���
int mp[1010][1010],col[1010],now[1010];
bool vis[1010];

void color(int u,int pre,int c){
	col[u]=c;
	for(int i=1;i<=n;i++)
		if(mp[u][i]&&!col[i])
			color(i,u,3-c);
}

bool find(int x){
	for(int i=1;i<=n;i++)
		if(mp[x][i]&&!vis[i]){
			vis[i]=1;
			if(!now[i]||find(now[i])){
				now[i]=x;
				return 1;
			}
		}
	return 0;
}

int dfs(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(col[i]!=1) continue;
		for(int j=1;j<=n;j++) vis[j]=0;
		res+=find(i);
	}
	return res;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v; ++u; ++v;	cin>>u>>v;
		mp[u][v]=mp[v][u]=1;
	}
	for(int i=1;i<=n;i++) if(!col[i])	color(i,0,1);
	cout<<n-dfs()<<endl;
	return 0;
}
/*#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1010;

int n, m, g[MAXN][MAXN], now[MAXN], col[MAXN];
bool vis[MAXN];

//����ͼȾɫ���ҳ�ͬһ�Ա����
void color(int u, int pre, int c)
{
	col[u] = c;
	for(int i=1;i<=n;i++)
		if(g[u][i] && !col[i])
			color(i, u, 3 - c);
}

bool find(int u)
{
	for(int i=1;i<=n;i++)
		if(g[u][i] && !vis[i])
		{
			vis[i] = 1;
			if(!now[i]|| find(now[i]))
			{
				now[i] = u;
				return 1;
			}
		}
	return 0;
}

inline int match()
{
	int res = 0;
	for(int i=1;i<=n;i++)
	{
		if(col[i] != 1) continue;
        //ֻѡȡĳһ�Ա����
		for(int j=1;j<=n;j++)
			vis[j] = 0;
		res += find(i);
	}
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		++x; ++y; //���ڸ���ϰ�ߣ���������е�+1
		g[x][y] = g[y][x] = 1;
	}
	for(int i=1;i<=n;i++)//��ÿһ����Ⱦɫ
    //���ڲ��ڶ���ͼ�еĵ�������ν��
		if(!col[i]) color(i, 0, 1);
	printf("%d\n",n - match());
	return 0;
}*/

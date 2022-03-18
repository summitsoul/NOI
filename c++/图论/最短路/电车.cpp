#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,a,b,c,d,ki[110][110];	//表示路口的数量，和电车的起点，终点


void floyd()
{
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(!(i == j || i == k || j == k))
					ki[i][j] = min(ki[i][k] + ki[k][j], ki[i][j]);
}

int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ki[i][j]=INF,ki[i][i]=0; 
	for(int i=1;i<=n;i++){
		cin>>c;
		for(int j=1;j<=c;j++){
			cin>>d; 
			if(j==1)	ki[i][d]=0;
			else	ki[i][d]=1;
		}
	}
	floyd();
	if(ki[a][b] == INF)	printf("-1");
	else	cout<<ki[a][b]<<endl;
	return 0;	
}
/*#include <bits/stdc++.h>
#define INF 0x3f3f3f3f//巨大无比的一个数！ 
using namespace std;
int n, s, e, m, x, f[1001][1001];//f[i][j]表示从i到j的长度 
void floy()//floyed模板 
{
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(!(i == j || i == k || j == k))//i不能等于j， j不能等于k， i不能等于k 
				{
					f[i][j] = min(f[i][k] + f[k][j], f[i][j]);//取最小值 
				}
			}
		}
	}
}
int main()
{
	memset(f, INF, sizeof(f));//初始化f 
	scanf("%d %d %d", &n, &s, &e);
	for(int i = 1; i <= n; i++)//自己到自己不用按开关 
	{
		f[i][i] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &x);
			if(j == 1)//第一个赋值为0 
			{
				f[i][x] = 0;
			}
			else
			{
				f[i][x] = 1;
			}
		}
	}
	floy();
	if(f[s][e] == INF)
	{
		printf("-1");
	}
	else
	{
		printf("%d", f[s][e]);
	}
	return 0;
}*/


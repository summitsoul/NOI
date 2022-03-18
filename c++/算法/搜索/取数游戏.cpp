#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans,mx;
int M[10][10];
int mp[10][10];

void dfs(int x,int y){
	if(y == m + 1){dfs(x + 1, 1); return ;}
	if(x == n + 1){mx = max(ans, mx); return ;}
	dfs(x, y + 1);
	if(mp[x][y] == 0){
		ans += M[x][y];
		for(int i = -1; i <= 1; i++)
			for(int j =-1; j <= 1; j++) 
				++mp[x + i][y + j];
		dfs(x, y + 1);
		for(int i = -1; i <= 1; i++)
			for(int j =-1; j <= 1; j++) 
				--mp[x + i][y + j];
		ans -= M[x][y];
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		memset(M, 0, sizeof(M));
		memset(mp, 0, sizeof(mp));
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> M[i][j];
		mx = 0;
		dfs(1, 1);
		cout<<mx<<endl;
	}
	return 0;
}

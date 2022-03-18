#include<vector>
#include<string>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n, ans = 0, tim = 0;
bool vis[17];
string str[17];
vector <int> v[20], edge[20];

void dfs(int x, int now){
	tim++;
	if(tim >= 10000){printf("%d\n", ans); return ;}
	ans = max(ans, now);
	for(int i = 0; i < v[x].size(); i++){
		int u = v[x][i], z = edge[x][i];
		if(vis[u]) continue;
		vis[u] = true;
		dfs(u, now + z);
		vis[u] = false;
	}
} 

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		cin >> str[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(str[i][str[i].length() - 1] == str[j][0])
				v[i].push_back(j), edge[i].push_back(str[j].length());
	for(int i = 1; i <= n; i++){
		vis[i] = true;
		dfs(i, str[i].length());
		vis[i] = false;
	}
	printf("%d\n", ans);
	return 0;
}

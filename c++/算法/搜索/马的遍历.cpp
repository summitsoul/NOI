#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 50010
using namespace std;
int n, m, x, y;
int mp[410][410];

dfs(int x, int y, int k){
	mp[x][y] = k; k++;
	if((x - 2) > 0 && (y - 1) > 0 && mp[x - 2][y - 1] > k) dfs(x - 2, y - 1, k);
	if((x + 2) <= n && (y + 1) <= m && mp[x + 2][y + 1] > k) dfs(x + 2, y + 1, k);
	if((x - 1) > 0 && (y - 2) > 0 && mp[x - 1][y - 2] > k) dfs(x - 1, y - 2, k);
	if((x + 1) <= n && (y + 2) <= m && mp[x + 1][y + 2] > k) dfs(x + 1, y + 2, k);
	if((x - 2) > 0 && (y + 1) > 0 && mp[x - 2][y + 1] > k) dfs(x - 2, y + 1, k);
	if((x + 2) <= n && (y - 1) <= m && mp[x + 2][y - 1] > k) dfs(x + 2, y - 1, k);
	if((x - 1) > 0 && (y + 2) > 0 && mp[x - 1][y + 2] > k) dfs(x - 1, y + 2, k);
	if((x + 1) <= n && (y - 2) <= m && mp[x + 1][y - 2] > k) dfs(x + 1, y - 2, k);
}

int main(){
	memset(mp, INF, sizeof(mp));
	scanf("%d %d %d %d", &n, &m, &x, &y);
	dfs(x, y, 0);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mp[i][j] != 0x3f)printf("%d ", mp[i][j]);
			else printf("-1 ");
		}
		printf("\n");
	}
	return 0;
}

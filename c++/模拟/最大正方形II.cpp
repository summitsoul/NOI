#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, ans = 0;
int mp[1510][1510];
int f[1510][1510][2];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &mp[i][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(mp[i][j] == 1) f[i][j][1] = min(f[i - 1][j - 1][1], min(f[i - 1][j][0], f[i][j - 1][0])) + 1, ans = max(ans, f[i][j][1]);
			if(mp[i][j] == 0) f[i][j][0] = min(f[i - 1][j - 1][0], min(f[i - 1][j][1], f[i][j - 1][1])) + 1, ans = max(ans, f[i][j][0]);
		}
	printf("%d\n", ans);
	return 0;
}

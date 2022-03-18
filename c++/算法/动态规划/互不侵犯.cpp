#include<cstdio>
using namespace std;
int n, yong, cnt = 0;
int sit[2010], gs[2010];
long long f[10][2010][110] = {0};

void dfs(int he, int sum, int node){
	if(node >= n){
		sit[++cnt] = he;
		gs[cnt] = sum; return ;
	}
	dfs(he, sum, node + 1);
	dfs(he + (1 << node), sum + 1, node + 2);
}

int main(){
	scanf("%d %d", &n, &yong);
	dfs(0, 0, 0);
	for(int i = 1; i <= cnt; i++) f[1][i][gs[i]] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= cnt; j++)
			for(int k = 1; k <= cnt; k++){
				if((sit[j] & sit[k])) continue;
				if((sit[j] << 1) & sit[k]) continue;
				if(sit[j] & (sit[k] << 1)) continue;
				for(int s = yong; s >= gs[j]; s--) 
					f[i][j][s] += f[i - 1][k][s - gs[j]];
			}
	long long ans = 0;
	for(int i = 1; i <= cnt; i++) ans += f[n][i][yong];
	printf("%lld", ans);
	return 0;
}

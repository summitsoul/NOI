#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, k, tot = 0, ans = 1e9, minn = 1e9;
int fa[100010], p[100010], s[100010], dp[100010];

int find(int x){
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x]; 
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++) fa[i] = i, p[i] = 1;
	for(int i = 1; i <= k; i++){
		int x, y; scanf("%d %d", &x, &y);
		int u = find(x), v = find(y);
		if(u != v) fa[u] = find(v), p[v] += p[u];
	}
	for(int i = 1; i <= n; i++)
		if(fa[i] == i) s[++tot] = p[i];
	for(int i = 1; i <= tot; i++)
		for(int j = 2 * m; j >= s[i]; j--)
			dp[j] = max(dp[j], dp[j - s[i]] + s[i]);
	for(int i = 1; i <= 2 * m; i++)
		if(minn > abs(dp[i] - m)) minn = abs(dp[i] - m), ans = dp[i];
	if(ans == 1e9) printf("0\n");
	else printf("%d\n", ans);
	return 0;
}

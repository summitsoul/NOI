#include<cstdio>
#define ll long long
#define N 2000010
using namespace std;
const int T = 1e9 + 7;
int n, k, tot = 0;
int nxt[N], lnk[N], son[N];
ll f[N][3];

void add(int x, int y){nxt[++tot] = lnk[x]; lnk[x] = tot; son[tot] = y;}

void dfs(int x, int fa){
	for(int i = 0; i < 3; i++){
		if(f[x][i]){for(int j = 0; j < i; j++) f[x][j] = 0; break;}
		f[x][i] = 1;
	}
	for(int i = lnk[x]; i; i = nxt[i])
		if(son[i] != fa){
			dfs(son[i], x);
			f[x][0] = f[x][0] * ((f[son[i]][1] + f[son[i]][2]) % T) % T;
			f[x][1] = f[x][1] * ((f[son[i]][0] + f[son[i]][2]) % T) % T;
			f[x][2] = f[x][2] * ((f[son[i]][0] + f[son[i]][1]) % T) % T;
		}
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; i++){
		int x, y; scanf("%d %d", &x, &y);
		add(x, y); add(y, x);
	}
	for(int i = 1; i <= k; i++){
		int x, y; scanf("%d %d", &x, &y);
		f[x][y - 1] = 1;
	}
	dfs(1, 0);
	printf("%lld\n", (f[1][0] + f[1][1] + f[1][2]) % T);
	return 0;
}

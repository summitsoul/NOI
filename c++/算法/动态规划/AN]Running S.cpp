#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int d[10010];
int f[10510][1010];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
	f[1][1] = d[1];
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= min(m, i); j++){
			if(j == 0)f[i][j] = max(f[i][j], f[i - 1][0]);
			else f[i + j][0] = max(f[i][j], f[i + j][0]);
			f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + d[i + 1]);
		}
	printf("%d\n", f[n][0]);
	return 0;
}

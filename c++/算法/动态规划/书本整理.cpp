#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, k, m, ans = 0x7f7f7f;
int f[110][110];
struct book{
	int a, w;
}b[110];

bool cmp(book x, book y){return x.a < y.a;}

int main(){
	scanf("%d %d", &n, &k); m = n - k;
	for(int i = 1; i <= n; i++)	scanf("%d %d", &b[i].a, &b[i].w);
	sort(b + 1, b + n + 1, cmp);
	memset(f, 20, sizeof(f));
	for(int i = 1; i <= n; i++) f[i][1] = 0;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= i - 1; j++)
			for(int l = 2; l <= min(i, m); l++)
				f[i][l] = min(f[i][l], f[j][l - 1] + abs(b[i].w - b[j].w));
	for(int i = m; i <= n; i++)
		ans = min(ans, f[i][m]);
	printf("%d\n", ans);
	return 0;
}

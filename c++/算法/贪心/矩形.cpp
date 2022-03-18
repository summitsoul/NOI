#include<cstdio>
#include<algorithm>
using namespace std;
int n, ans = 0, maxn = 0, Maxn = 0;
int x[310], y[310], a[310][310];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int c, d; scanf("%d %d", &c, &d); maxn = max(maxn, c); Maxn = max(Maxn, d);
		a[c][d]++;
	}
	for(int i = 1; i <= 100; i++)
		for(int j = 1; j <= 100; j++)
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	for(int x1 = 1; x1 <= maxn; x1++)
		for(int y1 = 1; y1 <= Maxn; y1++)
			for(int x2 = x1 + 1; x2 <= maxn; x2++)
				for(int y2 = y1 + 1; y2 <= Maxn; y2++){
					int sum1 = a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
					int sum2 = a[x2 - 1][y2 - 1] - a[x1][y2 - 1] - a[x2 - 1][y1] + a[x1 - 1][y1 - 1];
					sum1 -= sum2;
					ans = ans < sum1 ? sum1 : ans;
				}
	printf("%d\n", ans);
	return 0;
}

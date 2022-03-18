#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int c,h,b,f[1010][1010][2], ans = 1 << 30;
struct node{
	int x,t;
}a[1010];

bool cmp(const node&a, const node&b){return a.x < b.x;}

int main(){
	scanf("%d %d %d", &c, &h, &b);
	for(int i = 1; i <= c; i++)	scanf("%d %d", &a[i].x, &a[i].t);
	sort(a + 1, a + c + 1, cmp);
	memset(f, 127/2, sizeof(f));
	f[1][c][0] = max(a[1].x, a[1].t); f[1][c][1] = max(a[c].x, a[c].t);
	for(int i = 1; i <= c; i++)
		for(int j = c; j >= i; j--){
			f[i][j][0] = min(f[i][j][0], max(f[i - 1][j][0] + a[i].x - a[i - 1].x, a[i].t));
			f[i][j][0] = min(f[i][j][0], max(f[i][j + 1][1] + a[j + 1].x - a[i].x, a[i].t));
			f[i][j][1] = min(f[i][j][1], max(f[i - 1][j][0] + a[j].x - a[i - 1].x, a[j].t));
			f[i][j][1] = min(f[i][j][1], max(f[i][j + 1][1] + a[j + 1].x - a[j].x, a[j].t));
		}
	for(int i = 1; i <= c; i++) ans = min(ans, min(f[i][i][0], f[i][i][1]) + abs(b - a[i].x));
	printf("%d\n", ans);
	return 0;
}

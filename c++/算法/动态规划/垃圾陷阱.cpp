#include<cstdio>
#include<algorithm>
using namespace std;
int d, g;
int f[110][1010];
struct rub{
	int t, h, f;
	bool operator < (const rub & rb) const{
		return t < rb.t;
	}
}r[110];

int main(){
	memset(f, -1, sizeof(f));
	scanf("%d %d", &d, &g);
	for(int i = 1; i <= g; i++)
		scanf("%d %d %d", &r[i].t, &r[i].f, &r[i].h);
	sort(r + 1, r + g + 1);
	dp[0][0] = 10; r[0].f = 0; r[0].h = 0; r[0].t = 0;
	for(int i = 0; i < g; i++)
		for(int j = 0; j <= d; j++){
			f[i][j] = max(f[i][j], dp[i - 1][j] + r[i].h)
		}
}

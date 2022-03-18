#include<cstdio>
#include<algorithm>
using namespace std;
int a, b, m, n, c;
int t[5010], p[5010], q[5010], f[5010];

int main(){
	scanf("%d %d", &a, &b);
	int k = b / a;
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= n; i++){
		int x; scanf("%d", &x);
		t[i] = x * k;
	}
	for(int i = 1; i <= m; i++) scanf("%d %d", &p[i], &q[i]);
	scanf("%d", &c);
	for(int i = 1; i <= m; i++)
		for(int j = c; j >= t[p[i]]; j--)
			f[j] = max(f[j], f[j - t[p[i]]] + q[i]);
	printf("%d\n", f[c]);
	return 0;
}

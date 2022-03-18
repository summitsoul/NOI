#include<cstdio>
#include<algorithm>
using namespace std;
int n, c, k, ans = 0x3f3f3f;
int a[100010], b[100010];

int main(){
	scanf("%d %d %d", &n, &k, &c);
	for(int i = 1; i <= c; i++){
		int x; scanf("%d", &x);
		a[x] = 1;
	}
	for(int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
	for(int i = k; i <= n; i++) ans = min(ans, b[i] - b[i - k]);
	printf("%d\n", k - ans);
	return 0;
}

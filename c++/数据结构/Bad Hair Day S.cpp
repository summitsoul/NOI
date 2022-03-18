#include<cstdio>
using namespace std;
int n, t = 0;
int h[80010], p[80010];
long long ans = 0;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
	for(int i = 1; i <= n; i++){
		while(t && h[i] >= p[t]){
			t--;
		}
		ans += t;
		p[++t] = h[i];
	}
	printf("%lld\n", ans);
	return 0;
}

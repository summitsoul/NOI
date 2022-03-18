#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
struct node{
	int a, b;
	bool operator < (node y){
		return min(a, y.b) == min(b, y.a) ? a < y.a : min(a, y.b) < min(b, y.a);
	}
}pri[100010];

signed main(){
	int t; scanf("%lld", &t);
	while(t--){
		int n; scanf("%lld", &n);
		for(int i = 1; i <= n; i++) scanf("%lld %lld", &pri[i].a, &pri[i].b);
		sort(pri + 1, pri + n + 1);
		int ans = 0, sum = 0;
		for(int i = 1; i <= n; i++){
			sum += pri[i].a;
			ans = max(ans, sum) + pri[i].b;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
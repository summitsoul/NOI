#include<stack>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn = 100010;
int a[maxn], sum[maxn], l[maxn];
stack<int> s;

signed main(){
	int n; scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	int m = 0;
	for(int i = 1; i <= n; i++){
		while(!s.empty() && a[i] < a[s.top()]){
			m = max(m, (sum[i - 1] - sum[l[s.top()]]) * a[s.top()]);
			s.pop();
		}
		if(!s.empty()) l[i] = s.top();
		else l[i] = 0;
		s.push(i);
	}
	printf("%lld\n", m);
	return 0;
}

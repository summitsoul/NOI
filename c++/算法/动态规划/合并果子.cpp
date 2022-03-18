#include<cstdio>
#include<algorithm>
using namespace std;
int n, ans = 0;
int a[10010];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++){
		ans += (a[i] + a[i + 1]);
		a[i + 1] += a[i];
		for(int j = i + 1; j < n; j++){
			if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
			else break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

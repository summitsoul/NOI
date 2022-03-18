#include<cstdio>
#define N 200010
using namespace std;
int n, ans, maxn, cnt = 0;
int w[N], head[N];
struct edge{
	int to, next;
}e[N << 1];

void add(int u, int v){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u, v; scanf("%d %d", &u, &v);
		add(u, v); add(v, u);
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++){
		int max1 = 0, max2 = 0;
		int t1 = 0, t2 = 0;
		for(int j = head[i]; j; j = e[j].next){
			int v = e[j].to;
			if(w[v] > max1) max2 = max1, max1 = w[v];
			else if(w[v] > max2) max2 = w[v];
			t1 = (t1 + w[v]) % 10007;
			t2 = (t2 + w[v] * w[v]) % 10007;
		}
		t1 = t1 * t1 % 10007;
		ans = (ans + t1 + 10007 - t2) % 10007;
		if(maxn < max1 * max2) maxn = max1 * max2;
	}
	printf("%d %d\n", maxn, ans);
	return 0;
}

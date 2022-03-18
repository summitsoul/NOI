#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, height = 0, sum = 0, cnt = 0;
int h[310];
struct node{
	int c, w;
}a[310];

bool cmp(node x, node y){return x.c > y.c;}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	for(int i = 1; i <= n; i++){
		++cnt;
		for(int j = cnt; j <= n; j++)
			a[j].c = abs(h[j] - height), a[j].w = h[j];
		sort(a + cnt, a + n + 1, cmp);
		sum += a[cnt].c * a[cnt].c;
		height = a[cnt].w;
	}
	printf("%d\n", sum);
	return 0;
}

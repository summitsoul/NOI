#include<cstdio>
using namespace std;
int n, m, l, r, total, tim;
int a[100010];

bool judge(int x){
	int tot = 0, num = 0;
	for(int i = 1; i <= n; i++){
		if(tot + a[i] <= x) tot += a[i];
		else tot = a[i], num++;
	}
	return num >= m;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		r += a[i];
		l = l > a[i] ? l : a[i];
	}
	while(l <= r){
		int mid = (l + r) >> 1;
		if(judge(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}

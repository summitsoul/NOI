#include<cmath>
#include<cstdio>
using namespace std;
int n, ans;
int spot[55][2], fa[55];

int find(int x){
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d %d", &spot[i][0], &spot[i][1]);
	int l = 1, r = 0x7f7f7f7f;
	int ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++){
				int d = abs(spot[i][0] - spot[j][0]) + abs(spot[i][1] - spot[j][1]);
				if(d <= mid * 2){
					int x = find(i), y = find(j);
					if(x != y) fa[x] = y;
				}
			}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(fa[i] == i) cnt++;
		if(cnt == 1){
			ans = mid; r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}

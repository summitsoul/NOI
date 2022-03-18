#include<cstdio>
using namespace std;
int n, k, ans = 0;
int fa[300010];

int find(int x){
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
} 

int unity(int x, int y){
	int r1 = find(fa[x]), r2 = find(fa[y]);
	fa[r1] = r2;
}

int main(){
	int x, y, z;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= 3 * n; i++) fa[i] = i;
	while(k--){
		scanf("%d %d %d", &z, &x, &y);
		if(x > n || y > n){ans++; continue;}
		if(z == 1){
			if(find(x + n) == find(y) || find(x + 2 * n) == find(y)){ans++; continue;}
			unity(x, y); unity(x + n, y + n); unity(x +n * 2, y + n * 2);
		}
		else if(z == 2){
			if(x == y) {ans++; continue;}
			if(find(x) == find(y) || find(x + 2 * n) == find(y)) {ans++; continue;}
			unity(x, y + 2 * n); unity(x + n, y); unity(x +n * 2, y + n);
		}
	}
	printf("%d\n", ans);
	return 0;
}

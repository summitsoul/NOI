#include<cstdio>
#include<iostream>
using namespace std;
int n,d,maxn = 0;
int f[30010][710],a[30010];

int main(){
	scanf("%d %d", &n, &d);
	for(int i = 1; i <= n; i++){
		int x; scanf("%d", &x); a[x]++; maxn = max(maxn, x);
	}
	for(int i = maxn; i >= d; i--)
		for(int j = 0; j <= 700; j++){
			int mid = j - 350;
			if(d + mid <= 0) continue;
			f[i][j] = a[i];
			if(i + d + mid <= maxn) f[i][j] += max(max(f[i + d + mid][j], f[i + d + mid][j - 1]), f[i + d + mid][j + 1]); 
		}
	int ans = max(max(f[d][350], f[d][349]), f[d][351]);
	printf("%d\n", ans);
	return 0;
}

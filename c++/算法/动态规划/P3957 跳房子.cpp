#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF  0x8080808080808080
using namespace std;
int n, d, k, sum = 0;
int x[500010], s[500010], f[500010], a[500010];

int main(){
	scanf("%d %d %d", &n, &d, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &x[i], &s[i]);
		if(s[i] > 0) sum += s[i];
	}
	if(sum < k){printf("-1\n"); return 0;}
	memset(a, 0, sizeof(a));
	for(int i = n; i > 0; i--) a[x[i]] = s[i];
	for(int g = 0; g <= 1000; g++){
		for(int i = 1; i <= x[n]; i++) f[i] = a[i];
		f[0] = 0;
		if(g < d){
			for(int i = d - g; i <= d + g; i++) f[i] = max(f[i], f[0]);
			for(int i = d + g; i <= x[n]; i++)
				for(int j = d - g; j <= d + g; j++){
					//printf("i=%d j=%d ", i, j);
					if(i - j < d - g) continue;
					//printf("j=%d i-j=%d ", j, i - j);
					f[i] = max(f[i], f[i - j] + a[i]);
					//cout << "f[" << i <<"]=" << f[i] << endl;
					if(f[i] >= k){printf("%d", g); return 0;}
				}
		}
		else
			for(int i = 1; i <= x[n]; i++){
				if(i <= g){
					for(int j = 1; j <= d + g; j++)
						f[i] = max(f[i], f[i - j] + a[i]);
				}
				else{
					for(int j = d - g; j <= d + g; j++)
						f[i] = max(f[i], f[j] + a[i]);
				}
			}
	}
}

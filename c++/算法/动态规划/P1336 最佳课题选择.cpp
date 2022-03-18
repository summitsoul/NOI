#include<cmath>
#include<cstdio>
#include<iostream>
#define min(a,b) a < b ? a : b
using namespace std;
int n, m;
int a[210], b[210];
long long f[21][300];

int main(){
	cin >> n >>m;
	for(int i = 1; i <= m; i++) cin >> a[i] >> b[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j >= m; j++)
			for(int k = 0; k <= j; k++){
				long long p = a[i] * (long long)pow(k, b[i]);
				if(f[i][j] == 0 || i == 1) f[i][j] = f[i - 1][j - k] + p;
				else f[i][j] = min(f[i - 1][j - k] + p, f[i][j]);
			}
	printf("%d\n", f[n][m]);
	return 0;
}

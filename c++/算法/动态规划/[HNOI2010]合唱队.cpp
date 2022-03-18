#include<cstdio>
#define N 19650827
using namespace std;
int n;
int f[2010][2010][2], a[2010];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) f[i][i][0] = 1;
	for(int len = 1; len <= n; len++)
		for(int i = 1, j = i + len; j <= n; i++, j++){
			if(a[i] < a[i + 1]) f[i][j][0] += f[i + 1][j][0];
			if(a[i] < a[j]) f[i][j][0] += f[i + 1][j][1];
			if(a[j] > a[i]) f[i][j][1] += f[i][j - 1][0];
			if(a[j] > a[j - 1]) f[i][j][1] += f[i][j - 1][1];
			f[i][j][0] %= N;
			f[i][j][1] %= N;
		}
	printf("%d\n", (f[1][n][0] + f[1][n][1]) % N);
	return 0;
}

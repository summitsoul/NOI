#include<cstdio>
#include<algorithm>
using namespace std;
int n, ans = 0;
int f[250][250];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &f[i][i]);
	for(int len = 2; len <= n; len++)
		for(int i = 1; i <= n - len + 1; i++){
			int j = i + len - 1;
			for(int pos = i; pos < j; pos++)
				if(f[i][pos] == f[pos + 1][j] && f[i][pos] != 0 && f[pos + 1][j] != 0){
					f[i][j] = max(f[i][j], f[i][pos] + 1);
					ans = max(ans, f[i][pos] + 1);
				} 
		}
	printf("%d\n", ans);
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans = 0;
int a[2510][2510],f[2510][2510],s1[2510][2510],s2[2510][2510];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			if(!a[i][j]){
				s1[i][j] = s1[i][j - 1] + 1;
				s2[i][j] = s2[i - 1][j] + 1;
			}
			else f[i][j] = min(f[i - 1][j - 1],min(s1[i][j - 1],s2[i - 1][j])) + 1;
			ans = max(ans, f[i][j]);
		}
	memset(f, 0, sizeof(f));
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= 1; j--){
			if(!a[i][j]){
				s1[i][j] = s1[i][j + 1] + 1;
				s2[i][j] = s2[i - 1][j] + 1;
			}
			else f[i][j] = min(f[i - 1][j + 1],min(s1[i][j + 1],s2[i - 1][j])) + 1;
			ans = max(ans, f[i][j]);
		}
	printf("%d\n", ans);
	return 0;
}

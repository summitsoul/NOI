#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int f[15][20], mp[15][20];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &mp[i][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)	//ע�����Ǵ�0��ʼѭ������������Ϊ0 
			for(int k = 0; k <= j; k++)
				f[i][j] = max(f[i][j], f[i - 1][j - k] + mp[i][k]);
	printf("%d\n", f[n][m]);
	return 0;
}

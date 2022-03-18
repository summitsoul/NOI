#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f
using namespace std;
ll n,m,Max,Min=INF;
ll a[1010],b[1010];
ll f1[110][110][11],f2[110][110][11];

int main(){
	memset(f2, INF, sizeof(f2));
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i],b[i] += b[i - 1] + a[i];
	for(int i = n + 1; i <= 2 * n; i++) b[i] += b[i - 1] + a[i - n];
	for(int i = 1; i <= 2 * n; i++)
		for(int j = 1; j <= 2 * n; j++){
			f1[i][j][1] = (b[j] - b[i - 1] + 100000000)%10;
			f2[i][j][1] = (b[j] - b[i - 1] + 100000000)%10;
		}
	for(int i = 1; i <= 2 * n; i++)
		for(int j = i + 1; j <= 2 * n; j++)
			for(int l = 2; l <= m; l++)
				for(int k = i; k < j; k++){
					f1[i][j][l] = max(f1[i][j][l], f1[i][k][l - 1]*f1[k + 1][j][1]);
					f2[i][j][l] = min(f2[i][j][l], f2[i][k][l - 1]*f2[k + 1][j][1]);
				}
	for(int i = 1; i <= n; i++){
		Max = max(Max, f1[i][i + n - 1][m]);
		Min = min(Min, f2[i][i + n - 1][m]);
	}
	cout << Min << endl; cout << Max << endl;
	return 0;
}

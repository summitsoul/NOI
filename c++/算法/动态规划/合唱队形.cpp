#include<cmath>
#include<iostream>
using namespace std;
int n,maxn=0;
int t[110],f[110],g[110][2];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		g[i][1] = 1; g[i][2] = 1;
	} 
	for(int i = n - 1; i >= 1; i--)
		for(int j = i + 1; j <= n; j++)
			if(t[i] > t[j] && g[i][1] <= g[j][1] + 1) g[i][1] = g[j][1] + 1;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j < i; j++)
			if(t[i] > t[j] && g[i][2] <= g[j][2] + 1) g[i][2] = g[j][2] + 1;
	for(int i = 1; i <= n; i++){
		f[i] = g[i][1] + g[i][2] - 1;
		maxn = max(maxn, f[i]);
	}
	cout << n - maxn << endl;
	return 0;
}

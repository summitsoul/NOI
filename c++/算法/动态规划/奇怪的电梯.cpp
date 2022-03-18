#include<iostream>
using namespace std;
int n,a,b;
int k[210];
bool flag;

int dfs(int a, int sum){
	if(a == b){cout << sum << endl; flag = true; return 0;} 
	int u = a + k[a], d = a - k[a];
	sum++;
	if(u <= n) dfs(u, sum); 
	if(d >= 0) dfs(d, sum);
	sum--;
	return 0;
}

int main(){
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++) cin >> k[i];
	dfs(a, 0);
	if(!flag)cout << -1 << endl;
	return 0;
}

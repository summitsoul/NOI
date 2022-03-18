#include<vector>
#include<iostream>
using namespace std;
int n,k; 
vector<int> v[100010];

int dfs(int now, int last){
	int ans = 1;
	for(int i = 0; i < v[now].size(); i++){
		if(v[now][i] == last) continue;
		int a = dfs(v[now][i], now);
		if(a == -1 || a > k) return -1;
		else if(a == k) continue;
		ans += a;
	}
	return ans;
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i <= n; i++) v[i].clear();
		for(int i = 1; i < n; i++){
			int a,b; cin >> a >>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int ans = dfs(1,1);
		if(ans == k) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

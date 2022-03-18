#include<iostream>
#include<algorithm>
using namespace std;
int n,sum;
int ans[25],pc[25],vis[25]={0};

int dfs(int i,int num,int v){
	if(v > sum) return 0;
	if(i == n){
		if(v == sum){
			ans[i] = num;
			return 1;
		}
		else return 0;
	}
	vis[num] = 1;
	for(int j = 1; j <= n; j++){
		if(!vis[j] && dfs(i + 1,j,v + pc[i]*j)){
			ans[i] = num;
			return 1;
		}
	}
	vis[num] = 0;
	return 0;
}

int main(){
	cin >> n >> sum;
	pc[0] = pc[n - 1] = 1;
	if(n > 1)
		for(int i = 1; i*2 < n; i++)
			pc[i] = pc[n-i-1] = (n - i)*pc[i-1]/i;
	if(dfs(0,0,0))
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
	return 0;
}

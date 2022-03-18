#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n, cnt = 0;
int l[110], a[110][210];
string s;

inline void dfs(int x, int y){
	a[x][y] = 0;
	if(x + 1 <= n && a[x + 1][y]) dfs(x + 1, y);
	if(x - 1 > 0 && a[x - 1][y]) dfs(x - 1, y);
	if(y + 1 <= l[x] && a[x][y + 1]) dfs(x, y + 1);
	if(y - 1 > 0 && a[x][y - 1]) dfs(x, y - 1);
}

int main(){
	scanf("%d", &n);
	getline(cin, s); 
	for(int i = 1; i <= n; i++){
		getline(cin, s);
		l[i] = s.length();
		for(int j = 1; j <= l[i]; j++)
			if(s[j - 1] >= 'a' && s[j - 1] <= 'z') a[i][j] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= l[i]; j++)
			if(a[i][j]){
				dfs(i, j);
				cnt++;
			}
	printf("%d\n", cnt);
	return 0;
}

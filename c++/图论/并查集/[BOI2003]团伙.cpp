#include<cstdio>
using namespace std;
int n, m, ans = 0;
int f[2500];

int find(int x){
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= 2 * n; i++) f[i] = i;
	for(int i = 1; i <= m; i++){
		char ch; scanf("%s", &ch);
		int a, b; scanf("%d %d", &a, &b);
		if(ch == 'F') f[find(a)] = find(b);
		else{
			f[find(a + n)] = find(b);
			f[find(b + n)] = find(a);
		}
	}
	for(int i = 1; i <= n; i++)
		if(f[i] == i) ans++;
	printf("%d\n", ans);
	return 0;
}

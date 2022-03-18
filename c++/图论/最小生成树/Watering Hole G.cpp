#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int dist[310], a[310][310];
bool pan[310];

int prim(){
	memset(dist, 0x3f, sizeof(dist));
	dist[0] = 0;
	int ans = 0;
	for(int i = 0 ; i <= n; i++){
		int t = -1;
		for(int j = 0 ; j <= n; j++)
			if(!pan[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		pan[t] = true;
		ans += dist[t];
		for(int j = 0; j <= n; j++) dist[j] = min(dist[j], a[t][j]);
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[0][i]);
		a[i][0] = a[0][i];
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	printf("%d\n", prim());
	return 0;
}

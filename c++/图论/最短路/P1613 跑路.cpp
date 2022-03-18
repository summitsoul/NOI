#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
int dis[60][60];
bool pan[60][60][65];

inline int read(){
	int s= 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
	return s; 
}

int main(){
	memset(dis, 10, sizeof(dis));
	memset(pan, false, sizeof(pan));
	n = read(); m = read();
	for(int i = 1; i <= m; i++){
		int u, v; u = read(); v = read();
		dis[u][v] = 1;
		pan[u][v][0] = true;
	}
	for(int k = 1; k <= 64; k++)
		for(int i = 1; i <= n; i++)
			for(int t= 1; t <= n; t++)
				for(int j = 1; j <= n; j++)
					if(pan[i][t][k - 1] && pan[t][j][k - 1]){
						pan[i][j][k] = true;
						dis[i][j] = 1;
					}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	printf("%d\n", dis[1][n]);
	return 0;
}

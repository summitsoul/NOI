#include<cstdio>
#include<algorithm>
#define N 1010
using namespace std;
int n, sx, sy, tx, ty, ans = 0x7f7f7f7f;
int a[N][N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int cur){
    if(x == tx && y == ty){ans = min(ans, cur); return ;}
    if(x < 1 || x > n || y < 1 || y > n) return ;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(a[xx][yy] == 0){
            a[xx][yy] = 1;
            dfs(xx, yy, cur + 1);
            a[xx][yy] = 0;
        }
    }
    return ;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
    if(a[tx][ty] == 1){printf("-1\n"); return 0;}
    a[sx][sy] = 1;
    dfs(sx, sy, 0);
    if(ans == 0x7f7f7f7f) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}


#include<cstdio>
using namespace std;
int n, sx, sy, tx, ty;
int g[2001][2001];
const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
struct wang{
	int ii , jj, bu;
}dui[4000002]; 

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &g[i][j]);
	scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
	int head = 0, tail = 0;
	dui[tail].ii = sx;
	dui[tail++].jj = sy;
	g[sx][sy] = 1; 
	while(head < tail){
		for(int i = 0 ; i < 4; i++){
			int nx = dui[head].ii + dx[i],ny = dui[head].jj + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && !g[nx][ny]){
				if(nx == tx && ny == ty){
					printf("%d\n",dui[head].bu + 1);
					return 0;
				}
				g[nx][ny] = 1;
				dui[tail].ii = nx;
				dui[tail].jj = ny;
				dui[tail++].bu = dui[head].bu + 1;
			}
		}
		head++;
	}
	printf("-1\n");
	return 0;
} 
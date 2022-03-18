#include<cstdio>
#include<algorithm>
#define N 1010
using namespace std;
template <class t> void chemax(t &a, t b){if(a < b) a = b;}
int cnt;
int f[N][N];
struct tree{
	int cost, val;
}t[N * 10];

void init(int x){
	scanf("%d %d", &t[x].cost, &t[x].val);
	t[x].cost *= 2;
	if(!t[x].val){
		init(x << 1); init(x << 1 | 1);
	}
}

int dfs(int x, int cnt){
	if(f[x][cnt] > 0 || !cnt) return f[x][cnt];
	if(t[x].val) return f[x][cnt] = min(t[x].val, (cnt - t[x].cost) / 5);
	for(int i = 0; i <= cnt - t[x].cost; i++)
		chemax(f[x][cnt], dfs(x << 1, i) + dfs(x << 1 | 1, cnt - t[x].cost - i));
	return f[x][cnt];
}

int main(){
	scanf("%d", &cnt); cnt--;
	init(1);
	printf("%d\n", dfs(1, cnt));
	return 0;
}

#include<vector>
#include<cstdio>
#include<algorithm>
#define maxn 100010
#define ll long long
using namespace std;
int n,m;
ll sum = 0, cnt = 0;
int a[maxn],fa[maxn];
vector<int> p[maxn];
 
int find(int x){
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}
 
void join(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) fa[fx] = fy;
}
 
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)  scanf("%d",&a[i]), fa[i] = i;
	for(int i = 1; i <= m; i++){
		int u, v;scanf("%d %d",&u, &v);
		join(u, v);
	}
	if(n < 2 * (n - m - 1)){printf("-1\n");	return 0;}
	for(int i = 1; i <= n; i++){
		p[find(i)].push_back(a[i]);
		if(fa[i] == i)
		    cnt++;
	}
	if(cnt == 1){
		printf("0\n");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if(!p[i].size())
		    continue;
		sort(p[i].begin(), p[i].end());
		sum += p[i][0];
		for(int j = 1; j < p[i].size(); j++)
		    p[0].push_back(p[i][j]);
	}
	sort(p[0].begin(), p[0].end());
	for(int i = 0; i < n - m - 2; i++)
	    sum += p[0][i];
	printf("%lld\n", sum);
	return 0;
}


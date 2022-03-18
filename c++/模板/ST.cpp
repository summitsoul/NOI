#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 1e6 + 10;
int n,m;
int maxn[INF][21];

inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int query(int l, int r){
	int k = log2(r - l + 1);
	return max(maxn[l][k], maxn[r - (1 << k) + 1][k]);
}

int main(){
	n = read(); m = read();
	for(int i = 1; i <= n; i++) maxn[i][0] = read();
	for(int j = 1; j <= 21; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			maxn[i][j] = max(maxn[i][j - 1],maxn[i + (1 << (j - 1))][j - 1]);
	for(int i = 1; i <= m; i++){
		int l = read(),r = read();
		printf("%d\n",query(l, r));
	}
	return 0;
}

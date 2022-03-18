#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f
using namespace std;
int n,k,m,s,t;
int f[110][110],c[110],p[110][110];

int main(){
	cin >> n >> k >> m >> s >> t;
    for(register int i=1;i<=n;i++)
        for(register int j=1;j<=n;j++)
        	f[i][j]=INF;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= k; j++) cin >> p[i][j];
	for(int i = 1; i <= m; i++){
		int u,v,d; cin >> u >> v >> d;
		if(!p[c[v]][c[u]] && (c[u] != c[v])) f[u][v] = min(f[u][v], d);
		if(!p[c[u]][c[v]] && (c[u] != c[v])) f[v][u] = min(f[v][u], d);
	}
	if(c[s] == c[t]){
		cout << -1 <<endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j)
				for(int k = 1; k <= n; k++)
					if(j != k && i != k)
                        if(f[i][k]+f[k][j]<f[i][j])
                            f[i][j]=f[i][k]+f[k][j];
	if(f[s][t] == INF) cout << -1 << endl;
	else cout << f[s][t] <<endl;
	return 0;
}

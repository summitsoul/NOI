#include<cstdio>
#include<algorithm>
#define int long long
#define Mod 998244353
using namespace std;
int n, m, ans = 0;
int a[110][2010], f[110][110][110], g[110][110][110][110];

signed main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]);
    if(m == 2){
        f[0][0][0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= i; j++)
                for(int k = 0; k <= i; k++){
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % Mod;
                    if(j)
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k] * a[i][1]) % Mod;
                    if(k)
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1] * a[i][2]) % Mod;
                }
        for(int i = 1; i <= n / 2; i++)
            ans = (ans + f[n][i][i]) % Mod;
        printf("%lld\n", ans);
    }
    else{
        g[0][0][0][0] = 1;
        for(int i=1;i<=n;i++)
	        for(int j=0;j<=i;j++)
		        for(int k=0;k<=i;k++)
			        for(int l=0;l<=i;l++){
				g[i][j][k][l]=(g[i][j][k][l]+g[i-1][j][k][l])%Mod;
				if(j)
				g[i][j][k][l]=(g[i][j][k][l]+g[i-1][j-1][k][l]*a[i][1])%Mod;
				if(k)
				g[i][j][k][l]=(g[i][j][k][l]+g[i-1][j][k-1][l]*a[i][2])%Mod;
				if(l)
				g[i][j][k][l]=(g[i][j][k][l]+g[i-1][j][k][l-1]*a[i][3])%Mod;
			}
        for(int i=0;i<=n/2;i++)
	        for(int j=0;j<=n/2;j++)
		        for(int k=0;k<=n/2;k++){
			        if(i>j+k||j>i+k||k>i+j) continue;
			        ans+=g[n][i][j][k];
			        ans%=Mod;
		}
        printf("%lld\n", ans - 1);
    }
    return 0;
}
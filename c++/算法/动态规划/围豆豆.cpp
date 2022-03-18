#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, d, maxn, ans = -0x3f3f3f3f;
int v[15], ax[15], ay[15], val[1 << 11];
int dp[15][15][1 << 11], vis[15][15][1 << 12];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char c[15][15];
struct asd{
    int x, y, s;
    asd(int aa = 0, int bb = 0, int cc = 0){
        x = aa, y = bb, s = cc;
    }
}b[121];

inline int solve(int mx, int my, int xx, int yy, int ms){
    int ns = ms;
    for(int i = 1; i <= d; i++)
        if(((mx == ax[i] && xx < ax[i]) ||(mx < ax[i] && xx == ax[i])) && yy > ay[i])
            ns ^= (1 << (i - 1));
    return ns;
}

inline void SPFA(int i, int j){
    queue<asd> q;
    q.push(asd(i, j, 0));
    memset(dp, 0x3f, sizeof(dp));
    dp[i][j][0] = 0;
    while(!q.empty()){
        asd aa = q.front(); q.pop();
        int mx = aa.x, my = aa.y, ms = aa.s;
        vis[mx][my][ms] = 0;
        for(int i = 0; i < 4; i++){
            int xx = mx + dx[i], yy = my + dy[i];
            if(xx < 1 || yy < 1 || xx > n || yy > m || (c[xx][yy] > '0' && c[xx][yy] <= '9') || c[xx][yy] == '#') continue;
            int ns = ms;
            if(i & 1) ns = solve(mx, my, xx, yy, ms);
            if(dp[mx][my][ms] < dp[xx][yy][ns]){
                dp[xx][yy][ns] = dp[mx][my][ms] + 1;
                if(!vis[xx][yy][ns]){
                    vis[xx][yy][ns] = 1;
                    q.push(asd(xx, yy, ns));
                }
            }
        }
    }
    for(int k = 0; k < maxn; k++)
        ans = max(ans, val[k] - dp[i][j][k]);
}

int main(){
    scanf("%d %d %d", &n, &m, &d); maxn = 1 << d;
    for(int i = 1; i <= d; i++) scanf("%d", &v[i]);
    for(int i = 0; i < maxn; i++)
        for(int j = 1; j <= d; j++)
            if(i & (1 << (j - 1))) val[i] += v[j];
    for(int i = 1; i <= n; i++)
        scanf("%s", c[i] + 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(c[i][j] > '0' && c[i][j] <= '9'){
                int now = c[i][j] - '0';
                ax[now] = i, ay[now] = j;
            }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(c[i][j] == '0') SPFA(i, j);
    printf("%d\n", ans);
   return 0;
}
 /*#include<cstdio>
 #include<iostream>
 #include<algorithm>
 #include<queue>
 #include<cstring>
 using namespace std;
 int n,m,d;
 int mmax,f[11][11][1<<11],da[11],val[1<<11];
 struct asd{
     int x,y,s;
     asd(int aa=0,int bb=0,int cc=0){
         x=aa,y=bb,s=cc;
     }
 }b[11*11];
 char c[11][11];
 int xx[4]={0,-1,0,1},yy[4]={-1,0,1,0},ax[12],ay[12];
 int ans=-0x3f3f3f3f;
 int vis[12][12][1<<12];
 inline int solve(int mx,int my,int nx,int ny,int ms){
     int ns=ms;
     for(int i=1;i<=d;i++){
         if(((mx==ax[i] && nx<ax[i]) || (mx<ax[i] && nx==ax[i])) && ny>ay[i]){
             ns^=(1<<(i-1));
         }
     }
     return ns;
 }
 inline void SPFA(int ii,int jj){
     queue<asd> q;
     q.push(asd(ii,jj,0));
     memset(f,0x3f,sizeof(f));
     f[ii][jj][0]=0;
     //memset(vis,0,sizeof(vis));
     while(!q.empty()){
         asd aa=q.front();
        q.pop();
         int mx=aa.x,my=aa.y,ms=aa.s;
         vis[mx][my][ms]=0;
        for(int i=0;i<4;i++){
             int nx=mx+xx[i],ny=my+yy[i];
             if(nx<1 || ny<1 || nx>n || ny>m || (c[nx][ny]>='1' && c[nx][ny]<='9') || c[nx][ny]=='#') continue;
             int ns=ms;
            if(i&1) ns=solve(mx,my,nx,ny,ms);
            if(f[mx][my][ms]<f[nx][ny][ns]){
                f[nx][ny][ns]=f[mx][my][ms]+1;
                 if(vis[nx][ny][ns]==0){
                 vis[nx][ny][ns]=1;
                   q.push(asd(nx,ny,ns));
                }
           }
        }
     }
    for(int i=0;i<mmax;i++){
        ans=max(ans,val[i]-f[ii][jj][i]);
    }
}
 int main(){
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=d;i++){
        scanf("%d",&da[i]);
    }
     mmax=1<<d;
    for(int i=0;i<mmax;i++){
        for(int j=1;j<=d;j++){
            if(i&(1<<(j-1))) val[i]+=da[j];
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%s",c[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(c[i][j]>'0' && c[i][j]<='9'){
                int now=c[i][j]-'0';
                ax[now]=i,ay[now]=j;
             }
        }
    }
   for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]=='0'){
                SPFA(i,j);
            }
        }
    }
     printf("%d\n",ans);
    return 0;
}*/
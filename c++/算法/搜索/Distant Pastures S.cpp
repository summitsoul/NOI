#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, a, b, ans = 0;
int dis[110][110];
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char mp[110][110];
bool vis[110][110];
struct node{
    int x, y;
};

void SPFA(int x, int y){
    queue<node> q;
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    vis[x][y] = 1;
    q.push((node){x, y}); dis[x][y] = 0;
    while(q.size()){
        node d = q.front(); q.pop(); vis[d.x][d.y] = 0;
        for(int i = 0; i < 4; i++){
            int dx = d.x + mv[i][0], dy = d.y + mv[i][1];
            if(dx > 0 && dx <= n && dy > 0 && dy <= n){
                int t;
                if(mp[dx][dy] == mp[d.x][d.y]) t = a;
                else t = b;
                if(dis[dx][dy] > dis[d.x][d.y] + t){
                    dis[dx][dy] = dis[d.x][d.y] + t;
                    if(vis[dx][dy] == 0) vis[dx][dy] = 1, q.push((node){dx, dy});
                }
            }
        } 
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans = max(ans, dis[i][j]);
}

int main(){
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> mp[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            SPFA(i, j);
    printf("%d\n", ans);
    return 0;
}
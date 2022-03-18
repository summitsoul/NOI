#include<cstdio>
using namespace std;
int n, ans;
bool vis[20];
struct node{
    int x1, x2, y1, y2, c;
}f[17];

bool check(int x){
    for(int i = 1; i <= n; i++)
        if(!vis[i] && f[i].y1 == f[x].y2
        && ((f[i].x1 >= f[x].x1 && f[i].x1 <= f[x].x2) || 
        (f[i].x2 >= f[x].x1 && f[x].x2 >= f[i].x2))) return 0;
    return 1;
}

void search(int cnt, int finish, int c){
    if(cnt >= ans) return ;
    if(finish == n) ans = cnt;
    for(int i = 1; i <= n; i++)
        if(!vis[i] && check(i)){
            if(f[i].c == c){
                vis[i] = 1;
                search(cnt, finish + 1, c);
                vis[i] = 0;
            }
            else{
                vis[i] = 1;
                search(cnt + 1, finish + 1, f[i].c);
                vis[i] = 0;
            }
        }
}

int main(){
    scanf("%d", &n);
    ans = n;
    for(int i = 1; i <= n; i++)
        scanf("%d %d %d %d %d", &f[i].y1, &f[i].x1, &f[i].y2, &f[i].x2, &f[i].c);
    search(0, 0, -1);
    printf("%d\n", ans);
    return 0;
}
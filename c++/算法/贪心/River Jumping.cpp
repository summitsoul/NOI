#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, s, p, cnt = 0;
int w[100010], f[100010];
bool vis[100010];

int main(){
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + m + 1);
    w[0] = 0; w[m + 1] = n;
    for(int i = 1; i <= m + 1; i++)
        if(w[i] - p >= s){
            f[++cnt] = i;
            p = w[i];
            vis[i] = true;
        }
    if(p != w[m + 1]){printf("NO\n"); return 0;}
    for(int i = m; i >= 0; i--)
        if(!vis[i] && p - w[i] >= s){
            f[++cnt] = i;
            p = w[i];
            vis[i] = true;
        }
    if(cnt < m + 2){printf("NO\n"); return 0;}
    else{
        printf("YES\n");
        for(int i = 1; i <= cnt; i++)
            printf("%d ", f[i]);
        printf("\n");
    }
    return 0;
}
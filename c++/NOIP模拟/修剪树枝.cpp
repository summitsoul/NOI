#include<cstdio>
#include<algorithm>
#define N 2000010
using namespace std;
int n, k, cnt = 0, flag, ans = 0;
int head[N];
int tree[10010][10010];
struct edge{
    int to, next, w;
}e[N];

void add(int u, int v, int w){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].w = w;
    head[u] = cnt;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i < n; i++){
        int u, v, w; scanf("%d %d %d", &u, &v, &w); if(u != 1) flag = 1;
        tree[u][v] = w;
        add(u, v, w); add(v, u, w);

    }
    if(flag){
        int sum = 0;
        for(int i = 2; i < n; i++){
            sum += tree[i - 1][i];
            if(sum > k){sum -= tree[i - 1][i]; ans++;}
        }
        printf("%d\n", ans);
    }
    //else{
    //    sort()
    //    for(int i = 2; i < n; i++)
    //        if(tree[1][i] > k) ans++;
    //}
}
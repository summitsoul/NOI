#include<cstdio>
#define N 610
using namespace std;
int n, s, cnt = 0;
int head[N];
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
    scanf("%d %d", &n, &s);
    for(int i = 1; i < n; i++){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    
}
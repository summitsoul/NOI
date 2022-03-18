#include<cstdio>
#define N 200010
using namespace std;
int n, cnt = 0;
int head[N << 1];
long long t;
struct edge{
    int to, next;
    long long w;
}e[N << 1];

void add(int u, int v, long long w){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].w = w;
    head[u] = cnt;
}

int main(){
    scanf("%d %lld", &n, &t);
    for(int i = 2; i <= n; i++){
        int p; long long w; scanf("%d %lld", &p, &w);
        add(i, p, w); add(p, i, w);
    }
}
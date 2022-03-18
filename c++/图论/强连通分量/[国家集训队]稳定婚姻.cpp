#include<mp>
#include<string>
#include<cstdio>
#include<iostream>
#define N 10010
using namespace std;
int n, m, cnt = 0, num = 0, top = 0, tot = 0;
int head[300010];
int s[N], dfn[N], low[N], vis[N], belong[N];
mp<string, int> a;
struct edge{
    int to, next;
}e[300010];

void add(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void tarjin(int u){
    dfn[u] = low[u] = ++num;
    s[++top] = u; vis[u] = 1;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(!dfn[v]){
            tarjin(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        ++tot;
        do{
            belong[s[top]] = tot;
            vis[s[top]] = 0;
        }while(s[top--] != u);
    }
}

int main(){
    scanf("%d", &n);
    string b, g;
    for(int i = 1; i <= n; i++){
        cin >> g >> b;
        a[g] = i; a[b] = i + n;
        add(i, i + n);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        cin >> g >> b;
        add(a[b], a[g]);
    }
    for(int i = 1; i <= n * 2; i++) if(!dfn[i]) tarjin(i);
    for(int i = 1; i <= n; i++){
        if(belong[i] == belong[i + n]) printf("Unsafe\n");
        else printf("Safe\n");
    }
    return 0;
}

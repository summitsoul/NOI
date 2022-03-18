#include<queue>
#include<cstdio>
#include<algorithm>
#define N 20010
using namespace std;
int n, k, m, ans = 0;
int fa[N];
struct edge{
    int u, v, t, T;
}e;
struct fuckccf1{bool operator () (edge a,edge b) {return a.t>b.t;} };
struct fuckccf2{bool operator () (edge a,edge b) {return a.T>b.T;} };
priority_queue<edge, vector<edge>, fuckccf1> q1;
priority_queue<edge, vector<edge>, fuckccf2> q2;

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main(){
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d %d", &e.u, &e.v, &e.T, &e.t);
        q1.push(e); q2.push(e);
    }
    m = 0;
    while(q2.size() && m < k){
        e = q2.top(); q2.pop();
        int x = find(e.u), y = find(e.v);
        if(x == y) continue;
        ans = max(ans, e.T);
        m++;
        fa[x] = y;
    }
    while(q1.size() && m < n - 1){
        e = q1.top(); q1.pop();
        int x = find(e.u), y = find(e.v);
        if(x == y) continue;
        ans = max(ans, e.t);
        m++;
        fa[x] = y;
    }
    printf("%d\n", ans);
    return 0;
}
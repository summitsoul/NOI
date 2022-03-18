#include<cstdio>
#include<iostream>
#define N 500010
using namespace std;
int n, m, s, cnt = 0;
int lg[N], head[N  << 1];
int depth[N], fa[N][22];
struct edge{
    int next, to;
}e[N << 1];

void add(int u, int v){
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void dfs(int now, int fath){    //now表示当前节点,fath表示它的父亲节点
    fa[now][0] = fath;  //2的0次方为1,即它的父亲节点
    depth[now] = depth[fath] + 1;   //now的深度为它父亲的深度加1
    for(int i = 1; i <= lg[depth[now]]; i++)    //lg数组的大小是指当前节点的深度的以2为底的对数,我们回溯只能回溯到根节点，所以需要加上这个判断
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
        //这是整个算法的核心,表示now的第2 ^ i个祖先为now的第2 ^ (i - 1)个祖先的2 ^ (i- 1)祖先
        //2 ^ i = 2 ^(i - 1) + 2 ^ (i - 1)
    for(int i = head[now]; i; i = e[i].next)    //我们用链式前向星来存储整个图
        if(e[i].to != fath) dfs(e[i].to, now);  //如果now当前节点指向的点不为它的父亲,那么则为它的儿子,这是我们now作为父节点再进行dfs,将它的子节点进行预处理
}

int LCA(int x, int y){
    if(depth[x] < depth[y]) swap(x, y); //我们在这里强制x的深度>=y的深度
    while(depth[x] > depth[y]) 
        x = fa[x][lg[depth[x] - depth[y]] - 1]; //首先将x和y跳到同一层
    if(x == y) return x;    //如果x是y的祖先,那么他们的LCA就是x
    for(int i = lg[depth[x]] - 1; i >= 0; i--) //不断的向上爬
        if(fa[x][i] != fa[y][i])      //我们要跳到的是它们的LCA的下一层,所以它们肯定不一样,如果不相等就跳过去
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];    //返回父节点
}

int main(){
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v);
        add(u, v); add(v, u);
    }
    for(int i = 1; i <= n; i++)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    dfs(s, 0);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d %d", &u, &v);
        printf("%d\n", LCA(u, v));
    }
    return 0;
}
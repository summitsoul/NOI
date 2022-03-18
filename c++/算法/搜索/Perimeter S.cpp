#include<set>
#include<cstdio>
using namespace std;
int n, ans = 0;
set<pair<int, int>>blocks, vis;

bool is(int x, int y){
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if(blocks.count(make_pair(x + i, y + j)) == 1) return 0;
    return 1;
}

void dfs(int x, int y){
    if(blocks.count(make_pair(x, y)) != 0){ans++; return ;}
    if(vis.count(make_pair(x, y)) != 0) return ;
    vis.insert(make_pair(x, y));
    if(is(x, y)) return ;
    dfs(x + 1, y); dfs(x - 1, y); dfs(x, y + 1); dfs(x, y - 1);
}

int main(){
    scanf("%d", &n);
    int x, y;
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &x, &y);
        blocks.insert(make_pair(x, y));
    }
    pair<int, int> st =* blocks.begin();
    int stx, sty;
    stx = st.first - 1;
    sty = st.second - 1;
    dfs(stx, sty);
    printf("%d\n", ans);
    return 0;
}
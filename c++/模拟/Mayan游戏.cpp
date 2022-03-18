#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[10][10], ans[10][5], last[10][10][10], xiao[10][10];

bool remove(){      //消除
    int flag = 0;
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 7; j++){
            if(i - 1 >= 1 && i + 1 <= 5 && a[i][j] == a[i - 1][j] && a[i][j] == a[i + 1][j] && a[i][j])
                xiao[i - 1][j] = 1, xiao[i + 1][j] = 1, xiao[i][j] = 1, flag = 1;
            if(j - 1 >= 1 && j + 1 <= 7 && a[i][j] == a[i][j + 1] && a[i][j] == a[i][j - 1] && a[i][j])
                xiao[i - 1][j] = 1, xiao[i + 1][j] = 1, xiao[i][j] = 1, flag = 1;
        }
    if(!flag) return 0;
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 7; j++)
            if(xiao[i][j]){
                xiao[i][j] = 0;
                a[i][j] = 0;
            }
    return 1;
}

bool check(){       //判断是否全部消失
    for(int i = 1; i <= 5; i++)
        if(a[i][1]) return 0;
    return 1;
}

void update(){      //更新游戏状态
    for(int i = 1; i <= 5; i++){
        int cnt = 0;
        for(int j = 1; j <= 7; j++){
            if(!a[i][j]) cnt++;
            else{
                if(!cnt) continue;
                a[i][j - cnt] = a[i][j];
                a[i][j] = 0;
            }
        }
    }
}

void move(int i, int j, int x){     //移动
    int tmp = a[i][j];
    a[i][j] = a[i + x][j];
    a[i + x][j] = tmp;
    update();
    while(remove()) update();
}

void copy(int x){      //复制当前状态
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 7; j++)
            last[x][i][j] = a[i][j];
}

void dfs(int x){
    if(check()){
        for(int i = 1; i <= n; i++){
            if(i != 1) printf("\n");
            for(int j = 1; j <= 3; j++)
                printf("%d ", ans[i][j]);
        }
        exit(0);
    }
    if(x == n + 1) return ;
    copy(x);
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 7; j++){
            if(a[i][j]){
                if(i + 1 <= 5 && a[i][j] != a[i + 1][j]){
                    move(i, j, 1);
                    ans[x][1] = i - 1; ans[x][2] = j - 1; ans[x][3] = 1;
                    dfs(x + 1);
                    for(int i = 1; i <= 5; i++)
                        for(int j = 1; j <= 7; j++)
                            a[i][j] = last[x][i][j];
                    ans[x][1] = -1; ans[x][2] = -1; ans[x][3] = -1;
                }
                if(i - 1 >= 1 && a[i - 1][j] == 0){
                    move(i, j, -1);
                    ans[x][1] = i - 1; ans[x][2] = j - 1; ans[x][3] = -1;
                    dfs(x + 1);
                    for(int i = 1; i <= 5; i++)
                        for(int j = 1; j <= 7; j++)
                             a[i][j] = last[x][i][j];
                    ans[x][1] = -1; ans[x][2] = -1; ans[x][3] = -1;
                }
            }
        }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 8; j++){
            int x; scanf("%d", &x);
            if(x == 0) break;
            a[i][j] = x;
        }
    memset(ans, -1, sizeof(ans));
    dfs(1);
    printf("-1\n");
    return 0;
}
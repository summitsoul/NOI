/*#include<cmath>
#include<cstdio>
int a[11], n, s, p, ans = 0;
void dfs(int cur, int sum){ //cur记录现在多少个数， sum记录总和
    if(cur == n){
        if(sum == s)
            ans++;
        return ;
    }
    else{
        for(int i = 1; i < s; i++){
            if(sum + i <= s){
                if(cur == 0){
                    a[cur] = i;
                    dfs(cur + 1, sum + i);
                    a[cur] = 0;
                }
                else{
                    a[cur] = i;
                    if(fabs(a[cur] - a[cur-1]) <= p){
                        dfs(cur + 1, sum + i);
                        a[cur] = 0;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &s, &p);
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}*/

#include<cstdio>
using namespace std;
int n, s, p, ans = 0;

void dfs(int pur, int num, int sum){
    if(num == n){
        if(sum == s)ans++;
        return ;
    }
    if(sum > s) return ;
    for(int i = pur - p; i <= pur + p; i++)
        if(i > 0)
            dfs(i, num + 1, sum + i);
}

int main(){
    scanf("%d %d %d", &n, &s, &p);
    for(int i = 1; i < s; i++) dfs(i, 1, i);
    printf("%d\n", ans);
    return 0;
}
#include<cstdio>
#define mod 1000000007
using namespace std;
int x0, ans = 0;
bool flag;

void solve(int x){
    if(ans == 310000){flag = 1; return ;}
    ans++;
    int y = (2 * (x % mod) + 1) % mod;
    if(y == 0){
        if(ans % 3 == 0) ans /= 3;
        else ans = ans / 3 + 1;
        if(ans > 100000) flag = 1;
    }
    else solve(y);
    return ;
}

int main(){
    scanf("%d", &x0);
    solve(x0);
    if(!flag) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}

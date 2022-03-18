#include<cstdio>
#include<algorithm>
using namespace std;
int n, s, c, y, cost;
long long ans = 0;

int main(){
    scanf("%d %d", &n, &s);
    for(int i  = 1; i <= n; i++){
        scanf("%d %d", &c, &y);
        if(i == 1) cost = c;
        else cost = min(cost + s, c);
        ans += cost * y;
    }
    printf("%lld\n", ans);
    return 0;
}
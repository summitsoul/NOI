#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n, ans;
struct node{
    int a, b;
    bool operator < (node & y){
    return a * b < y.a * y.b;
    }
}pri[1010];

signed main(){
    scanf("%lld", &n);
    for(int i = 0; i <= n; i++)
        scanf("%lld %lld",&pri[i].a, &pri[i].b);
    sort(pri + 1, pri + n + 1);
    int x = pri[0].a;
    for(int i = 1; i <= n; i++){
        ans += max(ans, x / pri[i].b);
        x *= pri[i].a;
    }
    printf("%lld\n", ans);
    return 0;
}
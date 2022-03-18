#include<cstdio>
#define int long long
using namespace std;
int n, t, ans = 1; 
int last[100010];
struct cow{
    int pos, spe;
}c[100010];

signed main(){
    scanf("%lld %lld", &n, &t);
    for(int i = 1; i <= n; i++){
        scanf("%lld %lld", &c[i].pos, &c[i].spe);
        last[i] = c[i].pos + c[i].spe * t;
    }
    for(int i = n - 1; i >= 1; i--){
        if(last[i] >= last[i + 1])
            last[i] = last[i + 1];
        else ans++;
    }
    printf("%lld\n", ans);
    return 0;
}
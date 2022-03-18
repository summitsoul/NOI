#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const double eps = 1e-6;
int n, r, cnt = 0, ans = 0;
struct light{
    double l, r;
}l[110];

bool cmp(light x, light y){return x.r < y.r;}

void cal(int x, int y){
    double deta;
    deta = sqrt(r * r - y * y);
    l[++cnt].l = x * 1.0 - deta;
    l[cnt].r = x * 1.0 + deta;
}

int main(){
    int x, y;
    scanf("%d %d", &n, &r);
    for(int i = 1; i <= n; i++) scanf("%d %d", &x, &y), cal(x, y);
    sort(l + 1, l + cnt + 1, cmp);
    double loc = l[1].r;
    ans++;
    for(int i = 2; i <= cnt; i++)
        if(loc + eps < l[i].l) ans++, loc = l[i].r;
    printf("%d\n", ans);
    return 0;
}

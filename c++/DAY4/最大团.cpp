#include<cmath>
#include<cstdio>
#include<algorithm>
#define N 200010
using namespace std;
int n, m, k = 1, ans = 0;
struct node{
    int x, w, sum, pro;
}p[N];

bool cmp(node x, node y){return x.sum < y.sum;}

int main(){
    scanf("%d", &n);
    for(register int i = 1; i <= n; i++){
        scanf("%d %d", &p[i].x, &p[i].w);
        p[i].sum = p[i].x + p[i].w;
        p[i].pro = p[i].x - p[i].w;
    }
    ans++;
    sort(p + 1, p + n + 1, cmp);
    for(int i = 2; i <= n; i++)
        if(p[i].pro >= p[k].sum){ans++; k = i;}
    printf("%d\n", ans);
    return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[1010], b[1010], t[1010], ans[1010];
struct node{
    int mi, wan;
}mc[10010];

bool cmp(node x, node y){return x.mi < y.mi;}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), mc[i].wan = i;
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]), mc[i].mi = min(a[i], b[i]);
    sort(mc + 1, mc + n + 1, cmp);
    int z = 0, y = n + 1;
    for(int i = 1; i <= n; i++){
        if(mc[i].mi == a[mc[i].wan]){
            z++; ans[z] = mc[i].wan;
        }
        else{
            y--; ans[y] = mc[i].wan;
        }
    }
    for(int i = 1; i <= n; i++) t[i] = t[i - 1] + a[ans[i]];
    int sum = t[1] + b[ans[1]];
    for(int i = 2; i <= n; i++) sum = max(t[i], sum) + b[ans[i]];
    printf("%d\n", sum);
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
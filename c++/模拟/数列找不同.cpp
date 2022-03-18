#include<cstdio>
#include<algorithm>
using namespace std;
int n, q;
int a[100010], left[100010];

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
        int k; scanf("%d", &k);
        left[i] = max(left[i - 1], a[k] + 1);
        a[k] = i;
    }
    for(int i = 1; i <= q; i++){
        int l, r; scanf("%d %d", &l, &r);
        if(left[r] <= l) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

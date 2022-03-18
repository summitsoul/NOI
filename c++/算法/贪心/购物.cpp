#include<cstdio>
#include<algorithm>
using namespace std;
int x, n, ans = 0;
int a[1010];

int main(){
    scanf("%d %d", &x, &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if(a[1] != 1){printf("-1\n"); return 0;}
    sort(a + 1, a + n + 1);
    int sum = 0;
    while(sum < x){
        int i;
        for(i = n; i >= 1; i--) if(a[i] <= sum + 1) break;
        ans++; sum += a[i];
    }
    printf("%d\n", ans);
    return 0;
}

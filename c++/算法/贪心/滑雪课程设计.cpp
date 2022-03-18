#include<cstdio>
#include<algorithm>
using namespace std;
int n, ans = 0x7f7f7f7f;
int h[1010];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
    sort(h + 1, h + n + 1);
    for(int i = h[1]; i <= h[n]; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(h[j]- i > 17) sum += (h[j] - i - 17) * (h[j] - i - 17);
            if(h[j] < i) sum += (h[j] - i) * (h[j] - i);
        }
        ans = min(sum, ans);
    }
    printf("%d\n", ans);
    return 0;
}
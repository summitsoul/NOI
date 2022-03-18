#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int sum[1010], f[1010];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int x; scanf("%d", &x);
        sum[i] = sum[i - 1] + x;
        if(sum[i] >= 0) f[i] = 1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
            if(f[j] > 0 && sum[i] - sum[j] >= 0)
                f[i] = max(f[i], f[j] + 1);
    if(f[n] == 0) printf("Impossible\n");
    else printf("%d\n", f[n]);
    return 0;
}

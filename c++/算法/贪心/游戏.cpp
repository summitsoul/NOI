#include<cstdio>
#include<algorithm>
using namespace std;
int n, k, a, b;
int x[300];

int main(){
    scanf("%d %d %d %d", &n, &k, &a, &b);
    for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
    sort(x + 1, x + n + 1);
    for(int i = n; n - i + 1 <=  k; i--) b -= x[i];
    printf("%d\n", b);
    return 0;
}
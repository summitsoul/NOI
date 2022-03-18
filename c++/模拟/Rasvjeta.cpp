#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, k, sum = 0;
bool vis[2010];

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        int x; scanf("%d", &x);
        for(int j = max(x - k, 1); j <= min(x + k, n); j++)
            vis[j] = true;
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            i += k + k;
            sum++;
        }
    printf("%d\n", sum);
    return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, k;
int ans = 2147483647;
int mp[1010][1010], f_max[1010][1010], f_min[1010][1010];

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            scanf("%d", &mp[i][j]);
            f_max[i][j] = mp[i][j];
            f_min[i][j] = mp[i][j];
        }
    for(int l = 2; l <= k; l++)
        for(int i = n; i >= l; i--)
            for(int j = m; j >= l; j--){
                f_max[i][j] = max(mp[i][j], max(f_max[i - 1][j], max(f_max[i][j - 1], f_max[i - 1][j - 1])));
                f_min[i][j] = min(mp[i][j], min(f_min[i - 1][j], min(f_min[i][j - 1], f_min[i - 1][j - 1])));
            }
    for(int i = k; i <= n; i++)
        for(int j = k; j <= m; j++)
            ans = min(ans, f_max[i][j] - f_min[i][j]);
    printf("%d\n", ans);
    return 0;
}
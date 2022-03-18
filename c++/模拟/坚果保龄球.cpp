#include<cstdio>
#include<algorithm>
using namespace std;
int n, ans = 0;
int a[10], p[10][2010];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int k, t; scanf("%d %d", &k, &t);
        p[k][++a[k]] = t;
    }
    for(int i = 1; i <= 6; i++)
        sort(p[i] + 1, p[i] + a[i] + 1);
    for(int i = 1; i <= 6; i++){
        if(a[i] == 0) continue;
        int k = p[i][1]; ans++;
        for(int j = 2; j <= a[i]; j++){
            if(p[i][j] - k >= 60){
                ans++;
                k = p[i][j];
            }
        }
    }
    printf("%d\n", ans);
}
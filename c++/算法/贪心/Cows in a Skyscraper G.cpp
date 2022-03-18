#include<cstdio>
#include<algorithm>
using namespace std;
int n, W, w[20];

bool cmp(int x, int y){return w[x] > w[y];}

int main(){
    scanf("%d %d", &n, &W);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp);
    int ans = 0, sum = 0;
    for(int i = 1; i <= n; i++){
        sum += w[i];
        if(sum > W){ ans++; sum = w[i];}
    }
    printf("%d\n", ans + 1);
    return 0;
}
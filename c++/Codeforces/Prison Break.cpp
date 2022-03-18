#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, r, c;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &n, &m, &r, &c);
        int a = n - r + m - c;
        int b = r - 1 + m - c;
        int d = n - r + c - 1;
        int e = r - 1 + c - 1;
        int ans = max(a, max(b, max(c, d)));
        printf("%d\n", ans);
    }
    return 0;
}
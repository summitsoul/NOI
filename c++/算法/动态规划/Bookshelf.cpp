#include<cstdio>
#include<algorithm>
using namespace std;
int n, l;
int f[1000010];
struct book{
    int w, h;
}b[2010];

int main(){
    scanf("%d %d", &n, &l);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &b[i].h, &b[i].w);
    for(int i = 1; i <= n; i++){
        int mx = b[i].h, sum = b[i].w;
        f[i] = f[i - 1] + b[i].h;
        for(int j =i - 2; j >= 0; j--){
            sum += b[j + 1].w;
            if(sum > l) break;
            mx = max(mx, b[j + 1].h);
            f[i] = min(f[i], f[j] + mx);
        }
    }
    printf("%d\n", f[n]);
    return 0;
}
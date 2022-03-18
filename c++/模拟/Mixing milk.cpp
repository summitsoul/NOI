#include<cstdio>
#include<algorithm>
using namespace std;
int c[5], m[5];

int main(){
    for(int i = 1; i <= 3; i++) scanf("%d %d", &c[i], &m[i]);
    for(int i = 1; i <= 100; i++){
        int f = (i - 1) % 3 +1, s;
        if(f == 3) s = 1;
        else s = f + 1;
        int mi = min(c[s] - m[s], m[f]);
        m[f] -= mi;
        m[s] += mi;
    }
    printf("%d\n%d\n%d\n", m[1], m[2], m[3]);
    return 0;
}
#include<cstdio>
#define ll long long
using namespace std;
const int N = 3e6 + 10;
int n, p;
ll inv[N] = {0, 1};

int main(){
    scanf("%d %d", &n, &p);
    printf("1\n");
    for(int i = 2; i <= n; i++){
        inv[i] = (ll)p - (p/ i) * inv[p % i] % p;
        printf("%lld\n", inv[i]);
    }    
    return 0;
}
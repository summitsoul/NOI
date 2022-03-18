#include<cstdio>
using namespace std;
int a, n, ans = 0;

int gcd(int x, int y){
    return y ? gcd(y, x % y) : x;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i<= n; i++){
        scanf("%d", &a);
        if(a < 0) a = -a;
        ans = gcd(ans, a);
    }
    printf("%d\n", ans);
    return 0;
}
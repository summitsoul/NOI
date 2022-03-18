#include<cstdio>
#define ll long long
using namespace std;
int c, n;
int f1 = 1, f2 = 1, a1, b1, d1, a2, b2, d2; 
ll f[4000010];

ll fir(){return a1 * f[f1] / d1 + b1;}

ll sec(){return a2 * f[f2] / d2 + b2;}

int main(){
    scanf("%d %d", &c, &n);
    scanf("%d %d %d", &a1, &b1, &d1);
    scanf("%d %d %d", &a2, &b2, &d2);
    f[1] = c;
    for(int i = 2; i <= n; i++){
        ll x = fir(), y = sec();
        if(x < y){ f[i] = x; f1++;}
        else if(x > y){ f[i] = y; f2++;}
        else if(x == y){ f[i] = x; f1++; f2++;}
    }
    printf("%lld\n", f[n]);
    return 0;
}
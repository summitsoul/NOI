#include<cstdio>
#define ll long long
using namespace std;
ll n, mul = 1, sum = 0;
ll a[16], m[16], s[16];

inline int read(){
    int s = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
    return s;
}

void exgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){x = 1; y = 0; return ;}
    exgcd(b, a % b, x, y);
    int z = x; x = y; y = z - y * (a / b);
}

int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        int b = read(); m[i] = b;
        mul *= b;
        a[i] = read();
    }
    for(int i = 1; i <= n; i++){
        s[i] = mul / m[i];
        ll x = 0, y = 0;
        exgcd(s[i], m[i], x, y);
        sum += a[i] * s[i] * (x < 0 ? x + m[i]: x);
    }
    printf("%lld\n", sum % mul);
    return 0;
}
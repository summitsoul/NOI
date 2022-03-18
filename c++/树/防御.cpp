#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1e5+1,mo=1e9+9;
LL d[N], boom[N], minx[N << 2];
LL sum[N << 2], lazy[N << 2];

int read(){
    int a = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){a = a * 10 + ch - '0'; ch = getchar();}
    return a * f;
}

void pushup(int rt){
    minx[rt] = min(minx[rt << 1], minx[rt << 1 ^ 1]);
}

void pushdown(int rt){
    if(minx[rt<<1] != 2e9) minx[rt << 1] -= lazy[rt];
    if(minx[rt << 1 ^ 1] != 2e9) minx[rt << 1 ^ 1] -= lazy[rt];
    lazy[rt << 1] += lazy[rt], lazy[rt << 1 ^ 1] += lazy[rt];
    lazy[rt] = 0;
}

void build(int l, int r, int rt){
    if(l == r){
        d[l] = read(); 
        minx[rt] = d[l] ? d[l] : 2e9;
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 ^ 1);
    pushup(rt);
}

void change(int l, int r, int rt, int s){
    if(l == r){
        d[l] = d[l] - minx[rt] + s; 
        minx[rt] = 2e9; boom[l] = 1;
        return;
    }
    int m = l + r >> 1;
    if(lazy[rt]) pushdown(rt);
    if(s >= minx[rt << 1]) change(l, m, rt << 1, s);
    if(s >= minx[rt << 1 ^ 1]) change(m + 1, r, rt << 1 ^ 1, s);
    pushup(rt);
}

void add(int l, int r, int rt, int L, int R, int c, LL s){
    if(L <= l && r <= R){
        sum[rt] += c;
        if(minx[rt] <= c) change(l, r, rt, c);
        if(minx[rt] != 2e9) minx[rt] -= c, lazy[rt] += c;
        return;
    }
    s += sum[rt];
    if(lazy[rt]) pushdown(rt);
    int m = l + r >> 1;
    if(L <= m) add(l, m, rt << 1, L, R, c, s);
    if(m < R) add(m + 1, r, rt << 1 ^ 1, L, R, c, s);
    pushup(rt);
}

int query(int l, int r, int rt, int p){
    if(l == r) return sum[rt] % mo;
    int m = l + r >> 1;
    if(p <= m) return(sum[rt] + query(l, m, rt << 1, p)) % mo;
    else return(sum[rt] + query(m + 1, r, rt << 1 ^ 1, p)) % mo; 
}

int main(){
    int n = read(), q = read(); LL ans = 0;
    build(1, n, 1);
    for(int i = 1; i <= q; i++){
        scanf("\n");
        if(getchar() == 'A'){
            int L = read(), R = read(), c = read();
            add(1, n, 1, L, R, c, 0);
        }
        else{
            int x = read();
            if(boom[x]) ans = (ans + query(1, n, 1, x) * 2 - d[x] + mo) % mo;
            else ans = (ans + query(1, n, 1, x)) % mo; 
        }
    }
    printf("%lld", ans);
    return 0;
}
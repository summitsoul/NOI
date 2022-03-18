#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, len, sum = 0, cnt = 0;
int l[70], nxt[70];
bool ok;
bool used[70];

bool cmp(int x, int y){return x > y;}

void dfs(int k, int last, int rest){
    int i;
    if(!rest){
        if(k == m){ok = 1; return ;}
        for(i = 1; i <= cnt; i++)
            if(!used[i]) break;
        used[i] = 1;
        dfs(k + 1, i, len - l[i]);
        used[i] = 0;
        if(ok) return ;
    }
    int le = last + 1, r = cnt;
    while(le < r){
        int mid = (le + r) >> 1;
        if(l[mid] <= rest) r = mid;
        else le = mid + 1;
    }
    for(i = le; i <= cnt; i++){
        if(!used[i]){
            used[i] = 1;
            dfs(k, i, rest - l[i]);
            used[i] = 0;
            if(ok) return ;
            if(rest == l[i] || rest == len) return ;
            i = nxt[i];
            if(i == cnt) return ;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int d; scanf("%d", &d);
        if(d > 50) continue;
        l[++cnt] = d;
        sum += d;
    }
    sort(l + 1, l + n + 1, cmp);
    nxt[cnt] = cnt;
    for(int i = cnt - 1; i > 0; i--){
        if(l[i] == l[i + 1]) nxt[i] = nxt[i + 1];
        else nxt[i] = i;
    }
    for(len = l[1]; len <= sum / 2; len++){
        if(sum % len != 0) continue;
        m = sum / len;
        ok = 0;
        used[1] = 1;
        dfs(1, 1, len - l[1]);
        used[1] = 0;
        if(ok){printf("%d\n", len); return 0;}
    }
    printf("%d\n", sum);
    return 0;
}
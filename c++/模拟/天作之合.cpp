#include<cstdio>
using namespace std;
int a, s, ans = 0;
int e[10], f[10];

int main(){
    scanf("%d %d", &a, &s);
    int t = 100000;
    for(int i = 1; i <= 6; i++){
        e[a / t] = i;
        a %= t;
        t /= 10;
    }
    t = 100000;
    for(int i = 1; i <= 6; i++){
        f[i] = e[s / t];
        s %= t;
        t /= 10;
    }
    for(int i = 1; i <= 5; i++)
        for(int j = i + 1; j <= 6; j++)
            if(f[j] < f[i]) ans++;
    printf("%d\n", ans <= 2 ? ans + 2 : ans);
    return 0;
}
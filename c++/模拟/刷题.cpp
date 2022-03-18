#include<cstdio>
#include<algorithm>
using namespace std;
int n, ans;
int a[10], b[10], t[5010];
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 30};
long long ti;

bool judge(int x){
    if(x % 100 == 0){if(x % 400 == 0) return 1;}
    else{if(x % 4 == 0) return 1;}
    return 0;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &t[i]);
    sort(t + 1, t + n + 1);
    scanf("%d-%d-%d-%d:%d", &a[1], &a[2], &a[3], &a[4], &a[5]);
    scanf("%d-%d-%d-%d:%d", &b[1], &b[2], &b[3], &b[4], &b[5]);
    for(int i = a[1]; i < b[1]; i++)
        if(judge(i)) ti += 366;
        else ti += 365;
    for(int i = 1; i < a[2]; i++) ti -= day[i];
    for(int i = 1; i < b[2]; i++) ti += day[i];
    if(judge(a[1]) && a[2] > 2) ti--;
    if(judge(b[1]) && b[2] > 2) ti++;
    ti -= a[3]; ti += b[3];
    ti *= 1440;
    ti -= 60 * a[4] + a[5]; ti += 60 * b[4] + b[5];
    for(int i = 1; i <= n; i++)
        if(ti >= t[i]) ti -= t[i], ans++;
        else break;
    printf("%d\n", ans);
    return 0;
}
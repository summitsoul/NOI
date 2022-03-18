#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
int n, t_max;
int d[100010];

bool check(int x){
    int ans = 0;
    priority_queue<int, vector<int>, greater<int> >q;
    for(int i = 1; i <= x; i++) q.push(d[i]);
    if(ans > t_max) return 0;
    int z = x + 1, c = 0;
    for(int i = z; i <= n; i++){
        ans += q.top() - c;
        c = q.top(); q.pop();
        if(ans > t_max) return 0;
        q.push(d[i] + c);
    }
    for(int i = 1; i <= x; i++){
        ans += q.top() - c;
        c = q.top(); q.pop();
        if(ans > t_max) return 0;
    }
    return 1;
}

int main(){
    scanf("%d %d", &n, &t_max);
    for(int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
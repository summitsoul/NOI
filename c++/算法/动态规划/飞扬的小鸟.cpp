#include <bits/stdc++.h>
#define mset(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
struct node{
    ll hi,wi;
    int Index;
    friend bool operator < (node a, node b){
        if(a.wi==b.wi) return a.hi<b.hi;
        return a.wi>b.wi;
    }
}a[3000005];
int main (){
    int n,k,d;
    while (scanf ("%d%d%d",&n,&k,&d)!=EOF){
        priority_queue<node> Q;
        for (int i=1;i<=n;i++) scanf ("%lld%lld",&a[i].hi,&a[i].wi),a[i].Index=i;
        Q.push(a[1]);
        for (int i=2;i<=n;i++){
            while(!Q.empty()){
                if(i-Q.top().Index>k) Q.pop();
                else{
                    a[i].wi=a[Q.top().Index].wi+a[i].wi+(Q.top().hi>a[i].hi?0:d);
                    break;
                }
            }
            Q.push(a[i]);
        }
        printf("%lld\n",a[n].wi);
    }
    return 0;
}

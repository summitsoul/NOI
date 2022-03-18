#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, k;
long long a[100010];
set<long long>s;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        if(a[i] % k || s.find(a[i] / k) == s.end())
            s.insert(a[i]);
    printf("%d\n", s.size());
    return 0;
}
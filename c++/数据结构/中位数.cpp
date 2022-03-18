#include<vector>
#include<cstdio>
#include<algorithm>
#define N 1000010
using namespace std;
int n;
vector<int> a;

int main(){
    scanf("%d", &n);
    for(int i = 1, x; i <= n; i++){
        scanf("%d", &x);
        a.insert(upper_bound(a.begin(), a.end(), x), x);
        if(i % 2 == 1) printf("%d\n", a[(i - 1) >> 1]);
    }
    return 0;
}
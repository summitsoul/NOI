#include<cstdio>
using namespace std;
int n, ans = 1;
int a[4] = {6, 8, 4, 2};

int main(){
    scanf("%d %d", &n);
    while(n > 0){
        for(int i = 1; i <= n % 10; i++)
            if(i != 5) ans = ans * i % 10;
        n /= 5;
        ans = ans * a[n % 4] % 10;
    }
    printf("%d\n", ans);
    return 0;
}
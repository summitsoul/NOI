#include<cstdio>
using namespace std;
int n;
char c[10][10];

int main(){
    scanf("%d", &n); n += 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%c", &c[i][j]);
    
}
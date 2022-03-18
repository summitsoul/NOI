#include<bits/stdc++.h>
using namespace std;
int a[100];

int main(){
    a[1] = 1, a[2] = 1, a[3] = 0;
    for(int i = 4; i <= 10; i++){
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
        if(i == 6) a[i] = 0;
    }
    printf("%d\n", a[10]);
    return 0;
}
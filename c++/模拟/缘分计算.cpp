#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
int st, sum = 0;
int a[1010];
string str;

int main(){
    cin >> str; 
    scanf("%d", &st);
    for(int i = 0; i < str.size(); i++){
        int num = str[i] - 'A' + st;
        int w = 10000; bool flag = 0;
        while(w){
            if(num >= w) flag = 1;
            if(flag) a[++sum] = num / w;
            num %= w;
            w /= 10;
        }
    }
    while(sum > 2){
        if(sum == 3 && a[1] == 1 && a[2] == 0 && a[3] == 0){
            printf("100\n"); return 0;
        }
        for(int i = 1; i < sum; i++)
            a[i] = (a[i] + a[i + 1]) % 10;
        sum--;
    }
    if(sum == 1) printf("%d\n", a[1]);
    else printf("%d\n", a[1] * 10 + a[2]);
    return 0;
}
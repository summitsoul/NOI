#include<cstdio>
using namespace std;
int n;
char c[5000010], ans[5000010];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%c", c[i]);
    int l = 1, r = n, o = 0;
    while(o <= n){
        if(c[l] < c[r]){
            ans[++o] = c[l]; l++;
            continue; 
        }
        if(c[l] > c[r]){
            ans[++o] = c[r]; r--;
            continue;
        }
        else if(c[l] == c[r]){
            int i = l + 1, j = r - 1;
            while(j - i > 1 && c[i] == c[j]){
                i++; j--;
            }
            if(c[i] < c[j]){ans[++o] = c[i]; i++;}
            else{ans[++o] = c[j]; j--;}
        }
    }
    for(int i = 1; i <= n; i++){
        if(i % 80 == 0) printf("\n");
        printf("%c", ans[i]);
    }
    return 0;
}